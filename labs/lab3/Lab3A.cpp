

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int integerOne; //Declaring variables
    double doubleOne;
    char characterOne;
    string stringOne;

    cout << "Enter integer: " << endl; //Entering the requisite parts of the program
    cin >> integerOne;

    cout << "Enter double: " << endl;
    cin >> doubleOne;

    cout << "Enter character: " << endl;
    cin >> characterOne;

    cout << "Enter string: " << endl;
    cin.ignore();
    getline(cin, stringOne); //Just in case the user wants to say something profound with spaces. Allows for whitespace

    cout << integerOne << " " << doubleOne << " " << characterOne << " " << stringOne << endl; //Prints everything to the screen.

    cout << stringOne << " " << characterOne << " " << doubleOne << " " << integerOne << endl; //Prints everything to the screen in reverse order.

    cout << doubleOne << " cast to an integer is " << static_cast<int>(doubleOne) << endl; //Prints what our double cast to an integer is.

    return 0;
}