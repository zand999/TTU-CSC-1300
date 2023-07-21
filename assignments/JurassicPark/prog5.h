

#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

//structure for cost data
struct Cost{

	int timeForCare;
	int costPerHour;
	int costFoodPerWeek;
	int costUpkeepPerWeek;

};
//structre for baice dino into
struct Dinosaurs{

	string name;
	string discription;
	double avgLength;
	double avgHeight;
	string location;
	bool isDangerous;
	Cost cost;

};

//create methods
int deleteDinosaur(int, Dinosaurs dinosaurs[]);
bool moveArrayElements(string, int, Dinosaurs dinosaurs[]);
void printDinosaurs(int, Dinosaurs dinosaurs[]);
void printStatistics(int, Dinosaurs dinosaurs[]);
void saveDinosaursToFile(int, Dinosaurs dinosaurs[]);
float convertToFloat(string);
void validateInputInt(int,int,int &input);

#endif