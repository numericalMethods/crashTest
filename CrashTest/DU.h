#pragma once
ref class DU
{
private:
	double m;
	double k;
	double alpha;
	int countParametors;
public:
	DU(double* parametors)
	{
		countParametors = 3;
		
		m = parametors[0];
		k = parametors[1];
		alpha = parametors[2];

	};
	void setParametors(double* parametors)
	{
		m = parametors[0];
		k = parametors[1];
		alpha = parametors[2];
	};

	double firstFunction(double y)
	{
		return y;
	};
	double secondFunction(double x, double y)
	{
		return -(k / m) * x - (alpha / m) * y;	
	};
};

