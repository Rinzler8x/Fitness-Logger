#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <stdlib.h>
int count_wl = 0;
int count_fl = 0;

using namespace std;

//test for viraj
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
		ifstream fin_wl;
		fin_wl.open("workout_logs.txt", ios::in);
		fin_wl.seekg(0, ios::beg);
		fin_wl >> ::count_wl;
		for (int i = 0; i < ::count_wl; i++) {
			fin_wl >> excercise_wl[i];
			fin_wl >> steps_wl[i];
			fin_wl >> calories_wl[i];
			fin_wl >> distance_wl[i];
			fin_wl >> bpm_wl[i];
		}
		fin_wl.close();
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

	friend void file_write_wl(workout_log &W);
	/*{
		ofstream fout_wl;
		fout_wl.open("workout_logs.txt", ios::out);
		fout_wl << ::count_wl << endl;
		for (int i = 0; i < ::count_wl; i++) {
			fout_wl << excercise_wl[i] << endl;
			fout_wl << steps_wl[i] << endl;
			fout_wl << calories_wl[i] << endl;
			fout_wl << distance_wl[i] << endl;
			fout_wl << bpm_wl[i] << endl;
		}
		fout_wl.close();
	}*/

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

void file_write_wl(workout_log &W)
{
	ofstream fout_wl;
	fout_wl.open("workout_logs.txt", ios::out);
	fout_wl << ::count_wl << endl;
	for (int i = 0; i < ::count_wl; i++) {
		fout_wl << W.excercise_wl[i] << endl;
		fout_wl << W.steps_wl[i] << endl;
		fout_wl << W.calories_wl[i] << endl;
		fout_wl << W.distance_wl[i] << endl;
		fout_wl << W.bpm_wl[i] << endl;
	}
	fout_wl.close();
}

class food_log
{
protected:
	string type_fl[10]{};
	int calories_fl[10]{};

public:
	food_log()
	{
		ifstream fin_fl;
		fin_fl.open("food_logs.txt", ios::in);
		fin_fl.seekg(0, ios::beg);
		fin_fl >> count_fl;
		for (int i = 0; i < count_fl; i++) {
			fin_fl >> type_fl[i];
			fin_fl >> calories_fl[i];
		}
		fin_fl.close();
	}

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

	friend void file_write_fl(food_log &F);
	/*{
		ofstream fout_fl;
		fout_fl.open("food_logs.txt", ios::in);
		fout_fl << count_fl << endl;
		for (int i = 0; i < count_fl; i++) {
			fout_fl << type_fl[i] << endl;
			fout_fl << calories_fl[i] << endl;
		}
		fout_fl.close();
	}*/

};

void file_write_fl(food_log &F)
{
	ofstream fout_fl;
	fout_fl.open("food_logs.txt", ios::in);
	fout_fl << count_fl << endl;
	for (int i = 0; i < count_fl; i++) {
		fout_fl << F.type_fl[i] << endl;
		fout_fl << F.calories_fl[i] << endl;
	}
	fout_fl.close();
}

class lifetime : public workout_log, public food_log
{
protected:
	int steps_lt{};
	int calories_lt{};
	float distance_lt{};

public:
	lifetime()
	{
		ifstream fin_lt;
		fin_lt.open("lifetime.txt", ios::in);
		fin_lt.seekg(0, ios::beg);
		fin_lt >> steps_lt;
		fin_lt >> calories_lt;
		fin_lt >> distance_lt;
		fin_lt.close();
	}

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

	friend void file_write_lt(lifetime &L);
	/*{
		ofstream fout_lt;
		fout_lt.open("lifetime.txt", ios::in);
		fout_lt << steps_lt << endl;
		fout_lt << calories_lt << endl;
		fout_lt << distance_lt << endl;
		fout_lt.close();
	}*/
};

void file_write_lt(lifetime &L)
{
	ofstream fout_lt;
	fout_lt.open("lifetime.txt", ios::in);
	fout_lt << L.steps_lt << endl;
	fout_lt << L.calories_lt << endl;
	fout_lt << L.distance_lt << endl;
	fout_lt.close();
}

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
	user()
	{
		ifstream fin_u;
		fin_u.open("user_details.txt", ios::in);
		fin_u.seekg(0, ios::beg);
		fin_u >> ID;
		fin_u >> name;
		fin_u >> age;
		fin_u >> height;
		fin_u >> weight;
		fin_u >> blood_grp;
		fin_u >> BMI;
		fin_u.close();
	}

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
		cout << "ID: " << ID << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Height: " << height << endl;
		cout << "Weight: " << weight << endl;
		cout << "Blood Group: " << blood_grp << endl;
		cout << "BMI: " << BMI << endl;
	}

	friend void file_write_user(user &U);
	/*{
		ofstream fout_u;
		fout_u.open("user_details.txt", ios::out);
		fout_u << ID << endl;
		fout_u << name << endl;
		fout_u << age << endl;
		fout_u << height << endl;
		fout_u << weight << endl;
		fout_u << blood_grp << endl;
		fout_u << BMI << endl;
		fout_u.close();
	}*/
};

void file_write_user(user &U)
{
	ofstream fout_u;
	fout_u.open("user_details.txt", ios::out);
	fout_u << U.ID << endl;
	fout_u << U.name << endl;
	fout_u << U.age << endl;
	fout_u << U.height << endl;
	fout_u << U.weight << endl;
	fout_u << U.blood_grp << endl;
	fout_u << U.BMI << endl;
	fout_u.close();
}

void menu_main();
void menu_wl(user& U1)
{
	system("cls");
	int cho;
	cout << "Workout Log Menu" << endl;
	cout << "1. Add new workout" << endl;
	cout << "2. Delete workout log" << endl;
	cout << "3. View workout logs" << endl;
	cout << "4. Edit workout log" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> cho;

	switch (cho)
	{
	case 1:
		U1.wl_entry();
		break;

	case 2:
		break;

	case 3:
		U1.wl_view();
		break;

	case 4:
		break;

	case 5:
		file_write_wl(U1);
		menu_main();
		break;

	default:
		cout << "Invalid Input" << endl;
		break;
	}
}

void menu_fl(user& U1)
{
	system("cls");
	int cho;
	cout << "Food Log Menu" << endl;
	cout << "1. Add new food log" << endl;
	cout << "2. Delete food log" << endl;
	cout << "3. View food logs" << endl;
	cout << "4. Edit food log" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> cho;

	switch (cho)
	{
	case 1:
		U1.fl_entry();
		break;

	case 2:
		break;

	case 3:
		U1.fl_view();
		break;

	case 4:
		break;

	case 5:
		file_write_fl(U1);
		menu_main();
		break;

	default:
		cout << "Invalid Input" << endl;
		break;
	}
}

void menu_lt(user& U1)
{
	system("cls");
	int cho;

	cout << "Life Time Records Menu" << endl;
	cout << "1. View life time record" << endl;
	cout << "2. Reset life time record" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> cho;

	switch (cho)
	{
	case 1:
		U1.lt_view();
		break;

	case 2:
		break;

	case 3:
		file_write_lt(U1);
		menu_main();
		break;

	default:
		cout << "Invalid Input" << endl;
		break;
	}
}

void menu_user(user &U1)
{
	system("cls");
	int cho;
	
	cout << "User Details Menu" << endl;
	cout << "1. Add user details" << endl;
	cout << "2. View user details" << endl;
	cout << "3. Edit user details" << endl;
	cout << "4. Delete user details" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> cho;

	switch (cho)	
	{
	case 1:
		U1.user_entry();
		break;

	case 2:
		U1.user_view();
		break;

	case 3:
		break;
	
	case 4:
		break;

	case 5:
		file_write_user(U1);
		menu_main();
		break;

	default:
		cout << "Invalid Input" << endl;
		break;
	}
}

void menu_main()
{
	system("cls");
	user U1;
	int cho;
	cout << "Menu" << endl;
	cout << "1. Workout Logs" << endl;
	cout << "2. Food Logs" << endl;
	cout << "3. Life Time Records" << endl;
	cout << "4. User Details" << endl;
	cout << "5. Exit" << endl;

	do
	{
		cout << "Enter your choice: ";
		cin >> cho;
		cout << endl;

		switch (cho)
		{
		case 1:
			menu_wl(U1);
			break;

		case 2:
			menu_fl(U1);
			break;

		case 3:
			menu_lt(U1);
			break;

		case 4:
			menu_user(U1);
			break;

		case 5:
			exit(1);
			break;

		default:
			cout << "Invalid Input" << endl;
			break;
		}
	} while (cho != 0);
}


int main()
{
	menu_main();
	/*user U1;
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
			menu_wl();
			break;

		case 2:
			menu_fl();
			break;

		case 3:
			menu_lt();
			break;

		case 4:
			menu_user();
			break;

		case 5:
			U1.file_write_wl();
			U1.file_write_fl();
			U1.file_write_lt();
			U1.file_write_user();
			break;

		default:
			break;
		}
	} while (cho != 0);*/
	return 0;
}