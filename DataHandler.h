#ifndef DATAHANDLER_H
#define DATAHANDLER_H	
#include <string>
#include <iostream>
#include <fstream>
class DataHandler {
public:
	//Intitializes array with values from .txt file
	//@Param = the .txt file values are read from
	void ReadData(std::string source);
	//Outputs the current state of the array. Mainly used for testing purposes, but left in so the user can confirm that the desired operations are taking place
	void OutputData(); 
	//Searches the array for a specific integer and outputs the index of its location in the array
	//@Param = the target integer
	void FindInt(int target);
	//Replaces the element at a user specified index with a user specified integer
	//@Param = the index of the element to be replaced
	//@Param = the new value of the specified element
	void ModifyArrayByIndex(int index, int num);
	//Adds and integer to the end of the array
	//@Param = integer added
	void Add(int num); 
	//Removes the value at the specified index, shifts all other elements over by one, and shrinks the array by one
	//@Param = index of element to remove
	void Remove(int index); 
private:
	//Size of array with hard-coded initial size of 10, not the best practice but will do for the purposes of this program
	int size = 10;
	//Declaring our array
	int *DataArray = new int[size];
};
#endif