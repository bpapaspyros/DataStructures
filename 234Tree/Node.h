#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
	public:
		// Constructor + Destructor
		Node(int data, Node* p);
		~Node();

		// getters 
		int getChildren();

		// tree characteristics
		bool isLeaf();
		void insertChild(Node* child);

		// recursive function for counting nodes
		int recursiveNumOfNodes(Node* n);
		int recursiveNumOfLeaves(Node* n);

		// recursive function for returning leaf info
		int* recursiveIntArray(Node* n);

		// pointers to children
		std::vector<Node*> children;

		// node data 
		std::vector<int> _data;

		// pointer to parent
		Node* parent;
	private:
		// integer array with the leaf info
		int* intArray;

};

#endif