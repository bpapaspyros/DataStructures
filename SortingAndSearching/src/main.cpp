/*! \mainpage Main page
  *														    
  * \section intro_sec Purpose									    
  * 																			    
  * This is a project for the course Data Structures at the Computer Engineering and Informatics Department, University of Patras.
  * The purpose of this project was to implement basic sorting and searching algorithms.
  *
  * \section compile_sec Compiling
  *
  * <CENTER> mkdir build && cd build && cmake .. && make && cd .. </CENTER>
  * 
  * \section run_sec Running
  *
  * <CENTER> cd bin && ./sortNsearch </CENTER>
  *
  * \section dep_sec Dependancies (Debian based systems)
  *
  * <CENTER> sudo apt-get install cmake (Minimum version 2.6 required) </CENTER>															    
  *
  * \section info_sec More information																				    
  *																				    
  * Contact: b.papaspyros@gmail.com	or create an issue on the github page https://github.com/bpapaspyros/DataStructures	
  *
  * \author Vaios Papaspyros				            
  *																				   
  */

#include "Sort_N_Search.h"

/**
  * \param Takes in an integer which represents the array size. 
*/
int main(int argc, char** argv) {
	int elNum = 32;					// default array size

	if (argc == 2) {
		elNum = atoi(argv[1]);		// using the parameter given to determine the array size
	}
	
	// seed for the random number generator
	srand(time(NULL));

	// starting the user interface
	Sort_N_Search sns;
	sns.printMenu(elNum);

	return 0;
}