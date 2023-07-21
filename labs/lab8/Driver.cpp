

//#include <iomanip>
//#include <math.h>
//#include <string>
#include "Elephant.h"

int main(){
  string zooName, elephantNames[10];
  float data[10],total,average;
  int index;
  cout << "Hello! What is the name of your elephant zoo?\n";
  getline(cin,zooName);
  GetElephantData(data,elephantNames);
  GetStats(data,total,average,index);
  cout << "--------------------------\n";
  cout << "The total about of food consumed by all 10 elephants at " << zooName << " is " << total << " pounds in one month.\n\n";
  cout << "The average amount of food consumed at " << zooName << " is " << average << " pounds.\n\n";
  cout << "The elephant who eats the most (" << data[index] << ") is " << elephantNames[index] << "!!\n--------------------\n";
  return 0;




}
