#pragma once
#include <iostream>
#include "Errors.h"
#define NIL 0x00000000
using namespace std;
class Vector
{
protected:
	int v_size;
	int * v_vector;
	int v_error;

public:
	enum
	{
		e_no_error, e_memory_full, e_out_of_range
	};
	Vector(void)
	{
		v_vector = NIL;
		v_size = 0;
		v_error = e_no_error;
	};
	Vector(int size, int *a)
	{
		v_vector = new int[size];
		v_size = size;
		for (int i = 0; i < v_size; i++)
		{
			v_vector[i] = a[i];
		}


		v_error = e_no_error;
	};
	/*~Vector(void)
	{
	delete[] v_vector;
	v_size = 0;
	};*/
	int getError(void)
	{
		return v_error;
	};
	int getSize(void)
	{
		return v_size;
	};
	bool searchElement(int value)
	{
		for (int i = 0; i < v_size; i++)
		{
			if (v_vector[i] == value)
			{
				return true;
			}
		}
		return false;
	};
	void setRandomAll(void)
	{
		for (int i = 0; i < v_size; i++)
		{
			v_vector[i] = rand() % 8;
		}
	};
	void setValue(int position, int value)
	{
		if (position < 0 || position > v_size)
		{
			v_error = e_out_of_range;
			return;
		}
		v_vector[position] = value;
	};
	/*friend ostream & operator<<(ostream &os, Vector & a)
	{
	a.printVector();
	return os;
	}*/
	void printVector(void)
	{
		for (int i = 0; i < v_size; i++)
		{
			std::cout << v_vector[i] << " ";
		}
		std::cout << std::endl;
	}


	int operator <(Vector v)
	{
		return  v_size < v.v_size;
	}
	friend ostream & operator << (ostream &os, Vector &dt);

};
ostream & operator << (ostream &os, Vector &dt)
{
	dt.printVector();
	/*for (int i = 0; i < dt.v_size; i++)
	{
	os << dt.v_vector[i] << " ";
	}*/
	return os;
}