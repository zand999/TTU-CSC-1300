
#include <iostream>
using namespace std;

int main(){

  //Decleration of Variables
  string input = "y";
  int numCorrect;

  //Start of quiz loop
  while(input == "y" || input == "Y"){
    //set correct to 0 at start
    numCorrect = 0;

    cout << "\nWho is the main character in KonoSuba?\n";
    cout << "a.) Megumin\nb.) Kazuma\nc.) Aqua\nd.) Lalatina\ne.) Wiz\n\n";
    //take input
    cin >> input;
    //compute answer

    if(input == "b" || input == "B")
      numCorrect++;

    //repeat 9 more times
    cout << "\nWho is the main character in Log Horizon?\n";
    cout << "a.) Nyanta\nb.) Naotsugu\nc.) Akatsuki\nd.) Lalatina\ne.) Shiroe\n\n";

    cin >> input;
    if(input == "e" || input == "E")
      numCorrect++;

    cout << "\nWho is best girl in Re:Zero?\n";
    cout << "a.) Emilia\nb.) Pack\nc.) Rem\nd.) Ram\ne.) Felix\n\n";

    cin >> input;
    if(input == "a" || input == "A")
      numCorrect++;


    cout << "\nWhat is the name of the end song of Kagurya-Sama: Love Is War?\n";
    cout << "a.) Shelter\nb.) The Chika Fujiwara Dance\nc.) A Cruel Angel's Thesis\nd.) Tank!\ne.) Komm Susser Tod\n\n";

    cin >> input;
    if(input == "b" || input == "B")
      numCorrect++;


    cout << "\nWhat is the name of the dragon that charges her energy from an eletrical outlet\n";
    cout << "a.) Elma\nb.) Quetzalcoatl\nc.) Tooru\nd.) Kanna\ne.) Fafnir\n\n";

    cin >> input;
    if(input == "d" || input == "D")
      numCorrect++;


    cout << "\nYou were expecting a quiz question but it was me ________!\n";
    cout << "a.) Dio\nb.) Metallica\nc.) Queen\nd.) Green Day\ne.) Bad Company\n\n";

    cin >> input;
    if(input == "a" || input == "A")
      numCorrect++;

    cout << "\nWhat is the last spoken word said in Cowboy Bebop?\n";
    cout << "a.) Bang\nb.) Cowboy\nc.) Oh\nd.) Goodbye\ne.) Boom\n\n";

    cin >> input;
    if(input == "a" || input == "A")
      numCorrect++;

    cout << "\nWhat anime genre is overly saturated at this time?\n";
    cout << "a.) Action\nb.) Fantasy\nc.) Idols\nd.) Isekai\ne.) Sci-Fi\n\n";

    cin >> input;
    if(input == "d" || input == "D")
      numCorrect++;

    cout << "\nWho wrote a paper on how to get away with war crime?\n";
    cout << "a.) Viktoriya Ivanovna\nb.) Hans\nc.) Erich\nd.) Existence X\ne.) Tanya\n\n";

    cin >> input;
    if(input == "e" || input == "E")
      numCorrect++;

    cout << "\nWhat is the number one anime according to myanimelist.net\n";
    cout << "a.) Boku no Hero Academiaa\nb.) Fullmetal Alchemist: Brotherhood\nc.) Cowboy Bebop\nd.) Legend of the Galatic Heros\ne.) Black Butler\n\n";

    cin >> input;
    if(input == "b" || input == "D")
      numCorrect++;

    cout << "\n-----------------------------------------------------------\n\n";

    //print out differnt results
    switch(numCorrect){
      case 10: cout << "You got 10/10 a perfect score! I am impressed!"; break;
      case 9: cout << "You got 9/10 so you still got an A. I am impressed!"; break;
      case 8: cout << "You got 8/10 which is a B. Very good!"; break;
      case 7: cout << "You got 7/10 wichh is a C. Still passing!"; break;
      case 6: cout << "You got 6/10 which is a D. You should study more!"; break;
      case 5:
      case 4:
      case 3: cout << "You failed with a " << numCorrect << "/10. You really should care more about your studies."; break;
      case 2:
      case 1: cout << "You failed, but " << numCorrect << "/10 is better than nothing."; break;
      case 0: cout << "Even if you out all of one letter you should have gotten one. How did you miss all of them?"; break;

    }
    //test to see if player would like to try again
    cout << "\n\nDo you wish to try again?\n";
    cin >> input;
  }
}
