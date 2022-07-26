#pragma once
#include <string>
#include <iostream>

using std::cin; // to input capitol city number from the console
using std::cout;  // output result to the console
using std::getline; // pass data from external file
using std::endl; // create a line break

class Empire { 
private:
    /// <summary>
    /// Size of the squared symmetrical matrix. Size is nxn.
    /// </summary>
    int size;

    /// <summary>
    /// An array representing a symmetrical matrix. 
    /// </summary>
    int* node_array;

public:
    /// <summary>
    /// Default constructor. Initializes an array of integers that represent a 2x2 symmetrical matrix
    /// </summary>
    Empire() 
    {
        size = 2;
        node_array = new int[2 * (2 + 1) / 2]{ 0 };
    }

    /// <summary>
    /// Initializes the Empire map as an int array that represents a symmetrical matrix
    /// </summary>
    /// <param name="n">The dimensions of the map are n-by-n </param>
    Empire(int n) 
    {
        this->size = n;
        node_array = new int[n * (n + 1) / 2];
    }
   
    /// <summary>
    /// Public accessor for private size variable
    /// </summary>
    /// <returns></returns>
    int Size();

    /// <summary>
    /// Default destructor. Releases memory space occupied by the defualt object. Called automatically.
    /// </summary>   
    //  ~Empire() 
    //  {
    //    delete[]node_array;
    //  }

    /// <summary>
    /// Used to set the distance-by-time between two city nodes
    /// </summary>
    /// <param name="i"> Iterator for the rows in the array</param>
    /// <param name="j"> Iterator for the columns in the array</param>
    /// <param name="val"> The value of the edge to be stored</param>
    void Set(int i, int j, int val); 

    /// <summary>
    /// Retrieve the number stored inside of the node_array at the given index 
    /// </summary>
    /// <param name="i"> Iterator for the rows in the array</param>
    /// <param name="j"> Iterator for the columns in the array</param>
    /// <returns> int that represents the distance-in-time between nodes i and j </returns>
    int Get(int i, int j); 

    /// <summary>
    /// Use to display the table as an n-by-n symmetrical matrix.
    /// </summary>
    /// <example> empire[5][5] = { 
    /// {   0, 50, 30, 100, 10},
    /// {  50,  0,  5,  20,  0},
    /// {  30,  5,  0,  50,  0 },
    /// { 100, 20, 50,   0, 10 },
    /// {  10,  0,  0,  10,  0 },
    /// };
    /// </example>  
    void Display(); 
};