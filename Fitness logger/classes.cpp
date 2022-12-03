#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
int count_wl = 0;
int count_fl = 0;

using namespace std;

void pause_fn();

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

	void wl_edit()
	{
		int cho;
		cout << "Enter workout log to edit: ";
		cin >> cho;
		cho--;
		if (cho <= ::count_wl) {
			cout << "Enter new details for following" << endl;
			cout << "Type of excercise: ";
			cin >> excercise_wl[cho];
			cout << "No of Steps: ";
			cin >> steps_wl[cho];
			cout << "Calories burnt: ";
			cin >> calories_wl[cho];
			cout << "Distance travelled: ";
			cin >> distance_wl[cho];
			cout << "Average heart rate: ";
			cin >> bpm_wl[cho];
		}
		else
			cout << "Invalid Input" << endl;
	}

	int wl_delete()
	{
		int cho;
		cout << "Enter workout log to delete: ";
		cin >> cho;
		cho--;
		if (cho <= ::count_wl) {
			cout << "Deleting the following log:" << endl;
			cout << "Excercise: " << excercise_wl[cho] << endl;
			cout << "Steps: " << steps_wl[cho] << endl;
			cout << "Calories: " << calories_wl[cho] << endl;
			cout << "Distance: " << distance_wl[cho] << endl;
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
			return cho;
		}
		else
			cout << "Invalid Input" << endl;
	}

	friend void file_write_wl(workout_log &);
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

	void fl_edit()
	{
		int cho;
		cout << "Enter food log to edit: ";
		cin >> cho;
		cho--;
		if (cho <= ::count_fl) {
			cout << "Enter new details for following: " << endl;
			cout << "Type of food (Breakfast / Lunch / Dinner / Others): ";
			cin >> type_fl[cho];
			cout << "Amount of Calories: ";
			cin >> calories_fl[cho];
		}
		else
			cout << "Invalid Input" << endl;
	}

	void fl_delete()
	{
		int cho;
		cout << "Enter food log to delete: ";
		cin >> cho;
		cho--;
		if (cho <= ::count_fl) {
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

	friend void file_write_fl(food_log &);
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
		cout << "Fitness Plan Entry:" << endl;
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
		cout << "Fitness Plan" << endl;
		cout << "Trainer Name: " << pl_trainer << endl;
		cout << "Gym Name: " << pl_gym << endl;
		cout << "Fees: " << pl_fees << endl;
		cout << "Plan Duration: " << pl_duration << endl;
		cout << "Plan Type: " << pl_type << endl;
	}

	void pl_edit()
	{
		cout << "Enter new details for following:" << endl;
		cout << "Trainer Name: ";
		cin >> pl_trainer;
		cout << "Gym Name: ";
		cin >> pl_gym;
		cout << "Fees: ";
		cin >> pl_fees;
		cout << "Plan Duration:	";
		cin >> pl_duration;
		cout << "Plan Type: ";
		cin >> pl_type;
	}

	void pl_delete()
	{
		cout << "Fitness plan deleted" << endl;
		pl_trainer = '0';
		pl_gym = '0';
		pl_fees = 0;
		pl_duration = 0;
		pl_type = '0';
	}

	friend void file_write_pl(plan &);
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
		distance_lt += distance_wl[::count_wl];
	}

	void operator -(int cho)
	{
		steps_lt -= steps_wl[cho];
		calories_lt -= calories_wl[cho];
		distance_lt -= distance_wl[cho];
	}

	void lt_view()
	{
		cout << "Life Time Records" << endl;
		cout << "Total Steps: " << steps_lt << endl;
		cout << "Total Calories: " << calories_lt << endl;
		cout << "Total Distance Travelled: " << distance_lt << endl;
	}

	void lt_delete()
	{
		cout << "Life Time Records are reset" << endl;
		steps_lt = 0;
		calories_lt = 0;
		distance_lt = 0;
	}

	friend void file_write_lt(lifetime &);
};

void file_write_lt(lifetime &L)
{
	ofstream fout_lt;
	fout_lt.open("lifetime.txt", ios::out);
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
		cout << "Id: ";
		cin >> ID;
		cout << "Name: ";
		cin >> name;
		cout << "Age: ";
		cin >> age;
		cout << "Height: ";
		cin >> height;
		cout << "Weight: ";
		cin >> weight;
		cout << "Blood group: ";
		cin >> blood_grp;
	}

	void bmi()
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

	void user_edit()
	{
		cout << "Enter new details to following:" << endl;
		cout << "Id: ";
		cin >> ID;
		cout << "Name: ";
		cin >> name;
		cout << "Age: ";
		cin >> age;
		cout << "Height: ";
		cin >> height;
		cout << "Weight: ";
		cin >> weight;
		cout << "Blood group: ";
		cin >> blood_grp;
	}

	void user_delete()
	{
		cout << "User details are deleted" << endl;
		ID = 0;
		name = '0';
		age = 0;
		height = 0;
		weight = 0;
		blood_grp = '0';
	}

	friend void file_write_user(user &);
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
void pause_fn()
{
	cout << "Enter any key to continue...";
	getchar();
	getchar();
}

void menu_wl(user &U1)
{
	int cho = 0;
	int d{};
	do {
		system("cls");
		cout << "Workout Log Menu" << endl;
		cout << "1. Add new workout" << endl;
		cout << "2. View workout logs" << endl;
		cout << "3. Edit workout log" << endl;
		cout << "4. Delete workout log" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> cho;

		switch (cho)
		{
		case 1:
			U1.wl_entry();
			pause_fn();
			+U1;
			::count_wl++;
			break;

		case 2:
			U1.wl_view();
			pause_fn();
			break;

		case 3:
			U1.wl_edit();
			pause_fn();
			break;

		case 4:
			d = U1.wl_delete();
			pause_fn();
			U1-(d);
			break;

		case 5:
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

void menu_fl(user &U1)
{
	int cho;
	do {
		system("cls");

		cout << "Food Log Menu" << endl;
		cout << "1. Add new food log" << endl;
		cout << "2. View food logs" << endl;
		cout << "3. Edit food log" << endl;
		cout << "4. Delete food log" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> cho;

		switch (cho)
		{
		case 1:
			U1.fl_entry();
			pause_fn();
			break;

		case 2:
			U1.fl_view();
			pause_fn();
			break;

		case 3:
			U1.fl_edit();
			pause_fn();
			break;

		case 4:
			U1.fl_delete();
			pause_fn();
			break;

		case 5:
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

void menu_pl(user& U1)
{
	int cho;

	do {
		system("cls");

		cout << "Fitness Plan Menu" << endl;
		cout << "1. Add fitness plan" << endl;
		cout << "2. View fitness plan" << endl;
		cout << "3. Edit fitness plan" << endl;
		cout << "4. Delete fitness plan" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> cho;

		switch (cho)
		{
		case 1:
			U1.pl_entry();
			pause_fn();
			break;

		case 2:
			U1.pl_view();
			pause_fn();
			break;

		case 3:
			U1.pl_edit();
			pause_fn();
			break;

		case 4:
			U1.pl_delete();
			menu_main();
			break;

		case 5:
			file_write_pl(U1);
			pause_fn();
			break;

		default:
			cout << "Invalid Input" << endl;
			pause_fn();
			break;
		}
	} while (cho != 0);
}

void menu_lt(user &U1)
{	
	int cho;

	do {
		system("cls");

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
			pause_fn();
			break;

		case 2:
			U1.lt_delete();
			pause_fn();
			break;

		case 3:
			file_write_lt(U1);
			menu_main();
			break;

		default:
			cout << "Invalid Input" << endl;
			pause_fn();
			break;
		}
	} while (cho != 0);
}

void menu_user(user &U1)
{	
	int cho;

	do {
		system("cls");

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
			pause_fn();
			break;

		case 2:
			U1.user_view();
			pause_fn();
			break;

		case 3:
			U1.user_edit();
			pause_fn();
			break;

		case 4:
			U1.user_delete();
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

void menu_main()
{
	system("cls");
	user U1;
	int cho;
	cout << "Menu" << endl;
	cout << "1. Workout Logs" << endl;
	cout << "2. Food Logs" << endl;
	cout << "3. Life Time Records" << endl;
	cout << "4. Fitness Plan" << endl;
	cout << "5. User Details" << endl;
	cout << "6. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> cho;

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
		menu_pl(U1);
		break;

	case 5:
		menu_user(U1);
		break;

	case 6:
		exit(1);
		break;

	default:
		cout << "Invalid Input" << endl;
		break;
	}
}


int main()
{
	menu_main();
	return 0;
}