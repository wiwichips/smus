CC=gcc
CFLAGS=-std=c11 -g -pedantic -Wall

#main: main.c output.c output.h
#	$(CC) $(CFLAGS) main.c output.c -lm output.h -o main	

libbarchart.so: output.o driver.o
	$(CC) -shared -o libbarchart.so output.o driver.o -lm

output.o: output.c output.h
	$(CC) -fPIC -o output.o output.c -c

driver.o: driver.c driver.h
	$(CC) -fPIC -o driver.o driver.c -c

clean:
	rm -rf *.o *.so main
