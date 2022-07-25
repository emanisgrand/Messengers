#include "LTMatrix.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#define V 5

using std::vector;
using std::string;
using std::ifstream;
using std::stringstream;
using std::getline;
using std::stoi;

class matrix {
private:
    int n;
    int* Arr;
public:
    matrix() // default constructor
    {
        n = 2;
        Arr = new int[2 * (2 + 1) / 2]{ 0 };
    }

    matrix(int n)
    {
        this->n = n;
        Arr = new int[n * (n + 1) / 2];
    }
    ~matrix() // destructor
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

void newDijkstra(int n, int src)
{
    matrix M(n);
    // initialize the array.
    int val = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            M.Set(i, j, val);
        }
    }

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
            if (!sptSet[v] && M.Get(u, v) && dist[u] != INT_MAX
                && dist[u] + M.Get(u, v) < dist[v])
                dist[v] = dist[u] + M.Get(u, v);
        }
    }

    printSolution(dist, V);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    // the maximum is the answer.
    printSolution(dist, V);
}


void matrix::Set(int i, int j, int val)
{
    if (i == j)
    {
        Arr[i * (i - 1) / 2 + j - 1] = 0;
    }
    else if (i > j)
    {
        Arr[i * (i - 1) / 2 + j - 1] = val;
    }
    else {
        Set(j, i, val);
    }
}
int matrix::Get(int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    else if (i > j) {
        return Arr[i * (i - 1) / 2 + j - 1];
    }
    else if (i < j) {
        return Get(j, i);
    } else 
    return 0;
}

void matrix::Display() {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {            
           /* if (i >= j)
                cout << Arr[i * (i - 1) / 2 + j - 1] << " ";
            else*/
                cout << Get(i, j) << " ";
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

        matrix M(nums[0]);
        
        int ptr = 1;
        for (int i = 1; i <= nums[0]; i++)
        {
            for (int j = 1; j <= nums[0]; j++)
            {
                while (nums[ptr] >= 0)
                {
                    int val = nums[ptr];
                    
                    
                    M.Set(i, j, val);
                    ptr++;
                }
                    
            }
        }
        

        
        
        M.Display();
        
        newDijkstra(n, 0);
    

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                
            }
        }
        

        
        /*
        while (getline(infile, line)) {
            
            stringstream linestream(line);  

            string line_values;

            while (linestream >> line_values) {

            }
        }
        */
    }
    else {
        cout << "Failed to open file...";
    }
    
    
    //newDijkstra(n, 0);
    

    int empire[V][V] = { {  0,50,30,100,10},
                         { 50, 0, 5, 20, 0}, 
                         { 30, 5, 0, 50, 0}, 
                         {100,20,50,  0,10}, 
                         { 10, 0, 0, 10, 0}, 
    };

    //dijkstra(empire, n);    
    return 0;
    
}