CC=g++

all: testcase test map_bench

test: test/test.o
	$(CC) test/test.o -o test/test

map_bench: test/map_benchmark.o
	$(CC) test/map_benchmark.o -o test/map_bench

testcase: test/test.cpp test/map_benchmark.cpp
	$(CC) -c test/test.cpp -o test/test.o
	$(CC) -c test/map_benchmark.cpp -o test/map_benchmark.o
