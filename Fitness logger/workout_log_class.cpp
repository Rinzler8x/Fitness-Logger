#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Workout_log
{
	char workout_steps;
	char workout_calories;
	char workout_distance;
	char workout_time;
	char workout_avg_bpm;
	char workout_excerise;
	char workout_date;

public:
	Workout_log()
	{
		workout_steps = 0;
		workout_calories = 0;
		workout_distance = 0;
		workout_time = 0;
		workout_avg_bpm = 0;
		workout_excerise = 0;
		workout_date = 0;
	}

	Workout_log()
	{
		workout_steps = 0;
		workout_calories = 0;
		workout_distance = 0;
		workout_time = 0;
		workout_avg_bpm = 0;
		workout_excerise = 0;
		workout_date = 0;
	}

	void display()
	{
		cout << "Steps: " << workout_steps << endl;
		cout << "Calories: " << workout_calories << endl;
		cout << "Distance: " << workout_distance << endl;
		cout << "Workout Time: " << workout_time << endl;
		cout << "Average Heart Rate: " << workout_avg_bpm << endl;
		cout << "Excerise Type: " << workout_excerise << endl;
		cout << "Date: " << workout_date << endl;
	}
	
};