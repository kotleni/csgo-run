/*
  csgo_osx64.c - runner for csgo

  Copyright (C) 2022 kotleni
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
*/

#include <stdio.h>
#include <dlfcn.h>

#if defined(__APPLE__)
  #define LAUNCHER_PATH "bin/osx64/launcher.dylib"
#elif defined(__linux__)
  #define LAUNCHER_PATH "bin/linux64/launcher_client.so"
#endif

#ifndef true
  #define true 1
#endif
#ifndef false
  #define false 0
#endif

int main(int argc, char *argv[]) {
  return 0;
  long (*LauncherMain)(unsigned int, long);

  // load lib
  void* dl = dlopen(LAUNCHER_PATH, 2);
  if(!dl) {
    char* err = dlerror();
    printf("Failed to load the launcher (%s)\n", err);
    while(true);
  }

  // get launchermain function
  LauncherMain = (long (*)(unsigned int, long))dlsym(dl, "LauncherMain");
  if(!LauncherMain) {
    puts("Failed to load the launcher entry proc");
    while(true);
  }

  // invoke launchermain
  return LauncherMain(argc, (long)argv);
}