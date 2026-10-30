#!/bin/sh
set -eu
emcc ev.c -O2 -sWASM=1 -sALLOW_MEMORY_GROWTH=1 --no-entry \
  -sEXPORTED_FUNCTIONS='["_calculate"]' \
  -sEXPORTED_RUNTIME_METHODS='["cwrap"]' \
  -o ev.js
echo "Build complete. Serve index.html, ev.js and ev.wasm from the same folder."
