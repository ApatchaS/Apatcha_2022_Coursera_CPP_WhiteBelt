#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	map<set<string>, int> mar;

	int N;
	int marcounter = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		set<string> way;
		int Q;
		cin >> Q;
		for (int j = 0; j < Q; j++)
		{
			string stop;
			cin >> stop;
			way.insert(stop);
		}
		if (mar.count(way) == 0)
		{
			mar[way] = ++marcounter;
			cout << "New bus " << marcounter << endl;
		}
		else
			cout << "Already exists for " << mar[way] << endl;
	}
	return (0);
}
