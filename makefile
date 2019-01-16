CC=g++
CFLAGS=-O3 -march=native
INCLUDE=-I.
files=test.cpp Classes/Backend_class.cpp Classes/Matrix_class.cpp Classes/Sparse_class.cpp Classes/User_class.cpp

test: $(files)
	$(CC) $? $(CFLAGS) $(INCLUDE) -o $@