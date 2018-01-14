CC=gcc
CFLAGS=-Wall -I./src -o

-test: 			test-main/main.c src/doublylinkedlist.c
+test: 	test-main/main.c src/doublylinkedlist.c
       $(CC) $(CFLAGS) test test-main/main.c src/doublylinkedlist.c
clean:
-	rm -rf *.o
+	rm -rf *.o
