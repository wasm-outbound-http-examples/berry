# Use EMSCRIPTEN_FETCH_SYNCHRONOUS in Berry custom function to send HTTP(s) requests from inside WASM

## Instructions for this devcontainer

Tested with berry_web [commit 9ebc4e2d](https://github.com/berry-lang/berry_web/tree/9ebc4e2d0945e6ea5e58daba4bc747a44df5a02c),
Berry [commit fa5d4330](https://github.com/berry-lang/berry/tree/fa5d4330a517222934322fff8da3f8401009d550),
Emscripten [v3.1.68](https://github.com/emscripten-core/emscripten/tree/3.1.68).

### Preparation

1. Open this repo in devcontainer, e.g. using Github Codespaces.
   Type or copy/paste following commands to devcontainer's terminal.

### Building

1. `cd` into the folder of this example:

```sh
cd browser-sync-xhr
```

2. Clone the `berry_web` repo. It contains Berry's port to Emscripten platform and has main Berry-lang repo as submodule:

```sh
git clone --depth=1 --recurse-submodules https://github.com/berry-lang/berry_web.git
```

3. Copy example's source into the folder `berry_web/platform`:

```sh
cp main.c berry_web/platform/berry.c
```

4. `cd` into the folder of `berry_web`:

```sh
cd berry_web
```

5. Apply the patch:

   * Patch Makefile to produce WASM output, enable outbound HTTP requests, and disable Asyncify (to save 650k of wasm file size)
   * Patch platform/be_port.c to get rid of Asyncify call

```sh
dos2unix Makefile platform/be_port.c
git apply ../no-asyncify.patch
```

6. Compile the example using Emscripten:

```sh
make
```

This command will output `docs/berry.js` and `docs/berry.wasm`.

7. `cd` back into the folder of this example:

```sh
cd ..
```

8. Copy WASM and glue JS into current folder:

```sh
cp berry_web/docs/berry.{js,wasm} ./
```

### Test with browser

1. Run simple HTTP server to temporarily publish project to Web:

```sh
python3 -m http.server
```

Codespace will show you "Open in Browser" button. Just click that button or
obtain web address from "Forwarded Ports" tab.

2. As `index.html`, JS files, and a 270k-sized `berry.wasm` are loaded into browser, refer to browser developer console
   to see the results.


### Finish

Perform your own experiments if desired.
