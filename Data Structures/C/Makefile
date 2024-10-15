CC=gcc

all : hello

hello: hello.c test.o
	$(CC) -o hello hello.CC

test.o: test.c 
	$(CC) -c test.c -o test.o

clean:
	rm hello.exe test.o	