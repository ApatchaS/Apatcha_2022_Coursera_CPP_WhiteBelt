#include <iostream>
#include <vector>
#include <iomanip> //Header file for working with stream manipulators

using namespace std;

void	PrintFormatedDataTab(const vector<string>& names, const vector<double>& values, char fill, int width, int precision)
{
	cout << fixed; //Stream manipulator for displaying numbers with fixed precision (default is 6)
	cout << setprecision(precision); //Stream manipulator for setting the number of decimal places (precision setting)
	cout << setfill(fill); //Stream manipulator for setting a placeholder for empty space (default is ' ')
	cout << left; //Stream manipulator for switching off to the left
	for (const auto& name : names)
		cout  << setw(width) << name << " ";
	cout << endl;
	for (const auto& value : values)
		cout << setw(width) << value << " "; //Stream manipulator for setting the width of the output field (reset after the output of the next value)
	cout << endl;
}

int	main(void)
{
	vector<string>	names = {"a", "b", "c"};
	vector<double>	values = {5, 0.001, 0.000005};
	
	PrintFormatedDataTab(names, values, '.', 10, 2);
	return (0);
}