Data Structures
===============

Description
-----------
Project for CEID course "Data Structures" of the 4th semester.  SortingAlgorithms - contains implementation of few sorting and searching algorithms. It also contains useful methods for parsing data from files and writing to them, as well as methods that time the execution of the implemented algorithms.  2-3-4 ab Tree - An 2-3-4 tree is implemented along with all the basic funtions such as insert, remove, contains, etc. Additionally there has been use of the graphvis api to produce a .png icon for the tree state.

SortingAndSearching: 
-------------------

To compile and run the program:

```
cd SortingAndSearching
mkdir build && cd build
cmake .. && make
cd ../bin
./sortNsearch
```

2-3-4 ab Tree:
--------------

* Additional packages: graphviz

```
sudo apt-get install graphvis-dev
```
* To compile and run the program:

```
cd 234Tree
mkdir build && cd build
cmake .. && make
cd ../bin
./tree
```