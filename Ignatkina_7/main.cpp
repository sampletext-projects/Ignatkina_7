#include <iostream>

using namespace std;

void read_mas(int* mas, int size)
{
	cout << "mas: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] = ";
		cin >> mas[i];
	}
}

void write_mas(int* mas, int size)
{
	cout << "mas: ";
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}


int count_positive(int* mas, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] >= 0)
		{
			count++;
		}
	}
	return count;
}


int count_negative(int* mas, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] < 0)
		{
			count++;
		}
	}
	return count;
}


void transform(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (mas[i] >= 0)
		{
			mas[i] = sqrt(mas[i]);
		}
		else
		{
			mas[i] *= mas[i];
		}
	}
}

void remove_over_n(int** mas, int& size, int n)
{
	int index = 0;
	int* src = *mas; //исходный массив
	int k = 0;//количество удалённых элементов
	for (; index < size; index++)
	{
		src[index - k] = src[index];
		if (abs(src[index]) > n)
		{
			k++;
		}
	}

	size = size - k;//меняем размер

	int* dest = new int[size]; //новый массив
	index = 0;
	for (; index < size; index++)
	{
		dest[index] = src[index];
	}
	*mas = dest; //пересохраняем массив
}

void print_menu()
{
	cout << "1. Ввод массива" << endl;
	cout << "2. Вывод массива" << endl;
	cout << "3. Найти количество положительных элементов" << endl;
	cout << "4. Найти количество отрицательных элементов" << endl;
	cout << "5. Преобразовать элементы (SQRT(POS); SQR(NEG))" << endl;
	cout << "6. Удалить элементы, которые больше N" << endl;
	cout << "0. Выход" << endl;
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Программу сделала Игнаткина Валерия студент группы УТН-111" << "\n";
	cout << "Программа по манипулированию массивом с помощью функций" << endl;
	int size = -1;
	int* mas = 0;


	int t;
	do
	{
		print_menu();
		cin >> t;
		switch (t)
		{
		case 1:
			{
				cout << "Введите размер массива: ";
				cin >> size;

				mas = new int[size];
				read_mas(mas, size);
				break;
			}
		case 2:
			{
				if (size == -1)
				{
					cout << "Перед выводом необходимо ввести массив!" << endl;
					break;
				}
				write_mas(mas, size);
				break;
			}
		case 3:
			{
				if (size == -1)
				{
					cout << "Перед поиском необходимо ввести массив!" << endl;
					break;
				}
				int positive = count_positive(mas, size);
				cout << "Количество положительных: " << positive << endl;
				break;
			}
		case 4:
			{
				if (size == -1)
				{
					cout << "Перед поиском необходимо ввести массив!" << endl;
					break;
				}
				int negative = count_negative(mas, size);
				cout << "Количество отрицательных: " << negative << endl;
				break;
			}
		case 5:
			{
				if (size == -1)
				{
					cout << "Перед преобразованием необходимо ввести массив!" << endl;
					break;
				}
				transform(mas, size);
				cout << "Массив преобразован!" << endl;
				break;
			}
		case 6:
			{
				if (size == -1)
				{
					cout << "Перед удалением необходимо ввести массив!" << endl;
					break;
				}
				int n;
				cout << "Введите число N: ";
				cin >> n;
				remove_over_n(&mas, size, n);
				cout << "Элементы удалены!" << endl;
				break;
			}
		}
	}
	while (t != 0);


	system("pause");

	return 0;
}
