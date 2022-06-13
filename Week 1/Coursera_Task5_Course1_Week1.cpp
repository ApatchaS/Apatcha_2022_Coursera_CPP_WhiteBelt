#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	double N, A, B, X, Y;
	cin >> N >> A >> B >> X >> Y;
	if (N <= A)
		cout << N;
	else if (N > B)
		cout << N * (100 - Y) / 100;
	else
		cout << N * (100 - X) / 100;
	return (0);
}
