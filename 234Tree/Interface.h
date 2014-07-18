#ifndef INTERFACE_H
#define INTERFACE_H

#include "Tree.h"

class Interface {
	public:
		// constructor
		Interface();

		// main method with menus for the user
		void runTreeUI();

		// getters 
		Tree* getTree();
	private: 
		// calling tree methods with user input
		void addElement();			// calling the insert method
		void removeElement();		// calling the remove method
		void containsElement();		// calling the contains method
		void nodesNumber();			// calling the numberOfNodes method
		void intArray();			// calling the toIntArray method

		void sampleTree();			// creatting a sample tree for quick use

		// instance of our tree
		Tree* tree;
};

#endif