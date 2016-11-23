#include <cstdio>
#include <random>
#include <cmath>
#include <iostream>
#include <ctime>

#define SAMPLE_SIZE 100000

using namespace std;

int main()
{
	mt19937 mt_rand(time(nullptr));
	uniform_real_distribution<double> getRNum (0,1);
	auto rNum = bind(getRNum,mt_rand);
	int counter = 1;
	double start = clock();
	for(int i=0;i<SAMPLE_SIZE;i++)
	{
		double r = -log(1-rNum());
	}
	//printf("Finished %d Sampling in %lld s\n",SAMPLE_SIZE,timer.get_ticks());
	std::cout<<clock()-start<<endl;
	return 0;
}