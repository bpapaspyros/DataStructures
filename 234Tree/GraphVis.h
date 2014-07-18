#ifndef GRAPHVIS_H
#define GRAPHVIS_H

#define WITH_CGRAPH // comment to use the graph lib only

#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>
#ifndef WITH_CGRAPH
#include <graphviz/graph.h>
#endif

#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>
#include <string>
#include "Tree.h"


class GraphVis
{
public:
	GraphVis();
	~GraphVis();

	Agnode_t* addNode(std::string name);
	void addEdge(Agnode_t* n1, Agnode_t* n2);
	void writeGraphToPNG(std::string filename);
	void loadTree(Tree* tree);
	void addChildren(Node* father, Agnode_t* gnode, int numChildren);

	static char* stringToChar(std::string input);


private:
	Agraph_t *g;
	GVC_t *gvc;

	static int count;

};

#endif
