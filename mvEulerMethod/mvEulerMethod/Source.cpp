#include <iostream>
#include <cmath>
#include <tuple>
#include <time.h>

using namespace std;

double func(double, double);
void prt(double, double);
double getTime();

int main()
{
	double x0 = 0, y0 = 0;
	tuple<double, double> range (0.0, 30.0);
	int time = 10 * 60;

	double step = 2.0 * (get<1>(range) - get<0>(range));
	int numberOfInteretions;;
	
	while (true)
	{
		step /= 2.0;
		numberOfInteretions = (get<1>(range) - get<0>(range)) / step;
		double x = x0, y = y0;

		double start = getTime();
		while(numberOfInteretions--)
		{
			y += step * func(x, y);
			x += step;

			if(!numberOfInteretions)
				prt(x, y);
		}
		double end = getTime();
		if (time < end - start)
			break;
	}
	
	system("pause");
	return 0;
}

double func(double x, double y)
{
	return -y + cos(x) + sin(x);
}

void prt(double x, double y)
{
	cout << "x: " << x << "\ny: " << y << "\n";
}

double getTime()
{
	return clock() / CLOCKS_PER_SEC;
}