/** 
 * @class Node
 *														    
 * @brief Node Class
 *
 * This class has methods tha let you manage the node (children, data) and give
 * you significant functions to calculate tree values and others that let you iterate
 * through the tree																	    
 *																				    
 * @author Vaios Papaspyros							            
 *																				    
 * Contact: b.papaspyros@gmail.com	or create an issue on the github page https://github.com/bpapaspyros/DataStructures	
 *																				   
 */

#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
	public:
		// Constructor + Destructor
		/**
		 * @param Takes an integer data which stands for the node key and a pointer to a Node class instance
		 */
		Node(int data, Node* p);
		~Node();

		// getters 
		/**
		 * @return the number of children for this node instance
		 */
		int getChildren();

		// tree characteristics

		/**
		 * @return Returns true if this node is in fact a leaf or false otherwise
		 */
		bool isLeaf();

		/**
		 * @param Takes a pointer to a node instance
		 */
		void insertChild(Node* child);

		// recursive function for counting nodes
		/**
		 * @param Takes a pointer to a node instance
		 * @return Returns the number of nodes in the tree (int)
		 */
		int recursiveNumOfNodes(Node* n);

		/**
		 * @param Takes a pointer to a node instance
		 * @return Returns the number of leaves in the tree (int)
		 */
		int recursiveNumOfLeaves(Node* n);

		// recursive function for returning leaf info
		/**
		 * @param Takes a pointer to a node instance
		 * @return Returns an array of integers with the leaf content
		 */
		int* recursiveIntArray(Node* n);

		/// Pointers to children
		std::vector<Node*> children;

		/// Node data 
		std::vector<int> _data;

		/// Pointer to parent
		Node* parent;
	private:
		// integer array with the leaf info
		int* intArray;

};

#endif