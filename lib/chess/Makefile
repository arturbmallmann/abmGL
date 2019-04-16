CC = g++
LIBS = -lglfw -lGL -lm -lX11 -lglut -lGLU
CFLAGS = -g -Wall -Wno-deprecated

all: Position.o AbstractPiece.o
	$(CC) $(CFLAGS) $< -shared -o libabmgl.so $(LIBS)
#$@ $(LIBS)
# source that help me: https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html 
%.o: %.cpp
	$(CC) $(CFLAGS) -c -fPIC $<

clean:
	-rm -f *.o *.so
