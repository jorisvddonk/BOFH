# BOFH - Emscripten Edition

This is a version of BOFH that's compilable for the web using Emscripten.
Very few modifications have been made to allow this, however, the emterpreter is (unbfortunately) being used, so things are a bit slow...

# COMPILING

The easiest way to compile is using a Docker image containing the Emscripten SDK:

`docker run -it -v $(pwd):/src trzeci/emscripten:sdk-tag-1.38.3-64bit make`

# LICENSE

The author confirmed that the game content & code are licensed under
the 3-clause BSD license. My modifications are in the same license.

Original webpage: http://covertbitops.c64.org/
