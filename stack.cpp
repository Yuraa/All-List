#include "stdafx.h"
#include <iostream>
#include "stack.h"
#include "conio.h"


using namespace std;


/*
brief: ������� ������ �������� � ����
in: ������������� ��������, ��������� �� ��������� ������� �����
out: none
*/
void push(int val, node **top){

	node *var= new node;
	(*var).val = val;
	(*var).pred = *top;

	*top = var;
}

/*
brief: ������� ���������� �����
in: ��������� �� ��������� ������� �����
out: ������������� �������� ������� �����
*/
int pop(node **top)
{
	if (*top != NULL) {
		int val = (*top)->val;
		node *q = (*top)->pred;
		delete *top;
		*top = q;
		return val;
	}
}



/*
brief: ������� ������ �����
in: ��������� �� ������� �����
out: none
*/
void print(node *top){
		
	while (top)
	{
		printf_s("%d", (*top).val);
		top = top->pred;
	}
	
	_getch();

}



/*
	brief: ������� ������ � �������� �����
	in: ��������� �� ������� �����
	out: none
*/
void printDel(node* top)
{
	while (top!=NULL) cout << pop(&top);
	_getch();
}



/*
brief: ������� �������� ���� ��� ������ �� ������
in: none
out: none
*/
void StackMenu(){
	
	node *top=NULL;
	int val;
	int n;
	int PunktMenu = 0;
	do {
		system("cls");
		cout << " __________________________________________" << endl;
		cout << "| 1 |   �������� �������� � ����           |" << endl;
		cout << "| 2 |   ������� ��������� �������� �����   |" << endl;
		cout << "| 3 |   ������� ���� �� �����              |" << endl;
		cout << "| 4 |   ������� ���� �� ����� � ���������  |" << endl;
		cout << "| 0 |   ��������� � ���������� ����        |" << endl;
		cout << "|___|______________________________________|" << endl;
		cout << "|                                          |" << endl;
		cout << "| �������� ���� �� ������� � ������� Enter |" << endl;
		cout << "|__________________________________________|" << endl;
		cin >> PunktMenu;
		switch (PunktMenu){
		case 1:
		{
			int i = 0;
			cout << "������� ���������� ���������" << endl;
			cin >> n;
			cout << "������� ��������" << endl;
			while (i != n)	
			{
				cin >> val;
				push(val, &top);
				i++;
			}
			cout << "�������� ���������" << endl;
			_getch();
			break;
		}
		case 2:
		{
			int i = 0;
			cout << "������� ���������� ���������" << endl;
			cin >> n;
			while (i != n)
			{
				pop(&top);
				i++;
			}
			cout << "�������� �������" << endl;
			break;
		}
		case 3: print(top); break;
		case 4: printDel(top); break;
		}
	} while (PunktMenu != 0);
		_getch();
}






