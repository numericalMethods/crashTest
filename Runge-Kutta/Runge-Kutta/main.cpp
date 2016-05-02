#include <iostream>
using namespace std;

double first_function(double y) {
	return y;
}

double second_function(double k, double m, double M, double x, double y) {
	return -(k / m) *x - (M / m) * y;
}

void runge_kutta_method(double k1, double k2, double k3, double k4,
	double m1, double m2, double m3, double m4, 
	double dt, double time, double h,
	double k, double m, double M) {
	double t = 0;
	double x = 0.0001;
	double y = 0.0001;
	int count = 0;
	while (t <= time) {
		
		count++;
		
		k1 = h * first_function(y);
		m1 = h * second_function(k, m, M, x, y);

		k2 = h * first_function(y + k1 / 2);
		m2 = h * second_function(k, m, M, x + h / 2, y + (h * m1) / 2);

		k3 = h * first_function(y + k2 / 2);
		m3 = h * second_function(k, m, M, x + h / 2, y + (h * m2) / 2);

		k4 = h * first_function(y + h * k3);
		m4 = h * second_function(k, m, M, x + h, y + h * m3);

		x += (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
		y += (h / 6) * (m1 + 2 * m2 + 2 * m3 + m4);
		
		cout << "x " << count << ": " << x << endl;
		cout << "y " << count << ": " << y << endl;
		cout << endl;

		t += h;
	}
}

void main() {
	double k1 = 0, m1 = 0, k2 = 0, m2 = 0, k3 = 0, m3 = 0, k4 = 0, m4 = 0;
	runge_kutta_method(k1, k2, k3, k4, m1, m2, m3, m4, 0.0001, 1000, 0.1, 1, 2, 2);
}