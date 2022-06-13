#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int count = 0;
	int res = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (count == 2)
			break;
		if (str[i] == 'f')
		{
			count++;
			res = i;
		}
	}
	if (count == 0)
		cout << -2;
	else if (count == 1)
		cout << -1;
	else
		cout << res;
	return (0);
}
