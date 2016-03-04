#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include "LinkedList.h"

using namespace std;




/*
brief: ������� ���������� ��������� � ����� ������
in: ��������� �� ��������� ���������� �������� ������, ��������� �� ��������� ������� �������� ������
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
brief: ������� ���������� �������� � ������
in: ��������� �� ������ ������� ������, ������������� ����������, ���������� �� ����� ��������
out: none
*/
void addNumber(nodeL *first, int n){
	
	nodeL *var = new nodeL;
	nodeL *van = new nodeL;
	cout << "������� �������" << endl;
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
	cout << "������� �������" << endl;
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
	cout << "������� �������" << endl;
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
brief: ������� ���������� ��������� � ������ ������
in: ��������� �� ��������� ������� �������� ������
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
brief: ������� �������� ��������� � ������ ������
in: ��������� �� ��������� ������� �������� ������
out: ����������� �������� ���������� ��������
*/
int del(nodeL **first){
	int var = (**first).val;
	nodeL *adr = (**first).sled;
	delete *first;
	*first = adr;
	return var;
}















/*
brief: ������� �������� �������� �� ������
in: ��������� �� ������ ������� ������, ������������� ����������, ���������� �� ����� ��������
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
brief: ������� ������ ������ �� �����
in: ��������� �� ������ ������� ������
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
brief: ������� �������� ���� ��� ������ �� �������
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
		cout << "| 1 |   ���������� ��������� � ����� ������   |" << endl;
		cout << "| 2 |   ���������� ��������� � ������ ������  |" << endl;
		cout << "| 3 |   ���������� ���� �� ������             |" << endl;
		cout << "| 4 |   �������� ���� �� ������               |" << endl;
		cout << "| 5 |   ����� ��������� ������                |" << endl;
		cout << "| 6 |   �������� ���� �� ��������             |" << endl;
		cout << "| 7 |   ���������� �������� ����� ���������   |" << endl;
		cout << "| 8 |   ���������� �������� ����� ��������    |" << endl;
		cout << "| 0 |   ��������� � ���������� ����           |" << endl;
		cout << "|___|_________________________________________|" << endl;
		cout << "|                                             |" << endl;
		cout << "|   �������� ���� �� ������� � ������� Enter  |" << endl;
		cout << "|_____________________________________________|" << endl;
		cin >> PunktMenu;
		switch (PunktMenu)
		{
		case 1:
		{
			cout << "������� ���������� ���������" << endl;
			cin >> n;
			cout << "������� ��������" << endl;
			int i = 0;
			do {

				addLast(&last, &first);
				i++;

			} while (i != n);
			cout << "�������� �������" << endl;
			_getch();
			break;
		}
		case 2:
		{
			cout << "������� ���������� ���������" << endl;
			cin >> n;
			cout << "������� ��������" << endl;
			int i = 0;
			int val;
			do {
				cin >> val;
				addBegin(&first, val);
				i++;

				} while (i != n);
			cout << "�������� �������" << endl;
			_getch();
			break;
		}
		case 3:
		{
			int i = 1;
			int n;
			cout << "������� ����� ������� ��������" << endl;
			cin >> n;
			if (n == 1) addBegin(&first, n);
			else addNumber(first, n);
			break;
		}
		case 4:
		{
			int n;
			cout << "������� ����� ��������" << endl;
			cin >> n;
			if (n == 1)
			{
				cout << "������� �������" << endl;
				del(&first);
			}
			else DelNumber(first, n);
			break;
		}
		case 5:
		{
			cout << "�������� ������: ";
			print(first);
			cout << endl;
			break;
		}
		case 6:
		{
			int n;
			cout << "������� ��������" << endl;
			cin >> n;
			if (first->val == n)
				{
					del(&first);
					break;
				}
			DelZnach(first, n);
			cout << "������� ������" << endl;
			break;
		}
		case 7:
		{
			cout << "������� �������� ��������" << endl;
			int n;
			cin >> n;
			if (first->val == n)
				{
					int val;
					cout << "������� �������" << endl;
					cin >> val;
					addBegin(&first, val);
					cout << "������� ��������" << endl;
					_getch();
					break;
				}
			addBefore(first, n);
			cout << "������� ��������" << endl;
			_getch();
			break;
		}
		case 8:
		{
			int n;
			cout << "������� ��������" << endl;
			cin >> n;
			addAfter(first, n);
		}
		}
		} while (PunktMenu != 0);
		_getch();
	}
