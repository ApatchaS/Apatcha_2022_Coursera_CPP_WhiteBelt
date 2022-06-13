#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	map<string, set<string>> sinonims;

	int Q;
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		string com;
		cin >> com;
		if (com == "ADD")
		{
			string word1, word2;
			cin >> word1 >> word2;
			sinonims[word1].insert(word2);
			sinonims[word2].insert(word1);
		}
		if (com == "COUNT")
		{
			string word;
			cin >> word;
			cout << sinonims[word].size() << endl;
		}
		if (com == "CHECK")
		{
			string word1, word2;
			cin >> word1 >> word2;
			if (sinonims[word1].count(word2) == 0)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
	return (0);
}
