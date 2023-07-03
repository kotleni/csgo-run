## MacOS
1. Unlock software from unidentified developers (Settings -> Search "FileVault" -> Select "Anywhere" in "Allow applications downloaded from")
2. Open terminal (Launchpad -> Search "Terminal" -> Click)
3. Execute this commands in terminal one by one
```bash
xcode-select --install
git clone https://github.com/kotleni/csgo-run
cd csgo-run
```
4. Start building
for apple cpu:
```arch -x86_64 make osx```
<br>for intel cpu:
```arch -x86_64 make osx```
5. Done

## Linux (Ubuntu)
1. Open terminal
2. Execute this commands in terminal one by one
```apt install gcc make
git clone https://github.com/kotleni/csgo-run
cd csgo-run
```
3. Start building ```make linux```
4. Done

## Linux (Arch)
1. Open terminal
2. Execute this commands in terminal one by one
```pacman -Sy gcc make glibc
git clone https://github.com/kotleni/csgo-run
cd csgo-run
```
3. Start building ```make linux```
4. Done