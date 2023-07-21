

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

void enterStolenMoonPies(vector<int>& data,int);
int totalMoonPies(vector<int> data, int);
double averageMoonPies(int, int);
int highestMoonPies(vector<int> data, int);
int lowestMoonPies(vector<int> data, int);

int main(){
  int days,total,highest,lowest;
  double average;
  cout << setprecision(2) << fixed;
  cout << "How many days did Jane steal moon pies?\n";
  cin >> days;
  while( (days < 0) || cin.fail()){
    cout << "Please enter a valid number of days\n";
    cin.clear();
    cin.ignore(265,'\n');
    cin >> days;
  }
  vector<int> data(days);
  enterStolenMoonPies(data,days);
  total = totalMoonPies(data,days);

  cout << "\n---------------Results---------------\n";
  cout << "Total # Moon Pies Stolen: " << total << endl;
  cout << "Average # Moon Pies Stolen Per Day: " << averageMoonPies(days, total) << endl;
  cout << "Most # Moon Pies Stolen In Day: " << highestMoonPies(data, days) << endl;
  cout << "Least # Moon Pies Stolen In Day: " << lowestMoonPies(data, days) << endl;

}

void enterStolenMoonPies(vector<int>& data,int size){
  cout << "Please enter pies eaten each day.\n";
  for(int i = 0; i < size; i++){
    cout << "Day " << i + 1 << ":\n";
    cin >> data.at(i);
    while( (data.at(i) < 0) || cin.fail()){
      cout << "Please enter a valid number of pies\n";
      cin.clear();
      cin.ignore(265,'\n');
      cout << "Day " << i + 1 << ":\n";
      cin >> data.at(i);
    }

  }
}
int totalMoonPies(vector<int> data, int size){
  int total = 0;
  for(int i = 0; i < size; i++)
    total += data.at(i);
  return total;
}
double averageMoonPies(int size,int total){
  return (static_cast<double>(total) / static_cast<double>(size));
}
int highestMoonPies(vector<int> data, int size){
  int highest = 0;
  for(int i = 0; i < size; i++)
    if(data.at(i) > highest)
      highest = data.at(i);
  return highest;
}
int lowestMoonPies(vector<int> data, int size){
  int lowest = data.at(0);
  for(int i = 1; i < size; i++)
    if(data.at(i) < lowest)
      lowest = data.at(i);
  return lowest;
}
