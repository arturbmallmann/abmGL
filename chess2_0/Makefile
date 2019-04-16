CC = g++
MYLIBS = ../lib/chess
CFLAGS = -g -Wall -Wno-deprecated

INCLUDES = -I$(MYLIBS)
MYSHARED = -L$(MYLIBS)
LIBS = -lglfw -lGL -lm -lX11 -lglut -lGLU -labmgl

main: main.o
	$(CC) $(MYSHARED) $(INCLUDES) $(CFLAGS) $< -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
test: 
	LD_LIBRARY_PATH=$(MYLIBS):$LD_LIBRARY_PATH exec ./main
clean:
	-rm -f *.o main
