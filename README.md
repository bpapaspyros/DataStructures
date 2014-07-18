* SortingAndSearching: 

To compile and run the program:

```
cd SortingAndSearching
make
./sortNsearch
```

* 2-3-4 ab Tree:

Additional packages: graphvis

```
sudo apt-get install graphvis-dev
```

For Ubuntu 14.04:

```
cd 234Tree
make
./tree
```

For Ubuntu >=12.04:

> You need to alter the makefile and GraphVis.h

> * In the makefile: replace the **-lcgraph** with **-lgraph**
> * In GraphVis.h: comment the line " **#define WITH_CGRAPH** " to use the graph.h instead of the cgraph.h

Then:

```
cd 234Tree
make
./tree
```

* Use ```make clean``` to clear out any output files