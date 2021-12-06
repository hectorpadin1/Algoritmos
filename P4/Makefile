CFLAGS = -Wall -g -O0
CC = gcc

all:	clean time 


time:	grafos.o time.o
	$(CC) $(CFLAGS) -o p4 p4.c grafos.o time.o -lm


time.o:	grafos.o
	$(CC) $(CFLAGS) -c time.c -lm

grafos.o:
	$(CC) $(CFLAGS) -c grafos.c -lm


clean:
	rm -f *.o p4

tar:
	tar czvf p4.tar.gz *.c *.h Makefile