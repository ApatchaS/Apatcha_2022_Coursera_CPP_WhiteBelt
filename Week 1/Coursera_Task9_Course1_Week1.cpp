#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> p;
	int N;
	cin >> N;
	while (N >= 2)
	{
		p.push_back(N % 2);
		N /= 2;
	}
	p.push_back(N);
	for (int i = p.size() - 1; i >= 0; i--)
		cout << p[i];
	return (0);
}
