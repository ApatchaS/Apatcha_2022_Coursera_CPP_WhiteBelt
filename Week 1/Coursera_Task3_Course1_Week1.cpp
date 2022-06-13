#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c, d;
	cin >> a >> b >> c;
	if (a != 0)
	{
		d = pow(b, 2) - 4 * a * c;
		if (d == 0)
			cout << -b / (2 * a);
		else if (d > 0)
			cout << (-b + sqrt(d)) / (2 * a) << " " << (-b - sqrt(d)) / (2 * a);
	}
	else if (b != 0)
		cout << -c / b;
	return (0);
}
