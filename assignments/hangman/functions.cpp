#include <sstream>
#include <iostream>
#include <fstream>
#include "hangman.h"



void printStage(int num){

	switch(num){

		case 0:
			cout << "Stand\n";

		case 1:
			cout << "head\n";
			break;

		case 2:
			cout << "head\n";
			cout << "body\n";
			break;

		case 3:
			cout << "head\n";
			cout << "body\n";
			cout << "r-arm\n";
			break;

		case 4:
			cout << "head\n";
			cout << "body\n";
			cout << "R-arm\n";
			cout << "L-arm\n";
			break;

		case 5:
			cout << "head\n";
			cout << "body\n";
			cout << "R-arm\n";
			cout << "L-arm\n";
			cout << "R-leg\n";
			break;

		case 6:
			cout << "head\n";
			cout << "body\n";
			cout << "R-arm\n";
			cout << "L-arm\n";
			cout << "R-leg\n";
			cout << "L-leg\n";
			break;

		



	}

}
void printWord(char[] word, char[] underScores){

	int length;

	
	for(int i = 0; i < strlin(word); i ++){

		cout << underScores[i];

	}


}
void printLettersGuessed(bool[] guessed, char[] alphabet){


	cout << "\n";

	for(int i = 0; i < 26; i++){


		if(guessed[i]){
			cout << alphabet[i] << " ";
		}

	}
	cout << "\n";


}



