

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

int *makeArray(int);
void getData(int, int, int *data);
void findBiggest(int, int , int *data[]);

const int SIZE = 4;
int main(){
	int numGenres,biggestLibrary,biggestGenre,biggest;

	int *librarys[SIZE];


	cout << "How many genres of books do you have?\n";
	cin >> numGenres;


	for (int i = 0; i < SIZE; ++i){
		
		librarys[i] = makeArray(numGenres);
		
		//linbrays[i] = new int[numGenres]
		/*makeArray(numGenres);*/

	}

	cout << "Please enter the number of books in each genre.\n";

	for (int i = 0; i < SIZE; ++i){
		
		for(int j = 0; j < numGenres; j++){
			cout << "LIBRARY " << i + 1<< "   GENRE " << j + 1 << ":  ";
			//cin >> *(*(librarys +i) +j);
			//cin >> librarys[i][j]
			//cin >> *((librarys+i)+j);


			//cin >> *(librarys[i] +j);
			cin >> librarys[i][j];

		}
		cout << endl;

	}
	
	biggest = librarys[0][0];

	for (int i = 0; i < SIZE; ++i){
		
		for(int j = 0; j < numGenres; j++){
			/*TESTING
			//cin >> *(*(librarys +i) +j);
			//cin >> librarys[i][j]
			//cin >> *((librarys+i)+j);
			//cin >> *(librarys[i] +j);
			cin >> librarys[i][j];
			*/
			if(librarys[i][j] > biggest){
				biggest = librarys[i][j];
				biggestLibrary = i + 1;
				biggestGenre = j + 1;
			}
		}
		cout << endl;

	}
	
	
	cout << "LIBRARY " << biggestLibrary << " has the largest number of books in GENRE " << biggestGenre << endl;
	cout << "which contains " << biggest << " books!\n";
	//findBiggest(SIZE,numGenres,librarys);

	
}


int *makeArray(int size){
  return new int[size];
}

/*void getData(int libraryNum, int size, int *data){

	for (int i = 0; i < size; ++i)
	{
		cout << "LIBRARY " << libraryNum + 1<< "   GENRE " << i + 1 << ":  ";
		cin >> *(data + i);
	}

}*/

/*void findBiggest(int size1, int size2, int *data[][]){

	int biggestLibrary = 0,genreNum = 0, numbooks = *data[0];

	
	cout << "\nLIBRARY " << biggestLibrary << " has the largest number of books in GENRE " << genreNum << endl;
	cout << "which contains " << numbooks << " books!\n";

}*/


