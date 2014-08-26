#include "GraphVis.h"

int GraphVis::count = 0;

GraphVis::GraphVis()
{
	count = 0;

	/* Set up a graphviz context */
	gvc = gvContext();

	/* Create a simple digraph */
	#ifdef WITH_CGRAPH
	Agdesc_t tmp = {0,0,0,0,0,0,0,0};
	g = agopen((char *)"g", tmp, 0);
	#else
	g = agopen((char *)"g", 0);
	#endif
}


GraphVis::~GraphVis()
{
	/* Free layout data */
	gvFreeLayout(gvc, g);

	/* Free graph structures and close open files */
	agclose(g);

	gvFreeContext(gvc);
}


Agnode_t * GraphVis::addNode(std::string name)
{
	char* cname = NULL;
	cname = stringToChar(name);
	#ifdef WITH_CGRAPH
	Agnode_t * node = agnode(g, cname, 1);
	#else
	Agnode_t * node = agnode(g, cname);
	#endif
	delete[] cname;

	// // Set an attribute - in this case one that affects the visible rendering 
	// agsafeset(n, (char *)"color", (char *)"red", (char *)"");

	return node;
}


void GraphVis::addEdge(Agnode_t* n1, Agnode_t* n2)
{
	#ifdef WITH_CGRAPH
	/*Agedge_t *e = */agedge(g, n1, n2, (char *)"", 1);
	#else
	/*Agedge_t *e = */agedge(g, n1, n2);
	#endif
}


void GraphVis::writeGraphToPNG(std::string filename)
{
	FILE* fp;

	/* Compute a layout using layout engine from command line args */
	gvLayout(gvc, g, "dot");

	/* Open file to write image */
	fp = fopen(filename.c_str(), "w");

	/* Write the graph according to -T and -o options */
	gvRender(gvc, g, "png", fp);


	fclose(fp);
}


void GraphVis::loadTree(Tree* tree)
{
	std::string str = " ";

	for (unsigned int i=0; i<tree->root->_data.size(); i++) {
		std::string strSpace = " ";
		std::string strDat = std::to_string(tree->root->_data[i]);

		str += strDat + strSpace;
	}

	Agnode_t * gnode = addNode(str);
	addChildren(tree->root, gnode, tree->root->getChildren());
}


void GraphVis::addChildren(Node* father, Agnode_t* gnode, int numChildren)
{
	Agnode_t* gchild;
	Node* child;

	for(int i=0; i<numChildren; i++)
	{
		child = father->children[i];
		if(child != NULL)
		{

			std::string str = " ";

			if (child->getChildren() == 0) {
				std::string star = " L: ";
				str += star;
			}

			for (unsigned int i=0; i<child->_data.size(); i++) {
				std::string strSpace = " ";
				std::string strDat = std::to_string(child->_data[i]);

				str += strDat + strSpace;
			}

			std::string cnt = " (" + std::to_string(count++) + ")";

			str += cnt;


			gchild = addNode(str);
			addEdge(gnode, gchild);
			addChildren(child, gchild, child->getChildren());
		}
	}

}


char* GraphVis::stringToChar(std::string input)
{
	char* output = new char[input.size()+1];
	std::copy(input.begin(), input.end(), output);
	output[input.size()] = '\0';

	return output;
}


