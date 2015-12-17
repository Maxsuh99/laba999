#pragma once
#include <iostream>
#include "Errors.h"
#include "Vector.h"

using namespace std;

template <class T>
class Massiv
{
public:
	T *a_mass;
	int a_size;
public:


	Massiv(void)
	{
		a_mass = NULL;
		a_size = 0;
	};
	Massiv(int size)
	{
		a_mass = new T[size];
		a_size = size;
		if (a_size <= 0 || a_size > 10)
		{
			throw new IncorrectSize("Введен размер ", size);
		}
		//a_mass = NULL;
		//for (int i = 0; i < a_size; i++)
		//{
		//	a_mass[i] = NULL;
		//}
	};
	Massiv(T *a, int size)
	{
		a_mass = new T[size];
		if (a_array == NULL) throw new Overflow();
		for (int i = 0; i < size; i++)
		{
			a_mass[i] = a[i];
			a_size = size;
		}
	};
	Massiv(Massiv& a_)
	{
		a_mass = new T[a_.a_size];
		a_size = a_.a_size;
		for (int i = 0; i < a_size; i++)
		{
			a_mass[i] = a_.a_mass[i];
		}
	};

	~Massiv(void)
	{
		delete[]a_mass;
		a_size = 0;
	};



	void print()
	{
		if (a_size == 0) throw new IncorrectOutput("Некорректный размер");
		for (int i = 0; i < a_size; i++)
		{
			cout << a_mass[i];
			cout << " ";
		}
		cout << endl;
	};
	void push(T x)
	{
		if (a_size == 0)
		{
			a_size = 1;
			a_mass = new T[a_size];
			a_mass[0] = x;
			return;
		}

		T *a = new T[a_size];
		for (int i(0); i< a_size; i++)
			a[i] = a_mass[i];
		delete[]a_mass;
		a_mass = new T[++a_size];
		for (int i(0); i<a_size - 1; i++)
			a_mass[i] = a[i];
		delete[]a;
		a_mass[a_size - 1] = x;

	}

	Massiv operator * (Massiv arrayB)
	{
		if (arrayB.a_size == a_size)
		{
			Massiv massC(a_size);
			for (int i = 0; i < a_size; i++)
			{
				massC.a_mass[i] = a_mass[i] * arrayB.a_mass[i];
			}
			return massC;
		}
		else
		{
			//cout << "Размеры не совпадают " << endl;
			throw new MultiplicationError("Размеры не совпадают ");
		}
	}

	Massiv operator [] (int nIndex)
	{
		if (nIndex >= 0 && nIndex < a_size)
		{
			return a_mass[nIndex];
		}
		else
		{
			throw new IncorrectIndex("Введен индекс: ", nIndex);
			//cout << "Введён неправильный индекс" << endl;
		}
	}

	operator int()
	{
		return a_size;
	}

	bool operator == (Massiv massB)
	{
		if (massB.a_size == a_size)
		{
			for (int i = 0; i < a_size; i++)
			{
				if (a_mass[i] != massB.a_mass[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	int operator <(Massiv massB)
	{
		return a_size <massB.a_size;
	}
	int operator <= (Massiv massB)
	{
		if (massB.a_size == a_size)
		{
			int summA = 0;
			int summB = 0;
			for (int i = 0; i < a_size; i++)
			{
				summA += a_mass[i];
				summB += massB.a_mass[i];
			}
			if (summA > summB)
			{
				return 1;
			}
			if (summA == summB)
			{
				return 0;
			}
			if (summA < summB)
			{
				return -1;
			}
		}
		else
		{
			return -2;
		}
	}
};