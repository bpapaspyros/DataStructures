#include "Sort_N_Search.h"

using namespace std;

int main(int argc, char** argv) {
	int elNum = 32;					// default array size

	if (argc == 2) {
		elNum = atoi(argv[1]);		// using the parameter given to determine the array size
	}
	
	// seed for the random number generator
	srand(time(NULL));

	// testing 
	Sort_N_Search sns;
	sns.printMenu(elNum);

	return 0;
}