/** 
 * @class GraphVis
 *														    
 * @brief GraphVis Class
 *
 * This class uses the graphviz package to create a .png image of the current tree.
 * It includes methods used to load the appropriate data to the graphviz package.															    
 *																				    
 * @author Vaios Papaspyros							            
 *																				    
 * Contact: b.papaspyros@gmail.com or create an issue on the github page https://github.com/bpapaspyros/DataStructures	
 *																				   
 */

#ifndef GRAPHVIS_H
#define GRAPHVIS_H

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
		/**
		 * @brief Initializes the necessary values following the graphviz api
		 */
		GraphVis();
		~GraphVis();

		/**
		 * @brief Adds a node
		 * @param String containing the node's name
		 * @return Agnode_t* ready for use by graphviz
		 */
		Agnode_t* addNode(std::string name);

		/**
		 * @brief Adds an edge
		 * @param 2 Agnode_t* that will be connected with an edge
		 */
		void addEdge(Agnode_t* n1, Agnode_t* n2);

		/**
		 * @brief Transfers the tree to a png image
		 * @param Output image filename
		 */
		void writeGraphToPNG(std::string filename);

		/**
		 * @brief Used to load a tree's nodes and call the appropriate function to output the png
		 * @param A pointer to a Tree class instance
		 */
		void loadTree(Tree* tree);

		/**
		 * @brief Add nodes and edges to connect a parent node to its children
		 * @param Pointers to the parent (father) node, the child node and an integer
		 * representing the number of children
		 */
		void addChildren(Node* father, Agnode_t* gnode, int numChildren);

		/**
		 * @brief Converts a string variable to a char* for graphviz compatibility reasons
		 * @param A string variable
		 */
		static char* stringToChar(std::string input);


	private:
		Agraph_t *g;
		GVC_t *gvc;

		// used to put a unique number to every node
		static int count;
};

#endif
