osx:
	gcc -pthread -o csgo_osx64 csgo_run.c
linux:
	gcc -ldl -pthread -o csgo_linux64 csgo_run.c