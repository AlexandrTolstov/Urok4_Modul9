enum Sort { Increase, Decrease };

// Сортировка пузырьком

void bubbleSortInc(int *mass, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (*(mass + j) < *(mass + j - 1))
			{
				int temp = *(mass + j - 1);
				*(mass + j - 1) = *(mass + j);
				*(mass + j) = temp;
			}
		}
	}
}

void bubbleSortDec(int *mass, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (*(mass + j) > *(mass + j - 1))
			{
				int temp = *(mass + j - 1);
				*(mass + j - 1) = *(mass + j);
				*(mass + j) = temp;
			}
		}
	}
}

void bubbleSort(int *mass, int size, Sort Vib)
{
	if (Vib == Increase)
		bubbleSortInc(mass, size);
	else if (Vib == Decrease)
		bubbleSortDec(mass, size);
}

// Сортировка вставками

void VstavSortInc(int *mass, int size) {
	int temp, item;
	for (int i = 0; i < size; i++)
	{
		temp = *(mass + i);
		item = i - 1;
		while (item >= 0 && *(mass + item) > temp)
		{
			*(mass + item + 1) = *(mass + item);
			*(mass + item) = temp;
			item--;
		}
	}
}

void VstavSortDec(int *mass, int size) {
	int temp, item;
	for (int i = 0; i < size; i++)
	{
		temp = *(mass + i);
		item = i - 1;
		while (item >= 0 && *(mass + item) < temp)
		{
			*(mass + item + 1) = *(mass + item);
			*(mass + item) = temp;
			item--;
		}
	}
}

void VstavSort(int *mass, int size, Sort Vib)
{
	if (Vib == Increase)
		VstavSortInc(mass, size);
	else if (Vib == Decrease)
		VstavSortDec(mass, size);
}