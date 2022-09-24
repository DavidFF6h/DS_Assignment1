# DS_Assignment1

## Description:
  This program is intended to take in data from a file (Data.txt in this case), intert said data into an array, and allow the user to: Print the data, Find a specific integer value in said data, Modify and element through its index, add values to the data, and subtract values from the data

## How to run:
  This is the part of the assignment I am most worried about, I've never written a readme, and I'm not sure what instructions to give other than:
  
    1: Get files: Data.txt, DataHandler.h, DataHandler.cpp, and DS_Assignment1.cpp from github
    2: Bring those files into your IDE of choice
    3: Build and run
    
  If these instructions aren't what are being looked for, please give me a detailed description so I don't make the same mistakes in the future

## Instructions:
  User will be prompted with 6 choices of commands, each corresponding to a number 0-5
  Type the number corresponding to the desired command and press enter

## Data.txt:
  This file simply contains a list of 10 integers (for simplicity's sake) to be passed into the array that this program utilizes for all operations

## DataHandler.h:
  This is the programs header file containing all of the necessary member data and function definitions.
   ### In the public section it contains definitions for:
    
     -void ReadData(string source), which takes in the source file (Data.txt) and inserts its values into the array
     -void OutputData(), which simply prints the current values of the array.
     -void FindInt(int target), which searches through the array to find the user specified number, if it exists, and prints its index to the console
     -void ModifyArrayByIndex(int index, int num), which allows the user to replace the value at a user specified index with a user specified value, and prints both the new value and the one that has been replaced
     -void Add(int num), which allows the user to add an integer to the end of the array
     -void Remove(int index), which allows the user to remove the element at the specified index
     
     All of these functions will be broken down further in the DataHandler.cpp section
   ### In the private section it contains:
      -int size = 10, which is the initial size of the array
      -int *DataArray = new int[size], is the pointer to the array that all of the functions act upon

## DataHandler.cpp:

  This is the implementation file containing all of the logic for the functions created in DataHandler.h
    ### void DataHandler::ReadData(string source)
      This function starts by creating an ifstream named "input" and using input.open(source) to open our source file (Data.txt) and give its data to our ifstream.
      If input exists, the function then declares int x = 0 and goes into a loop
                                    while(!input.eof()), or while input has not reached the end of the file
                                      insert that line of input into the array at element x
                                      increase x by one
     If input does not exist, print to console that no file has been found and return
     
   ### void DataHandler::OutputData()
     This function simply prints "Array:" and starts a new line, for readability's sake, and goes into a loop
                                    for(int i = 0 to size)
                                      print i followed by ": " followed by the array element at index i and starts a new line
     Then the function prints "-----", for readability and returns
     
   ### void DataHandler::FindInt(int target)
     This function looks for the target integer by going into a loop
                                    for(i = 0 to size)
                                      if array element a is equal to the target integer, print target is at index i, and returns
     If the function makes it all the way through the loop, print target is not in the array, and returns
     
   ### void DataHandler::ModifyArrayByIndex(int index, int num)
     Because the assignment specified that this fuction must both print the number and the number that is replaced, this function begins by creating int temp which is set equal to the array at the user specified index. Then, the array element at that index is replaced by the user specified value. The function then prints, temp at index index has been replaced by num.
     
   ### void DataHandler::Add(int num)
     This function starts by printing that the user specified num has been added to the end of the array, increases size by one, and sets element size-1 of the array equal to num.
     
   ### void DataHandler::Remove(int index)
     This function begins by printing that the element at the specified index has been removed, and goes into a loop
                                      for(i = index to size)
                                        element i = element i+1, which effectively shifts all elements down one, eliminating the specified index in the process
     The function the decreases size by one, and returns

## DS_Assignment1.cpp
  ### This is the test file:
      Prior to int main() I forward declared Process commands, which prompts the user to input a number corresponding to their desired command(FindInt, ModifyArrayByIndex, Add, Remove, OutputData, Exit) and keeps them in a loop until the exit command is used
      I also forward declared Do_FindInt(DataHandler& data), Do_ModifyArrayByIndex(DataHandler& data), Do_Add(DataHandler& data), Do_Remove(DataHandler& data), and Do_OutputData(DataHandler& data), which simply prompt the user for input and call the corresponding DataHandler member function, passing in the input
      int ProcessInputInt(), which is used inplace of cin in the above functions, as if it recieves a value that doesn't make sense, like a string, it will tell the user their input was invalid and loop until thier input is valid 
      In int main, I create an instance of DataHandler named datahandler, and use datahandler.ReadData to initialize the array, before entering ProcessCommands to start the command loop

## Input and Output screenshots:
  -Upon running the program, the user is greeted with:
  ![Initial](https://user-images.githubusercontent.com/113874835/191409962-d21f18e3-bdec-4e2a-ae5b-82115c4cb763.png)
  
  -After entering 4 to print the array we get: (notice that we are prompted for input once again after array is printed)
  ![Print](https://user-images.githubusercontent.com/113874835/191410135-af033a9b-9665-4c9e-865c-ed4a951b80f8.png)
  
  -After entering 0 to search for an int, we are asked what int we would like to search for, here 13 was entered and the function returned that 13 is at index 1, which is consistent with the image above:
  ![Search](https://user-images.githubusercontent.com/113874835/191410355-abb58879-ca11-4097-94fc-0bb7a1000e54.png)
  
  -After entering 1 to change a value by its index, we are prompted to enter the index, and the new value for the element at said index, 2 and 47 are entered respectively. Then, command 4 is used to print the array and show that element 2 is now equal to 47:
  ![Mod](https://user-images.githubusercontent.com/113874835/191410648-1e585040-800a-45d2-b545-3ba8e9110513.png)
  
  -After entering 2 to add and integer to the end of the array, we are asked what integer we would like to add. 62 in this case. Command 4 is then called to show that 62 was indeed added to the end of the array, and that the array is one element larger:
  ![Add](https://user-images.githubusercontent.com/113874835/191411010-577e3be8-356c-4cf3-98e6-aa9b8f9de135.png)
  
  -After entering 3 to remove an integer by index, we choose to remove index 7. The console then prints that 26 at element 7 has been removed, and we once again call command 4 to show that everything is working correctly:
  ![Remove](https://user-images.githubusercontent.com/113874835/191411199-ecabe589-4645-4f1d-b607-6e01173123dd.png)
  
  -Then, command 5 is called, and the program terminates:
  ![Exit](https://user-images.githubusercontent.com/113874835/191411252-fd860c32-e449-41e0-8a90-b89dd2373156.png)



