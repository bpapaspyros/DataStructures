#include "Interface.h"
#include "GraphVis.h"
#include <iostream>

using namespace std;


/*- -------------------------------------------------------------- -*/
Interface::Interface() {
	tree = new Tree();	// initializing the tree
}

/*- -------------------------------------------------------------- -*/
void Interface::runTreeUI() {
	// user's choice from the menu
	char in;

	// menu with the basic functions of the tree
	do {
		GraphVis a;			// instance for the graphviz class 

		// printing a menu for the user
		cout << "\n\n";
		cout << "\t\t 1 - INSERT: Add an element                              " << endl;
		cout << "\t\t 2 - REMOVE: Remove an element                           " << endl;
		cout << "\t\t 3 - CONTAINS: Check if the tree contains an element     " << endl;
		cout << "\t\t *- ------------------------------------------------- -* " << endl;
		cout << "\t\t 4 - Number of nodes                                     " << endl;
		cout << "\t\t 5 - Get integer array                                   " << endl;
		cout << "\t\t *- ------------------------------------------------- -* " << endl;
		cout << "\t\t 6 - Sample tree                                         " << endl;
		cout << "\t\t *- ------------------------------------------------- -* " << endl;
		cout << "\t\t e - Exit                                                " << endl;

		// getting the users choice
		cout << "\t\t\n Choice: ";
		cin >> in;

		// calling the appropriate methods
		switch (in) {
			case '1':
				addElement();		// add a new element to the tree
				break;
			case '2':
				removeElement();	// remove an existing element from the tree
				break;
			case '3':
				containsElement();	// checks if an element exists 
				break;
			case '4':
				nodesNumber();		// counts the nodes of the tree recursively
				break;
			case '5':
				intArray();			// returns an array with the leaf info
				break;
			case '6':
				sampleTree();		// initializes the tree to a sample tree
				break;
			case 'e':
				break;				// exiting the loop
			default: 
				cout << "* Invalid input *" << endl;
		}


		// graphical representation
		if (tree -> root != 0 ) {
			a.loadTree(getTree());
			a.writeGraphToPNG( "tree.png");	// generating a png
		}

	} while(in != 'e');
}

/*- -------------------------------------------------------------- -*/
void Interface::addElement() {

	// checking whether the tree is initialized or not 
	// and then we execute the insert method
	if ( tree->root == 0 ) {

		// telling the user he has to initialize the tree
		cout << "The tree is not initialized. Add 2 values for the firs 2 leaves " << endl;

		// reading in the first value
		int leaf1 = 0;
		cout << "First Leaf: ";
		cin >> leaf1;

		int leaf2 = 0;
		do {
			cout << "Second Leaf: ";
			cin >> leaf2;
		}while(leaf1 == leaf2);


		// adding the leaves to the tree and updating the root
		Node* l1 = new Node(leaf1, tree->root);
		Node* l2 = new Node(leaf2, tree->root);

		tree->root = new Node((leaf1+leaf2)/2, 0);

		tree->root->insertChild(l1);
		tree->root->insertChild(l2);

		tree->initRootKeys();

	} else {
				// getting a value from the user
		int key;
		cout << "Give a value for the leaf: ";
		cin >> key;

		tree -> insert(key);	// attempting to insert the leaf to the tree
	}
}

/*- -------------------------------------------------------------- -*/
void Interface::removeElement() {
	if (tree->root != 0) {
			// getting a value from the user
		int key;
		cout << "\t Give a value for the leaf: ";
		cin >> key;

		tree -> remove(key);
	} else {
		cout << "\n\n\t ->x The tree is empty / not initialized" << endl;
	}
}

/*- -------------------------------------------------------------- -*/
void Interface::containsElement() {
	// getting input from the user
	int key; 
	cout << "\t Enter a value to search in the tree: ";
	cin >> key;

	// searching our tree by calling the appropriate function
	if ( tree->contains(key) ) {
		cout << "\n\n\t -> The value given exists in a leaf !" << endl;
	} else {
		cout << "\n\n\t -> The value given doen't exist in the tree" << endl;
	}
}

/*- -------------------------------------------------------------- -*/
void Interface::nodesNumber() {
	cout << "\n\n\t -> The tree currently holds: " << tree->numberOfNodes() << " nodes" << endl;
}

/*- -------------------------------------------------------------- -*/
void Interface::intArray() {
	// getting array size and the array itself
	int size = tree->numberOfLeaves();
	int* intArray = tree->toIntArray();


	// display options
	cout << "\t\t 1 - Print array to screen 			 " << endl;
	cout << "\t\t 2 - Write array to file (leafInfo.txt) " << endl;

	// user input
	char ch;
	cin >> ch;

	switch(ch) {
		case '1':
			// printing the array to screen
			for (int i=0; i<size; i++) {
				cout << "\t\t|\t  " << intArray[i] << endl;
			}
			break;

		case '2':
			// writing all info to a txt file
			tree->leafInfoToFile(intArray, size);
			break;
	}
}

/*- -------------------------------------------------------------- -*/
void Interface::sampleTree() {
	// creating a sample tree

	tree -> root = new Node(20, 0);

	tree -> root -> insertChild(new Node(10, tree->root));
	tree -> root -> insertChild(new Node(30, tree->root)); 

	tree->insert(5);
	tree->insert(13);
	tree->insert(35);
	tree->insert(45);
	tree->insert(65);
	tree->insert(22);
	tree->insert(18);
	tree->insert(25);
}

/*- -------------------------------------------------------------- -*/
Tree* Interface::getTree() {
	return tree;
}

/*- -------------------------------------------------------------- -*/
