CC=g++
CFLAGS=-Wall -O3 -std=c++14
BINS=Experimentacion
all: clean Experimentacion

MSC_Exhaustivo:
	$(CC) $(CFLAGS) -o Experimentacion Experimentacion.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
