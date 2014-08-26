#include "Tree.h"

/*- -------------------------------------------------------------- -*/
// initializing our tree 
Tree::Tree() {

}

/*- -------------------------------------------------------------- -*/
// initializing the tree with a non-Null root 
Tree::Tree(Node* node) {
	root = node;
}

/*- -------------------------------------------------------------- -*/
// deleting any remaining pointers to avoid memory leaks
Tree::~Tree() {
	delete root;
}

/*- -------------------------------------------------------------- -*/
// answering whether the tree is empty or not
bool Tree::empty() {
	if (root->getChildren()<2) {
		return true;
	} else {
		return false;
	}
}

/*- -------------------------------------------------------------- -*/
// answering whether the tree contains the given key or not
bool Tree::contains(int key) {
	Node* temp = root;	// temporary variable used as iterator for the tree

	// if the tree is empty then there is no need to search
	if ( empty() ) {
		return false;
	}

	// traversing the tree until we find the key or until we run out of nodes
	do {

		if ( !(temp-> getChildren()) ) {	// checking if the leaf has the requested value
			if ( key == temp->_data[0] ) {
				return true;
			} else {
				return false;
			}
		} else {
			int i;
			temp = iterate(key, temp, i);			
		} 

	} while (1);
}

/*- -------------------------------------------------------------- -*/
void Tree::insert(int key) {
	if ( !contains(key) ) {
		Node* next_node = root;
		Node* prev_node = root;
		int child_index;

		while ( next_node->getChildren() !=0 ) {
			prev_node = next_node;
			next_node = iterate(key, prev_node, child_index);
		}


		if ( prev_node->getChildren() < 4 ) {

			// creating a new leaf with the requested data
			Node* leaf = new Node(key, prev_node);	

			// inserting the child to the vector		
			prev_node->insertChild(leaf);

			// sorting the leaves
			sort(prev_node->children);

			// updating the parent keys 
			updateKeys(prev_node->_data, prev_node->children);

			Node* temp = next_node->parent;
			while(temp != 0) {
				sort(temp->children);
				updateKeys(temp->_data, temp->children);

				temp = temp->parent;
			}

			sort(root->children);
			updateKeys(root->_data, root->children);

			prev_node = prev_node->parent;
		
		} else {
			// creating a new leaf with the requested data
			Node* leaf = new Node(key, prev_node);	

			// inserting the child to the vector
			// * KNOWING WE ARE EXIDING THE CAPACITY OF THE TREE * //
			prev_node->insertChild(leaf);

			while (prev_node->getChildren() > 4) {
				// holding the middle key for the top node
				int topKey = prev_node->_data[1];

				// sorting the leaves
				sort(prev_node->children);

				/* Now that the leaves are sorted we can break the node to 2 nodes */
				Node* rightNode = new Node(-1, prev_node->parent);

				/*- ------------------------------------------------------------- -*/
					// copying the last 3 leaves to a new vector (RIGHT)
				for (int i=2; i<5; i++) {
					rightNode->children.push_back(prev_node->children[i]);
				}

					// popping the last 3 leaves from the old vector
				for (int i=0; i<3; i++) {
					prev_node->children.pop_back();
				}

				/*- ------------------------------------------------------------- -*/
					// updating the keys for those new nodes
				updateKeys(prev_node->_data, prev_node->children);
				updateKeys(rightNode->_data, rightNode->children); 

				/*- ------------------------------------------------------------- -*/
					// assigning new parents
				if (prev_node->parent == 0) {
					Node* splitNode = new Node(topKey, prev_node->parent);

						// Adding the left and right node to the top one
					splitNode->insertChild(prev_node);
					splitNode->insertChild(rightNode);

						// this is the new root
					root = splitNode;

						// assigning new parents
					prev_node->parent = splitNode;
					rightNode->parent = splitNode;

						// updating keys
					updateKeys(splitNode->_data, splitNode->children);
					sort(splitNode->children);
				} else {

						// breaking the nodes and pushing back to the existing
					Node* p = prev_node->parent;
					
					p->_data.push_back(topKey);
					p->insertChild(rightNode);
				}

				// keeping the tree balanced
				// correcting keys and sorting the nodes
				Node* temp = prev_node->parent;
				do{
					sort(temp->children);
					updateKeys(temp->_data, temp->children);

					temp = temp->parent;
				}while (temp != 0);

				sort(root->children);
				updateKeys(root->_data, root->children);

				prev_node = prev_node->parent;
			}// while
		} // else

	}
}

/*- -------------------------------------------------------------- -*/
void Tree::remove(int key) {
	if ( contains(key) ) {
		Node* next_node = root;
		Node* prev_node = root;
		int child_index;

		while ( next_node->getChildren() !=0 ) {
			prev_node = next_node;
			next_node = iterate(key, prev_node, child_index);
		}


		// removing the requested leaf in any case
		prev_node->children.erase(prev_node->children.begin()+child_index);
		updateKeys(prev_node->_data, prev_node->children);
		
		if (prev_node->getChildren()<2) {
			int getVal = prev_node->children[0]->_data[0];

			prev_node->children.pop_back();

			Node* p = prev_node->parent;
			while(p->getChildren() == 1) {
				prev_node = p;

				prev_node->children.clear();
				prev_node->_data.clear();

				p = p->parent;
			}

			int index = 0;

			while(prev_node != p->children[index]) {
				index++;
			}

			p->children.erase(p->children.begin()+index);

			insert(getVal);
		}

	}
}

/*- -------------------------------------------------------------- -*/
int Tree::numberOfNodes() {
	return root->recursiveNumOfNodes(root);
}

/*- -------------------------------------------------------------- -*/
int Tree::numberOfLeaves() {
	return root->recursiveNumOfLeaves(root);
}

/*- -------------------------------------------------------------- -*/
int* Tree::toIntArray() {
	return root->recursiveIntArray(root);
}

/*- -------------------------------------------------------------- -*/

// method used to iterate through the tree given a value
Node* Tree::iterate(int key, Node* prev_node, int& child_index) {
	// defining the direction of the search
	if ( prev_node->getChildren() == 2 ) {			// - 2 children - 
			

		if (key <= prev_node->_data[0]) {
			prev_node = prev_node->children[0];		// going left
			child_index = 0;
		} else {
			prev_node = prev_node->children[1];		// going right
			child_index = 1;
		} 
			
		
	} else if ( prev_node->getChildren() == 3) {	// - 3 children -
		

		if (key <= prev_node->_data[0]) {
			prev_node = prev_node->children[0];		// going left
			child_index = 0;
		} else if (key <= prev_node->_data[1]) {
			prev_node = prev_node->children[1]; 	// going c-left
			child_index = 1;
		} else {
			prev_node = prev_node->children[2];		// going right
			child_index = 2;
		}


	} else if ( prev_node->getChildren() == 4) {	// - 4 children -
		

		if (key <= prev_node->_data[0]) {
			prev_node = prev_node->children[0];		// going left
			child_index = 0;
		} else if (key <= prev_node->_data[1]) {
			prev_node = prev_node->children[1]; 	// going c-left
			child_index = 1;
		} else if (key <= prev_node->_data[2]) {
			prev_node = prev_node->children[2];		// going c-right
			child_index = 2;
		} else {
			prev_node = prev_node->children[3];		// going right
			child_index = 3;
		} 


	}

	return prev_node;
}

/*- -------------------------------------------------------------- -*/
// simple bublesort method for sorting small vectors
void Tree::sort(std::vector<Node*>& children) {

	int l = children.size();	// getting the length of the vector

	while (l>1) {
		int j = 0;
		for (int i=0; i<l-1; i++) {
			int in1 = children[i]->_data.size()-1;
			int in2 = children[i+1]->_data.size()-1;

			if (children[i]->_data[in1] > children[i+1]->_data[in2]) {
				// swapping the elements
				Node* temp    = children[i];
				children[i]   = children[i+1];
				children[i+1] = temp;

				j++;
			}
		}

		if (j == 0) {
			break;
		}

		l--;
	}
}

/*- -------------------------------------------------------------- -*/
void Tree::updateKeys(std::vector<int>& _data, std::vector<Node*> ch) {
	int l = ch.size();		// getting vector size (number of children)

	_data.clear();			// clearing all the keys

	// updating keys and adding data depending on the children count
	switch (l) {
		case 2:
			_data.push_back( (ch[0]->_data[ch[1]->_data.size()-1] + ch[1]->_data[0])/2 );
			break;
		case 3:
			_data.push_back( (ch[0]->_data[ch[0]->_data.size()-1] + ch[1]->_data[0])/2 );
			_data.push_back( (ch[1]->_data[ch[1]->_data.size()-1] + ch[2]->_data[0])/2 );
			break;
		case 4:
			_data.push_back( (ch[0]->_data[ch[0]->_data.size()-1] + ch[1]->_data[0])/2 );
			_data.push_back( (ch[1]->_data[ch[1]->_data.size()-1] + ch[2]->_data[0])/2 );
			_data.push_back( (ch[2]->_data[ch[2]->_data.size()-1] + ch[3]->_data[0])/2 );
			break;	
	}
}

/*- -------------------------------------------------------------- -*/
void Tree::initRootKeys() {
	sort(root->children);
	updateKeys(root->_data, root->children);
}

/*- -------------------------------------------------------------- -*/
void Tree::leafInfoToFile(int* inArray, int size) {
	std::string str = "leafInfo.txt";		// output file name
	std::ofstream  dataFile(str.c_str());	// file stream

	// writing the array elements to file
	for (int i=0; i<size; i++) {
		dataFile << inArray[i] << "\n";	
	}

	dataFile.close();	// closing the file

}

/*- -------------------------------------------------------------- -*/