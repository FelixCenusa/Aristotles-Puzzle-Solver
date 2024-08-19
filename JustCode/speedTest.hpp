#include <iostream>
#include <time.h>
#include <vector>
#include "linkedList.hpp"
using namespace std;

void speedTest(const int NUM_OPS) {
	cout << "Speed test of different data structures: " << endl;
	clock_t start = clock();
	linkedList<int> list;
	for (int i = 0; i < NUM_OPS; i++) {
		list.insertFirst(i);
	}
	for (int i = 0; i < NUM_OPS; i++) {
		list.removeFirst();
	}
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Time: " << time << " seconds for the linkedList" << endl;

	// compare with the time it takes to do the same operations with a vector
	start = clock();
	vector<int> vec;
	for (int i = 0; i < NUM_OPS; i++) {
		vec.insert(vec.begin(), i);
	}
	for (int i = 0; i < NUM_OPS; i++) {
		vec.erase(vec.begin());
	}
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Time: " << time << " seconds for the Vector" << endl;

	// compare with the time it takes to do the same operations with a array
	start = clock();
	int* arr = new int[NUM_OPS];
	int arrSize = 0;
	for (int i = 0; i < NUM_OPS; i++) {
		for (int j = arrSize; j > 0; j--) {
			arr[j] = arr[j - 1];
		}
		arr[0] = i;
		arrSize++;
	}
	for (int i = 0; i < NUM_OPS; i++) {
		for (int j = 0; j < arrSize - 1; j++) {
			arr[j] = arr[j + 1];
		}
		arrSize--;
	}
		end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Time: " << time << " seconds for the Array" << endl << endl;

	// From running the program 3 different times, the average came out to be:
	// Time: 0.034 seconds ( for the linked list)
	// Time: 1.45 seconds ( for the vector) (times slower compared to linked list: ~42)
	// Time: 31.417 seconds ( for the array) (times slower compared to linked list: ~924)
}