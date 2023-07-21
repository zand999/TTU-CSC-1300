

//g++-9 -o name name.coo -fopen

#include <iostream>
#include <iomanip>
#include <ctime>
#include <omp.h>
using namespace std;

double update_sum(int total_terms);

int main(void)
{
	double pi;
	int total_terms = 2000000000;

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
//int my_rank = omp_get_thread_num();
double update_sum(int total_terms){

	double sum = 0.0;
	int thread_count = 8;

	#pragma omp parallel num_threads(thread_count)
	{

		int my_rank = omp_get_thread_num();
		int num_parts = total_terms/thread_count;
		int my_first_i = num_parts * my_rank;
		int my_last_i;
		if (my_rank == thread_count-1)
    	my_last_i = total_terms;
		else
     my_last_i = my_first_i + num_parts;



		double factor = 1;
		if (my_first_i % 2 == 0.0)
    	factor = 1.0;
		else
     	factor = -1.0;

		double my_sum = 0.0;
		for(int i = my_first_i ; i < my_last_i ; i++, factor = -factor){
	    my_sum += factor/(2.0 * i + 1.0);
		}

		#pragma omp critical
		{
			sum += my_sum;
		}


		}

	return sum;

}
