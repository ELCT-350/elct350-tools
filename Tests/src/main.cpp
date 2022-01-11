
#include <cmath>
#include "plotter.h"

void plotTest1();
void plotTest2();

int main()
{
	plotTest1();
	plotTest2();
}

void plotTest1()
{
	Plotter plotter("SimpleTest");

	plotter.SetLabels("data");

	plotter.AddRow(0.0, 1.0);
	plotter.AddRow(1.0, 3.0);
	plotter.AddRow(2.0, 2.0);

	plotter.Plot();
}

void plotTest2()
{
	Plotter plotter("TrigTest");

	plotter.SetLabels("sin(t)", "cos(t)", "sin(t)*(cos(t)");
	plotter.SetSize(1000, 600);

	for (double t = 0.0; t < 10.0; t += 0.01)
	{
		plotter.AddRow(t, sin(t), cos(t), sin(t)*cos(t));
	}
	
	plotter.Plot();

}