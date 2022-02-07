#To use this make file, navigate to the directory containing the makefile and type "make"
#		

all: main

test: main.c main.exe
	rm main.exe
	gcc -std=c11 -o main.exe main.c SimpletronOps.c
	./main.exe

init: main.c
	gcc -std=c11 -o main.exe main.c SimpletronOps.c
	./main.exe
	
main: main.c
	gcc -std=c11 -o main.exe main.c SimpletronOps.c

clean:
	rm main.exe
