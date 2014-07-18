#include "Node.h"


/*- -------------------------------------------------------------- -*/
// initializing our node
Node::Node(int data, Node* p) {
	// data value for the node
	_data.push_back(data);

	// keeping a pointer to the parent
	parent = p;
}
/*- -------------------------------------------------------------- -*/
// deleting any remaining pointers to avoid memory leak
Node::~Node() {
	for(int i=0; i<getChildren(); i++) {
		delete children[i];
	}
}

/*- -------------------------------------------------------------- -*/
// counting nodes recursively
int Node::recursiveNumOfNodes(Node* n) {
	int size = 0;

	if (n->parent == 0) {
		size++;
	}

	if (n->children.size() == 0) {
		size--;
	}

	for(unsigned int i=0; i<n->children.size(); i++) {
		if ( n->children[i] != 0 ) {
			size++;
			size += recursiveNumOfNodes(n->children[i]);
		}
	}

	return size;
}

/*- -------------------------------------------------------------- -*/
// counting leaves recursively
int Node::recursiveNumOfLeaves(Node* n) {
	int size = 0;

	if (n->children.size() == 0) {
		size++;
	}

	for(unsigned int i=0; i<n->children.size(); i++) {
		if ( n->children[i] != 0 ) {
			size += recursiveNumOfLeaves(n->children[i]);
		} 
	}

	return size;
}

/*- -------------------------------------------------------------- -*/
// returning an int array with the leaf info
int* Node::recursiveIntArray(Node* n) {
	static int index = 0;

	if (n->parent == 0) {
		intArray = new int[recursiveNumOfLeaves(n)];
	}

	if (n->children.size() == 0) {
		intArray[index++] = n->_data[0];
	}

	for(unsigned int i=0; i<n->children.size(); i++) {
		if ( n->children[i] != 0 ) {
			intArray = recursiveIntArray(n->children[i]);
		} 
	}


	if (n->parent == 0) {
		index = 0;
	}

	return intArray;
}

/*- -------------------------------------------------------------- -*/
// returning the child count
int Node::getChildren() {
	return children.size();
}

/*- -------------------------------------------------------------- -*/
// answering whether the node is a leaf or not
bool Node::isLeaf() {
	if ( getChildren() == 0 ) {
		return true;
	} else {
		return false;
	}
}

/*- -------------------------------------------------------------- -*/
// pushing back children
void Node::insertChild(Node* child)
{
	children.push_back(child);
}

/*- -------------------------------------------------------------- -*/