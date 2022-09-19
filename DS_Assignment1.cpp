#include "DataHandler.h"
#include <iostream>

//Forward Declaring 
void ProcessCommands(DataHandler& data);
void Do_FindInt(DataHandler& data);
void Do_ModifyArrayByIndex(DataHandler& data);
void Do_Add(DataHandler& data);
void Do_Remove(DataHandler& data);
void Do_OutputData(DataHandler& data);
int ProcessInputInt();
int main(){
	DataHandler datahandler;
	datahandler.ReadData("Data.txt");
	ProcessCommands(datahandler);
	return 0;
}

void ProcessCommands(DataHandler& data)
{
	std::string commands[] = {
		"Search For Integer",
		"Change Integer Value By Index",
		"Add Integer To End Of Array",
		"Remove Integer By Index",
		"Output Array",
		"Exit"
	};
	const int NumberOfCommands = 6;
	int choice;
	do {
		for (int i = 0; i != NumberOfCommands; i++) {
			std::cout << "Select: " << i << " " << commands[i] << std::endl;
		}
		choice = ProcessInputInt();
		switch (choice) {
		case 0: Do_FindInt(data); break;
		case 1: Do_ModifyArrayByIndex(data); break;
		case 2: Do_Add(data); break;
		case 3: Do_Remove(data); break;
		case 4: Do_OutputData(data); break;
		case 5: return;
		default: {
			std::cout << "Input does not correspond to a command." << std::endl;
			continue;
		}
		}
	} while (choice != 5);
}

void Do_FindInt(DataHandler& data)
{
	int num;
	std::cout << "Enter the number you would like to search for: ";
	num = ProcessInputInt();
	data.FindInt(num);
}

void Do_ModifyArrayByIndex(DataHandler& data)
{
	int index, num;
	std::cout << "Enter the index of the number you would like to modify: ";
	index = ProcessInputInt();
	std::cout << "Enter the new value of index " << index << " : ";
	num = ProcessInputInt();
	data.ModifyArrayByIndex(index, num);
}

void Do_Add(DataHandler& data)
{
	int num;
	std::cout << "Enter the number you would like to add to the end of the array: ";
	num = ProcessInputInt();
	data.Add(num);
}

void Do_Remove(DataHandler& data)
{
	int num;
	std::cout << "Enter the index of the number you would like to remove: ";
	num = ProcessInputInt();
	data.Remove(num);
}

void Do_OutputData(DataHandler& data)
{
	data.OutputData();
}

int ProcessInputInt()
{
	int input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "Invalid input, use integer values only!" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Try again: ";
		std::cin >> input;
	}
	return input;
}