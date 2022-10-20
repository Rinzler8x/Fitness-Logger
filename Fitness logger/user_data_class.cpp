#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;

class User_data
{
	char user_ID;
	char user_name;
	char user_age;
	char user_height;
	char user_weight;
	char user_bld_grp;
	char user_bmi;

public:
	User_data()
	{
		user_ID = 0;
		user_name = 0;
		user_age = 0;
		user_height = 0;
		user_weight = 0;
		user_bld_grp = 0;
		user_bmi = 0;
	}

	User_data()
	{
		user_ID = 0;
		user_name = 0;
		user_age = 0;
		user_height = 0;
		user_weight = 0;
		user_bld_grp = 0;
		user_bmi = 0;
	}

	void display()
	{
		cout << "ID: " << user_ID << endl;
		cout << "Name: " << user_name << endl;
		cout << "Age: " << user_age << endl;
		cout << "Height: " << user_height << endl;
		cout << "Weight: " << user_weight << endl;
		cout << "Blood Group: " << user_bld_grp << endl;
		cout << "BMI: " << user_bmi << endl;
	}
};