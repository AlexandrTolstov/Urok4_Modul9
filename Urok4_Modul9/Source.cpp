#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <cmath>

#include "GenMass.h"

using namespace std;


void main() {

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N1 = 0;
	printf("Введите номер задания\nN = ");

	scanf("%d", &N1);

	if (N1 == 1)
	{
		int *mass = NULL;
		int Str = 0;
		int Col = 0;

		GenMassTwoDimMalloc(mass, &Str, &Col, 0, 1);

		if (mass == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Количество строк в которой есть хотя бы 1 нуль:\n");
			int Ind = 0;
			int Sum = 0;
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					if (*(mass + i*Col + j) == 0)
						Ind = 1;
				}
				if (Ind == 1)
					Sum++;
				Ind = 0;
			}
			printf("Str = %d", Sum);
			printf("\n");
		}
		free(mass);
	}
	else if (N1 == 2)
	{
		
	}
	else if (N1 == 3)
	{
		
	}
	else if (N1 == 4)
	{
		
	}
	else if (N1 == 5)
	{
		
	}
	else if (N1 == 6)
	{
		
	}
	else if (N1 == 7)
	{
		
	}
	else if (N1 == 8)
	{
		
	}
	else if (N1 == 9)
	{
		
	}
	else if (N1 == 10)
	{
		
	}
	else if (N1 == 11)
	{
		
	}
	else if (N1 == 12)
	{
	
	}
	else if (N1 == 13)
	{

	}
	system("pause");
}