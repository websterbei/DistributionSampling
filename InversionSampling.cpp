#include <cstdio>
#include <random>
#include <cmath>
#include "timer.h"
#include <iostream>

#define SAMPLE_SIZE 100000

using namespace std;

int main()
{
	CUtilTimer timer;
	mt19937 mt_rand(time(nullptr));
	uniform_real_distribution<double> getRNum (0,1);
	auto rNum = bind(getRNum,mt_rand);
	int counter = 1;
	timer.start();
	for(int i=0;i<SAMPLE_SIZE;i++)
	{
		double r = -log(1-rNum());
	}
	timer.stop();
	//printf("Finished %d Sampling in %lld s\n",SAMPLE_SIZE,timer.get_ticks());
	std::cout<<timer.get_ticks()<<endl;
	return 0;
}