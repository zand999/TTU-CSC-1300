
#include <sstream>
#include <iostream>
#include <fstream>
#include "prog5.h"

//provided method
float convertToFloat(string s){
	istringstream i(s);
	float x;
	if (!(i >> x))
		x = 0;
	return x;
}

//custom method to validate int input for a range
void validateInputInt(int min, int max,int &input){
	
	while(((input < min) || (input > max)) || cin.fail()){
    	cout << "Please enter a valid input.\n";
    	cin.clear();
    	cin.ignore(265,'\n');
    	cin >> input;
  	}
}

//method to save dino data to a file
void saveDinosaursToFile(int numDinos, Dinosaurs dinosaurs[]){

	//declare varaible to hold file name
	string input;
	//create new ofstream object
	ofstream file;
	//get the name of the file the user wishes to save the data to
	cout << "What is the name of the text file you wish to write to?\nFilename: ";
	cin >> input;
	//open file and/or create it
	file.open(input);
	
	//save the data to the file with the proper synax
	for(int i = 0; i < numDinos; i++){
		file <<  dinosaurs[i].name << "#" << dinosaurs[i].discription << dinosaurs[i].avgLength << "#" << dinosaurs[i].avgHeight << "#" << dinosaurs[i].location << "#" << dinosaurs[i].isDangerous << "#" << dinosaurs[i].cost.timeForCare << "#"<< dinosaurs[i].cost.costPerHour << "#" << dinosaurs[i].cost.costFoodPerWeek << "#" << dinosaurs[i].cost.costUpkeepPerWeek;
	}
	//clost file
	file.close();

}
int deleteDinosaur(int numDinos, Dinosaurs dinosaurs[]){

	//create variable to hold the dino name
	string name;

	//print out the dinos that can be deleted
	cout << "\nThe following is a list of all the dinosaurs you take care of:\n\n";
	for(int i = 0; i < numDinos; i++){
		cout <<  dinosaurs[i].name << endl;
	}
	//prompt user to get the name of the dino they wish to delete
	cout << "\nWhat dinosaur do you wish to remove?\nDinosaur Name:";
	cin.ignore(256,'\n');
	getline(cin, name);

	//call boolean method to see if the name the user provided matches any of the dinos and if it was removed
	if(moveArrayElements(name,numDinos,dinosaurs)){
		//anounce the removeal of the dino
		cout << "\nYou have removed " << name << endl;
		numDinos--;
		return numDinos;
	}else{
		//anounce the error that the dino could not be removed
		cout << "Error! " << name << " still exists?\n";
		return numDinos;
	}

}
//method to check if dino can be removed and remove it when possible
bool moveArrayElements(string name,int numDinos, Dinosaurs dinosaurs[]){
	//create int location to rember the dino that can be removed
	int location;
	//bool to compare whether or not the dino was found
	bool ifFound = false;
	//attempt to find dino in the list of dinos if found set ifFound to true so it can be deleted
	for(int i = 0; i < numDinos; i++){
		if(dinosaurs[i].name == name){
			ifFound = true;
			location = i;
			break;
		}
	}
	//check if dino was found if overwrite it with the next dino in the list and do so untill the end of the list
	if(ifFound){
		for(int i = location; i < numDinos; i++){
			dinosaurs[i].avgLength = dinosaurs[i + 1].avgLength;
			dinosaurs[i].avgHeight = dinosaurs[i + 1].avgHeight;
			dinosaurs[i].location = dinosaurs[i + 1].location;
			dinosaurs[i].isDangerous = dinosaurs[i + 1].isDangerous;
			dinosaurs[i].cost.timeForCare = dinosaurs[i + 1].cost.timeForCare;
			dinosaurs[i].cost.costPerHour = dinosaurs[i + 1].cost.costPerHour;
			dinosaurs[i].cost.costFoodPerWeek = dinosaurs[i + 1].cost.costFoodPerWeek;
			dinosaurs[i].cost.costUpkeepPerWeek = dinosaurs[i + 1].cost.costUpkeepPerWeek;
		}
		return true;
	}else{
		return false;
	}

}

//method to print statistcs for dinos
void printStatistics(int numDinos, Dinosaurs dinosaurs[]){
	//create num holders
	int total = 0, subTotal = 0;

	cout << "Cost Of Each Dinosaur For One Week: \n\nDinosaur\t\t\t\tCost\n";
	//itterate though each dino
	for(int i = 0; i < numDinos; i++){
		//calculate the total expence for 1 dino
		subTotal = (dinosaurs[i].cost.timeForCare * dinosaurs[i].cost.costPerHour) + dinosaurs[i].cost.costFoodPerWeek + dinosaurs[i].cost.costUpkeepPerWeek;
		//add the expence of the dino to the total
		total += subTotal;
		//print out expence for 1 dino
		cout << dinosaurs[i].name << "\t\t\t\t" << ((dinosaurs[i].name.size() <= 5)? "\t$" : "$") << subTotal << endl;
	}
	//print out the total
	cout << endl << "Total Cost:\t\t\t\t$" << total;

}
//method to print out the data to the screen or to a file
void printDinosaurs(int numDinos, Dinosaurs dinosaurs[]){

	//declare valiables
	string temp,filename;
	int choice;
	//menue to prompt user to print dino data to the screen or to a file
	cout << "What would you like to do?\n\t1. Print Dinosaurs to the Screen\n\t2. Print Dinosaurs to a file\n\tChoose 1 or 2\nChoice: ";
	cin >> choice;
	//validate input
	validateInputInt(1,2,choice);
	//compate user input
	if(choice == 1){
		//start loop to itterate through list of dinos
		for(int i = 0; i < numDinos; i++){

			cout << "\n-----------------------------------------------------\n";
			//set "max" length of each line
			int charWrapMin = 65;
			//get full size of discription
			int length = dinosaurs[i].discription.size();
			//set temp to default value;
				temp = "";
			cout << "Name:\t" << dinosaurs[i].name << endl;
			cout << "Description:\n\t";
	
			//start loop for itteration through each character in the discription
			for(int j = 0; j < length; j++){
				
				if(dinosaurs[i].discription.at(j) == ' '){
					//add character to temp
					temp += dinosaurs[i].discription.at(j);
					//check if temp size is larger than "max" line value
					if(temp.size() > charWrapMin){
						//if so return line and tab
						cout << temp << "\n\t";
						//reset value to start constructing new line
						temp = "";
					}
				}else{
					//if not just add the character to temp
					temp += dinosaurs[i].discription.at(j);
				}
			}
			//print out the last line
			cout << temp << endl;
			//reset temp value
			temp = "";

			//print out the rest of the info
			cout << "Length: \t\t" << dinosaurs[i].avgLength << endl;
			cout << "Height: \t\t" << dinosaurs[i].avgHeight << endl;
			cout << "Location: \t\t" << dinosaurs[i].location << endl;
			cout << "Dangerous?\t\t" << ((dinosaurs[i].isDangerous)? "Yes\n" : "No\n");
			cout << "Number of hours to care for Dinosaur: \t\t $ " << dinosaurs[i].cost.timeForCare << endl;
			cout << "Cost per hours to care for Dinosaur: \t\t $ " << dinosaurs[i].cost.costPerHour << endl;
			cout << "Cost to heed Dinosaur: \t\t\t\t $ " << dinosaurs[i].cost.costFoodPerWeek << endl;
			cout << "Grooming & Supplies Cost: \t\t\t $ " << dinosaurs[i].cost.costUpkeepPerWeek << endl;
		}

	}else if(choice == 2){

		//create new ofstream object
		ofstream file;
		//get the name of the file the user wishes to write to
		cout << "What is the name of the text file you wish to write to?\nFilename: ";
		cin >> filename;
		//open and/or create file
		file.open(filename);

		for(int i = 0; i < numDinos; i++){
			file << "\n-----------------------------------------------------\n";
			//set "max" length of each line
			int charWrapMin = 65;
			//get full size of discription
			int length = dinosaurs[i].discription.size();
			//set temp to default value;
				temp = "";
			file << "Name:\t" << dinosaurs[i].name << endl;
			file << "Description:\n\t";
	
			//start loop for itteration through each character in the discription
			for(int j = 0; j < length; j++){
				
				if(dinosaurs[i].discription.at(j) == ' '){
					//add character to temp
					temp += dinosaurs[i].discription.at(j);
					//check if temp size is larger than "max" line value
					if(temp.size() > charWrapMin){
						//if so return line and tab
						file << temp << "\n\t";
						//reset value to start constructing new line
						temp = "";
					}
				}else{
					//if not just add the character to temp
					temp += dinosaurs[i].discription.at(j);
				}
			}
			//print out the last line
			file << temp << endl;
			//reset temp value
			temp = "";

			//print out the rest of the info
			file << "Length: \t\t" << dinosaurs[i].avgLength << endl;
			file << "Height: \t\t" << dinosaurs[i].avgHeight << endl;
			file << "Location: \t\t" << dinosaurs[i].location << endl;
			file << "Dangerous?\t\t" << ((dinosaurs[i].isDangerous)? "Yes\n" : "No\n");
			file << "Number of Hours to car for Dinosaur: \t\t $ " << dinosaurs[i].cost.timeForCare << endl;
			file << "Cost Per Hours to Care for Dinosaur: \t\t $ " << dinosaurs[i].cost.costPerHour << endl;
			file << "Cost to Feed Dinosaur: \t\t\t\t $ " << dinosaurs[i].cost.costFoodPerWeek << endl;
			file << "Grooming & Supplies Cost: \t\t\t $ " << dinosaurs[i].cost.costUpkeepPerWeek << endl;
		}
		cout << "\n-----------------------------------------------------\n";
	}

	

}
	
    