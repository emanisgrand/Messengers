#include "ImperialMessengers.h"

int Empire::Get(int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    else if (i > j) {
        return node_array[i * (i - 1) / 2 + j - 1];
    }
    else if (i < j) {
        return node_array[j * (j - 1) / 2 + i - 1];
    }
    else
        return 0;
}

void Empire::Set(int i, int j, int val)
{
    int index = i * (i - 1) / 2 + j - 1;
    if (i == j)
    {
        node_array[index] = 0;
    }
    else if (i > j)
    {
        node_array[index] = val;
    }
    else {
        Set(j, i, val);
    }
}


void Empire::Display() {
    for (int i = 1; i <= Size(); i++)
    {
        for (int j = 1; j <= Size(); j++)
        {
            cout << Empire::Get(i, j) << " ";
        }
        cout << endl;
    }
}

int Empire::Size(){
    return size;
}