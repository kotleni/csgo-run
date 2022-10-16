osx:
	gcc -pthread -o csgo_osx64 csgo_run.c
linux:
	gcc -pthread -o csgo_linux64 csgo_run.c -ldl