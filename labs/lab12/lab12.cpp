

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;
struct playerInfo{

	string name;
	string hometown;
	int age;
	int numGames;

};

int *makeArray(int);

int main(){
	//declare data
	int numPlayers,mostHours,leastHours;
	string mostPlayer,leastPlayer;
	//get number of players
	cout << "How many esports players are at TTU?\n";
	cin >> numPlayers;
	//clear cin
	cin.ignore(265,'\n');
	
	//create structure array to store data on each player
	struct playerInfo player[numPlayers];
	//create pointer array to store number of hours of each game a player played
	int *playerHours[numPlayers];

	//start for loop to itterate through each player
	for(int i = 0; i < numPlayers; i++){

		cout << "PLAYER " << i +1 << endl;
		//get player name
		cout << "\tNAME: ";
		getline(cin, player[i].name);
		//get player hometown
		cout << "\tHOMETOWN: ";
		getline(cin, player[i].hometown);
		//get player age
		cout << "\tAGE:";
		cin >> player[i].age;
		//find how many different games the current player plays
		cout << "\tHow many games does " << player[i].name << " play? ";
		cin >> player[i].numGames;

		//create int array to store play time for each game for current player
		playerHours[i] = makeArray(player[i].numGames);

		//start for loop to get hours for each game
		for(int j = 0; j < player[i].numGames; j++){
			//get hours for each game and store it for the current player
			cout << "\t\tNumber of hours " << player[i].name << " played game " << j + 1 << ": ";
			cin >> playerHours[i][j];
		}
		//clear cin
		cin.ignore(265,'\n');
	}

	//set default values
	mostHours = playerHours[0][0];
	leastHours = playerHours[0][0];
	mostPlayer = player[0].name;
	leastPlayer = player[0].name;
	//start for loop for itterating through each player
	for(int i = 0; i < numPlayers; i++){
		//start for loop for itterating though each different game of the current player
		
		for(int j = 0; j < player[i].numGames; j++){
			//check if current value is the biggest, if not check if oldest
			if(playerHours[i][j] >= mostHours){
				//save name of player and highest value
				mostHours = playerHours[i][j];
				mostPlayer = player[i].name;
			}else if(playerHours[i][j] <= leastHours){
				//save name of player and lowest value
				leastHours = playerHours[i][j];
				leastPlayer = player[i].name;
			}

		}
		
	}
	//print out the results
	cout << "The player who played the most hours (" << mostHours << ") is " << mostPlayer << ".\n";
	cout << "The player who played the leset hours (" << leastHours << ") is " << leastPlayer << ".\n";
	




}
//create int array
int *makeArray(int size){
  return new int[size];
}

