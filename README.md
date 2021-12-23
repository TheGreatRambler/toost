# Toost

Level viewer for Super Mario Maker 2, based on  JiXiaomai's work

# How to build
If building for desktop, obtain development files for `sdl2`, `glew`, `glfw3`, `zlib`, `cairo`, `freetype2`, and `libcurl`, as well as having an up to date GCC and pkg-config. Compilation on Windows should use MSYS2, on Mac should use homebrew and on linux should use standard GCC. Type `make` for a debug build and `make BUILD=release` for a release build.
If building for web, first obtain a working Emscripten build environment and put its binaries on the path, such as `emmake`, `emcc` and `em++`. Next, run `./prepare_web_deps.sh`. This only needs to be done once, as it downloads and compiles Cairo to prepare it for the web environment. Once that is done, you can run `make PLATFORM=web` for a debug build and `make PLATFORM=web BUILD=release` for a release build. To prepare a zip to distribute, run `./build_release.sh` for desktop and `./build_release.sh web` for web.

# Hosting the web build
As long as all files in `bin` are in the same directory on your webserver and you are hosting them over https, you can access index.html to see the viewer.

# Credits
* Ji Xiaomai, as the core level renderer is based on his work
* The Spriters Resource for the sprites