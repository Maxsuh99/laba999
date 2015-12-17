#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "Vector.h"
#include "massiv.h"
#include "Errors.h"

using namespace std;

template <class T>
void getLessThan(Massiv<T>& mas, T val)
{
	for (int i = 0; i < mas.a_size; i++)
	{
		if (mas.a_mass[i] < val)
		{
			cout << mas.a_mass[i] << " ";
		}
	}
	cout << endl;
}

void main()
{
	try{
		setlocale(LC_CTYPE, "RUSSIAN");

		//Massiv<int> mas4(3), mas5(4);  // ���������� ��� ��������� (�� ��������� �������)
		//mas4*mas5;                     //

		Massiv<int> mas(3);             // ���������� : ������ �� ������ ������
		mas[4];


		//Massiv<int> mas(12);              //����������: ������ �� ���������� ������

		//Massiv<int> mas;                  //����������: ������������ �����, �.�. ������ ����� ������������ ������
		//mas.print();


		//system("pause");

	}
	catch (Error *e)
	{
		e->show();
	}
};
