#include <iostream>
#include <string>
#include <map>

using namespace std;

void print(const map <string, string>& countries)
{
	for (const auto& c : countries)
		cout << c.first << "/" << c.second << endl;
}

int main()
{
	map <string, string> countries;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		string com;
		cin >> com;
		if (com == "CHANGE_CAPITAL")
		{
			string country;
			string capital;
			cin >> country >> capital;
			if (countries.find(country) == countries.end())
			{
				countries[country] = capital;
				cout << "Introduce new country " << country << " with capital " << capital << endl;
			}
			else if(countries[country] == capital)
				cout << "Country " << country << " hasn't changed its capital\n";
			else
			{
				cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << capital <<endl;
				countries[country] = capital;
			}
		}
		if (com == "RENAME")
		{
			string oldcountry;
			string newcountry;
			cin >> oldcountry >> newcountry;
			if ((countries.find(oldcountry) == countries.end()) || (countries.find(newcountry) != countries.end()) || (newcountry == oldcountry))
				cout << "Incorrect rename, skip\n";
			else
			{
				countries[newcountry] = countries[oldcountry];
				countries.erase(oldcountry);
				cout << "Country " << oldcountry << " with capital " << countries[newcountry] << " has been renamed to " << newcountry << endl;
			}
		}
		if (com == "ABOUT")
		{
			string country;
			cin >> country;
			if (countries.find(country) == countries.end())
				cout << "Country " << country << " doesn't exist\n";
			else
				cout << "Country " << country << " has capital " << countries[country]<<endl;
		}
		if (com == "DUMP")
			if (countries.size() == 0)
				cout << "There are no countries in the world\n";
			else
				print(countries);
	}
	return (0);
}
