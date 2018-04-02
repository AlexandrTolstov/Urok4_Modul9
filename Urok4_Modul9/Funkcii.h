#include <stdio.h>
using namespace std;

int f_sec(int h, int m, int s)
{
	return s + 60 * (m + 60 * h);
}

void LackyNum(int *mass, int size)
{
	int NumFirst, NumSecond;

	int MassN[6] = { 0 };
	int Num = 0;
	int Num1 = 0;

	for (int i = 0; i < size; i++)
	{
		Num1 = *(mass + i);
		for (int j = 5; j >= 0; j--)
		{
			Num = Num1 % 10;
			MassN[j] = Num;
			Num1 = Num1 / 10;
		}
		NumFirst = MassN[0] + MassN[1] + MassN[2];
		NumSecond = MassN[3] + MassN[4] + MassN[5];

		if (NumFirst == NumSecond)
		{
			cout << *(mass + i) << "\t";
		}
	}
}

void PolindNum(int *mass, int size)
{
	int MassN[6] = { 0 };
	int Num = 0;
	int Num1 = 0;

	for (int i = 0; i < size; i++)
	{
		Num1 = *(mass + i);
		for (int j = 5; j >= 0; j--)
		{
			Num = Num1 % 10;
			MassN[j] = Num;
			Num1 = Num1 / 10;
		}

		if (MassN[0] == MassN[5] && MassN[1] == MassN[4] && MassN[2] == MassN[3])
		{
			cout << *(mass + i) << "\t";
		}
	}
}

void MaxNum(int *mass, int size)
{
	int Max = 0;

	for (int i = 0; i < size; i++)
	{
		if (Max < *(mass + i)) Max = *(mass + i);
	}

	cout << "Max = " << Max << endl;
}

/*Количество дней в месяце с учетов високосных и не високосных годов*/
int NumOfDay(int *g, int *m)
{
	int k;
	switch (*m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		k = 31;
		break;
	}
	case 2:
	{
		if (*g % 4 == 0 && *g % 100 != 0 || *g % 400 == 0) k = 29;
		else k = 28;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		k = 30;
		break;
	}

	default:
		break;
	}
	return k;
}

/*Следующая дата*/
void PrDate(int *g, int *m, int *d)
{
	if (*d == 1 && *m == 1)
	{
		*m = 1;
		*g = *g - 1;
		*d = NumOfDay(g, m);
	}
	else if (*d == 1)
	{
		*m = *m - 1;
		*d = NumOfDay(g, m);
	}
	else *d = *d - 1;
}

/*Предыдущая дата*/
void NextDate(int *g, int *m, int *d)
{
	if (*d == NumOfDay(g, m) && *m == 12)
	{
		*m = 1;
		*d = 1;
		*g = *g + 1;
	}
	else if (*d == NumOfDay(g, m))
	{
		*m = *m + 1;
		*d = 1;
	}
	else *d = *d + 1;
}

/*Наибольшее общее кратное алгоритм Евклида*/
int KratEvklid(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
			a = a%b;
		else b = b%a;
	}
	return a + b;
}

/*Расчет количесва букв в предложении*/
int NumOfL(char *Pr)
{
	int i = 0;
	int n = 0;
	while (*(Pr + i) != '.')
	{
		cout << *(Pr + i);
		n++;
		i++;
	}
	cout << endl;
	return n;
}

/*Расчет количесва заданной буквы в предложении*/
int NumOfSignL(char *Pr, char L)
{
	int i = 0;
	int n = 0;
	while (*(Pr + i) != '.')
	{
		i++;
		if (*(Pr + i) == L)
		{
			n++;
		}
	}
	return n;
}

/*Вывод предложения*/
void PrintPredl(char *Pr)
{
	int i = 0;
	while (*(Pr + i) != '.')
	{
		cout << *(Pr + i);
		i++;
	}
	cout << endl;
}

/*Нахождение буквы в двух предложениях и выяснение в каком из них ее большне*/
void SravnPredl(char *Pr1, char *Pr2, char L)
{
	int n1, n2;

	n1 = NumOfSignL(Pr1, L);
	n2 = NumOfSignL(Pr2, L);

	if (n1 > n2) cout << "В первом предложении букв \"" << L << "\" больше чем во втором" << endl;
	else cout << "Во втором предложении букв \"" << L << "\" больше чем в первом" << endl;
}

/*__________________________________________________________________________________________________________*/
/*Урок 4 Модуль 7*/

/*Копирование строк в новый массив*/
void KopyStr(char *Str1, char *Str2)
{
	for (int i = 0; i < strlen(Str1); i++)
	{
		*(Str2 + i) = *(Str1 + i);
		cout << *(Str2 + i);
	}
	cout << endl;
}

/*Копирование строк в новый массив с переворачиванием*/
void KopyStrInvert(char *Str1, char *Str2)
{
	int j = strlen(Str1);
	int z = strlen(Str1);
	for (int i = 0; i < z; i++)
	{
		*(Str2 + j - 1) = *(Str1 + i);
		j--;
	}

	for (int i = 0; i < z; i++)
	{
		cout << *(Str2 + i);
	}
	cout << endl;
}