CFLAGS = -O
CC = g++

Test: main.o user.o community.o
	$(CC) $(CFLAGS) -o Test main.o user.o community.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
user.o: user.cpp
	$(CC) $(CFLAGS) -c user.cpp
community.o: community.cpp
	$(CC) $(CFLAGS) -c community.cpp
clean:
	rm -f core *.o 