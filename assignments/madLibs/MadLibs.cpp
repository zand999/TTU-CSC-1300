

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

int showMenuGetChoice();
string *createStringArray(int);
void getInfoFromUser(int, string *questions, string *answers);
void printStory(int, int, string *answers);


int main(){

  int choice,size;

  //start game loop
  while(choice != 4){

    //create pointer varaibles
    string* questions = nullptr;
    string* answers = nullptr;
    //start ifstream
    ifstream get;
    //get game choice and assign it to int choice
    choice = showMenuGetChoice();
    //open in correct text file
    if(choice == 1){
      get.open("starWars.txt");
    }else if(choice == 2){
      get.open("dog.txt");
    }else if(choice == 3){
      get.open("pirate.txt");
    }else if(choice == 4){
      break;
    }
    //check if open
    if(get.is_open()){
      //read first line to figure out array size

      get >> size;
      //create arrays
      questions = createStringArray(size);
      answers = createStringArray(size);
      //idk why this fixes a few things
      get.ignore(256,'\n');
      //fill in the arrays with data from text file
      for(int i = 0; i < size; i++){
        getline(get,*(questions+i));
      }

      //get all of the answers from the user
      getInfoFromUser(size,questions,answers);
      //close file
      get.close();

    }else{
      cout << "Error opening file program failed";
    }

    cout << "\n\n";
    //print out the story baised on resaults
    printStory(choice,size,answers);
  }

  return 0;
}

int showMenuGetChoice(){

  int choice;
  //display menue
  cout << "Let's play some MADLIBS!!\n\nChoose a MAD LIBS game:\n";
  cout << "1. The Power of the Force (Star Wars Mad Libs)\n";
  cout << "2. Dog Days (Dog Ate My Mad Libs)\n";
  cout << "3. Talk Like a Pirate (Pirate Mab Libs)\n";
  cout << "4. END GAME\n\nCHOOSE 1-4:";
  //get choice
  cin >> choice;
  //validate input
  while((choice > 4 && choice < 1) || cin.fail()){
    cout << "Please enter a valid choice.\n";
    cin.clear();
    cin.ignore(265,'\n');
    cin >> choice;
  }
  //return choice
  return choice;

}

string *createStringArray(int size){
  //create new string array and return it to a pointer
  return new string[size];

}

void getInfoFromUser(int size, string *questions, string *answers){
  //get input from user and assign it to the loction in the pointer
  for(int i = 0; i < size;i++){

    cout << *(questions + i) << endl;
    cin >> *(answers + i);

  }


}


void printStory(int choice, int size, string *answers){
  //variable to hold line from story template
  string text;
  //start ifsteam
  ifstream get;

  //this section here is to prove I can print out both user and story input seperatly properly
  /*
  //open correct file
  if(choice == 1){
    get.open("starWarsText.txt");
  }else if(choice == 2){
    get.open("dogText.txt");
  }else if(choice == 3){
    get.open("pirateText.txt");
  }


  if(get.is_open()){
    cout << "\n--------------------------\n\n";

    //print out story template
    for(int i = 0; i < size; i++){

      getline(get,text);
      cout << text << "\n";
    }
    //need to get the last line
    getline(get,text);
    cout << text << "\n";
    cout << "\n\n--------------------------\n\n";

    //print out user inputs
    for(int i = 0; i < size; i++){
      cout << " " << *(answers + i) << " ";
    }
    cout << "\n\n--------------------------\n\n";
    for(int i = 0; i < size; i++){

      getline(get,text);


      cout << " " << text << " ";
      cout << " " << *(answers + i) << " ";
    }

  }else{
    cout << "Error Opening File, Failed to create story.";
  }
  get.close();
  */


  //This section is suppose to combine the two
  if(choice == 1){
    get.open("starWarsText.txt");
  }else if(choice == 2){
    get.open("dogText.txt");
  }else if(choice == 3){
    get.open("pirateText.txt");
  }


  if(get.is_open()){

    cout << "\n\n--------------------------\n\n";
    for(int i = 0; i < size; i++){

      getline(get,text);
      //FOR SOME REASON TO PRINT OUT I CONNOT USE text << " "; and intead have to use text << "\n"
      cout << text << " " << *(answers + i) << " ";
      //THIS WORKS THOUGH \/ \/ \/ \/ \/ \/
      //cout << text << "\n" << *(answers + i) << " ";

    }
    //get last line of story
    getline(get,text);
    cout << text << "\n";
    cout << "\n--------------------------\n\n";

    /*string story = "";

    for(int i = 0; i < size; i++){

      getline(get,text);

      story += text + *(answers + i);
      
    }
    cout << story << endl;*/

  }else{
    cout << "Error Opening File, Failed to create story.";
  }
  //clost file
  get.close();
}
