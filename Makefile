CC=g++
CFLAGS=-Wall -O3 -std=c++14
BINS=1 2 3 4
all: clean 1 2 3 4

1:
	$(CC) $(CFLAGS) -o 1 implementacion1.cpp
2:
	$(CC) $(CFLAGS) -o 2 implementacion2.cpp
3:
	$(CC) $(CFLAGS) -o 3 implementacion3.cpp
4:
	$(CC) $(CFLAGS) -o 4 implementacion4.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
