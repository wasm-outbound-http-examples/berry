# Make HTTP requests from inside WASM in Berry-lang

This devcontainer is configured to provide you the latest stable version of Emscripten.

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/wasm-outbound-http-examples/berry)


<table>
<tr>
<th>#</th>
<th>Example</th>
<th>Description</th>
<th>Browser demo</th>
</tr>
<tr>
<td>1</td>
<td>

[EMSCRIPTEN_FETCH_SYNCHRONOUS](browser-sync-xhr/README.md)

</td>
<td>

Berry "native" function employing sync XHR

</td>
<td>

[Demo](https://wasm-outbound-http-examples.github.io/berry/sync-xhr/)

</td>
</tr>
<tr>
<td>2</td>
<td>

[EMSCRIPTEN_FETCH_SYNCHRONOUS with enabled ASYNCIFY](browser-sync-xhr-asyncify/README.md)

</td>
<td>

Berry "native" function employing sync XHR, built with ASYNCIFY support.
Resulting WASM file is 650k larger.

</td>
<td>

[Demo](https://wasm-outbound-http-examples.github.io/berry/sync-xhr-asyncify/)

</td>
</tr>
</table>

<sub>Created for (wannabe-awesome) [list](https://github.com/vasilev/HTTP-request-from-inside-WASM)</sub>
