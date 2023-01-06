[![Makefile CI](https://github.com/kotleni-reverse/csgo-run/actions/workflows/makefile.yml/badge.svg)](https://github.com/kotleni-reverse/csgo-run/actions/workflows/makefile.yml)
## Custom implementation of CSGO runner
Support only osx-x64 and linux-x64<br>

### Features
* Fully open-source
* Library injection
* Zero dependencies

## Installing
Just replace runner file (csgo_linux64 or csgo_osx64) in CSGO root dir.
Allow installation of programs from third-party developers.

## Launch options
Injecting lib: `-inj <path> -injdelay <secs>` (see this <a href="https://youtu.be/NVNAeQIqQIo">video</a> for detail)

### How to build (osx)
`make osx` (or `arch -x86_64 make osx` for arm)

### How to build (linux)
`make linux`
