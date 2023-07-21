/*
  Title: main.cpp
  Author: Alex Zandstra
  Date Started: 10/31/19
  Purpose: To create a program that manages data anyalitics for social media
*/

#include <iostream>
#include <vector>
using namespace std;

//predefine methods
void getFBTData(vector<float>&,int);
void printArray(vector<float>&,int);
float getMin(vector<float>&,int);
float getMax(vector<float>&,int);
float getAverage(vector<float>&,int);
void printAboveAvg(vector<float>&,int,float);
void printBelowAvg(vector<float>&,int,float);

//main methods
int main(){
  //get number serveyed
  cout << "Enter number of students are surveyed (>2):";
  float total;
  cin >> total;
  //verify input
  while( total < 2 || cin.fail()){
    cout << "Please enter a valid number of people";
    cin.clear();
    cin.ignore(265,'\n');
    cin >> total;
  }
  //create array
  vector<float> data(total);
  float average,min,max;
  //run functions
  getFBTData(data,total);
  printArray(data,total);
  min = getMin(data,total);
  cout << "STATISTICS FOR TIME SPENT ON FACEBOOK & TWITTER\n";
  average = getAverage(data,total);
  cout << "Average: " << average << endl;
  cout << "Min: " << min << endl;
  max = getMax(data,total);
  cout << "Max: " << max << endl;
  printAboveAvg(data,total,average);
  printBelowAvg(data,total,average);

  return 0;
}
//get data for arrays
void getFBTData(vector<float>& data,int length){
  for(int i = 0; i < length; i++){
    cout << "Please enter number of hours for student " << (i + 1) <<  endl;
    cin >> data.at(i);
    //verify input
    while( data.at(i) < 0 || cin.fail()){
      cout << "Please enter a valid number of hours";
      cin.clear();
      cin.ignore(265,'\n');
      cin >> data.at(i);
    }
  }
}
//print out the etirety of the array
void printArray(vector<float>& data,int length){
  cout << "These are what were entered: \n";
  for(int i = 0; i < length; i++){
    cout << data.at(i) << " ";
  }
  cout << endl;
}
//find the smallest value in the array
float getMin(vector<float>& data,int length){
  float min = data.at(0);
  for(int i = 1; i < length; i++){
    min = (data.at(i) < min)? data.at(i) : min;
  }
  return min;
}
//find the biggest value in the array
float getMax(vector<float>& data,int length){
  float max = data.at(0);
  for(int i = 1; i < length; i++){
    max = (data.at(i) > max)? data.at(i) : max;
  }
  return max;
}
//cumpute the averate and retuern the value
float getAverage(vector<float>& data,int length){
  float sum = 0;
  for(int i = 0; i < length; i++){
    sum += data.at(i);
  }
  return (sum / length);
}
//print the values above the determined average
void printAboveAvg(vector<float>& data,int length,float average){
  cout << "Those above average:\n";
  for(int i = 0; i < length; i++){
    if(data.at(i) > average){
      cout << data.at(i) << " ";
    }
  }
  cout << endl;
}
//print the values below the determined average
void printBelowAvg(vector<float>& data,int length, float average){
  cout << "Those below average:\n";
  for(int i = 0; i < length; i++){
    if(data.at(i) < average){
      cout << data.at(i) << " ";
    }
  }
  cout << endl;
}
