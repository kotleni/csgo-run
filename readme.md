[![Makefile CI](https://github.com/kotleni-reverse/csgo-run/actions/workflows/makefile.yml/badge.svg)](https://github.com/kotleni-reverse/csgo-run/actions/workflows/makefile.yml)

<b>Attention! This project was developed for educational purposes. Don't use it to inject cheats online.<br>I take no responsibility for possible VAC bans.</b>

## Custom implementation of CSGO runner
Support only osx-x64, osx-arm64 (via rosetta2) and linux-x64<br>

### Features
* Fully open-source
* Library injection
* Zero dependencies

### Tested on
| OS | Works? | Description |
| ------------- | ------------- | ----------- |
| MacOS Ventura 13.2 for M1 (2020)  | Yes | Works great. Recommended delay for injections - 70 secs |
| Linux | Unknown | Not tested, but compiles. Should work. |
| Windows | No | Not works. Uses a different starting algorithm. See <a href="https://github.com/kotleni/csgo-run/issues/3">#3</a> |

### Docs
<a href="https://github.com/kotleni/csgo-run/blob/master/docs/build.md">Building</a><br>
<a href="https://github.com/kotleni/csgo-run/blob/master/docs/installing.md">Installing</a><br>
<a href="https://github.com/kotleni/csgo-run/blob/master/docs/injecting.md">Injecting shared libraries</a><br>
<a href="https://github.com/kotleni/csgo-run/blob/master/docs/args.md">Launch options</a><br>
<a href="https://github.com/kotleni/csgo-run/blob/master/docs/troubleshooting.md">Troubleshooting</a><br>