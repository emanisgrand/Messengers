#include "eman.h"   // utility and logic functions
#include "ImperialMessengers.h" // Empire constructor.

void spread_message(int file_v[], int src)
{
    int V = file_v[0];
    Empire M(V);

    int ptr = 0;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (i > j)
            {
                ptr++;
            }
            int val = file_v[ptr];
            M.Set(i, j, val);
        }
    }

    // M.Display();

    int* dist = new int[V]();
    bool* visited = new bool[V]();

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            int index = u < v ? u * (u - 1) / 2 + v - 1 : v * (v - 1) / 2 + u - 1;

            if (!visited[v] && file_v[index] && dist[u] != INT_MAX
                && dist[u] + file_v[index] < dist[v])
                dist[v] = dist[u] + file_v[index];
        }
    }

    display_min_time_spread(dist, visited, M.Size());
}

int minDistance(int dist[], bool visited[])
{
    int len = sizeof(dist); 
    int min = INT_MAX, min_index = 0, v = 0;
    while (dist[v] >= 0)
    {

        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
        v++;
    }     
    return min_index;
}

void display_min_time_spread(int dist[], bool visited[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = dist[i];
        }
    }
    cout << ans;
}

int* extract_values(char* argVal[])
{
    int* file_v = new int['nul'];
    ifstream infile(argVal[1]);
    if (infile.is_open() && infile.good())
    {
        int V = 0;
        string line;
        getline(infile, line);
        stringstream linestream(line);
        V = stoi(line);
        file_v = new int[V+1] {V};
        int i = 1;
        while (getline(infile, line))
        {
            stringstream linestream(line);
            while (linestream >> line)
            {
                file_v[i] = stoi(line);
                ++i;
            }
        }
        return file_v;
    }
    else {
        cout << "Failed to open file...";
    }
}

bool input_valid(int argCount, char* argVal[])
{
    if (argCount > 1)
    {
        ifstream infile(argVal[1]); // open the file.

        if (infile.is_open() && infile.good())
        {
            return true;
        }
        else {
            cout << "Failed to open file...";
        }
    }
    else {
        cout << "ERROR: No file name entered.\nhint: try again by calling the executable followed by the filename.extension.\n eg:\n\t $> EMartinezIM.exe test.txt" << endl;        
    }  
}

int printSolution(int time_distance[], int n)
{
    printf("Vertex   time_distanceance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, time_distance[i]);
    return 0;
}