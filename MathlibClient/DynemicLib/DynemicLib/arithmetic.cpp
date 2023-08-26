extern "C" __declspec(dllexport) double Sum(double a, double b)
{
	return a + b;
}
extern "C" __declspec(dllexport) double Min(double a, double b)
{
	return a - b;
}
extern "C" __declspec(dllexport) double Mult(double a, double b)
{
	return a * b;
}
extern "C" __declspec(dllexport) double Div(double a, double b)
{
	return a / b;
}
