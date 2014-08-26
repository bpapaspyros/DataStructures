/** 
 * @class Interface
 *														    
 * @brief Interface Class
 *
 * This class is basicaly a CLI implementation so that the user can easily manage
 * the tree and/or add/remove nodes. The user can also request values concerning 
 * the tree's current state. The class offers a sample tree option for quick testing																    
 *																				    
 * @author Vaios Papaspyros							            
 *																				    
 * Contact: b.papaspyros@gmail.com	or create an issue on the github page https://github.com/bpapaspyros/DataStructures	
 *																				   
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include "Tree.h"

class Interface {
	public:
		// constructor
		/**
		 * @brief Instanciates a Tree object for use later on
		 */
		Interface();

		// main method with menus for the user
		/**
		 * @brief Prints a basic menu to the user with all the available function
		 * that can be invoked on the tree
		 */
		void runTreeUI();

		// getters 
		/**
		 * @return Returns a pointer to the whole tree
		 */
		Tree* getTree();
	private: 
		// calling tree methods with user input
		/**
		 * @brief Takes in user input and calls the insert function of the tree
		 */
		void addElement();			

		/**
		 * @brief Takes in user input and calls the remove function of the tree
		 */
		void removeElement();	

		/**
		 * @brief Takes in user input and calls the contains function of the tree
		 */
		void containsElement();		

		/**
		 * @brief Calls the recursive numberOfNodes function of the tree
		 */
		void nodesNumber();			

		/**
		 * @brief Calls the recursive toIntArray function of the tree
		 */
		void intArray();			

		/**
		 * @brief Loads a sample tree for quick use
		 */
		void sampleTree();			

		// instance of our tree
		Tree* tree;
};

#endif