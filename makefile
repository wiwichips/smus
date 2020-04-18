CC=gcc
CFLAGS=-std=c11 -g -pedantic -Wall

#main: main.c output.c output.h
#	$(CC) $(CFLAGS) main.c output.c -lm output.h -o main	

libbarchart.so: output.c output.h
	$(CC) -fPIC -shared -o libbarchart.so output.c output.h 

clean:
	rm -rf *.o *.so main
