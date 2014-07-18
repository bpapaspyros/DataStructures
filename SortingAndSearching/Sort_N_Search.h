#ifndef SORT_N_SEARCH_H
#define SORT_N_SEARCH_H

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <ctime>

class Sort_N_Search {
	public:
		// Constructor & Destructor
		Sort_N_Search();

		// Sorting methods
		void mergesort(int* inArray, int lower_lim, int upper_lim);
		void merge(int* inArray, int lower_lim, int upper_lim);

		void quicksort(int* inArray, int lower_lim, int upper_lim);
		void bublesort(int* inArray, int size);

		// Searching methods 
		int binarySearch(int* inArray, int lower_limit, int upper_limit, int key);
		int binaryInterpolationSearch(int* inArray, int size, int key);

		// Printing methods
		void printMenu(int elNum);
		void printArray(int* inArray, int size);

		// getters
		double getExecutionTime();
	private:
		// Misc methods
			// handling keys
		std::string getFilename();
		int getSearchKey();
		void printKey(int pos);
			// swap
		void swap(int& a, int& b);
			// array initialization
		void initArray(int* inArray, int size);
		void initArray(int* inArray, int size, int up_lim);
		void initArrayFromFile(int* inArray, const char* filename);
			// file management
		int getFileElements(const char* filename);
		void writeSortedToFile(int* inArray, int size);

		// times
			// handling the timer
		void start_timer();
		void stop_timer();
			// storing the times
		clock_t t_start;
		double dtime;

		// comparisons
		int comp;
};

#endif