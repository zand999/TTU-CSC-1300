
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
   double wholeSurvey = 16500;
   double regularEnergy = wholeSurvey * 0.15;
   double citrusEnergy = regularEnergy * 0.58;
   cout << "Num of people who drink more than one a week: " << regularEnergy << endl;
   cout << "Num of people who drink more than one a week and prefer citrus flavor: " << round(citrusEnergy) << endl;
   return 0;

}
