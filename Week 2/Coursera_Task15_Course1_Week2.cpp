#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	set<string> strs;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		strs.insert(str);
	}
	cout << strs.size();
	return (0);
}