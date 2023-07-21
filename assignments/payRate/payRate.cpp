
#include <iostream>
using namespace std;

int main(){
  double hours;
  double hourlypay;
  double pay;
  int employeecount = 0;
  bool goAgain=true;
  char responce;


  while(goAgain){
    cout << endl << endl;

    //Intput
    cout << "Enter the number of hours worked: \n";
    cin >> hours;
    cout << "Enter the rate: \n";
    cin >> hourlypay;

    //Processing
    pay = hours * hourlypay;

    //output
    cout << "Your pay is: " << pay << endl;
    cout <<"\n\n";

    employeecount++;
    cout << "do you wish to go again? \n";
    cin >> responce;
    cout << endl;

    if (responce == 'n' || responce == 'N'){
      goAgain = false;
    }

  }
  cout << "The number of employeese is: " << employeecount;


}
