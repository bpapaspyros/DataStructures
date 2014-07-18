CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++0x
INCLUDES=-I. -I/usr/include/graphviz/
LIBS=-lgvc -lcgraph -lcdt -lpthread
DEBUG=-g


all:	main.o	GraphVis.o	Interface.o Tree.o	Node.o
	$(CXX) $^ -o tree $(LIBS)

test:	test.o
	$(CXX) $< -o $@ $(LIBS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $< -o $@

.PHONY:	clean

clean:
	rm -f tree test main *png *.o