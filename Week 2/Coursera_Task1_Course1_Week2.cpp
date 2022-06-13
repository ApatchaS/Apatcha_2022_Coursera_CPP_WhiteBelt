#include <iostream>

using namespace std;

int Factorial(int N)
{
	int res = 1;
	if (N < 0)
		return (1);
	else
	{
		for (int i = 2; i <= N; i++)
			res *= i;
		return (res);
	}
}

int main()
{
	int N;
	cin >> N;
	cout << Factorial(N);
	return (0);
}
