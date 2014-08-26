#include "Node.h"


/*- -------------------------------------------------------------- -*/
// initializing our node
/**
 * @brief The constructor adds the data given as parameter
 * to the data vector and sets the current node's parent
 */
Node::Node(int data, Node* p) {
	// data value for the node
	_data.push_back(data);

	// keeping a pointer to the parent
	parent = p;
}

/*- -------------------------------------------------------------- -*/
// deleting any remaining pointers to avoid memory leak
/**
 * @brief The destructor deletes all members of the children vector
 * when the instance goes out of scope
 */
Node::~Node() {
	for(int i=0; i<getChildren(); i++) {
		delete children[i];
	}
}

/*- -------------------------------------------------------------- -*/
// counting nodes recursively
/**
 * @brief Counts the number of nodes recursively
 */
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
/**
 * @brief Counts the number of leaves recursively
 */
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
/**
 * @brief Creates an array of integers with the info located in the leaves. 
 * The array should be sorted if the tree is balanced correctly
 */
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
/**
 * @brief Returns the number of children for this node instance
 */
int Node::getChildren() {
	return children.size();
}

/*- -------------------------------------------------------------- -*/
// answering whether the node is a leaf or not
/**
 * @brief Depending on whether the current node is a leaf or not
 * it returns a boolean value
 */
bool Node::isLeaf() {
	if ( getChildren() == 0 ) {
		return true;
	} else {
		return false;
	}
}

/*- -------------------------------------------------------------- -*/
// pushing back children
/**
 * @brief Pushes a node to the children vector
 */
void Node::insertChild(Node* child)
{
	children.push_back(child);
}

/*- -------------------------------------------------------------- -*/