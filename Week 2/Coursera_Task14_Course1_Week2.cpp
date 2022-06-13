#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map <vector<string>, int> buses;

	int N;
	int busescounter = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		vector<string>stops;
		int Q;
		cin >> Q;
		for (int j = 0; j < Q; j++)
		{
			string stop;
			cin >> stop;
			stops.push_back(stop);
		}
		if (buses.find(stops) == buses.end())
		{
			buses[stops] = ++busescounter;
			cout << "New bus " << busescounter << endl;
		}
		else
			cout << "Already exists for " << buses[stops] << endl;
	}
	return (0);
}
