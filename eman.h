#pragma once

#include <sstream> // stringstream
#include <fstream> // ifstream
#include <iostream> // cout

using std::stoi; // convert string to integer
using std::cout;  // output result to the console
using std::endl; // create a line break

using std::string;  // store input from file
using std::stringstream; // pass data from external line 
using std::ifstream;  // read from external file

/// utility functions and reference used:
/// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

/// <summary>
/// prints error message when no file is passed, or when the file is invalid
/// </summary>
/// <param name="argCount"> Number of arguments from the main function </param>
/// <param name="argVal"> The name of the argument that was passed in </param>
/// <returns> True if external file reference stream is open and valid otherwise False </returns>
bool input_valid(int argCount, char* argVal[]);

/// <summary>
/// if valid, reads values from the external file reference line by line and stores the values
/// </summary>
/// <param name="argVal"> name of the file that was passed as an argument </param>
/// <returns> integer array of the space-separated-values from the external file reference </returns>
int* extract_values(char* argVal[]);

/// <summary>
/// prints the minimum time it takes to reach all nodes to the console
/// </summary>
/// <param name="dist"> integer array. index refers to node. value is the distance </param>
/// <param name="visited"> boolean array. index refers to node. value is whether distances from that node have been processed </param>
/// <param name="N"></param> integer. the total number of nodes (aka vertices in a graph).
void display_min_time_spread(int dist[], bool visited[], int N);

/// <summary>
/// prints the cheapest path to reach every node from a given starting point 
/// </summary>
/// <param name="file_v"> an integer array with all of the values taken from the external file </param>
/// <param name="src"> node to start from </param>
void spread_message(int file_v[], int src);

/// <summary>
/// A utility function to print a table with distances from source to each node
/// </summary>
/// <param name="time_distance"> the array of distance values </param>
/// <param name="n"> the size of the array </param>
/// <returns>0</returns>
int print_distances(int time_distance[], int n);

/// <summary>
/// A utility function that finds yet unvisited nodes with the cheapest route to take
/// </summary>
/// <param name="dist"> integer array. index refers to node. value is the distance </param>
/// <param name="visited"> boolean array. index refers to node. value is whether distances from that node have been processed </param>
/// <returns> the node with the cheapest, un</returns>
int minDistance(int dist[], bool visited[]);