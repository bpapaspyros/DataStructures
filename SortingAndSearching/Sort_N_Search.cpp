#include "Sort_N_Search.h"


Sort_N_Search::Sort_N_Search() {
	// initializing the times to -1
	t_start = -1;
	dtime = -1;
	comp = 1;
}

					/**********************************
					 *								  *
				     *            Sorting             *
					 *								  *
					 **********************************/
/*- -------------------------------------------------------------- -*/

/* MERGESORT implementation. The basic idea behind the mergesort algorithm is that *
 * we split the initial array that we are given in to two equal arrays recursively *
 * until we come to have two numbers and then we sort those and merge them into a  *
 * single array (the original one that we were given)                              */

// recursive call of this method to achieve the mergesort algorithm
void Sort_N_Search::mergesort(int* inArray, int lower_lim, int upper_lim) {
	if (lower_lim < upper_lim){
		comp++;
		mergesort(inArray, lower_lim, (lower_lim+upper_lim)/2);
		mergesort(inArray, (lower_lim+upper_lim)/2+1, upper_lim);
		merge(inArray, lower_lim, upper_lim);
	}
}

void Sort_N_Search::merge(int* inArray, int lower_lim, int upper_lim)
{
    int mid = floor((lower_lim + upper_lim) / 2);
    int i1 = 0;
    int i2 = lower_lim;
    int i3 = mid + 1;

    // storing the changes temporarily in a buffer
    int temp[upper_lim-lower_lim+1];

    // merge in sorted form the 2 arrays
    while ( i2 <= mid && i3 <= upper_lim ) {
        if ( inArray[i2] < inArray[i3] )
            temp[i1++] = inArray[i2++];
        else
            temp[i1++] = inArray[i3++];
        comp++;
    }

    // merge the remaining elements in the left array
    while ( i2 <= mid ) {
        temp[i1++] = inArray[i2++];
        comp++;
    }

    // merge the remaining elements in the right array
    while ( i3 <= upper_lim ) {
        temp[i1++] = inArray[i3++];
        comp++;
    }

    // transfer the changes to the given array
    for ( int i = lower_lim; i <= upper_lim; i++ ) {
        inArray[i] = temp[i-lower_lim];
    }
}

/*- -------------------------------------------------------------- -*/

/* QUICKSORT implementation. The basic idea behind the quicksort algorithm is that *
 * we use the divide and conquer method. We initially split the array to two 	   *
 * arrays and then we apply the same method to the sub arrays recursively until    *
 * the we get all elements sorted.                                                 */

void Sort_N_Search::quicksort(int* inArray, int lower_lim, int upper_lim) {
	// increasing the comparison counter
	comp++;

	// left and right limits
	int i = lower_lim;
	int k = upper_lim+1;

	// setting the pivot
	int s = inArray[lower_lim];

	while (i<k) {
		do{
			i++;
		}while(inArray[i]<s);

		do{
			k--;
		}while(inArray[k]>s);

		if (k>i) {
			swap(inArray[k], inArray[i]);
			comp++;
		}
	}

	swap(inArray[lower_lim], inArray[k]);

	if (lower_lim<k-1) {
		quicksort(inArray, lower_lim, k-1);
	}

	if (k+1<upper_lim) {
		quicksort(inArray, k+1, upper_lim);
	}
}

/*- -------------------------------------------------------------- -*/

/* BUBLESORT implementation. The basic idea behind the bublesort algorithm is *
 * that we scan the whole array until we find the min value and then we use   *
 * the same method with the next min value until all elements are sorted      */

void Sort_N_Search::bublesort(int* inArray, int size) {
	while (size>1) {
		int j = 0;
		for (int i=0; i<size-1; i++) {
			if (inArray[i]>inArray[i+1]) {
				swap(inArray[i], inArray[i+1]);
				j++;
			}
		}

		if (j == 0) {
			break;
		}

		comp++;
		size--;
	}
}
/*- -------------------------------------------------------------- -*/
					/**********************************
					 *								  *
				     *           Searching            *
					 *								  *
					 **********************************/
/*- -------------------------------------------------------------- -*/

/* BINARY implementation. The basic idea behind the binary search algorithm is   *
 * that we check the middle value of the array and if it is smaller than the key *
 * given then we search recursively the right half of the array otherwise we     *
 * search the right part, unless the key give is located in the middle		     */

int Sort_N_Search::binarySearch(int* inArray, int lower_limit, int upper_limit, int key) {
	int index;	// index of the requested element (or -1 if it doesn't exist)

	if (lower_limit > upper_limit) {
		index = -1;	// element not found, returning -1
	} else {
		int mid = (lower_limit + upper_limit)/2;
	
		if (key == inArray[mid]) {
			index = mid;
		} else if (key < inArray[mid]) {
			index = binarySearch(inArray, lower_limit, mid-1, key);
		} else if (key > inArray[mid]) {
			index = binarySearch(inArray, mid+1, upper_limit, key);
		}
	}

	return index;
}

/*- -------------------------------------------------------------- -*/

/* BINARY INTERPOLATION implementation. The basic idea behind the binary *
 * interpolation search algorithm is that we combine the benefits of     *
 * applying a binary and an interpolation search so that we narrow down  * 
 * the search key in less loops. There has been added a code snippet to  *
 * check if the initial next variable is out of bounds for our array 	 */															   
int Sort_N_Search::binaryInterpolationSearch(int* inArray, int size, int key) {
	int left = 0;
	int right = size-1;
	int next = size*((key-inArray[left])/(double)(inArray[right]-inArray[left])) + 1;

	// checking if next is out of bounds
	if (next > size - 1) {
		next = size - 1;
	} else if (next < 0) {
		next = 0;
	}

	while (key != inArray[next]) {
		int i = 0;

		size = right - left + 1;

		if (size <= 3) {
			for (int j=0; j<size; j++) {
				if (key == inArray[left+j]) {
					return left+j;
				} 
			}

			return -1;
		}  

		if (key >= inArray[next]) {
			while (key > inArray[next + i*(int)(sqrt(size)) - 1 ] )  {
				i++;
			}

			right = next + i*(int)(sqrt(size));
			left = next + (i-1)*(int)(sqrt(size));
		} else {
			while (key < inArray[ (int)( next - i*(int)(sqrt(size)) + 1 )]) {
				i++;
			}

			right = next - (i-1)*(int)(sqrt(size));
			left = next - i*(int)(sqrt(size));
		}

		next = left + (right - left + 1)*((key - inArray[left])/(double)(inArray[right]-inArray[left]));
	}

	if (key == inArray[next]) {
		return next;
	} else {
		return -1;
	}
}

/*- -------------------------------------------------------------- -*/
					/**********************************
					 *								  *
				     *  Misc methods for general use  *
					 *								  *
					 **********************************/
/*- -------------------------------------------------------------- -*/
// simple swap method
void Sort_N_Search::swap(int& a, int& b) {
	int temp = b;
	b = a;
	a = temp;
}

/*- -------------------------------------------------------------- -*/
// populating an array of integers with random numbers
void Sort_N_Search::initArray(int *inArray, int size, int up_lim) {
	for (int i=0; i<size; i++) {
		inArray[i] = rand()%up_lim;
		// inArray[i] = size-i;
	}
}

void Sort_N_Search::initArray(int *inArray, int size) {
	initArray(inArray, size, 100); // defaults to the range 0-99
}

/*- -------------------------------------------------------------- -*/
void Sort_N_Search::initArrayFromFile(int* inArray, const char* filename) {
	std::ifstream  dataFile(filename);	// file stream

	// index for the array
	int i = 0;

	// element read from the file
	int element;
	dataFile >> element;

	// while there are elements in the file
	while (dataFile.good()) {
	    inArray[i++] = element;	// we initialize the array with those elements
	    dataFile >> element;
	}

	dataFile.close();	// closing the file
}

/*- -------------------------------------------------------------- -*/
int Sort_N_Search::getFileElements(const char* filename) {
	int elNum = 0;	// number of elements we counted in the file

    std::string line;					// string variable to read the whole line 
    std::ifstream dataFile(filename);	// file stream

    while (std::getline(dataFile, line)){
		++elNum;	// counting elements
    }

	return elNum;	// returning the element number

}

/*- -------------------------------------------------------------- -*/
void Sort_N_Search::writeSortedToFile(int* inArray, int size) {
	std::string str = "sortedOut.txt";		// output file name
	std::ofstream  dataFile(str.c_str());	// file stream

	// writing the array elements to file
	for (int i=0; i<size; i++) {
		dataFile << inArray[i] << "\n";	
	}

	dataFile.close();	// closing the file

}

/*- -------------------------------------------------------------- -*/
// getting a string (filename) from the user 
std::string Sort_N_Search::getFilename() {
	std::string str;

	std::cout << "Filename: ";
	std::cin >> str;

	return str;
}

/*- -------------------------------------------------------------- -*/
// user's choice of the key to search for 
int Sort_N_Search::getSearchKey() {
	int key;

	std::cout << "Search for: ";	// asking the user for a search key
	std::cin >> key;	// getting user input

	return key;
}

/*- -------------------------------------------------------------- -*/
// getting the current system time, initiating the timer
void Sort_N_Search::start_timer() {
	t_start = clock();
}

/*- -------------------------------------------------------------- -*/
// stoping the timer 
void Sort_N_Search::stop_timer() {
	dtime =  (double)(clock() - t_start)/CLOCKS_PER_SEC;
}

/*- -------------------------------------------------------------- -*/
// returning the measured time to the user
double Sort_N_Search::getExecutionTime() {
	return dtime;
}

/*- -------------------------------------------------------------- -*/
					/**********************************
					 *								  *
				     *        Printing Methods        *
					 *								  *
					 **********************************/
/*- -------------------------------------------------------------- -*/
void Sort_N_Search::printArray(int* inArray, int size) {
	// printing a given array so that it is readable
	std::cout << "\n\t*********************************************** \n" << std::endl;

	for (int i=0; i<size; i++) {
		std::cout << "\t\t\t\t" << inArray[i] << std::endl;
	}

	std::cout << "\n\t*********************************************** \n" << std::endl;

}

/*- -------------------------------------------------------------- -*/
// informing the user whether the key he inserted was found or not
void Sort_N_Search::printKey(int pos) {
	if (pos != -1) {
		std::cout << "The requested element's index is: " << pos << std::endl;
	}else {
		std::cout << "The requested element was not found !" << std::endl;
	}

}

/*- -------------------------------------------------------------- -*/
// visual menu for the user that lets him choose algorithms for searching and sorting
void Sort_N_Search::printMenu(int elNum) {
	if (elNum<2) {
		elNum = 32;			// element number defaulting to 32
	}

	char c; 				// user selection
	int* sortThis;

	do {
		// printing a visula menu to the user
		std::cout << "\t * 1 - Random Elements " << std::endl;
		std::cout << "\t * 2 - Get elements from file " << std::endl;
		std::cout << "\t * e - Exit" << std::endl;
		std::cout << "\t Choice: ";

		// getting input from the user
		std::cin >> c;
		c = tolower(c);

		switch (c) {
			case '1':
				c = 'e';
				sortThis = new int[elNum];	// reserving space from heap
				initArray(sortThis, elNum);	// initializing the array with random values
				break;
			case '2':
				c = 'e';
				{
					std::string filename = getFilename();

					elNum = getFileElements(filename.c_str());

					sortThis = new int[elNum];	// reserving space from heap
					initArrayFromFile(sortThis, filename.c_str());	// initializing the array from a file
				}
				break;
			case 'e':
				c = 'e';
				break;
		}

	}while (c!='e');	

	do {
		// printing a visula menu to the user
		std::cout << "\t * 1 - Mergesort " << std::endl;
		std::cout << "\t * 2 - Quicksort " << std::endl;
		std::cout << "\t * 3 - Bublesort" << std::endl;
		std::cout << "\t * e - Exit" << std::endl;
		std::cout << "\t Choice: ";

		// getting input from the user
		std::cin >> c;
		c = tolower(c);

		// printArray(sortThis, elNum);	// printing the initial-unsorted array

		// choosing the sorting algorithm
		switch (c) {
			case '1':	// chose mergesort
				c = 'e';

				start_timer();	// starting the timer
				mergesort(sortThis, 0, elNum-1);
				stop_timer();	// stopping the timer
	
				writeSortedToFile(sortThis, elNum);
				break;
			case '2':	// chose quicksort
				c = 'e';

				start_timer();
				quicksort(sortThis, 0, elNum-1);
				stop_timer();

				
				writeSortedToFile(sortThis, elNum);
				break;
			case '3':	// bublesort
				c = 'e';

				start_timer();	// starting the timer
				bublesort(sortThis, elNum);
				stop_timer();	// stopping the timer

				writeSortedToFile(sortThis, elNum);
				break;
			case 'e':
				c = 'e';
				break;
		}
	}while (c!='e');

	// printing the time spent on sorting
	std::cout << "\t -> The execution time of the selected algorithm was: " << dtime << " seconds \n" << std::endl;
	std::cout << "\t -> Comparisons: " << comp << "\n" << std::endl;

	// choosing the search algorithm
	do {
		// printing a visual menu to the user
		std::cout << "\t * 1 - Binary Search" << std::endl;
		std::cout << "\t * 2 - Binary Interpolation Search" << std::endl;
		std::cout << "\t * e - Exit" << std::endl;
		std::cout << "\t Choice: ";

		// getting input from the user
		std::cin >> c;
		c = tolower(c);

		int key;	// key for the upcomiing search
		int pos;	// position of the value we are searching for

		switch (c) {
			case '1':	// binary search
				c = 'e';
				key = getSearchKey();	// getting a key from the user
				pos = binarySearch(sortThis, 0, elNum, key);
				printKey(pos);	// printing the key if found
				break;
			case '2':	// binary interpolation search				
				c = 'e';
				key = getSearchKey();	// getting a key from the user
				pos = binaryInterpolationSearch(sortThis, elNum, key);
				printKey(pos);	// printing the key if found
				break;
			case 'e':
				c='e';
				break;
		}
	}while(c!='e');

	delete sortThis;

}

/*- -------------------------------------------------------------- -*/