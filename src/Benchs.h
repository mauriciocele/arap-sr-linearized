#if !defined(__GA_BENCHS__H__)
#define __GA_BENCHS__H__

#include <ctime>
#include <fstream>

using namespace std;

class Benchmarks
{
public:
	ofstream benchs;
	double avgTime;
	int avgCount;
	bool enabled;
	static const int avgSize = 10;

	clock_t begin;
	clock_t end;


	Benchmarks()
	{
		avgTime = 0.0;
		avgCount = 0;
		enabled = false;
		benchs.open("benchs.txt");
	}

	~Benchmarks()
	{
		benchs.close();
	}

	bool IsStarted()
	{
		return enabled;
	}

	void Start()
	{
		enabled = true;
	}

	void Stop()
	{
		enabled = false;
	}

	void Begin()
	{
		if(!enabled)
		{
			return;
		}

		begin = clock();
	}

	void End()
	{
		if(!enabled)
		{
			return;
		}

		end = clock();
		
		double secDeform = (double) ( end - begin ) / CLOCKS_PER_SEC;

		avgTime += secDeform;

		avgCount++;

		if(avgCount == avgSize)
		{
			benchs << avgTime / (double)avgCount << endl;
			avgTime = 0.0;
			avgCount = 0;
		}
	}
};

#endif