#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <cmath>

#include "Sort.h"
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
		int *mass = NULL;
		int *NumStr = NULL;
		int Str = 0;
		int Col = 0;

		GenMassTwoDimMalloc(mass, &Str, &Col, 0, 20);

		if (mass == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Номера строк, элементы каждой из которых образуют монотонно убывающую последовательность:\n");
			int Ind = 1;
			int Sum = 0;
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col - 1; j++)
				{
					if (*(mass + i*Col + j) <= *(mass + i*Col + j + 1))
						Ind = 0;
				}
				if (Ind == 1)
				{
					NumStr = (int *)realloc(NumStr, (Sum + 1) * sizeof(int));
					*(NumStr + Sum) = i;
					printf("%d\n", *(NumStr + Sum));
					Sum++;
				}
				Ind = 1;
			}
			printf("\n");
		}
		free(mass);
		free(NumStr);
	}
	else if (N1 == 3)
	{
		int *mass = NULL;
		int *ProstCh = NULL;
		int Str = 0;
		int Col = 0;

		GenMassTwoDimMalloc(mass, &Str, &Col, 0, 20);

		if (mass == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			int Ind = 0;
			int Sum = 0;
			printf("\nПростые числа в матрице:\n");
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					for (int z = 2; z < *(mass + i*Col + j); z++)
					{
						if (*(mass + i*Col + j) % z == 0) Ind = 1;
					}
					if (Ind == 0 && *(mass + i*Col + j) > 1)
					{
						ProstCh = (int *)realloc(ProstCh, (Sum + 1) * sizeof(int));
						*(ProstCh + Sum) = *(mass + i*Col + j);
						printf("%d\t", *(ProstCh + Sum));
						Sum++;
					}
					Ind = 0;
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	else if (N1 == 4)
	{
		int *mass = NULL;
		int *RazlCh = NULL;
		int Str = 0;
		int Col = 0;

		GenMassTwoDimMalloc(mass, &Str, &Col, 0, 20);

		if (mass == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			RazlCh = (int *)malloc(sizeof(int));

			*RazlCh = 0;

			int Ind = 0;
			int Sum = 0;
			printf("\nРазличные чисела в матрице:\n");

			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					for (int z = 0; z <= Sum; z++)
					{
						if (*(RazlCh + z) == *(mass + i*Col + j))
						{
							Ind = 1;
						}
					}
					if (Ind == 0)
					{
						RazlCh = (int *)realloc(RazlCh, (Sum + 1) * sizeof(int));
						*(RazlCh + Sum) = *(mass + i*Col + j);
						Sum++;
					}
					Ind = 0;
				}
			}

			bubbleSortInc(RazlCh, Sum);

			for (int i = 0; i < Sum; i++)
				printf("%d\t", *(RazlCh + i));

			printf("\nКоличество различных чисел в матрице N = %d\n", Sum);
			printf("\n");
		}
	}
	else if (N1 == 5)
	{
		int *mass = NULL;
		int *Chis = NULL;
		int *Indic = NULL;
		int *RazlCh = NULL;
		int Str = 0;
		int Col = 0;

		GenMassTwoDimMalloc(mass, &Str, &Col, 1, 4);

		if (mass == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					bubbleSortInc(&(*(mass + i*Col)), Col);
				}
			}
			printf("\n");

			printf("\nОтсортированный построчно массив:\n");
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
					printf("%d\t", *(mass + i*Col + j));
				printf("\n");
			}
			printf("\n");

			RazlCh = (int *)malloc(sizeof(int));

			*RazlCh = 0;

			int Ind = 0;
			int Sum = 0;
			printf("\nРазличные чисела в матрице:\n");

			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					for (int z = 0; z <= Sum; z++)
					{
						if (*(RazlCh + z) == *(mass + i*Col + j))
						{
							Ind = 1;
						}
					}
					if (Ind == 0)
					{
						RazlCh = (int *)realloc(RazlCh, (Sum + 1) * sizeof(int));
						*(RazlCh + Sum) = *(mass + i*Col + j);
						Sum++;
					}
					Ind = 0;
				}
			}

			bubbleSortInc(RazlCh, Sum);

			for (int i = 0; i < Sum; i++)
				printf("%d\t", *(RazlCh + i));

			printf("\nКоличество различных чисел в матрице N = %d\n", Sum);

			printf("\nЧисла встречающиеся во всех строках\n");

			Indic = (int *)malloc(Str*sizeof(int));

			Ind = 1;
			for (int z = 0; z < Sum; z++)
			{
				for (int i = 0; i < Str; i++)
				{
					*(Indic + i) = 0;
					for (int j = 0; j < Col; j++)
					{
						if (*(RazlCh + z) == *(mass + i*Col + j))
							*(Indic + i) = 1;
					}
					//printf("%d\t", *(Indic + i));
					if (*(Indic + i) == 0) Ind = 0;
				}
				//printf("\n");
				if (Ind == 1) printf("%d\t", *(RazlCh + z));
			}
			printf("\n");
		}
	}
	system("pause");
}