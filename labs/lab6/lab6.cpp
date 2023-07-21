

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main(){

    //create variables
    string play = "y";
    int number, input,tries;

    //start game loop
    while(play == "y" || play == "Y"){
      //set seed
      srand(time(0));
      //generate random number and reset values
      number = (rand() % 100) +1;
      tries = 0;

      //start guessing loop
      do{
          //take input
        cout << "Enter a number between 1-100: ";
        cin >> input;
        //validate input
        while(input < 1 && input  > 100){
          cout << "Invalid Number! Enter a number between 1-100: ";
          cin >> input;
        }
        //check input values
        if(input > number)
          cout << "Too High!\n";
        else if(input < number)
          cout << "Too Low\n";

        tries++;

      }while(input != number);

      //print output
      cout << "Correct! You got it in " << tries << " tries!\n\n";

      //check if player wishes to continue
      cout << "Do you wish to continue? (Y/N)\n";
      cin >> play;

    }

}
