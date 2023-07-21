


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

//structure for cost
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

void printDinosaurs(struct dino);

int main(){

	//create new stuctre dino
	Dinosaurs dino;

	//temp holding variable
	string temp;

	cout << "Please enter the dinosaur data when prompted: \n";
	//get dino name
	cout << "Name: ";
	getline(cin,dino.name);
	//get dino description
	cout << "Description: ";
	getline(cin,dino.discription);
	//get avg length of dino
	cout << "Average Length: ";
	cin >> dino.avgLength;
	//get avg dino height
	cout << "Average Height: ";
	cin >> dino.avgHeight;
	//clear cin
	cin.ignore(265,'\n');
	//get dino location info
	cout << "Location: ";
	getline(cin,dino.location);
	//get whether or not dino is dangerous
	cout << "Is It Dangerous (y/n): ";
	cin >> temp;
	//set boolean based on text input
	if(temp == "y"){
		dino.isDangerous = true;
	}else if(temp == "n"){
		dino.isDangerous = false;
	}else{
		cout << "Error setting danger!\n";
	}
	//get time for case info
	cout << "How many hours do you spend caring for the " << dino.name << "?\nNumber Hours: ";
	cin >> dino.cost.timeForCare;
	//get cost per hour info
	cout << "What is the cost per hour for caring for the " << dino.name << "?\nCost Per Hour: ";
	cin >> dino.cost.costPerHour;
	//get food cost for dino info
	cout << "How much money do you spend on food for the  " << dino.name << "?\nFood Cost: ";
	cin >> dino.cost.costFoodPerWeek;
	//get suppies and upkeep per week info
	cout << "How much money do you spend on grooming and medical supplies for the " << dino.name << "?\nSupply Cost: ";
	cin >> dino.cost.costUpkeepPerWeek;

	//IGNORE ME! printDinosaurs(dino);

	//set "max" length of each line
	int charWrapMin = 65;
	//get full size of discription
	int length = dino.discription.size();
	//set temp to default value;
	temp = "";
	cout << "Name:\t" << dino.name << endl;
	cout << "Description:\n\t";

	//start loop for itteration through each character in the discription
	for(int i = 0; i < length; i++){
		//check to see if the current character is a space
		if(dino.discription.at(i) == ' '){
			//add character to temp
			temp += dino.discription.at(i);
			//check if temp size is larger than "max" line value
			if(temp.size() > charWrapMin){
				//if so return line and tab
				cout << temp << "\n\t";
				//reset value to start constructing new line
				temp = "";
			}
		}else{
			//if not just add the character to temp
			temp += dino.discription.at(i);
		}
	}
	//print out the last line
	cout << temp << endl;
	//reset temp value
	temp = "";
	//print out the rest of the info
	cout << "Length: \t\t" << dino.avgLength << endl;
	cout << "Height: \t\t" << dino.avgHeight << endl;
	cout << "Location: \t\t" << dino.location << endl;
	cout << "Dangerous?\t\t" << ((dino.isDangerous)? "Yes\n" : "No\n");
	cout << "Number of Hours to car for Dinosaur: \t\t $ " << dino.cost.timeForCare << endl;
	cout << "Cost Per Hours to Care for Dinosaur: \t\t $ " << dino.cost.costPerHour << endl;
	cout << "Cost to Feed Dinosaur: \t\t\t\t $ " << dino.cost.costFoodPerWeek << endl;
	cout << "Grooming & Supplies Cost: \t\t\t $ " << dino.cost.costUpkeepPerWeek << endl;




}
/*void printDinosaurs(struct dino){

	int charWrapMin = 55;
	int length = dino.discription.size();
	string temp = "";
	cout << "Name:\t\t" << dino.name << endl;
	cout << "Description:\n";
	for(int i = 0; i < length; i++){
		if(dino.discription.at(i) == " "){
			temp += dino.discription.at(i);
			if(temp.size() > 55){
				cout << temp << "\n\t";
				temp = "";
			}
		}else{
			temp += dino.discription.at(i);
		}
	}
	cout << temp << endl;
	temp = "";
	cout << "Length: \t\t" << dino.avgLength << endl;
	cout << "Height: \t\t" << dino.avgHeight << endl;
	cout << "Location: \t\t" << dino.location << endl;
	cout << "Dangerous?\t\t" << ((dino.isDangerous)? "Yes\n" : "No\n");
	cout << "Number of Hours to car for Dinosaur: \t\t $ " << dino.cost.timeForCare << endl;
	cout << "Cost Per Hours to Care for Dinosaur: \t\t $ " << dino.cost.costPerHour << endl;
	cout << "Cost to Feed Dinosaur: \t\t $ " << dino.cost.costFoodPerWeek << endl;
	cout << "Grooming & Supplies Cost: \t\t $ " << dino.cost.costUpkeepPerWeek << endl;


}*/






