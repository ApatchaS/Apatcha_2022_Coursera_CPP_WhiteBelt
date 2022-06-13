#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string w)
{
	for (int i = 0; i < w.size() / 2; i++)
		if (w[i] != w[w.size() - 1 - i])
			return (false);
	return (true);
}

int main()
{
	string W;
	cin >> W;
	cout << IsPalindrom(W);
	return (0);
}
