#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_tab(const vector<int>& tab)
{
	for (const auto& item : tab)
		cout << item << " ";
	return ;
}

int main()
{
	int	N;

	cin >> N;
	vector <int> tab(N);
	for (auto& item : tab)
		cin >> item;
	sort(begin(tab), end(tab), [](const int& first, const int& second) {return (abs(first) < abs(second));});
	print_tab(tab);
	return (0);
}
