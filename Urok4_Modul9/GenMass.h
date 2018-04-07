#include <stdio.h>
#include <iostream>

using namespace std;

void GenMass(int *mass, int Razm) {
	cout << "��� ������:" << endl;
	for (int i = 0; i < Razm; i++)
	{
		*(mass + i) = 1 + rand() % 99;
		cout << *(mass + i) << "\t";
	}
	cout << endl;
}

void GenMassD(double *mass, int Razm) {
	cout << "��� ������:" << endl;
	for (int i = 0; i < Razm; i++)
	{
		*(mass + i) = 1 + rand() % 99;
		cout << *(mass + i) << "\t";
	}
	cout << endl;
}

void GenMass(int *mass, int Razm, int Min, int Max) {
	cout << "��� ������:" << endl;
	for (int i = 0; i < Razm; i++)
	{
		*(mass + i) = Min + rand() % (Max - Min);
		cout << *(mass + i) << "\t";
	}
	cout << endl;
}

void GenMassD(double *mass, int Razm, double Min, double Max) {
	cout << "��� ������:" << endl;
	for (int i = 0; i < Razm; i++)
	{
		*(mass + i) = Min + rand() % (int(Max - Min));
		cout << *(mass + i) << "\t";
	}
	cout << endl;
}

void GenMassTwoDim(int **mass, int Str, int Col, int Min, int Max) {
	cout << "��� ������:" << endl;
	for (int i = 0; i != Str; i++)
	{
		*(mass + i) = new int[Str];
	}

	for (int i = 0; i < Str; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			*(*(mass + i) + j) = Min + rand() % (Max - Min);
			cout << *(*(mass + i) + j) << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void GenMassTwoDimDouble(double **mass, int Str, int Col, int Min, int Max) {
	cout << "��� ������:" << endl;
	for (int i = 0; i != Str; i++)
	{
		*(mass + i) = new double[Str];
	}

	for (int i = 0; i < Str; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			*(*(mass + i) + j) = Min + rand() % (Max - Min);
			cout << *(*(mass + i) + j) << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

/*��������� ���������� ������� ������ malloc*/
void GenMassTwoDimMalloc(int *&mass, int *Str, int *Col, int Min, int Max)
{
	srand(time(0));
	printf("������� ��������� ����� ������� Str = ");
	scanf("%d", &*Str);
	printf("������� ��������� �������� ������� Col = ");
	scanf("%d", &*Col);

	mass = (int *)malloc(((*Str)*(*Col)) * sizeof(int));

	if (mass == NULL)
	{
		printf("������ �� ��������");
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int i = 0; i < *Str; i++)
		{
			for (int j = 0; j < *Col; j++)
			{
				*(mass + i*(*Col) + j) = Min + rand() % (Max - Min + 1);
				printf("%d\t", *(mass + i*(*Col) + j));
			}
			printf("\n");
		}
	}
}

/*��������� ���������� ������� ������ malloc*/
void GenMassMalloc(int *&mass, int *N, int Min, int Max)
{
	srand(time(0));
	printf("������� ���������� ��������� ������� N = ");
	scanf("%d", &*N);

	mass = (int *)malloc((*N) * sizeof(int));

	if (mass == NULL)
	{
		printf("������ �� ��������");
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int i = 0; i < *N; i++)
		{
			*(mass + i) = Min + rand() % (Max - Min);
			printf("%d\t", *(mass + i));
		}
	}
}

/*����� �������� ������������� �������� �������*/

int SumMaxInd(int **mass, int Str, int Col)
{
	int Max = **mass;
	int SumInd = 0;
	int IndI = 0;
	int IndJ = 0;

	for (int i = 0; i < Str; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Max < *(*(mass + i) + j))
			{
				Max = *(*(mass + i) + j);
				SumInd = i + j;
				IndI = i;
				IndJ = j;
			}
		}
	}
	cout << "SumInd = " << IndI << " + " << IndJ << " = " << SumInd << endl;
	return SumInd;
}

/*������� �������������� ��������� �������*/

int SredArMass(int **mass, int Str, int Col)
{
	int Sum = 0;
	int SredAr = 0;

	for (int i = 0; i < Str; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			Sum = Sum + *(*(mass + i) + j);
		}
	}

	SredAr = Sum / (Str*Col);
	return SredAr;
}

/*���������� ������ ��� ����� ��������� �������� �������*/

void MassSumCol(int **mass, int Str, int Col, int *OdMass)
{
	for (int j = 0; j < Col; j++)
	{
		*(OdMass + j) = 0;
		for (int i = 0; i < Str; i++)
		{
			*(OdMass + j) = *(OdMass + j) + *(*(mass + i) + j);
		}
		cout << *(OdMass + j) << "\t";
	}
	cout << endl;
}

/*����� ������������� � ������������ ��������� �������*/

int SumMaxMin(int **mass, int Str, int Col)
{
	int Max = **mass;
	int MaxIndI = 0;
	int MaxIndJ = 0;
	int Min = **mass;
	int MinIndI = 0;
	int MinIndJ = 0;

	for (int i = 0; i < Str; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Max < *(*(mass + i) + j))
			{
				Max = *(*(mass + i) + j);
				MaxIndI = i;
				MaxIndJ = j;
			}
			if (Min > *(*(mass + i) + j))
			{
				Min = *(*(mass + i) + j);
				MinIndI = i;
				MinIndJ = j;
			}
		}
	}
	cout << "Max = Mass[" << MaxIndI << "][" << MaxIndJ << "] = " << Max << endl;
	cout << "Min = Mass[" << MinIndI << "][" << MinIndJ << "] = " << Min << endl;
	return Max + Min;
}

/*������������ �������� ����� �������*/

void SumMaxMin(int **mass, int Str, int Col, int *MaxMass)
{
	for (int i = 0; i < Str; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (*(MaxMass + i) < *(*(mass + i) + j))
			{
				*(MaxMass + i) = *(*(mass + i) + j);
			}
		}
		cout << *(MaxMass + i) << endl;
	}
}

//void MassRazlChisla(int *&RazlCh, int *N, int *&mass, int Str, int Col)
//{
//	int Ind = 0;
//	printf("\n��������� ������ � �������:\n");
//
//	for (int i = 0; i < Str; i++)
//	{
//		for (int j = 0; j < Col; j++)
//		{
//			for (int z = 0; z <= *N; z++)
//			{
//				if (*(&RazlCh + z) == *(&mass + i*Col + j))
//				{
//					Ind = 1;
//				}
//			}
//			if (Ind == 0)
//			{
//				RazlCh = (int *)realloc(RazlCh, (*N + 1) * sizeof(int));
//				*(RazlCh + *N) = *(mass + i*Col + j);
//				*N++;
//			}
//			Ind = 0;
//		}
//	}
//}
