#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <cstdio>
#include "knn.h"

using namespace std;

int throwMenu()
{
	system("cls");
	printf("Данная программа позволяет узнать группу человека по данным роста и веса!\n");
	printf("Выберите опцию:\n");
	printf("1. Загрузить данные из файла\n");
	printf("2. Определить группу по данным\n");
	printf("3. Выход\n");
	printf("-> ");
	int option = 0;
	cin >> option;
	return option;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int option = 0;
	Sample** s = NULL;
	int size = 0;
	while (true)
	{
		option = throwMenu();
		switch (option)
		{
			case 1: 
			{
				system("cls");
				printf("Введите путь до файла:\n");
				char path[256] = "";
				cin.get();
				cin.getline(path, 256);
				s = readDataFromFile(path, &size);
				if (s == NULL)
					printf("Неверный путь!\n\n\n\n");
				else printf("Файл загружен!\n\n\n\n");
				system("pause");
				break;
			}
			case 2:
			{
				system("cls");
				if (s == NULL)
				{
					printf("Данные не загружены! Сначала загрузите данные!\n");
					system("pause");
					break;
				}
				printf("Введите рост, вес и количество \"соседей\" через пробел.\n");
				printf("Дроби вводите через точку.\n");
				double d[2] = {0.0, 0.0};
				int k = 0;
				scanf_s("%lf %lf %d", &d[0], &d[1], &k);
				scanf_s("%*[^\n]");
				Vector* v = new Vector();
				v->size = 2;
				v->components = d;
				char* cl = getClass(v, k, s, size);
				if (cl == NULL) 
					printf("Ошибка!");
				else printf("Группа: %s\n\n\n\n", cl);

				system("pause");
				break;
			}
			case 3: 
			{
				return 0;
			}
		}
	}
	system("pause");
    return 0;
}

