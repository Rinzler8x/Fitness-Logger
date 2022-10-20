#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>

using namespace std;

int menu()
{
	int choice;
	do
	{
		system("cls");
		cout << "Menu" << endl;
		cout << "1. Life Time Total" << endl;
		cout << "2. Workout Logs" << endl;
		cout << "3. User Data" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Life Time Total" << endl;
			break;

		case 2:
			system("cls");
			cout << "Workout Logs" << endl;
			break;

		case 3:
			system("cls");
			cout << "User Data" << endl;
			break;

		default:
			system("cls");
			cout << "Invalid Input" << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}


void main()
{
	menu();
	_getch();
}