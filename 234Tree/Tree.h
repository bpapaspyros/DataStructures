#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <iostream>
#include <fstream>
// #include <cstring>

class Tree {
	public:
		// Constructor + Destructor
		Tree();				// no root
		Tree(Node* node);	// initializing the root with a given node
		~Tree();			// avoiding memory leaks

		// Tree functionality
		bool empty();			// checks if tree is empty
		bool contains(int key);	// checks if tree contains "key"
		void insert(int key);	// inserting the value "key"
		void remove(int key);	// deleting the value "key"
		int numberOfNodes();	// returning the number of nodes
		int* toIntArray();		// returning an array with the tree values

		int numberOfLeaves();	// returning the number of leaves 

		// writes leaf info to file
		void leafInfoToFile(int* inArray, int size);

		// initialize the root keys
		void initRootKeys();

		// Tree root
		Node* root;
	private:
		// custom iterator for our tree
		Node* iterate(int key, Node* prev_node, int& child_index);	

		// simple bublesort method for sorting a small vector
		void sort(std::vector<Node*>& children);

		// refreshing a node data to make traversing easier
			// _data   -> keys in the node
			// ch_data -> children's data
		void updateKeys(std::vector<int>& _data, std::vector<Node*> ch);
};

#endif