/*
  csgo_run.c - Custom imeplementation of csgo runner

  Copyright (C) 2023 kotleni
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
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <dlfcn.h>

#if defined(__APPLE__)
  #include <malloc/malloc.h>
  #define LAUNCHER_PATH "bin/osx64/launcher.dylib"
#elif defined(__linux__)
  #include <malloc.h>
  #define LAUNCHER_PATH "bin/linux64/launcher_client.so"
#endif

typedef struct {
  char* injectLib;
  int injectDelay;
} Arguments;

typedef struct {
  char* libpath;
  int delay;
} InjectConfig;

void* inject(InjectConfig* cfg) {
  sleep(cfg->delay);
  printf("Injecting %s\n", cfg->libpath);

  // load lib
  void* handle = dlopen(cfg->libpath, 10);

  if(!handle) {
    // fail to load the library
    printf("Injecting error: %s\n", dlerror());
    return NULL;
  }
  
  return NULL;
}

void parse_arguments(int argc, char *argv[], Arguments* arguments) {
  for(int i = 0; i < argc; i += 1) {
    if(strcmp(argv[i], "-inj") == 0) {
      arguments->injectLib = argv[i + 1];
    } else if(strcmp(argv[i], "-injdelay") == 0) {
      arguments->injectDelay = atoi(argv[i + 1]);
    }
  }
}

int main(int argc, char *argv[]) {
  Arguments* arguments = (Arguments*) malloc(sizeof(Arguments));
  arguments->injectLib = NULL; // -inj <lib>
  arguments->injectDelay = 0;  // -injdelay <secs>

  parse_arguments(argc, argv, arguments);

  long (*LauncherMain)(unsigned int, long);

  // load lib
  void* dl = dlopen(LAUNCHER_PATH, 2);
  if(!dl) {
    char* err = dlerror();
    printf("Failed to load the launcher (%s)\n", err);
    while(1);
  }

  // get launchermain function
  LauncherMain = (long (*)(unsigned int, long))dlsym(dl, "LauncherMain");
  if(!LauncherMain) {
    puts("Failed to load the launcher entry proc");
    while(1);
  }

  // -inj <lib>
  if(arguments->injectLib != NULL) {
    pthread_t tid;
    InjectConfig* inj_cfg = (InjectConfig*) malloc(sizeof(InjectConfig));
      inj_cfg->libpath = arguments->injectLib;
      inj_cfg->delay = arguments->injectDelay;
    pthread_create(&tid, NULL, &inject, inj_cfg);
    pthread_detach(tid);
  }
  
  // invoke launchermain
  return LauncherMain(argc, (long)argv);
}
