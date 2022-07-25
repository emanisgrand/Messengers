#include "LTMatrix.h"

void LTMatrix::setRowMajor(int i, int j, int x)
{
    if (i >= j)
    {
        int index = ((i * (i - 1)) / 2) + j - 1;
        A[index] = x;
    }
}

void LTMatrix::setColMajor(int i, int j, int x)
{
    if (i >= j)
    {
        int index = (n * (j - 1) - (( (j - 2) * (j - 1) ) /2 )) + (i - j);
        A[index] = x;
    }
}

int LTMatrix::getRowMajor(int i, int j)
{
    if (i >= j)
    {
        int index = ((i * (i - 1)) / 2) + j - 1;
        return A[index];
    }
    else
    {
        return 0;
    }
}

int LTMatrix::getColMajor(int i, int j)
{
    if (i >= j)
    {
        int index = (n * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j);
        return A[index];
    }
    else {
        return 0;
    }
}

void LTMatrix::Display(bool row)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                if (row) {
                    cout << getRowMajor(i, j) << " ";
                } else {
                    cout << getColMajor(i, j) << " ";
                }
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
/*
void newDijkstra(int n, int src)
{
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
*/