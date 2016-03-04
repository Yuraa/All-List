#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include "queue.h"

using namespace std;




/*
brief: ������� ���������� ��������� � ����� �������
in: ��������� �� ��������� ���������� �������� �������, ��������� �� ��������� ������� �������� �������
out: none
*/
void add(nodeQ **last, nodeQ **first) //���������� ��������
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
brief: ������� �������� ��������� � ������ �������
in: ��������� �� ��������� ������� �������� �������
out: ����������� �������� ���������� ��������
*/
int del(nodeQ **first){
	int var = (**first).val;
	nodeQ *adr = (**first).sled;
	delete *first;
	*first = adr;
	return var;
}





/*
brief: ������� ������ ������� �� �����
in: ��������� �� ������ ������� �������
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
brief: ������� �������� ���� ��� ������ � ��������
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
		cout << "| 1 |   ���������� ��������� � ����� �������  |" << endl;
		cout << "| 2 |   �������� �������� �� ������ �������   |" << endl;
		cout << "| 3 |   ����� ���������                       |" << endl;
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
	
					add(&last, &first);
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
				for (int i = 0; i < n; i++)	del(&first);
				cout << "�������� �������" << endl;
				_getch();
				break;
			}
			case 3:
			{
				cout << "�������� �������: ";
				print(first);
				cout << endl;
				break;
			}
		}
	} while (PunktMenu != 0);
		_getch();
	}





