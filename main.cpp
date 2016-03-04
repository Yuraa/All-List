// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "queue.h"
#include "stack.h"
#include "LinkedList.h"
#include <iostream>
#include <stdlib.h>
#include "conio.h"





using namespace std;




	
	
	
	
	
	int _tmain(int argc, _TCHAR* argv[])
	{
	setlocale(LC_ALL, "Russian");
	int PunktMenu = 0;
	do {
		system("cls");
		cout << " __________________________________________" << endl;
		cout << "| 1 |           Работа со стеком           |" << endl;
		cout << "| 2 |           Работа с очередью          |" << endl;
		cout << "| 3 |           Работа со списком          |" << endl;
		cout << "| 0 |           Выход из программы         |" << endl;
		cout << "|___|______________________________________|" << endl;
		cout << "|                                          |" << endl;
		cout << "| Выберите один из режимов и нажмите Enter |" << endl;
		cout << "|__________________________________________|" << endl;
		cin >> PunktMenu;
		switch (PunktMenu){
		case 1: StackMenu(); break;
		case 2: QueueMenu(); break;                     // меню
		case 3: ListMenu(); break;
		}
	}																				
	while (PunktMenu!= 0); 
	_getch();
	return 0;
}









