#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>

#define SAMPLE_SIZE 100000

using namespace std;

int main()
{
	mt19937 mt_rand(time(nullptr));
	uniform_real_distribution<double> getXNum (0,300);
	uniform_real_distribution<double> getYNum (0,1);
	auto xVal = bind(getXNum,mt_rand);
	auto yVal = bind(getYNum,mt_rand);
	double start = clock();
	int counter = 1;
	while(counter<SAMPLE_SIZE)
	{
		double x = xVal();
		if(yVal()<=exp(-x)) counter++;
	}
	double duration = (clock()-start)/(double) CLOCKS_PER_SEC;
	printf("Finished %d Sampling in %.5f s\n",SAMPLE_SIZE,duration);

	return 0;
}