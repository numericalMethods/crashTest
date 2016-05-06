#pragma once
#include "numericmethod.h"
#include "DU.h"
#include "TaskKoshi.h"

using namespace std;

ref class RungeKuttaMethod : public NumericMethod
{
private:
	DU du;
	TaskKoshi task;
	double dt;
	double h;
	double time;
public:
	//double first_function(double y) {return y;}
	//double second_function(double k, double m, double M, double x, double y) {return -(k / m) *x - (M / m) * y;}

	RungeKuttaMethod(DU du, TaskKoshi task, double dt, double h, double time)
	{
		this.dt = dt;
		this.h = h;
		this.time = time;
		this.du = du;
		this.task = task;
	};
	
	void setDU(DU du){ this.du = du};
	void setTaskKoshi(TaskKoshi task) {this.task = task};
	
	virtual pair<double,double> executeMethood()
	{
		double m1, m2, m3, m4; 
		double k1, k2, k3, k4;
		double t = 0;
		double x = 0.0001;
		double y = 0.0001;
		int count = 0;
		while (t <= time) {
			count++;
		
			k1 = h * du.firstFunction(y);
			m1 = h * du.secondFunction(x, y);

			k2 = h * du.firstFunction(y + k1 / 2);
			m2 = h * du.secondFunction(x + h / 2, y + (h * m1) / 2);

			k3 = h * du.firstFunction(y + k2 / 2);
			m3 = h * du.secondFunction(x + h / 2, y + (h * m2) / 2);

			k4 = h * du.firstFunction(y + h * k3);
			m4 = h * du.secondFunction(x + h, y + h * m3);

			x += (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
			y += (h / 6) * (m1 + 2 * m2 + 2 * m3 + m4);
		
			t += h;
			return make_pair(x,y);
		}
	};
};

