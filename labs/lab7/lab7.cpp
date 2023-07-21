

#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;

//create message method
int DisplayCoolMessage(int times){
  cout << "\n  _   _   _   _     _   _   _   _  \n";
  cout << " / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\ \n";
  cout << "  E | v | i | l ) ( C | o | r | p )\n";
  cout << " \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ \n\n";
  return (times + 1);
}


//create sick days method
void GoblinSickDays(){
  int numberOfGoblins,total = 0,input;
  cout << "\nHow many Goblin tellers worked at Gringotts during each of the last three years?";
  cin >> numberOfGoblins;
  for(int i = 1; i <= numberOfGoblins; i++){
    for(int j = 1; j <= 3; j++){
      cout << "\nHow many sick days was Goblin " << i << " out for, during year " << j << " ? ";
      cin >> input;
      total += input;
    }
  }
  cout << "\nThe " << numberOfGoblins << " Goblins were out sick for a total of " << total << " days during the last 3 years.\n\n";



}
//main method
int main(){
  //create variables
  int input;
  int messagePrintTotal = 0;

  //start program loop
  while(input != 3){
  cout << "WELCOME TO GRINGOTT's BANK!\n";
  cout << "Please choose one of the following options:\n";
  cout << "     1 - Enter Goblin Sick Days\n     2 - Display Something Cool\n     3 - End the Program\n\nChoice: ";
  //get menue selection
  cin >> input;
  //validate input
  while((input <= 1 && input >= 3) || cin.fail()){
    cout << "Please choose one of the following options:\n";
    cout << "     1 - Enter Goblin Sick Days\n     2 - Display Something Cool\n     3 - End the Program\n\nChoice: ";
    cin.clear();
    cin.ignore(265,'\n');
    cin >> input;
  }
  //compare input
  switch(input){

    case 1:GoblinSickDays();break;
    case 2:cout << "hello"; messagePrintTotal = DisplayCoolMessage(messagePrintTotal);break;
    case 3:break;
  }


  //check if program is done
  }
  //print final message
  cout << "You chose to display the cool message " << messagePrintTotal << " times.\n\nBye!\n";

}
