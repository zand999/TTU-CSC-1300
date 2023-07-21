
#include <iostream>
using namespace std;

void GetElephantData(float amount[], string names[]){
  cout << "\nEnter the bname and how many pound of food each elephant ate last month.\n";
  for(int i = 0; i < 10; i++){
    cout << "\nELEPHANT " << (i + 1) << ":\n";
    cout << "NAME: \n";
    getline(cin,names[i]);
    cout << "FOOD AMOUNT: \n";
    cin >> amount[i];
    cin.ignore(256,'\n');

  }

}

void GetStats(float amount[], float& total, float& average, int& index){
  total = 0;
  index = 0;
  for(int i = 0; i < 10; i++){
    total += amount[i];
  }
  for(int i = 0; i < 9; i++){
    if(amount[i + 1] > amount[i]){
      index = i+1;
    }
  }
  average = total / 10;


}
