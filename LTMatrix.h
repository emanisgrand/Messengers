#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class LTMatrix {
private:
	int n;
	int* A;
public:
	LTMatrix(int n)
	{
		this->n = n;
		A = new int[n * (n + 1) / 2]; // nonzero elements.
	}
	~LTMatrix() { delete[] A; }		// class deconstructor
	void Display(bool row = true);
	void setRowMajor(int i, int j, int x);
	void setColMajor(int i, int j, int x);
	int getRowMajor(int i, int j);
	int getColMajor(int i, int j);
	int getN() { return n; }
};