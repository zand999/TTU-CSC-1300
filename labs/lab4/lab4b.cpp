

#include <iomanip>
#include <iostream>
using namespace std;
int main(){

  //declare variables
  string month;
  int day;

  //get inputs
  cout << "enter the month and day in the format \"Month Day\": ";
  cin >> month;
  cin >> day;

  //print output
  if(month == "March" && day >= 20 || month == "April" || month == "May" || month == "June" && day <= 20)
    cout << "spring\n";
  else if(month == "June" && day >= 21 || month == "July" || month == "August" || month == "September" && day <= 21)
    cout << "summer\n";
  else if(month == "September" && day >= 22 || month == "October" || month == "November" || month == "December" && day <= 20)
    cout << "fall\n";
  else if(month == "December" && day >= 21 || month == "January" || month == "February" || month == "September" && day <=19)
    cout << "winter\n";
  else
    cout << "invalid\n";

}
