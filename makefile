CC=g++
CFLAGS=-O3 -march=native

test: test.cpp
	$(CC) $? $(CFLAGS) -o $@