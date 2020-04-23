CFLAGS = -O
CC = g++

Test: main.o user.o
	$(CC) $(CFLAGS) -o Test main.o user.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
user.o: user.cpp
	$(CC) $(CFLAGS) -c user.cpp
clean:
	rm -f core *.o 