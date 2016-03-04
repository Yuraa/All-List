#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include "queue.h"

using namespace std;




/*
brief: функция добавления элементов в конец очереди
in: указатель на указатель последнего элемента очереди, указатель на указатель первого элемента очереди
out: none
*/
void add(nodeQ **last, nodeQ **first) //добавление элемента
{
	int val;
	cin >> val;
	nodeQ *var = new nodeQ;
	var->val = val;
	var->sled = NULL;
	if (*first == NULL) (*first) = var;
	else	(*last)->sled = var;
	*last = var;
	
}






/*
brief: функция удаления элементов с начала очереди
in: указатель на указатель первого элемента очереди
out: возвращение значения удаленного элемента
*/
int del(nodeQ **first){
	int var = (**first).val;
	nodeQ *adr = (**first).sled;
	delete *first;
	*first = adr;
	return var;
}





/*
brief: функция вывода очереди на экран
in: указатель на первый элемент очереди
out: none
*/
void print(nodeQ *first)
{
	do
	{
		cout << (*first).val;
		first = (*first).sled;
	} while (first != NULL);
	_getch();
}


/*
brief: функция создания меню для работы с очередью
in: none
out: none
*/
void QueueMenu()
{

	nodeQ *first = NULL;
	nodeQ *last = NULL;
	int n;
	int PunktMenu = 0;
	do {
		system("cls");
		cout << " _____________________________________________" << endl;
		cout << "| 1 |   Добавление элементов в конец очереди  |" << endl;
		cout << "| 2 |   Удаление элемента из начала очереди   |" << endl;
		cout << "| 3 |   Вывод элементов                       |" << endl;
		cout << "| 0 |   Вернуться в предыдущее меню           |" << endl;
		cout << "|___|_________________________________________|" << endl;
		cout << "|                                             |" << endl;
		cout << "|   Выберите один из режимов и нажмите Enter  |" << endl;
		cout << "|_____________________________________________|" << endl;
		cin >> PunktMenu;
		switch (PunktMenu)
		{
			case 1:
			{
				cout << "Введите количество элементов" << endl;
				cin >> n;
				cout << "Введите элементы" << endl;
				int i = 0;
				do {
	
					add(&last, &first);
					i++;

					} while (i != n);
				cout << "Элементы введены" << endl;
				_getch();
				break;
			}
			case 2:
			{
				cout << "Введите количество элементов" << endl;
				cin >> n;
				for (int i = 0; i < n; i++)	del(&first);
				cout << "Элементы удалены" << endl;
				_getch();
				break;
			}
			case 3:
			{
				cout << "Элементы очереди: ";
				print(first);
				cout << endl;
				break;
			}
		}
	} while (PunktMenu != 0);
		_getch();
	}





