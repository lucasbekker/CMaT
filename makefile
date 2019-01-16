CC=g++
CFLAGS=-O3 -march=native
INCLUDE=-I./Classes -I./Include

test: test.cpp
	$(CC) $(CFLAGS) $@.cpp $(INCLUDE) -o $@