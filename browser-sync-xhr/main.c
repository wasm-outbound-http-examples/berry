#include "berry.h"
#include "be_repl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten/fetch.h>

int httpget_func(bvm *vm)
{
    int argc = be_top(vm);
    if (argc == 1 && be_isstring(vm, 1))
    {
        const char *url = be_tostring(vm, 1);

        emscripten_fetch_attr_t attr;
        emscripten_fetch_attr_init(&attr);
        strcpy(attr.requestMethod, "GET");
        attr.attributes =
            EMSCRIPTEN_FETCH_LOAD_TO_MEMORY | EMSCRIPTEN_FETCH_SYNCHRONOUS | EMSCRIPTEN_FETCH_REPLACE;
        emscripten_fetch_t *fetch = emscripten_fetch(&attr, url);

        if (fetch->status == 200)
        {
            be_pushnstring(vm, (const char *)fetch->data, fetch->numBytes);
        }
        else
        {
            be_raise(vm, "runtime_error", "http status not 200");
        }

        emscripten_fetch_close(fetch);
    }
    else
    {
        be_raise(vm, "runtime_error", "wrong parameters for 'httpget': expecting url string");
    }
    be_return(vm);
}

int main(void)
{
    bvm *vm = be_vm_new();
    be_regfunc(vm, "httpget", httpget_func);
    be_loadstring(vm, "print(httpget('https://httpbin.org/anything'))");
    int res = be_pcall(vm, 0);
    if (res == BE_EXCEPTION)
    {
        be_dumpexcept(vm);
    }
    be_vm_delete(vm);

    return 0;
}
