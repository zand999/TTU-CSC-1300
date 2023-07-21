

#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;

//string input and randomizer
string strdecision(string item){
  //temp variables
  int random;
  string info[3];
  //get input
  cout << flush;
  cout << "Enter in one " << item << " you like.\n";
  getline(cin, info[0]);
  cout << "Enter in another " << item << " you like.\n";
  getline(cin, info[1]);
  cout << "Enter in a " << item << " you dislike.\n";
  getline(cin, info[2]);
  cout << "\n" << flush;
  //random num
  random = rand() % 3;
  switch(random){
    case 0: return info[0];break;
    case 1: return info[1];break;
    case 2: return info[2];break;

  }
}


int main(){
  //create variables
  string name;
  int numSmall[3],numBig[3];
  bool play = true;
  //start loop
  do{
    string name,location,job,company,car,home,input = "y";
    int children[3],salary[3],temp;
    //take inputs;
    name = strdecision("name");
    cout << "Enter 3 numbers between 1-100, seperated by a space.\n";
    cin >> children[0];
    cin >> children[1];
    cin >> children[2];

    //validate int input
    while(children[0] < 1 || children[0] >100){
      cout << "The first number you entered is invalid.\nPlease enter a number between 1-100.\n";
      cin >> children[0];
    }
    while(children[1] < 1 || children[1] >100){
      cout << "The Second number you entered is invalid.\nPlease enter a number between 1-100.\n";
      cin >> children[1];
    }
    while(children[2] < 1 || children[2] >100){
      cout << "The Third number you entered is invalid.\nPlease enter a number between 1-100.\n";
      cin >> children[2];
    }
    getline(cin,input);
    //take more inputs
    cout << endl;
    location = strdecision("city, state");
    job = strdecision("job title");
    company = strdecision("compnay or restaurant");
    cout << "Enter 3 numbers between 10,000-500,000, seperated by a space. and no comma\n";
    cin >> salary[0];
    cin >> salary[1];
    cin >> salary[2];


    //validate inputs
    while(salary[0] < 10000 || salary[0] >500000){
      cout << "The first number you entered is invalid.\nPlease enter a number between 10,000-500,000.\n";
      cin >> salary[0];
    }
    while(salary[1] < 10000 || salary[1] >500000){
      cout << "The Second number you entered is invalid.\nPlease enter a number between 10,000-500,000.\n";
      cin >> salary[1];
    }
    while(salary[2] < 10000 || salary[2] >500000){
      cout << "The Third number you entered is invalid.\nPlease enter a number between 10,000-500,000.\n";
      cin >> salary[2];
    }
    getline(cin,input);
    cout << endl;
    //take more inputs
    car = strdecision("car");

    //decide on house
    switch(rand() % 4){
      case 0: home = "mansion"; break;
      case 1: home = "apartment"; break;
      case 2: home = "shack"; break;
      case 3: home = "house"; break;
    }

    //output
    cout << "*********** Mash Results **********\n";
    cout << "You will live in a " << home << ".\n";
    cout << "You will be happly married to " << name << ".\n";
    cout << "You and yout spouse will have " << children[rand() % 3] << " kids.\n";
    cout << "You will live in " << location << ".\n";
    cout << "You will work at " << company << " as a " << job << " making $" << salary[rand() % 3] << " a year.\n";
    cout << "You will drive a " << car << ".\n\n\n";


    //check if user wishes to continue
    cout << "Do you wish to play again? Y/N \n";
    cin >> input;
    if(input != "y" && input != "Y")
      play = !play;

  }while(play);

  return 0;
}
