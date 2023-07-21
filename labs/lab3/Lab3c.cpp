

#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
	const double PI = 3.14159;
 	string fullName;

	cout << "\nWhat is your first & last name?\n";
	getline(cin, fullName);

	// Calculate the circumference
	double circumference, diameter;
	cout << "\n\nWhat is the diameter of the circle?\n";
	cin >> diameter;
	cin.ignore();
	circumference = PI * diameter;



	// Display the circumference.
	cout << "\n\nHello, " << fullName;
	cout << "! The circumference of your circle is: " << circumference;
	cout << endl << endl;

	return 0;
}
