# Install dependecies
brew install sdl2 sdl2_image sdl2_ttf sdl2_mixer lua

# Troubleshooting

## -lSDL2_mixer called error (libgme error)
handy remove
brew uninstall --ignore-dependencies game-music-emu
and handy install
https://github.com/libgme/game-music-emu/tree/master

otherwise got error
./gameengine
dyld: Library not loaded: @rpath/libclang_rt.ubsan_osx_dynamic.dylib
  Referenced from: /usr/local/opt/game-music-emu/lib/libgme.0.dylib
  Reason: image not found
make: *** [run] Abort trap: 6
