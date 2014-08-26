/** 
 * @class Sort_N_Search
 *														    
 * @brief Sorting and Searching algorithms 									    
 * 																			    
 * This class contains three sorting algorithms (Mergesort, Quicksort, Bublesort)  
 * and two searching (Binary and Binary Interpolation). The above algotithms are   
 * designed to be used with integers. There have also been implemented methods for 
 * reading and writing data from/to files, methods that allow the programmer to    
 * meassure the execution time of any of the above algorithms. There are also      
 * methods that intialize an array with random integers as well as a basic CLI for 
 * the user.																	    
 *																				    
 * @author Vaios Papaspyros							            
 *																				    
 * Contact: b.papaspyros@gmail.com	or create an issue on the github page https://github.com/bpapaspyros/DataStructures	
 *																				   
 */

#ifndef SORT_N_SEARCH_H
#define SORT_N_SEARCH_H

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstring>

class Sort_N_Search {
	public:
		// Constructor & Destructor

		/**
		 * @brief Constructor
		 *
		 * Initalizing time values to the defaults
		 */
		Sort_N_Search();

		// Sorting methods

		/**
		 * @param An array with our elements and two integers representing the upper and lower
		 * limit of the array
		 */
		void mergesort(int* inArray, int lower_lim, int upper_lim);

		/**
		 * @brief Merge
		 * 
		 * Merges two sub arrays into one that is sorted
		 *
		 * @param An array with our elements and two integers representing the upper and lower
		 * limit of the array
		 */
		void merge(int* inArray, int lower_lim, int upper_lim);

		/**
		 * @param An array with our elements and two integers representing the upper and lower
		 * limit of the array
		 */
		void quicksort(int* inArray, int lower_lim, int upper_lim);

		/**
		 * @param An array with our elements and its size
		 */
		void bublesort(int* inArray, int size);

		// Searching methods 

		/**
		 * @param An array with our elements, two integers representing the upper and lower
		 * limit of the array and the search key given by the user
		 *
		 * @return The index where the key was found or a -1 indicating the key was not found
		 */
		int binarySearch(int* inArray, int lower_limit, int upper_limit, int key);

		/**
		 * @param An array with our elements, its size and the search key given by the user
		 *
		 * @return The index where the key was found or a -1 indicating the key was not found
		 */
		int binaryInterpolationSearch(int* inArray, int size, int key);

		// Printing methods
		
		/**
		 * @param Number of elements in the array passed from the main fucntion
		 */
		void printMenu(int elNum);

		/**
		 * @param An array and its size
		 */
		void printArray(int* inArray, int size);

		// getters

		/**
		 * @return Execution time meassured
		 */
		double getExecutionTime();
	private:
		// Misc methods
			// handling keys

		/**
		 * @return returns a string containing a filename
		 */
		std::string getFilename();

		/**
		 * @return returns an integer representing the search key
		 */		
		int getSearchKey();

		/**
		 * @param Index of the requested element
		 */
		void printKey(int pos);
		
		// swap
		/**
		 * @param Two integers passed by refernce
		 */
		void swap(int& a, int& b);
		
		// array initialization
		/**
		 * @param An empty array and its size
		 */
		void initArray(int* inArray, int size);

		/**
		 * @param An empty array, its size and the upper limit for the randomly generated numbers
		 */
		void initArray(int* inArray, int size, int up_lim);
		void initArrayFromFile(int* inArray, const char* filename);

		// file management
		/**
		 * @param Filename of a text file containing our data
		 * @return The number of elements in this file
		 */
		int getFileElements(const char* filename);

		/**
		 * @param An array and its size
		 */
		void writeSortedToFile(int* inArray, int size);

		// times
			// handling the timer
		void start_timer();
		void stop_timer();
			// storing the times
		clock_t t_start;
		double dtime;
};

#endif