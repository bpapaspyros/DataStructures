CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++0x
DEBUG=-g


all:	main.o	Sort_N_Search.o
	$(CXX) $^ -o sortNsearch 

test:	test.o
	$(CXX) $< -o $@ 

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY:	clean

clean:
	rm -f sortNsearch *.o out.txt