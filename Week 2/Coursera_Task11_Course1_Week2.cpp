#include <iostream>
#include <string>
#include <map>

using namespace std;

map <char, int> BuildCharCounters(const string& str)
{
	map <char, int> charmap;
	for (const auto& symbol : str)
		charmap[symbol]++;
	return (charmap);
}

int main()
{
	int N;
	cin >> N;
	string first;
	string second;
	for (int i = 0; i < N; i++)
	{
		cin >> first >> second;
		if (BuildCharCounters(first) == BuildCharCounters(second))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return (0);
}
