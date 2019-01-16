CC=g++
CFLAGS=-O3 -march=native
INCLUDE=-I./Classes -I./Include

test: test.cpp Classes/Backend_class.cpp Classes/Matrix_class.cpp Classes/Sparse_class.cpp Classes/User_class.cpp
	$(CC) $(CFLAGS) $@.cpp $(INCLUDE) -o $@