#include <iostream>
#include <vector>

using namespace std;

int	main()
{
	int N;
	int Sum = 0;
	int Arif = 0;
	cin >> N;
	vector<int> days(N);
	vector<int> temp;
	for (int& day : days)
	{
		cin >> day;
		Sum += day;
	}
	Arif = Sum / N;
	for (int i = 0; i < N; i++)
		if (days[i] > Arif)
			temp.push_back(i);
	cout << temp.size() << endl;
	for (auto i : temp)
		cout << i << " ";
	return (0);
}
