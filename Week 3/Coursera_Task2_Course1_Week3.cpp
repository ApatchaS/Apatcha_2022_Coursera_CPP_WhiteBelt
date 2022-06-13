#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print_tab(const vector<string>& tab)
{
	for (const auto& item : tab)
		cout << item << " ";
	return ;
}

string tolower_string(string str)
{
	for (auto& item : str)
		item = tolower(item);
	return (str);
}

int main()
{
	int N;

	cin >> N;
	vector<string> tab(N);
	for (auto& item : tab)
		cin >> item;
	sort(begin(tab), end(tab), [](string first, string second) {return (tolower_string(first) < tolower_string(second));});
	print_tab(tab);
	return (0);
}
