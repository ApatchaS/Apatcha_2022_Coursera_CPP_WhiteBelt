#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int	main(void)
{
	ifstream	input("input.txt");
	double		buf;

	cout << fixed << setprecision(3);
	while(input >> buf)
		cout << buf << endl;
	return (0);
}