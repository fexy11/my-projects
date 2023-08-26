#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	HINSTANCE load;
	load = LoadLibrary(L"C:\\Users\\eggle\\source\\repos\\DynemicLib\\x64\\Debug\\DynemicLib.dll");
	typedef double (*sum) (double, double);
	typedef double (*min) (double, double);
	typedef double (*mult) (double, double);
	typedef double (*div) (double, double);
	sum Sum;
	min Min;
	mult Mult;
	div Div;
	Sum = (sum)GetProcAddress(load, "Sum");
	Min = (min)GetProcAddress(load, "Min");
	Mult = (mult)GetProcAddress(load, "Mult");
	Div = (div)GetProcAddress(load, "Div");
	double a = 100;
	double b = 200;
	cout << Sum(a, b) << endl;
	cout << Min(a, b) << endl;
	cout << Mult(a, b) << endl;
	cout << Div(a, b) << endl;

	FreeLibrary(load);

}