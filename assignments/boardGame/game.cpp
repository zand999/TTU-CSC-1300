

//import classes
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

//declare methods
int getplayernum();
void getplayernames(string[],int);
int rolldice(string);
void activateactionspace(string[],int[],int[],int,int);
void playerfinishedboard(string[],int[],int[],int);

/*

MAIN CLASS

*/

int main(){
  int numplayers,die = 0;
  string play = "y";
  srand(time(0));


  while(play == "y" || play == "Y" ){
    cout << "\nWelcome to TextLand!\n\n";

    //get number of players and validate input
    numplayers = getplayernum();
    //create arrays with player length
    string names[numplayers];
    int boardspace[numplayers],score[numplayers];
    bool gameend = false;
    //call getplayernames method to get names and store them
    getplayernames(names,numplayers);
    //set arrays to zero
    for(int i = 0; i < numplayers; i++){
      boardspace[i] = 0;
      score[i] = 0;
    }
    for(int i = 0; !gameend; i++){
      //roll dice and moce piece
      boardspace[i] += rolldice(names[i]);
      boardspace[i] = (boardspace[i] > 25)? 25 : boardspace[i];
      cout << endl << names[i] << " is now on space " << boardspace[i] << ".\n";
      //call method to hanndle space event
      activateactionspace(names,boardspace,score,numplayers,i);
      //check if need to end loop and call end method
      if(boardspace[i] >= 25){
        //set space to
        boardspace[i] = 25;
        gameend = !gameend;
        playerfinishedboard(names,boardspace,score,numplayers);
      }
      //set back to player 1
      if(i == numplayers-1){
        i = -1;
      }
    }

    //check for new game otherwise end program
    cout << "\nDo you with do play again?(y/n)\n";
    cin >> play;

  }
  return 0;
}

/*

METHODS

*/

/*I created this method for convence
it deals with how many people are playing and
deals with the input*/
int getplayernum(){
  int num;
  //get number of people
  cout << "How many people are playing? (1-20)\n";
  cin >> num;
  //validate inputs
  while((num > 20 && num < 1) || cin.fail()){
    cout << "Please enter a valid number of players\n";
    cin.clear();
    cin.ignore(265,'\n');
    cin >> num;
  }
  return num;
}
/*This method takes in the number of players and
the array for the names and inputs the names for
each of the array indexes*/
void getplayernames(string temp[],int num){
  //clear the \n
  cin.ignore(256,'\n');
  //get names
  for(int i = 0; i < num; i++){
    cout << "Player " << (i + 1) << " what is your name?\n";
    getline(cin,temp[i]);
  }
  cout << "\n---------------\n";
}

/*this function passes in the persons name and returns the
number of spaces the person should move*/

int rolldice(string name){

  cout << endl << name << ", Press ENTER to roll dice.\n";
	cin.get();
  //decide die number
  int dieRoll = (rand() % 6) + 1;
  cout << "You rolled a " << dieRoll << ".\n\n";
  switch(dieRoll){
  	case 1:
  		cout << " _________\n";
  		cout << "|         |\n";
  		cout << "|    o    |\n";
  		cout << "|         |\n";
  		cout << "|_________|\n\n";
  		break;
  	case 2:
  		cout << " _________\n";
  		cout << "|         |\n";
  		cout << "|  o      |\n";
  		cout << "|      o  |\n";
  		cout << "|_________|\n\n";
  		break;
  	case 3:
  		cout << " _________\n";
  		cout << "| o       |\n";
  		cout << "|    o    |\n";
  		cout << "|       o |\n";
  		cout << "|_________|\n\n";
  		break;
  	case 4:
  		cout << " _________\n";
  		cout << "| o     o |\n";
  		cout << "|         |\n";
  		cout << "| o     o |\n";
  		cout << "|_________|\n\n";
  		break;
  	case 5:
  		cout << " _________\n";
  		cout << "| o     o |\n";
  		cout << "|    o    |\n";
  		cout << "| o     o |\n";
  		cout << "|_________|\n\n";
  		break;
  	case 6:
  		cout << " _________\n";
  		cout << "| o     o |\n";
  		cout << "| o     o |\n";
  		cout << "| o     o |\n";
  		cout << "|_________|\n\n";
  		break;
  }
  return dieRoll;
}

/*This method handles what happens when a player finnishes
moving and lands on a new space.*/
void activateactionspace(string namestemp[],int spacetemp[],int scoretemp[],int numplayers,int currentplayer){
  //chose good or bad result
  int karma = rand() % 2;
  ifstream input;
  string line;
  if(karma){
    cout << "\n    .oOOOOOOo.\n";
    cout << "  oO'        'Oo\n";
    cout << " O'  O      O  'O\n";
    cout << "O                O\n";
    cout << "O  Oo,      ,oO  O\n";
    cout << " O. 'OOOOOOOO' .O\n";
    cout << "  Yb.        .dP\n";
    cout << "    'YOOOOOOP'\n";
    cout << "\nYAY!\n";

    //chose the location in the textfile
    karma = (rand() % 20) + 1;
    //open and find location in text file and close it
    input.open("good.txt");
    if(input.is_open()){
      for(int i = 1; i <= karma; i++){
        getline(input,line);
      }
    }
    input.close();
    cout << endl << line << endl;
    //chose number of points to add and add them
    karma = (rand() % 100000) + 1;
    scoretemp[currentplayer] += karma;
    //print result
    cout << "Added " << karma << " to your score.\nYou now have a score of " << scoretemp[currentplayer] << ".\n";


  }else{
    cout <<"\n    .-""""""""-.\n";
    cout <<"  .'            '.\n";
    cout <<" /   O        O   \\\n";
    cout <<":             `    :\n";
    cout <<"|                  | \n";
    cout <<":    .--------.    :\n";
    cout <<" \\  '          '  /\n";
    cout <<"  '.            .'\n";
    cout <<"    '-........-'\n";
    cout << "\nOH NO!\n";

    //chose the location in the textfile
    karma = rand() % 20 + 1;
    //open and find location in text file and close it
    input.open("bad.txt");
    if(input.is_open()){
      for(int i = 1; i <= karma; i++){
        getline(input,line);
      }
    }
    input.close();
    cout << endl << line << endl;
    //chose number of points to add and subtract them
    karma = (rand() % 100000) + 1;
    scoretemp[currentplayer] -= karma;
    //print result
    cout << "Subtracted " << karma << " to your score.\nYou now have a score of " << scoretemp[currentplayer] << ".\n";

  }
  cout << "\n-----------------\n";

}

/*This method handles what happends when a player wins
the game*/
void playerfinishedboard(string namestemp[],int spacetemp[],int scoretemp[],int numplayers){
  int space = 0,player = 0,highestscore = 0;
  //find player with the highest space number
  for(int i = 0; i < numplayers; i++){
    if(spacetemp[i] > space){
      space = spacetemp[i];
      player = i;
    }
  }
  cout << "\nPlayer who surrvived the entire board: " << namestemp[player] << endl;
  //find player with highest score
  for(int i = 0; i < numplayers; i++){
    if(scoretemp[i] > highestscore){
      highestscore = scoretemp[i];
      player = i;
    }
  }
  cout << "Player who has the highest score is: " << namestemp[player] << " with a score of " << highestscore << endl;


}
