#include <cstdio>
#include "timer.h"
#include <random>
#include <cmath>
#include <ctime>
#define SAMPLE_SIZE 100000
#define TRIALS 5

std::normal_distribution<double> get_normal_distribution() {
	std::normal_distribution<> d(0,1);
	return d;
}

std::bernoulli_distribution get_bernoulli_distribution() {
	std::bernoulli_distribution d(0.5);
	return d;
}

std::poisson_distribution<int> get_poisson_distribution() {
	std::poisson_distribution<> d(4);
	return d;
}

std::exponential_distribution<double> get_exponential_distribution() {
	std::exponential_distribution<> d(1);
	return d;
}
std::discrete_distribution<int> get_discrete_distribution() {
	std::discrete_distribution<> d({40, 10, 10, 40});
	return d;
}

template <class T>
long benchmark(T dist, std::mt19937 mt_rand) {
	//CUtilTimer timer;
	//timer.start();
	std::clock_t start;
	start = std::clock();
	for(int i=0;i<TRIALS;i++) {
		for(int j=0;j<SAMPLE_SIZE;j++) dist(mt_rand);
	}
	return (std::clock()-start)/TRIALS;
	//timer.stop();
	//return timer.get_ticks()/TRIALS;
}

long benchmarkmt19937(std::mt19937 mt_rand) {
	//CUtilTimer timer;
	std::clock_t start;
	//timer.start();
	start = std::clock();
	for(int i=0;i<TRIALS;i++) {
		for(int j=0;j<SAMPLE_SIZE;j++) mt_rand();
	}
	return (std::clock()-start)/TRIALS;
	//timer.stop();
	//return timer.get_ticks()/TRIALS;
}

int main() {
	std::mt19937 mt_rand(time(nullptr));
	std::printf("%-30s %-15s %-15s %-15s\n","Distribution","Sample Size","Clocks","Clocks per Sample");
	long avgcyc = benchmark(get_normal_distribution(), mt_rand);
	std::printf("%-30s %-15d %-15ld %-15ld\n","Normal Distribution",SAMPLE_SIZE,avgcyc,(long)std::round((double)avgcyc/SAMPLE_SIZE));
	avgcyc = benchmark(get_bernoulli_distribution(), mt_rand);
	std::printf("%-30s %-15d %-15ld %-15ld\n","Bernoulli Distribution",SAMPLE_SIZE,avgcyc,(long)std::round((double)avgcyc/SAMPLE_SIZE));
	avgcyc = benchmark(get_poisson_distribution(), mt_rand);
	std::printf("%-30s %-15d %-15ld %-15ld\n","Poisson Distribution",SAMPLE_SIZE,avgcyc,(long)std::round((double)avgcyc/SAMPLE_SIZE));
	avgcyc = benchmark(get_exponential_distribution(), mt_rand);
	std::printf("%-30s %-15d %-15ld %-15ld\n","Exponential Distribution",SAMPLE_SIZE,avgcyc,(long)std::round((double)avgcyc/SAMPLE_SIZE));
	avgcyc = benchmark(get_discrete_distribution(), mt_rand);
	std::printf("%-30s %-15d %-15ld %-15ld\n","Discrete Distribution",SAMPLE_SIZE,avgcyc,(long)std::round((double)avgcyc/SAMPLE_SIZE));
	std::printf("\n");
	avgcyc = benchmarkmt19937(mt_rand);
	std::printf("Clock Cycles per Call to mt19937: %ld\n", (long)std::round((double)avgcyc/SAMPLE_SIZE));
	return 0;
}