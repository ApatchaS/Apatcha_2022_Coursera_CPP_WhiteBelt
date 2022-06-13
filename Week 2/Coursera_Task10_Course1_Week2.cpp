#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int Q;
	string com;
	int daycounter;
	string mission;
	int j = 0;

	vector<int> MONTHS(12,31);
	MONTHS[1] = 28;
	MONTHS[3] = 30;
	MONTHS[5] = 30;
	MONTHS[8] = 30;
	MONTHS[10] = 30;
	
	vector<vector<string>> tasks(MONTHS[j]);

	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> com;
		if (com == "NEXT")
		{	
			if (MONTHS[j % 12] > MONTHS[(j + 1) % 12])
				for (int k = MONTHS[(j + 1) % 12]; k < MONTHS[j % 12]; k++)
					tasks[MONTHS[(j + 1) % 12] - 1].insert(end(tasks[MONTHS[(j + 1) % 12] - 1]), begin(tasks[k]), end(tasks[k]));
			j++;
			tasks.resize(MONTHS[j % 12]);
		}
		else
		{
			cin >> daycounter;
			daycounter--;
			if (com == "ADD")
			{
				cin >> mission;
				tasks[daycounter].push_back(mission);
			}
			else
			{	
				cout << tasks[daycounter].size();
				for (auto t : tasks[daycounter])
					cout << " " << t;
				cout << endl;
			}
		}
	}
	return (0);
}
