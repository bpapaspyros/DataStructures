/** 
 * @class Tree
 *														    
 * @brief Tree Class
 *
 * This class contains methods that execute the fundamental tree functions such as 
 * add, remove, etc. There are also methods that calculate tree related values, such as 
 * the number of nodes or leaves. An additional method offers functionality for writing the 
 * tree data to a file.															    
 *																				    
 * @author Vaios Papaspyros							            
 *																				    
 * Contact: b.papaspyros@gmail.com or create an issue on the github page https://github.com/bpapaspyros/DataStructures	
 *																				   
 */

#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <iostream>
#include <fstream>

class Tree {
	public:
		// Constructor + Destructor
		Tree();		
		
		/**
		 * @brief Initializes the tree with another tree
		 * @param Takes a Node* 
		 */
		Tree(Node* node);

		~Tree();

		// Tree functionality
		/**
		 * brief Just checking if the tree is empty or not 
		 * @return Returns true if the tree is empty of nodes, otherwiese returns false
		 */
		bool empty();			

		/**
		 * @brief Simply checks if the given value is contained in the tree as a leaf
		 * @param Takes an integer that stands for the element we are looking for
		 * @return Returns tree if the given value exists in the tree
		 */
		bool contains(int key);	

		/**
		 * @brief Inserts the requested value to the tree as a leaf while keeping it balanced
		 * @param Integer value to be added to the tree as a leaf
		 */
		void insert(int key);	

		/**
		 * @brief Removes the requested leaf while keeping the tree balanced
		 * @param Integer value of a leaf to be removed
		 */
		void remove(int key);	

		/**
		 * @brief Counting the number of nodes that the tree holds with a recursive function
		 * @return Returns the number of nodes contained in the tree
		 */
		int numberOfNodes();	

		/**
		 * @brief An array containing all the info from the leaves
		 * @return Returns an integer array
		 */
		int* toIntArray();		

		/**
		 * @brief Counting the number of leaves that the tree holds with a recursive function
		 * @return Returns the number of leaves contained in the tree
		 */
		int numberOfLeaves();	

		// writes leaf info to file
		/**
		 * @brief Writes the leaf info to text file
		 */
		void leafInfoToFile(int* inArray, int size);

		// initialize the root keys
		/**
		 * @brief Initializes the root keys
		 */
		void initRootKeys();

		// Tree root
		Node* root;
	private:
		// custom iterator for our tree
		/**
		 * @brief Iterates depending on the given value and updates the referenced int
		 * with the index of the child the Node* pointer ended up
		 * @param An int, a Node* and a reference to an int
		 * @return A pointer to the node we wanted to reach
		 */
		Node* iterate(int key, Node* prev_node, int& child_index);	

		// simple bublesort method for sorting a small vector
		/**
		 * @brief sorts the children of the given node depending on their keys
		 * @param A Node* vector passed by reference
		 */
		void sort(std::vector<Node*>& children);

		// refreshing a node data to make traversing easier
			// _data   -> keys in the node
			// ch_data -> children's data
		/**
		 * @brief Updates the keys of a node depending on the values of its children
		 * @param Takes an int vector by reference and a Node* vector containing
		 * a node's children
		 */
		void updateKeys(std::vector<int>& _data, std::vector<Node*> ch);
};

#endif