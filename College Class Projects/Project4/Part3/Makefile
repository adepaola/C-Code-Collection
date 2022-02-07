all:  main

main: main.o bitmap.o
	gcc -std=c11 main.o bitmap.o -o main.exe

bitmap.o: bitmap.h bitmap.c
	gcc -std=c11 -c bitmap.c bitmap.h

main.o: bitmap.h main.c
	gcc -std=c11 -c main.c bitmap.h

clean:
	rm *.o *.exe
