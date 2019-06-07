CC=g++
CFLAGS= -c -Wall 
LIBS=-lglfw -lGL -lm -lX11 -lglut -lGLU
all:mainico

mainico: main.o Point.o 
		${CC} main.o Point.o -o mainico ${LIBS}

Point.o: Point.cpp
		${CC} ${CFLAGS} Point.cpp

main.o: main.cpp
		${CC} ${CFLAGS} main.cpp
test:
	exec ./mainico

clean:
	rm -rf *.o mainico
