CC = g++
CFLAGS = -g -Wall -Wno-deprecated
LIBS =  -lglfw -lGL -lm -lX11 -lglut -lGLU -ldl 

all: main

main: glad.o main.o 
	$(CC) $(CFLAGS) glad.o main.o -o $@.run $(LIBS)
glad.o: glad.c
	$(CC) $(CFLAGS) -c $< 
main.o: main.cpp
	$(CC) $(CFLAGS) -c $< 
test: 
	exec ./main.run

clean:
	-rm -f *.o *.run
