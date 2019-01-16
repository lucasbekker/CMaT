CC=nvcc
CFLAGS=-O3

test: test.cu
	$(CC) $? $(CFLAGS) -o $@