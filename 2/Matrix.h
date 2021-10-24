#pragma once
class Matrix
{
private:
	int** array;
	int w;
	int h;
public:
	Matrix();
	Matrix(int w, int h);
	Matrix(int* array1D, int w, int h);
	int at(int i, int j) const;
	void setAt(int i, int j, int value);
	void print();
	Matrix& operator++();
	Matrix& operator--();
	Matrix operator++(int);
	Matrix operator--(int);
	~Matrix();
};