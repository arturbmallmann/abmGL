CC = g++
LIBS = -lglfw -lGL -lm -lX11 -lglut -lGLU
CFLAGS = -g -Wall -Wno-deprecated

all: SimpleForms 
SimpleForms: SimpleForms.o
	$(CC) $(CFLAGS) $< -shared -o libSimpleForms.so $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -fPIC $<

clean:
	-rm -f *.o *.so
