CC = g++
LIBS = -lglfw -lGL -lm -lX11 -lglut -lGLU
CFLAGS = -g -Wall -Wno-deprecated

main: main.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
test: 
	exec ./main
clean:
	-rm -f *.o main
