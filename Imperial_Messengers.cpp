#include "LTMatrix.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#define V 5

using std::string;
using std::ifstream;
using std::stringstream;
using std::getline;
using std::stoi;

class Kingdom {
private:
    int n;
    int* Arr;
public:
    Kingdom() // default constructor
    {
        n = 2;
        Arr = new int[2 * (2 + 1) / 2]{ 0 };
    }

    Kingdom(int n)
    {
        this->n = n;
        Arr = new int[n * (n + 1) / 2];
    }
    ~Kingdom() // destructor
    {
        delete[]Arr;
    }

    void Set(int i, int j, int val);
    int Get(int i, int j);
    void Display();
};


// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
    return 0;
}


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void send_decree(int nums[], int src)
{
    Kingdom M(nums[0]);
    
    int ptr = 0;
    for (int i = 1; i <= nums[0]; i++)
    {
        for (int j = 1; j <= nums[0]; j++)
        {
            if (i > j)
            {
                ptr++;
            }
            int val = nums[ptr];
            M.Set(i, j, val);
        }
    }

    M.Display();

    int dist[V]; 

    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            int index = u < v ? u * (u - 1) / 2 + v - 1 : v * (v - 1) / 2 + u - 1;

            if (!sptSet[v] && nums[index] && dist[u] != INT_MAX
                && dist[u] + nums[index] < dist[v])
                dist[v] = dist[u] + nums[index];

        }
    }

    printSolution(dist, V);
}

void Kingdom::Set(int i, int j, int val)
{
    int index = i * (i - 1) / 2 + j - 1;
    if (i == j)
    {
        Arr[index] = 0;
    }
    else if (i > j)
    {
        Arr[index] = val;
    }
    else {
        Set(j, i, val);
    }
}
int Kingdom::Get(int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    else if (i > j) {
        return Arr[i * (i - 1) / 2 + j - 1];
    }
    else if (i < j) {
        return Arr[j * (j - 1) /2 + i - 1];
    } else 
    return 0;
}

void Kingdom::Display() {
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cout<< Kingdom::Get(i, j) << " ";
        }
        cout << endl;
    }
}

void validateInput(int argCount, char* argVal[])
{
    if (argCount > 1)
    {
        cout << "argv[1] = " << argVal[1] << endl;
    }
    else {
        cout << "No file name entered. Exiting...";
    }
}

int main(int argc, char* argv[])
{
    validateInput(argc, argv);
    
    ifstream infile(argv[1]); // open the file.
    
    if (infile.is_open() && infile.good())
    {
        string line;

        int nums[12];

        int n = 0;

        while (getline(infile, line))
        {
            stringstream linestream(line);
            while (linestream >> line)
            {
                nums[n] = stoi(line);
                n++;
            }
        }
        send_decree(nums, 0);
    }else {
        cout << "Failed to open file...";
    }
    
    int empire[V][V] = { {  0,50,30,100,10},
                         { 50, 0, 5, 20, 0}, 
                         { 30, 5, 0, 50, 0}, 
                         {100,20,50,  0,10}, 
                         { 10, 0, 0, 10, 0}, 
    };

    //dijkstra(empire, n);    
    return 0;
    
}