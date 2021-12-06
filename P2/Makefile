CFLAGS = -Wall -g -O0
CC = gcc

all: clean test


test:	 func.o time.o tables.o
	$(CC) $(CFLAGS) -o test p2.c time.o func.o tables.o -lm

tables.o:
	$(CC) $(CFLAGS) -c tables.c -lm

time.o:
	$(CC) $(CFLAGS) -c time.c -lm

func.o:
	$(CC) $(CFLAGS) -c func.c -lm

clean:
	rm -f *.o test


tar:
	tar czvf p2.tar.gz *.c *.h Makefile