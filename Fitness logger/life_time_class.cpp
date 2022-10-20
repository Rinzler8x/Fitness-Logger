#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Life_time
{
	char total_steps;
	char total_calories;
	char total_distance;
	char total_time;

public:
	Life_time()
	{
		total_steps = 0;
		total_calories = 0;
		total_distance = 0;
		total_time = 0;
	}

	Life_time()
	{
		total_steps = 0;
		total_calories = 0;
		total_distance = 0;
		total_time = 0;
	}

	void display()
	{
		cout << "Total Steps: " << total_steps << endl;
		cout << "Total Calories: " << total_calories << endl;
		cout << "Total Distance: " << total_distance << endl;
		cout << "Total Time: " << total_time << endl;
	}
};