cd third_party/pixman-0.40.0
CC=emcc AR=emar LD=emcc RANLIB=emranlib PNG_LIBS="-L." ./configure --host=wasm32-unknown-emscripten --disable-gtk --enable-libpng --disable-shared --disable-openmp
export EMCC_CFLAGS="-s USE_PTHREADS=1 -s USE_LIBPNG=1 -s USE_ZLIB=1"
emmake make
cd ../..

cd third_party/cairo-1.16.0
CC=emcc CXX=em++ AR=emar LD=emcc RANLIB=emranlib png_LIBS="-L." FREETYPE_LIBS="-L." pixman_LIBS="-L$PWD/../pixman-0.40.0/pixman/.libs -lpixman-1" ax_cv_c_float_words_bigendian=no ./configure --host=wasm32 --disable-shared --disable-xlib --disable-xcb --disable-qt --disable-quartz --disable-win32 --disable-os2 --disable-beos --disable-drm --disable-gallium --disable-cogl --disable-directfb --disable-vg --disable-script --disable-fc --disable-ps --disable-pdf --disable-svg --disable-tee --disable-xml --disable-gobject --disable-full-testing --disable-interpreter --disable-symbol-lookup
export EMCC_CFLAGS="-s USE_PTHREADS=1 -s USE_LIBPNG=1 -s USE_ZLIB=1 -s USE_FREETYPE=1"
emmake make
cd ../..