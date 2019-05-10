CC=g++
CFLAGS= -c -Wall 
LIBS=-lglfw -lGL -lm -lX11 -lglut -lGLU
all:mainico

mainico: main.o Bmp.o
		${CC} main.o Bmp.o -o main ${LIBS}

Bmp.o: Bmp.cpp
		${CC} ${CFLAGS} Bmp.cpp

main.o: main.cpp
		${CC} ${CFLAGS} main.cpp
test:
	exec ./main

clean:
	rm -rf *.o main

