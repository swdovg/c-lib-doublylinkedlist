CC=gcc
CFLAGS=-Wall -I./src -o

test: 			test-main/main.c src/doublylinkedlist.c
	$(CC) $(CFLAGS) test test-main/main.c src/doublylinkedlist.c
#
#doublylinkedlist.o: 	src/doublylinkedlist.c src/doublylinkedlist.h
#	$(CC) $(CFLAGS) doublylinkedlist.o src/doublylinkedlist.c
#
#main.o: 		test-main/main.c
#	$(CC) $(CFLAGS) main.o test-main/main.c
#
clean:
	rm -rf *.o 
#
