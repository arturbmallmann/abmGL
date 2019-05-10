CC = g++
LIBS = -lglfw -lGL -lm -lX11 -lglut -lGLU
CFLAGS = -g -Wall -Wno-deprecated

#all: Position.o AbstractPiece.o SimpleForms.o
#	$(CC) $(CFLAGS) $< -shared -o libabmgl.so $(LIBS)
	
all: Torre SimpleForms Position AbstractPiece

Torre: Torre.o AbstractPiece.o
	$(CC) $(CFLAGS) $< -shared -o libTorre.so $(LIBS)


#AbstractPiece: AbstractPiece.o 
#	$(CC) $(CFLAGS) $< -shared -o lib$@.so $(LIBS)

#Position: Position.o 
#	$(CC) $(CFLAGS) $< -shared -o libPosition.so $(LIBS)

#SimpleForms: SimpleForms.o
#	$(CC) $(CFLAGS) $< -shared -o libSimpleForms.so $(LIBS)

%: %.o
	$(CC) $(CFLAGS) $< -shared -o lib$@.so $(LIBS)


#$@ $(LIBS)
# source that help me: https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html 
%.o: %.cpp
	$(CC) $(CFLAGS) -c -fPIC $<

clean:
	-rm -f *.o *.so
