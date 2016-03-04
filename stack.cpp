#include "stdafx.h"
#include <iostream>
#include "stack.h"
#include "conio.h"


using namespace std;


/*
brief: функция записи элемента в стек
in: целочисленное значение, указатель на указатель вершины стека
out: none
*/
void push(int val, node **top){

	node *var= new node;
	(*var).val = val;
	(*var).pred = *top;

	*top = var;
}

/*
brief: функция считывания стека
in: указатель на указатель вершины стека
out: целочисленное значение вершины стека
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
brief: функция вывода стека
in: указатель на вершину стека
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
	brief: функция вывода и удаления стека
	in: указатель на вершину стека
	out: none
*/
void printDel(node* top)
{
	while (top!=NULL) cout << pop(&top);
	_getch();
}



/*
brief: функция создания меню для работы со стеком
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
		cout << "| 1 |   Добавить элементы в стек           |" << endl;
		cout << "| 2 |   Удалить последние элементы стека   |" << endl;
		cout << "| 3 |   Вывести стек на экран              |" << endl;
		cout << "| 4 |   Вывести стек на экран с удалением  |" << endl;
		cout << "| 0 |   Вернуться в предыдущее меню        |" << endl;
		cout << "|___|______________________________________|" << endl;
		cout << "|                                          |" << endl;
		cout << "| Выберите один из режимов и нажмите Enter |" << endl;
		cout << "|__________________________________________|" << endl;
		cin >> PunktMenu;
		switch (PunktMenu){
		case 1:
		{
			int i = 0;
			cout << "Введите количество элементов" << endl;
			cin >> n;
			cout << "Введите элементы" << endl;
			while (i != n)	
			{
				cin >> val;
				push(val, &top);
				i++;
			}
			cout << "Элементы добавлены" << endl;
			_getch();
			break;
		}
		case 2:
		{
			int i = 0;
			cout << "Введите количество элементов" << endl;
			cin >> n;
			while (i != n)
			{
				pop(&top);
				i++;
			}
			cout << "Элементы удалены" << endl;
			break;
		}
		case 3: print(top); break;
		case 4: printDel(top); break;
		}
	} while (PunktMenu != 0);
		_getch();
}






