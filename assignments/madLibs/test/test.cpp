#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;


int *createArray(int);

int main(){

	/*

		You can replace all, "new int[10];" with createArray(10) cause I made that method

	*/
	
	//size of 10
	int an1DArray[] = {1,2,3,4,5,6,7,8,9,10};

	//print it out
	cout << "Printing an 1D array standardly\n";
	for(int i = 0; i < 10; i++){
		cout << an1DArray[i] << " ";
	}

	/*
		1D Array w/ pointer
	*/
	int *pointer1;
	pointer1 = an1DArray;

	
	cout << "\n\n\nPrinting an 1D pointer/array using a pointer and pointer notation\n";
	for(int i = 0; i < 10; i++){
		cout << *(pointer1 + i) << " ";
	}
	//or
	cout << "\n\nPrinting an 1D pointer/array using a pointer and array notation\n";
	for(int i = 0; i < 10; i++){
		cout << pointer1[i] << " ";
	}
	
	/*
		1D Array w/ dynamic alocation
	*/
	int *pointer2;
	pointer2 = new int[10];
	cout << "\n\n\nPrinting an 1D pointer/array using a pointer using dynamic alocation and pointer notation\n";
	for(int i = 0; i < 10; i++){
		cout << *(pointer2 + i) << " ";
	}
	//or
	cout << "\n\nPrinting an 1D pointer/array using a pointer dynamic alocation and array notation\n";
	for(int i = 0; i < 10; i++){
		cout << pointer2[i] << " ";
	}


	/*
		2D Array
	*/
	//btw I think you can do this dynamicaly like: int *testAray = new *int[size]
	//or something similar, but IDK about that right now
	//create array of pointers
	
	int *pointerArray[10];
	

	
	//go through and assign each pointer in the array to a new array
	for(int i = 0; i <  10; i++){
		pointerArray[i] = new int[10];
	}
	
	//Populate the 10x10 2D array/pointer
	for (int i = 0, counter = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			pointerArray[i][j] = ++counter;

		}
		
	}


	// since this is technicaly a 10x10 we no not need to remember lengths
	cout << "\n\n\nPrinting 2D pointer/array with array notation\n";
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cout << pointerArray[i][j] << " ";
		}
		cout << endl;
	}
	//You can technicaly use pointer notation but I dont know how  
  
}

int *createArray(int size){

  
  return new int[size];

}
