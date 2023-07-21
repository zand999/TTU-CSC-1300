

#include <iostream>
using namespace std;

//predefine methods
void getFBTData(float[],int);
void printArray(float[],int);
float getMin(float[],int);
float getMax(float[],int);
float getAverage(float[],int);
void printAboveAvg(float[],int,float);
void printBelowAvg(float[],int,float);

//main methods
int main(){
  //get number serveyed
  cout << "Enter number of students are surveyed (>2):";
  int total;
  cin >> total;
  //verify input
  while( total < 2 || cin.fail()){
    cout << "Please enter a valid number of people";
    cin.clear();
    cin.ignore(265,'\n');
    cin >> total;
  }
  //create array
  float data[total],average,min,max;
  //run functions
  getFBTData(data,total);
  printArray(data,total);
  min = getMin(data,total);
  cout << "Min: " << min << endl;
  max = getMax(data,total);
  cout << "Max: " << max << endl;
  average = getAverage(data,total);
  printAboveAvg(data,total,average);
  printBelowAvg(data,total,average);

  return 0;
}
//get data for arrays
void getFBTData(float data[],int length){
  for(int i = 0; i < length; i++){
    cout << "Please enter number of hours for student " << (i + 1) <<  endl;
    cin >> data[i];
    //verify input
    while( data[i] < 0 || cin.fail()){
      cout << "Please enter a valid number of hours";
      cin.clear();
      cin.ignore(265,'\n');
      cin >> data[i];
    }
  }
}
//print out the etirety of the array
void printArray(float data[],int length){
  cout << "These are what were entered: \n";
  for(int i = 0; i < length; i++){
    cout << data[i] << " ";
  }
  cout << endl;
}
//find the smallest value in the array
float getMin(float data[],int length){
  float min = data[0];
  for(int i = 1; i < length; i++){
    min = (data[i] < min)? data[i] : min;
  }
  return min;
}
//find the biggest value in the array
float getMax(float data[],int length){
  float max = data[0];
  for(int i = 1; i < length; i++){
    max = (data[i] > max)? data[i] : max;
  }
  return max;
}
//cumpute the averate and retuern the value
float getAverage(float data[],int length){
  float sum = 0;
  for(int i = 0; i < length; i++){
    sum += data[i];
  }
  return (sum / length);
}
//print the values above the determined average
void printAboveAvg(float data[],int length,float average){
  cout << "Those above average:\n";
  for(int i = 0; i < length; i++){
    if(data[i] > average){
      cout << data[i] << " ";
    }
  }
  cout << endl;
}
//print the values below the determined average
void printBelowAvg(float data[],int length, float average){
  cout << "Those below average:\n";
  for(int i = 0; i < length; i++){
    if(data[i] < average){
      cout << data[i] << " ";
    }
  }
  cout << endl;
}
