# 211344015 alonsuissa12@gmail.com

CXX=g++
CXXFLAGS=-std=c++14 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
OBJECTS=Graph.o Algorithms.o TestCounter.o Test.o

.PHONY: all clean run valgrind tidy

all: demo test

run: demo
	./demo

demo: Demo.o Algorithms.o Graph.o
	$(CXX) -std=c++14 -Werror -Wsign-conversion Demo.o Algorithms.o Graph.o -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) -std=c++14 -Werror -Wsign-conversion  $(OBJECTS) -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

Graph.o: Graph.cpp
	$(CXX) -std=c++14 -Werror -Wsign-conversion -c Graph.cpp -o Graph.o

Algorithms.o: Algorithms.cpp
	$(CXX) -std=c++14 -Werror -Wsign-conversion -c Algorithms.cpp -o Algorithms.o

TestCounter.o: TestCounter.cpp
	$(CXX) -std=c++14 -Werror -Wsign-conversion -c TestCounter.cpp -o TestCounter.o

Test.o: Test.cpp
	$(CXX) -std=c++14 -Werror -Wsign-conversion -c Test.cpp -o Test.o

Demo.o: Demo.cpp
	$(CXX) -std=c++14 -Werror -Wsign-conversion -c Demo.cpp -o Demo.o

clean:
	rm -f *.o demo test
