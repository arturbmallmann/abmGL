CC = g++
MYLIBS = ../lib
CFLAGS = -g -Wall -Wno-deprecated

INCLUDES = -I$(MYLIBS)
MYSHARED = -L$(MYLIBS)

LIBS = -lglfw -lGL -lm -lX11 -lglut -lGLU -lSimpleForms

main: main.o
	$(CC) $(MYSHARED) $(CFLAGS) $< -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(INCLUDES) $(CFLAGS) -c $<
test: 
	LD_LIBRARY_PATH=$(MYLIBS):$LD_LIBRARY_PATH exec ./main
clean:
	-rm -f *.o main
