// TransportMatrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>


void init(int** matrix, int size);
void print(int** matrix, int size);
void transport(int** matrix, int size);
int** create_matrix(int size);
int** rotate90(int** matrix, int size);

int main()
{
	srand(time(NULL));
	int custom_size = 4;
	int** custom_matrix = create_matrix(custom_size);
	init(custom_matrix, custom_size);
	print(custom_matrix, custom_size);
	//transport(custom_matrix, custom_size);
	//print(custom_matrix, custom_size);
	print(rotate90(custom_matrix, custom_size), custom_size);
	return 0;
}

void init(int** matrix, int size) {
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			*(*(matrix + i) + j) = count++;		
		}
	}
}

void print(int** matrix, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%3d", *(*(matrix + i) + j));
		}
		printf("\n");
	}
	printf("I finished\n");
}

void transport(int** matrix, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			if (i > j) {
				int temp = *(*(matrix + i) + j);
				*(*(matrix + i) + j) = *(*(matrix + j) + i);
				*(*(matrix + j) + i) = temp;
			}
		}
	}
}

int** create_matrix(int size) {
	int** my_matrix = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		*(my_matrix + i) = (int*) malloc(size * sizeof(int));
		for (int j = 0; j < size; j++)
		{
			*(*(my_matrix + i) + j) = 0;
		}
	}
	return my_matrix;
}

int** rotate90(int** matrix, int size) {
	int** new_matrix = create_matrix(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			*(*(new_matrix + j) + size - 1 - i) = *(*(matrix + i) + j);
		}
	}
	return new_matrix;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.