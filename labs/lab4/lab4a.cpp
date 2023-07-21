

#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
  //declare variables
  double input;
  //take input
  cout << "Enter caffeine intake: ";
  cin >> input;
  while(input <= 0){
    cout << "Enter caffeine intake: ";
    cin >> input;
  }

  //print calculation
  cout << setprecision(2) << fixed;
  cout << "After 6 hours: " << input / 2.0 << endl;
  cout << "After 12 hours: " << (input / 2.0)/2 << endl;
  cout << "After 18 hours: "<< ((input / 2.0)/2)/2 << endl;

  return 0;

}
