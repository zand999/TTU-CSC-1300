/*
    File Name lab2a.cpp
    Authors: Alex Zandstra, Jonas Norman
    Date: 9/05/19
    Purpose: Calculate cost of stock, commission, and sum of both
*/
#include <iostream>
#include <iomanip>
using namespace std;


int main(){
  //Declare varables for constants
  const double STOCKAMT = 750.0, PRICE = 35.0, COMMISSION = 0.02;


  //Set double formatting
  cout << setprecision(2) << fixed;

  //Print out computation
  cout << "Amount paid for the stock:  $" << (STOCKAMT * PRICE) << endl << endl;

  cout << "Commission paid on the sale:  $" << (STOCKAMT * PRICE) * COMMISSION << endl << endl;

  cout << "Total amount paid for stock: $" << (STOCKAMT * PRICE) + (STOCKAMT * PRICE) * COMMISSION << endl << endl;






}
