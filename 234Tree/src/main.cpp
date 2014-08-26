/*! @mainpage Main page
 *														    
 * @section intro_sec Purpose									    
 * 																			    
 * This is a project for the course Data Structures at the Computer Engineering and Informatics Department, University of Patras.
 * The purpose of this project was to implement a 234 ab tree and basic methods for adding, removing, etc nodes.
 *
 * @section compile_sec Compiling
 *
 * <CENTER> mkdir build && cd build && cmake .. && make && cd .. </CENTER>
 * 
 * @section run_sec Running
 *
 * <CENTER> cd bin && ./tree </CENTER>
 *
 * @section dep_sec Dependancies (Debian based systems)
 *
 * <CENTER> sudo apt-get install cmake graphvis-dev (Minimum version 2.6 required for cmake) </CENTER>															    
 *
 * @section info_sec More information																				    
 *																				    
 * Contact: b.papaspyros@gmail.com	or create an issue on the github page https://github.com/bpapaspyros/DataStructures	
 *
 * @author Vaios Papaspyros (elm)		            
 *																				   
 */

#include "Interface.h"

/*- -------------------------------------------------------------- -*/
int main() {

	// elm interface :)

	Interface elm;		// instance for our interface class
	elm.runTreeUI();	// calling the ui method to start interacting with the user

	return 0;
}


