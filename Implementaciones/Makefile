CC=g++
CFLAGS=-Wall -O3 -std=c++14
BINS=MSC_Exhaustivo MSC_Optimizado MSC_Greedy MSC_GreedyOp
all: clean MSC_Exhaustivo MSC_Optimizado MSC_Greedy MSC_GreedyOp

MSC_Exhaustivo:
	$(CC) $(CFLAGS) -o MSC_Exhaustivo implementacion1.cpp
MSC_Optimizado:
	$(CC) $(CFLAGS) -o MSC_Optimizado implementacion2.cpp
MSC_Greedy:
	$(CC) $(CFLAGS) -o MSC_Greedy implementacion3.cpp
MSC_GreedyOp:
	$(CC) $(CFLAGS) -o MSC_GreedyOp implementacion4.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
