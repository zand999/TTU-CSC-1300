
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;


int *makeArray(int);
void getStudentData(int, int *data);
void getAverage(int, int *data);
void selectionSort(int, int *data);
void printArray(int, int *data);
void selectionSort( int, int *data);

int main(){
  int *data  = nullptr,numStudents;
  cout << "How many students?\n";
  cin >> numStudents;
  while((numStudents < 0) || cin.fail()){
    cout << "Please enter a valid  number.\n";
    cin.clear();
    cin.ignore(265,'\n');
    cin >> numStudents;
  }
  data = makeArray(numStudents);
  getStudentData(numStudents, data);
  getAverage(numStudents,data);
  selectionSort(numStudents,data);
  printArray(numStudents,data);
  cout << "\n Goodbye!\n";
}

int *makeArray(int size){
  return new int[size];
}

void getStudentData(int size, int *data){
  cout << "Please enter average number of hours each month for each student:\n";
  for(int i = 0; i < size; i++){
    cout << "Day " << i + 1 << ": ";
    cin >> *(data +i);
    while((*(data +i) < 0) || cin.fail()){
      cout << "Please enter a valid  number.\n";
      cin.clear();
      cin.ignore(265,'\n');
      cin >> *(data +i);
    }
  }
}
void getAverage(int size, int *data){
  int total;
  for (size_t i = 0; i < size; i++) {
    total += *(data + i);
  }
  cout << "The average is: " << (total / size) << endl;
}

void printArray(int size, int *data){
  cout << "Here is the data:\n";
  for (size_t i = 0; i < size; i++) {
    cout << *(data + i) << endl;
  }
}


/**************************************************
 * Function selectionSort                         *
 * This function performs the selection sort      *
 * algorithm on array, sorting it into ascending  *
 * order. The parameter size holds the number of  *
 * elements in the array.                         *
 **************************************************/

void selectionSort( int size, int *data)
{
   int startScan, minIndex, minValue;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minValue = *(data+startScan);
      for(int index = startScan + 1; index < size; index++)
      {
         if (*(data+index) < minValue)
         {
            minValue = *(data+index);
            minIndex = index;
         }
      }
      *(data+minIndex) = *(data+startScan);
      *(data+startScan) = minValue;
	}
}
