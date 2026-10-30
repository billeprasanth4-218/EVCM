EV ChargeMate — C + WebAssembly version

Contents:
- ev.c: C calculation engine (the actual calculations are performed in C)
- index.html: mobile-friendly interface
- build.sh: compile command for Emscripten
- README.txt: setup and test instructions

Requirements:
- Emscripten SDK installed and activated
- A local web server or static HTTPS hosting

Build:
  emcc ev.c -O2 -sWASM=1 -sALLOW_MEMORY_GROWTH=1 --no-entry \
    -sEXPORTED_FUNCTIONS='["_calculate"]' \
    -sEXPORTED_RUNTIME_METHODS='["cwrap"]' \
    -o ev.js

The build generates ev.js and ev.wasm. Keep them beside index.html.

Run:
- Start a local HTTP server in this folder, for example:
    python -m http.server 8000
- Open http://localhost:8000 in the computer browser.
- To test on a phone on the same Wi-Fi, open http://COMPUTER-LAN-IP:8000
  (replace COMPUTER-LAN-IP with your computer's local IP).
- Or upload the files to a free static HTTPS host.

Expected test with defaults:
- Battery energy: 24.00 kWh
- Grid energy: 26.67 kWh
- Estimated cost: ₹213.33
- Estimated duration: about 3 h 42 min

Note:
- This is a software simulation; it does not connect to or control a real EV charger.
- If Emscripten is not installed, ev.js and ev.wasm will not exist until you run the build command.
