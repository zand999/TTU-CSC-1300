
#include "prog5.h"

int enterDinosaurs(int, Dinosaurs dinosaurs[]);

int main(){

	//create array of dinosaurs
	Dinosaurs dinosaurs[100];
	//declare vaiables
	int choice = 0,numDinos = 0;
	string input;

	//menue choice
	cout << "\nWhat would you like to do?\n\t1. Enter some Dinosaurs\n\t2. Delete a Dinosaur\n\t3. List/Print Dinosaurs\n\t4. Print Dinosaur Cost\n\t5. End Program\nChoice: ";
	cin >> choice;

	//validate int input
	validateInputInt(1,5,choice);

	//start program loop
	while(choice != 5){
		//call correct method for user choice
		switch(choice){
			//Enter in dinosaurs either by file or by hand and return the new number of dinos
			case 1:numDinos = enterDinosaurs(numDinos,dinosaurs);break;
			//Call method to delete dinos and return nuew number of dinos
			case 2:numDinos = deleteDinosaur(numDinos,dinosaurs);break;
			//call method to print dino info to the screen or to a text file
			case 3:printDinosaurs(numDinos,dinosaurs);break;
			//call method to print money statistics
			case 4:printStatistics(numDinos,dinosaurs);break;
		}

		//get menue chocie
		cout << "\nWhat would you like to do?\n\t1. Enter some Dinosaurs\n\t2. Delete a Dinosaur\n\t3. List/Print Dinosaurs\n\t4. Print Dinosaur Cost\n\t5. End Program\nChoice: ";
		cin >> choice;
		//validate input
		validateInputInt(1,5,choice);
	}
	//check if user wishes to save data to a file
	cout << "Would you like to save your dinosaurs to a file? (y/n): ";
	cin >> input;
	//compare user input
	if(input == "y"){
		//call method to save the data to a file
		saveDinosaursToFile(numDinos,dinosaurs);
	}

	return 0;
}



int enterDinosaurs(int numDinos, Dinosaurs dinosaurs[]){
	//declare valiables
	int choice,size,count = 0;
	string filename,temp,input;
	//check if zoo is at max compasity
	if(numDinos >= 100 ){

		cout << "You cannot enter more dinosaurs as the zoo is as max capacity\n";
		return numDinos;

	}else if(numDinos < 0){
		cout << "Error dinosaurs is negative!\nresetting to default values!\n";
		

	}else{
		//get user choice to get dinos from file or by hand
		cout << "What do you want to do?\n\t1. Load my dinosaurs from a file.\n\t2. Enter one dinosaur manually.\n\tChoose 1 or 2.\nChoice: ";
		cin >> choice;
		//validate input
		validateInputInt(1,2,choice);
		//compare input
		if(choice == 1){
			//get info from file
			//create new ifstream object
			ifstream file;
			//get name of file to import
			cout << "\nWhat is the name of the file with yout list of dinosaurs? (ex: filename.txt)\nFilename: ";
			cin.ignore(256,'\n');
			getline(cin,filename);
			
			//open file
			file.open(filename);
			//check if file is open
			if(file.is_open()){

				//take in data from file and assign it to input
				getline(file,input);
				//get size of input and assign the number to int size
				size = input.size();
				
				//itterate though the input for each char
				for(int i = 0,j = 0; i < size; i++){
					//keep adding chars to temp until program reaches # or end of string
					//check if char is # 
					if(input.at(i) == '#'){
						
						//determine which variable temp needs through j and increase j by one to choose next variable that needs to be filled
						//once it reaches the last variable increase the number of dinos so fill new stucture
						switch(j){
							case 0: 
								dinosaurs[numDinos].name = temp;
								temp = ""; j++; 
								break;

							case 1: 
								dinosaurs[numDinos].discription = temp;
								temp = "";j++;
								break;

							case 2: 
								dinosaurs[numDinos].avgLength = convertToFloat(temp);
								temp = "";
								j++;
								break;

							case 3: 
								dinosaurs[numDinos].avgHeight = convertToFloat(temp);
								temp = "";
								j++;
								break;

							case 4: 
								dinosaurs[numDinos].location = temp;
								temp = "";
								j++;
								break;

							case 5: 
								dinosaurs[numDinos].isDangerous = convertToFloat(temp);
								temp = "";
								j++;
								break;

							case 6: 
								dinosaurs[numDinos].cost.timeForCare = convertToFloat(temp); 
								temp = "";
								j++;
								break;

							case 7: 
								dinosaurs[numDinos].cost.costPerHour = convertToFloat(temp); 
								temp = "";
								j++;
								break;

							case 8: 
								dinosaurs[numDinos].cost.costFoodPerWeek = convertToFloat(temp); 
								temp = "";
								j++;
								break;

							case 9: 
								dinosaurs[numDinos].cost.costUpkeepPerWeek = convertToFloat(temp); 
								j = 0; 
								temp = ""; 
								numDinos++; 
								break;
						}

					
					}else{
						//if not just add the character to temp
						temp += input.at(i);
					}

				}
				//assign the last set of test to the correct variable
				dinosaurs[numDinos].cost.costUpkeepPerWeek = convertToFloat(temp);
				//reset temp
				temp = "";
				//increate total num of dinos by one
				numDinos++;
				

			}else{
				cout << "Error opening file! Does file exist?\n";
			}
			//close the file
			file.close();


		}else if(choice == 2){
			//input data by hand
			//need to set defualt value for while loop
			choice = 1;

			while(choice == 1){
			

				cout << "Please enter the dinosaur data when prompted: \n";
				//get dinosaurs[numDinos] name
				cin.ignore(256,'\n');
				cout << "Name: ";
				getline(cin,dinosaurs[numDinos].name);
				cout << "Description: ";
				getline(cin,dinosaurs[numDinos].discription);
				//get avg length of dinosaurs[numDinos]
				cout << "Average Length: ";
				cin >> dinosaurs[numDinos].avgLength;
				//get avg dinosaurs[numDinos] height
				cout << "Average Height: ";
				cin >> dinosaurs[numDinos].avgHeight;
				//clear cin
				cin.ignore(265,'\n');
				//get dinosaurs[numDinos] location info
				cout << "Location: ";
				getline(cin,dinosaurs[numDinos].location);
				//get whether or not dinosaurs[numDinos] is dangerous
				cout << "Is It Dangerous (y/n): ";
				cin >> temp;
				//set boolean based on text input
				if(temp == "y"){
					dinosaurs[numDinos].isDangerous = true;
				}else if(temp == "n"){
					dinosaurs[numDinos].isDangerous = false;
				}else{
					cout << "Error setting danger!\n";
				}
				//get time for case info
				cout << "How many hours do you spend caring for the " << dinosaurs[numDinos].name << "?\nNumber Hours: ";
				cin >> dinosaurs[numDinos].cost.timeForCare;
				//get cost per hour info
				cout << "What is the cost per hours for caring for the " << dinosaurs[numDinos].name << "?\nCost Per Hour: ";
				cin >> dinosaurs[numDinos].cost.costPerHour;
				//get food cost for dinosaurs[numDinos] info
				cout << "How much money do you spend on food for the  " << dinosaurs[numDinos].name << "?\nFood Cost: ";
				cin >> dinosaurs[numDinos].cost.costFoodPerWeek;
				//get suppies and upkeep per week info
				cout << "How much money do you spend on grooming and medical supplies for the " << dinosaurs[numDinos].name << "?\nSupply Cost: ";
				cin >> dinosaurs[numDinos].cost.costUpkeepPerWeek;

				//increase the total number of dinos by one
				numDinos++;

				//menue to see if user wishes to add more dinos
				cout << "Do you want to add another dinosuar?\n\t1. Yes\n\t2. No\nChoice: ";
				cin >> choice;
			}
			
		}

	}
	
	//return the new number of dinos
	return numDinos;
}
	

