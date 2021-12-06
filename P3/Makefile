CFLAGS = -Wall -g -O0
CC = gcc

all:	clean time 


time:	func.o monticulo.o time.o
	$(CC) $(CFLAGS) -o time p3.c func.o monticulo.o time.o -lm


time.o:	func.o monticulo.o
	$(CC) $(CFLAGS) -c time.c -lm

func.o:
	$(CC) $(CFLAGS) -c func.c -lm

monticulo.o:
	$(CC) $(CFLAGS) -c monticulo.c -lm

clean:
	rm -f *.o time

tar:
	tar czvf p3.tar.gz *.c *.h Makefile