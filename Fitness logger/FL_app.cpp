#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include<Windows.h>
int count_wl = 0;
int count_fl = 0;

using namespace std;

void pause_fn();
void pause_wlcm();
void menu_main();

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
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout.width(74);
		cout << "W O R K O U T  L O G S  E N T R Y" << endl;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\nEnter following details: " << endl;
		cout << "Type of excercise: ";
		cin >> excercise_wl[::count_wl];
		cout << "No of Steps: ";
		cin >> steps_wl[::count_wl];
		cout << "Calories burnt: ";
		cin >> calories_wl[::count_wl];
		cout << "Distance travelled (in km): ";
		cin >> distance_wl[::count_wl];
		cout << "Average heart rate: ";
		cin >> bpm_wl[::count_wl];

		::count_wl++;
	}

	void wl_view()
	{
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout.width(69);
		cout << "W O R K O U T  L O G S" << endl;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		if (::count_wl == 0)
			cout << "\nNo logs entered" << endl;
		else {
			for (int i = 0; i < ::count_wl; i++) {
				cout << "\nExcercise: " << excercise_wl[i] << endl;
				cout << "Steps    : " << steps_wl[i] << endl;
				cout << "Calories : " << calories_wl[i] << endl;
				cout << "Distance (in km): " << distance_wl[i] << endl;
				cout << "Average Heart rate: " << bpm_wl[i] << endl;
				cout << "\n";
			}
		}
	}

	void wl_delete()
	{
		int cho;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout << "\nEnter workout log to delete: ";
		cin >> cho;
		cho--;
		if (cho < ::count_wl) {
			cout << "Deleting the following log:" << endl;
			cout << "Excercise: " << excercise_wl[cho] << endl;
			cout << "Steps: " << steps_wl[cho] << endl;
			cout << "Calories: " << calories_wl[cho] << endl;
			cout << "Distance (in km): " << distance_wl[cho] << endl;
			cout << "Average Heart rate: " << bpm_wl[cho] << endl;

			for (int i = cho; i < ::count_wl; i++) {
				string temp_s;
				temp_s = excercise_wl[i];
				excercise_wl[i] = excercise_wl[i + 1];
				excercise_wl[i + 1] = temp_s;

				int temp_i;
				temp_i = steps_wl[i];
				steps_wl[i] = steps_wl[i + 1];
				steps_wl[i + 1] = temp_i;

				temp_i = calories_wl[i];
				calories_wl[i] = calories_wl[i + 1];
				calories_wl[i + 1] = temp_i;

				float temp_f;
				temp_f = distance_wl[i];
				distance_wl[i] = distance_wl[i + 1];
				distance_wl[i + 1] = temp_f;

				temp_i = bpm_wl[i];
				bpm_wl[i] = bpm_wl[i + 1];
				bpm_wl[i + 1] = temp_i;
			}
			::count_wl--;
		}
		else
			cout << "Invalid Input" << endl;
	}

	void menu_wl(workout_log &U1)
	{
		int cho = 0;
		do {
			system("cls");
			cout << "\n";
			cout.width(74);
			cout << "W O R K O U T   L O G   M E N U" << endl;
			cout << "\n";
			cout << setw(66); cout << "1. Add new workout" << endl;
			cout << setw(68); cout << "2. View workout logs" << endl;
			cout << setw(69); cout << "3. Delete workout log" << endl;
			cout << setw(55); cout << "4. Exit" << endl;
			cout << "\n";
			cout << setw(67); cout << "Enter your choice: ";
			cin >> cho;

			switch (cho)
			{
			case 1:
				wl_entry();
				pause_fn();
				break;

			case 2:
				wl_view();
				pause_fn();
				break;

			case 3:
				wl_delete();
				pause_fn();
				break;

			case 4:
				file_write_wl(U1);
				menu_main();
				break;

			default:
				cout << "Invalid Input" << endl;
				pause_fn();
				break;
			}
		} while (cho != 0);
	}

	friend void file_write_wl(workout_log&);
};

void file_write_wl(workout_log& W)
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
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout.width(74);
		cout << "F O O D  L O G  E N T R Y" << endl;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\nEnter the following details: " << endl;
		cout << "Type of food (Breakfast / Lunch / Dinner / Others): ";
		cin >> type_fl[::count_fl];
		cout << "Amount of Calories: ";
		cin >> calories_fl[::count_fl];

		::count_fl++;
	}

	void fl_view()
	{
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout.width(66);
		cout << "F O O D  L O G" << endl;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		if (::count_fl == 0)
			cout << "\nNo logs entered" << endl;
		else {
			for (int i = 0; i < ::count_fl; i++) {
				cout << "\nType of Food: " << type_fl[i] << endl;
				cout << "Amount of Calories: " << calories_fl[i] << endl;
				cout << "\n";
			}
		}
	}

	void fl_delete()
	{
		int cho;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\nEnter food log to delete: ";
		cin >> cho;
		cho--;
		if (cho < ::count_fl) {
			cout << "Deleting the following log:" << endl;
			cout << "Type of Food: " << type_fl[cho] << endl;
			cout << "Amount of Calories: " << calories_fl[cho] << endl;

			for (int i = cho; i < ::count_fl; i++) {
				string temp_s;
				temp_s = type_fl[i];
				type_fl[i] = type_fl[i + 1];
				type_fl[i + 1] = temp_s;

				int temp_i;
				temp_i = calories_fl[i];
				calories_fl[i] = calories_fl[i + 1];
				calories_fl[i + 1] = temp_i;
			}
			::count_fl--;
		}
		else
			cout << "Invalid Input" << endl;
	}

	void menu_fl(food_log& U1)
	{
		int cho;
		do {
			system("cls");
			cout << "\n";
			cout.width(72);
			cout << "F O O D  L O G  M E N U" << endl;
			cout << "\n";
			cout << setw(70); cout << "1. Add new food log" << endl;
			cout << setw(68); cout << "2. View food logs" << endl;
			cout << setw(69); cout << "3. Delete food log" << endl;
			cout << setw(58); cout << "4. Exit" << endl;
			cout << "\n";
			cout << setw(70); cout << "Enter your choice: ";
			cin >> cho;

			switch (cho)
			{
			case 1:
				fl_entry();
				pause_fn();
				break;

			case 2:
				fl_view();
				pause_fn();
				break;

			case 3:
				fl_delete();
				pause_fn();
				break;

			case 4:
				file_write_fl(U1);
				menu_main();
				break;

			default:
				cout << "Invalid Input" << endl;
				pause_fn();
				break;
			}
		} while (cho != 0);
	}

	friend void file_write_fl(food_log&);
};

void file_write_fl(food_log& F)
{
	ofstream fout_fl;
	fout_fl.open("food_logs.txt", ios::out);
	fout_fl << count_fl << endl;
	for (int i = 0; i < count_fl; i++) {
		fout_fl << F.type_fl[i] << endl;
		fout_fl << F.calories_fl[i] << endl;
	}
	fout_fl.close();
}

class plan
{
protected:
	string pl_trainer{};
	string pl_gym{};
	string pl_type{};
	float pl_fees{};
	int pl_duration{};


public:
	plan()
	{
		ifstream fin_pl;
		fin_pl.open("plan.txt", ios::in);
		fin_pl.seekg(0, ios::beg);
		fin_pl >> pl_trainer;
		fin_pl >> pl_gym;
		fin_pl >> pl_fees;
		fin_pl >> pl_duration;
		fin_pl >> pl_type;
	}

	void pl_entry()
	{
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout.width(77);
		cout << "F I T N E S S  P L A N  E N T R Y" << endl;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n";
		cout << "Enter following details:" << endl;
		cout << "Trainer Name: ";
		cin >> pl_trainer;
		cout << "Gym Name: ";
		cin >> pl_gym;
		cout << "Fees: ";
		cin >> pl_fees;
		cout << "Plan Duration: ";
		cin >> pl_duration;
		cout << "Plan Type: ";
		cin >> pl_type;
	}

	void pl_view()
	{
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout.width(71);
		cout << "F I T N E S S  P L A N" << endl;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n\n";
		cout << "Trainer Name: " << pl_trainer << endl;
		cout << "Gym Name: " << pl_gym << endl;
		cout << "Fees: " << pl_fees << endl;
		cout << "Plan Duration: " << pl_duration << endl;
		cout << "Plan Type: " << pl_type << endl;
	}

	void pl_delete()
	{
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout << "Fitness plan deleted" << endl;
		pl_trainer = '0';
		pl_gym = '0';
		pl_fees = 0;
		pl_duration = 0;
		pl_type = '0';
	}

	void menu_pl(plan& U1)
	{
		int cho;

		do {
			system("cls");
			cout << "\n";
			cout.width(76);
			cout << "F I T N E S S  P L A N  M E N U" << endl;
			cout << "\n";
			cout << setw(69); cout << "1. Add fitness plan" << endl;
			cout << setw(70); cout << "2. View fitness plan" << endl;
			cout << setw(72); cout << "3. Delete fitness plan" << endl;
			cout << setw(57); cout << "4. Exit" << endl;
			cout << "\n";
			cout << setw(69); cout << "Enter your choice: ";
			cin >> cho;

			switch (cho)
			{
			case 1:
				pl_entry();
				pause_fn();
				break;

			case 2:
				pl_view();
				pause_fn();
				break;

			case 3:
				U1.pl_delete();
				menu_main();
				break;

			case 4:
				file_write_pl(U1);
				menu_main();
				break;

			default:
				cout << "Invalid Input" << endl;
				pause_fn();
				break;
			}
		} while (cho != 0);
	}

	friend void file_write_pl(plan&);
};

void file_write_pl(plan& P)
{
	ofstream fout_pl;
	fout_pl.open("plan.txt", ios::out);
	fout_pl << P.pl_trainer << endl;
	fout_pl << P.pl_gym << endl;
	fout_pl << P.pl_fees << endl;
	fout_pl << P.pl_duration << endl;
	fout_pl << P.pl_type << endl;
	fout_pl.close();
}

class lifetime : public workout_log, public food_log, public plan
{
protected:
	int steps_lt{};
	int calories_lt{};
	float distance_lt{};

public:
	lifetime(){}

	void lt_add()
	{
		for (int i = 0; i < ::count_wl; i++) {
			steps_lt += steps_wl[i];
			calories_lt += calories_wl[i];
			distance_lt += distance_wl[i];
		}
	}

	void lt_view()
	{
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout.width(77);
		cout << "L I F E  T I M E  R E C O R D S" << endl;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n\n";
		cout << "Total Steps: " << steps_lt << endl;
		cout << "Total Calories: " << calories_lt << endl;
		cout << "Total Distance Travelled: " << distance_lt << endl;
	}

	void lt_delete()
	{
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n\n" << endl;
		cout << "Life Time Records are reset" << endl;
		steps_lt = 0;
		calories_lt = 0;
		distance_lt = 0;
	}

	void menu_lt(lifetime& U1)
	{
		int cho;

		do {
			system("cls");
			cout << "\n";
			cout.width(81);
			cout << "L I F E  T I M E  R E C O R D S  M E N U" << endl;
			cout << "\n";
			cout << setw(74); cout << "1. View life time record" << endl;
			cout << setw(57); cout << "2. Exit" << endl;
			cout << "\n";
			cout << setw(69); cout << "Enter your choice: ";
			cin >> cho;

			switch (cho)
			{
			case 1:
				lt_add();
				lt_view();
				pause_fn();
				break;

			case 2:
				menu_main();
				break;

			default:
				cout << "Invalid Input" << endl;
				pause_fn();
				break;
			}
		} while (cho != 0);
	}
};

class user : public lifetime
{
protected:
	int ID{};
	string name{};
	int age{};
	float height{};
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
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout.width(70);
		cout << "U S E R  E N T R Y" << endl;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n\n";
		cout << "Enter the following details:" << endl;
		cout << "Id: ";
		cin >> ID;
		cout << "Name: ";
		cin >> name;
		cout << "Age: ";
		cin >> age;
		cout << "Height (in m): ";
		cin >> height;
		cout << "Weight (in kg): ";
		cin >> weight; 
		cout << "Blood group: ";
		cin >> blood_grp;
	}

	void user_view()
	{
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout.width(70);
		cout << "U S E R  D E T A I L S" << endl;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n" << endl;
		cout << "ID: " << ID << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Height (in m): " << height << endl;
		cout << "Weight (in kg): " << weight << endl;
		cout << "Blood Group: " << blood_grp << endl;
	}

	void user_delete()
	{
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n\n" << endl;
		cout << "User details are deleted" << endl;
		ID = 0;
		name = '0';
		age = 0;
		height = 0;
		weight = 0;
		blood_grp = '0';
	}

	void user_summary()
	{
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n";
		cout.width(73);
		cout << "A C C O U N T  S U M M A R Y" << endl;
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
		cout << "\n";
		user_view();
		pl_view();
		lt_view();
	}

	void menu_user(user& U1)
	{
		int cho;

		do {
			system("cls");
			cout << "\n";
			cout.width(77);
			cout << "U S E R  D E T A I L S  M E N U" << endl;
			cout << "\n";
			cout << setw(69); cout << "1. Add user details" << endl;
			cout << setw(70); cout << "2. View user details" << endl;
			cout << setw(72); cout << "3. Delete user details" << endl;
			cout << setw(57); cout << "4. Exit" << endl;
			cout << "\n";
			cout << setw(69); cout << "Enter your choice: ";
			cin >> cho;

			switch (cho)
			{
			case 1:
				user_entry();
				pause_fn();
				break;

			case 2:
				bmi(U1);
				user_view();
				cout << U1;
				pause_fn();
				break;

			case 4:
				user_delete();
				pause_fn();
				break;

			case 5:
				file_write_user(U1);
				menu_main();
				break;

			default:
				cout << "Invalid Input" << endl;
				pause_fn();
				break;
			}
		} while (cho != 0);
	}

	friend ostream& operator <<(ostream& output, const user& U);
	
	friend void bmi(user&);

	friend void file_write_user(user&);

	~user(){}
};

void bmi(user& U)
{
	U.BMI = U.weight / (U.height * U.height);
}

template <class T>
T bmi(T w, T h)
{
	T res;
	res = w / (h * h);
	return res;
}

ostream& operator <<(ostream& output, const user& U)
{
	output << "BMI : " << U.BMI << endl;
	return output;
}

void file_write_user(user& U)
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
void pause_fn()
{
	cout << "\n";
	cout << "Press Enter to continue...";
	getchar();
	getchar();
}

void pause_wlcm()
{
	cout << "\n";
	cout.width(74);
	cout << "Press Enter to continue...";
	getchar();
}

void menu_main()
{
	system("cls");
	float h, w;
	user U1;
	int cho;
	system("cls");
	cout.width(62);
	cout << "=========\n";
	cout.width(60);
	cout << "M E N U" << endl;
	cout.width(62);
	cout << "=========\n" << endl;
	cout << setw(63); cout << "1. Workout Logs" << endl;
	cout << setw(60); cout << "2. Food Logs" << endl;
	cout << setw(68); cout << "3. Life Time Records" << endl;
	cout << setw(63); cout << "4. Fitness Plan" << endl;
	cout << setw(63); cout << "5. User Details" << endl;
	cout << setw(66); cout << "6. Account Summary" << endl;
	cout << setw(64); cout << "7. Calculate BMI" << endl;
	cout << setw(55); cout << "8. Exit" << endl;

	do
	{
		cout << endl;
		cout << setw(67);
		cout << "Enter your choice: ";
		cin >> cho;
		cout << endl;

		switch (cho)
		{
		case 1:
			U1.menu_wl(U1);
			break;

		case 2:
			U1.menu_fl(U1);
			break;

		case 3:
			U1.menu_lt(U1);
			break;

		case 4:
			U1.menu_pl(U1);
			break;

		case 5:
			U1.menu_user(U1);
			break;

		case 6:
			U1.user_summary();
			pause_fn();
			break;

		case 7:
			for (int i = 0; i < 120; i++)
			{
				cout << "_";
			}
			cout << "\n" << endl;
			cout.width(72);
			cout << "B M I   C A L C U L A T I O N" << endl;
			for (int i = 0; i < 120; i++)
			{
				cout << "_";
			}
			cout << "Enter following details" << endl;
			cout << "Height (in m): ";
			cin >> h;
			cout << "Weight (in kg): ";
			cin >> w;
			cout << "\nBMI: " << bmi(w, h);
			pause_fn();
			menu_main();
			break;

		case 8:
			U1.~user();
			exit(1);
			break;

		default:
			cout << "Invalid Input" << endl;
			break;
		}
	}while (cho != 0);
}


int main()
{
	int i, n = 5;
	for (i = 0; i < n; i++)
	{
		cout << "\n";
	}
	cout << "\n\t\t\t";
	for (int i = 0; i < 70; i++)
	{
		cout << "*";
		Sleep(7);
	}
	cout << "\n" << endl;
	cout.width(74);
	cout << "F I T N E S S  L O G G E R" << endl;
	cout.width(67);
	cout << "W E L C O M E" << endl;
	cout << "\n";
	cout << "\n\t\t\t";
	for (int i = 0; i < 70; i++)
	{
		cout << "*";
		Sleep(7);
	}
	cout.width(45);
	pause_wlcm();
	menu_main();
	return 0;
}