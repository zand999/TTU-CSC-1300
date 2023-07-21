/*
	Title:  serial_pi.cpp
	Author: Tennessee Tech IPDC, modified by April Crockett 
		(https://www.csc.tntech.edu/pdcincs/index.php/organizing-committee/)
	Description: Serial version of Pi Estimation
	Date:  10/24/2019
*/

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

double update_sum(int total_terms);

int main(void) 
{
	double pi;
	int total_terms = 1000000000;

	cout << "Computation started..\n";

	clock_t tStart = clock();
	pi = 4.0 * update_sum(total_terms);
	clock_t tStop = clock();

	double compute_time = (static_cast<double>(tStop - tStart)/CLOCKS_PER_SEC);
	cout << setprecision(3) << fixed;
	cout << "Pi = " << pi << endl;
	cout << setprecision(1) << "Computation time = "  << compute_time << " seconds\n";

	return 0;
}

double update_sum(int total_terms)
{
	double sum=0.0;
	double factor = 1;
	for(int i = 0 ; i < total_terms ; i++, factor = -factor)
	{
		sum += factor/(2.0 * i + 1.0);
	}
	return sum;
}

