#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include<fstream>
#include <stdlib.h>
int count_wl = 0;
int count_fl = 0;

using namespace std;

class workout_log
{
protected:
	int steps_wl[10]{};
	int calories_wl[10]{};
	float distance_wl[10]{};
	int bpm_wl[10]{};
	string excercise_wl[10]{};

public:
	workout_log()
	{
		ifstream fin;
		fin.open("workout_logs.txt", ios::in);
		fin.seekg(0, ios::beg);
		fin >> ::count_wl;
		for (int i = 0; i < ::count_wl; i++) {
			fin >> excercise_wl[i];
			fin >> steps_wl[i];
			fin >> calories_wl[i];
			fin >> distance_wl[i];
			fin >> bpm_wl[i];
		}
		fin.close();
	}

	void wl_entry()
	{
		cout << "Workout Logs Entry" << endl;
		cout << "Enter following details: " << endl;
		cout << "Type of excercise: ";
		cin >> excercise_wl[::count_wl];
		cout << "No of Steps: ";
		cin >> steps_wl[::count_wl];
		cout << "Calories burnt: ";
		cin >> calories_wl[::count_wl];
		cout << "Distance travelled: ";
		cin >> distance_wl[::count_wl];
		cout << "Average heart rate: ";
		cin >> bpm_wl[::count_wl];

		::count_wl++;
	}

	void wl_view()
	{
		cout << "Workout Logs" << endl;
		for (int i = 0; i < ::count_wl; i++) {
			cout << "Excercise: " << excercise_wl[i] << endl;
			cout << "Steps: " << steps_wl[i] << endl;
			cout << "Calories: " << calories_wl[i] << endl;
			cout << "Distance: " << distance_wl[i] << endl;
			cout << "Average Heart rate: " << bpm_wl[i] << endl;
		}
	}

	void file_write()
	{
		ofstream fout;
		fout.open("workout_logs.txt", ios::out);
		fout << ::count_wl << endl;
		for (int i = 0; i < ::count_wl; i++) {
			fout << excercise_wl[i] << endl;
			fout << steps_wl[i] << endl;
			fout << calories_wl[i] << endl;
			fout << distance_wl[i] << endl;
			fout << bpm_wl[i] << endl;
		}
		fout.close();
	}

	/*void file_read()
	{
		ifstream fin;
		fin.open("workout_logs.txt", ios::in);
		fin.seekg(0, ios::beg);
		fin >> ::count_wl;
		for (int i = 0; i < ::count_wl; i++) {
			fin >> excercise_wl[i];
			fin >> steps_wl[i];
			fin >> calories_wl[i];
			fin >> distance_wl[i];
			fin >> bpm_wl[i];
		}
		fin.close();
	}*/
};

class food_log
{
protected:
	string type_fl[10]{};
	int calories_fl[10]{};

public:
	food_log(){}

	void fl_entry()
	{
		cout << "Food Log Entry" << endl;
		cout << "Enter the following details: " << endl;
		cout << "Type of food (Breakfast / Lunch / Dinner / Others): ";
		cin >> type_fl[::count_fl];
		cout << "Amount of Calories: ";
		cin >> calories_fl[::count_fl];

		::count_fl++;
	}

	void fl_view()
	{
		cout << "Food Log" << endl;
		for (int i = 0; i < ::count_fl; i++) {
			cout << "Type of Food: " << type_fl[i] << endl;
			cout << "Amount of Calories: " << calories_fl[i] << endl;
		}
	}

};

class lifetime : public workout_log, public food_log
{
protected:
	int steps_lt{};
	int calories_lt{};
	float distance_lt{};

public:
	lifetime(){}

	void operator +()
	{
		steps_lt += steps_wl[::count_wl];
		calories_lt += calories_wl[::count_wl];
		if (count_fl == count_wl)
			calories_lt -= calories_fl[::count_fl];
		distance_lt += distance_wl[::count_wl];
	}

	void lt_view()
	{
		cout << "Life Time Records";
		cout << "Total Steps: " << steps_lt << endl;
		cout << "Total Calories: " << calories_lt << endl;
		cout << "Total Distance Travelled: " << distance_lt << endl;
	}
};

class user : public lifetime
{
protected:
	int ID{};
	string name{};
	int age{};
	int height{};
	float weight{};
	string blood_grp{};
	float BMI{};

public:
	user(){}

	void user_entry()
	{
		cout << "User Entry" << endl;
		cout << "Enter the following details:" << endl;
		cout << "Enter Id: ";
		cin >> ID;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter age: ";
		cin >> age;
		cout << "Enter height: ";
		cin >> height;
		cout << "Enter weight: ";
		cin >> weight;
		cout << "Enter blood group: ";
		cin >> blood_grp;
	}

	void calc_bmi()
	{
		BMI = weight / (height * height);
	}

	void user_view()
	{
		cout << "User Details" << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Height: " << height << endl;
		cout << "Weight: " << weight << endl;
		cout << "Blood Group: " << blood_grp << endl;
		cout << "BMI: " << BMI << endl;
	}
};

int main()
{
	user U1;
	int cho;
	cout << "Menu" << endl;
	cout << "Workout Log entry" << endl;
	cout << "Display" << endl;
	cout << "User entry" << endl;
	cout << "User display" << endl;

	do
	{
		cout << "Enter your choice: ";
		cin >> cho;
		cout << endl;

		switch (cho)
		{
		case 1:
			U1.wl_entry();
			break;

		case 2:
			U1.wl_view();
			break;

		case 3:
			U1.user_entry();
			break;

		case 4:
			U1.user_view();
			break;

		case 5:
			U1.file_write();
			break;

		case 6:
			//U1.file_read();
			break;

		default:
			break;
		}
	} while (cho != 0);
	return 0;
}