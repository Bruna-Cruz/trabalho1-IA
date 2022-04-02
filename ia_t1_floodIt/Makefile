CC = gcc
CFLAGS = -Wall


all: floodIt

floodIt: main.o 
	$(CC) -o Floodit main.c lib/floodIt_functions.c


%.o: %.c 
	$(CC) $(CFLAGS) -c  $@ $<

clean:
	-rm -f *~ *\# \#* *.o Floodit

purge: clean
	-rm -f FloodIt
