#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include "LinkedList.h"

using namespace std;




/*
brief: функция добавления элементов в конец списка
in: указатель на указатель последнего элемента списка, указатель на указатель первого элемента списка
out: none
*/
void addLast(nodeL **last, nodeL **first) 
{

	int val;
	cin >> val;
	nodeL *var = new nodeL;
	var->val = val;
	var->sled = NULL;
	if (*first == NULL) (*first) = var;
	else	(*last)->sled = var;
	*last = var;

}







/*
brief: функция добавления элемента в список
in: указатель на первый элемент списка, целочисленная переменная, отвечающая за номер элемента
out: none
*/
void addNumber(nodeL *first, int n){
	
	nodeL *var = new nodeL;
	nodeL *van = new nodeL;
	cout << "Введите элемент" << endl;
	int i = 1;
	int val;
	cin >> val;
	var->val = val;
	
	while (i<=n)
	{
		van = first;
		first = first->sled;
		if (first == NULL) return;
		i++;
	}
	var->sled = first;
	van->sled = var;
	return;
}





void addBefore(nodeL *first, int n){

	nodeL *var = new nodeL;
	cout << "Введите элемент" << endl;
	int val;
	cin >> val;
	
	while (first->val != n)
	{
		first = first->sled;
		if (first == NULL) return;
	}

	var->val = val;
	var->sled = first->sled;
	return;
}




void addAfter(nodeL *first, int n){

	nodeL *var = new nodeL;
	nodeL *van = new nodeL;
	cout << "Введите элемент" << endl;
	int val;
	cin >> val;
	var->val = val;
	while (first->val != n)
		{

			van = first;
			first = first->sled;
			if (first == NULL) return;
	
		} 

	var->sled = first->sled;
	van->sled = var;
	return;
}

/*
brief: функция добавления элементов в начало списка
in: указатель на указатель первого элемента списка
out: none
*/
void addBegin(nodeL **first,int val)
{ 
	
	nodeL *var = new nodeL;
	var->val = val;
	if (*first == NULL) var->sled = NULL;
	else {
		var->sled = *first;
		*first = var;
	}
}











/*
brief: функция удаления элементов с начала списка
in: указатель на указатель первого элемента списка
out: возвращение значения удаленного элемента
*/
int del(nodeL **first){
	int var = (**first).val;
	nodeL *adr = (**first).sled;
	delete *first;
	*first = adr;
	return var;
}















/*
brief: функция удаления элемента из списка
in: указатель на первый элемент списка, целочисленная переменная, отвечающая за номер элемента
out: none
*/
void DelNumber(nodeL *first, int n){
	nodeL *var = NULL;
	int i = 1;
	while (i<n)
		{
			var = first;
			first = first->sled;
			if (first == NULL) return;
			i++;
		}
	nodeL *val = first->sled;
	delete first;

	var->sled = val;
	return;
}







void DelZnach(nodeL *first, int n){
	nodeL *var = NULL;
	int i = 1;	
	while (first->val != n)
	{
		var = first;
		first = first->sled;
		if (first == NULL) return;
		i++;
	}
	nodeL *val = first->sled;
	delete first;

	var->sled = val;
	return;
}










/*
brief: функция вывода списка на экран
in: указатель на первый элемент списка
out: none
*/
void print(nodeL *first)
{
	do
	{
		cout << (*first).val;
		first = (*first).sled;
	} while (first != NULL);
	_getch();
}












/*
brief: функция создания меню для работы со списком
in: none
out: none
*/
void ListMenu()
{

	nodeL *first = NULL;
	nodeL *last = NULL;
	int n;
	int PunktMenu = 0;
	do {
		system("cls");
		cout << " _____________________________________________" << endl;
		cout << "| 1 |   Добавление элементов в конец списка   |" << endl;
		cout << "| 2 |   Добавление элементов в начало списка  |" << endl;
		cout << "| 3 |   Добавление узла по номеру             |" << endl;
		cout << "| 4 |   Удаление узла по номеру               |" << endl;
		cout << "| 5 |   Вывод элементов списка                |" << endl;
		cout << "| 6 |   Удаление узла по значению             |" << endl;
		cout << "| 7 |   Добавление элемента перед значением   |" << endl;
		cout << "| 8 |   Добавление элемента после значения    |" << endl;
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

				addLast(&last, &first);
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
			cout << "Введите элементы" << endl;
			int i = 0;
			int val;
			do {
				cin >> val;
				addBegin(&first, val);
				i++;

				} while (i != n);
			cout << "Элементы введены" << endl;
			_getch();
			break;
		}
		case 3:
		{
			int i = 1;
			int n;
			cout << "Введите номер позиции элемента" << endl;
			cin >> n;
			if (n == 1) addBegin(&first, n);
			else addNumber(first, n);
			break;
		}
		case 4:
		{
			int n;
			cout << "Введите номер элемента" << endl;
			cin >> n;
			if (n == 1)
			{
				cout << "Введите элемент" << endl;
				del(&first);
			}
			else DelNumber(first, n);
			break;
		}
		case 5:
		{
			cout << "Элементы списка: ";
			print(first);
			cout << endl;
			break;
		}
		case 6:
		{
			int n;
			cout << "Введите значение" << endl;
			cin >> n;
			if (first->val == n)
				{
					del(&first);
					break;
				}
			DelZnach(first, n);
			cout << "Элемент удален" << endl;
			break;
		}
		case 7:
		{
			cout << "Введите значение элемента" << endl;
			int n;
			cin >> n;
			if (first->val == n)
				{
					int val;
					cout << "Введите элемент" << endl;
					cin >> val;
					addBegin(&first, val);
					cout << "Элемент добавлен" << endl;
					_getch();
					break;
				}
			addBefore(first, n);
			cout << "Элемент добавлен" << endl;
			_getch();
			break;
		}
		case 8:
		{
			int n;
			cout << "Введите значение" << endl;
			cin >> n;
			addAfter(first, n);
		}
		}
		} while (PunktMenu != 0);
		_getch();
	}
