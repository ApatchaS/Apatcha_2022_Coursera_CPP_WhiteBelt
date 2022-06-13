#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person
{
	public:
  		void ChangeFirstName(int year, const string& first_name)
    	{	
			tab[year].first = first_name;
			return ;
  		}
		void ChangeLastName(int year, const string& last_name)
  		{
			tab[year].second = last_name;
			return ;
		}
		string GetFullName(int year)
		{
			vector<string> first_name;
			vector<string> last_name;
			FindFullNameHistory(first_name, last_name, year);
			size_t first_name_size = first_name.size();
			size_t last_name_size = last_name.size();
			if (first_name_size == 0 && last_name_size == 0)
				return ("Incognito");
			if (first_name_size == 0)
				return (last_name[0] + " with unknown first name");
			if (last_name_size == 0)	
				return (first_name[0] + " with unknown last name");
			return (first_name[0] + " " + last_name[0]);
		}
		string GetFullNameWithHistory(int year)
		{
			vector<string> first_name;
			vector<string> last_name;
			FindFullNameHistory(first_name, last_name, year);
			size_t first_name_size = first_name.size();
			size_t last_name_size = last_name.size();
			if (first_name_size == 0 && last_name_size == 0)
				return ("Incognito");
			if (first_name_size == 0)
				return (FormatedName(last_name) + " with unknown first name");
			if (last_name_size == 0)	
				return (FormatedName(first_name) + " with unknown last name");
			return (FormatedName(first_name) + " " + FormatedName(last_name));
		}
	private:
		string FormatedName(const vector<string>& src)
		{
			size_t size = src.size();
			if (size == 1)
				return (src[0]);
			string history = "";
			for (size_t iter = 1; iter < size; iter++)
			{
				history += src[iter];
				if (iter + 1 != size)
					history += ", ";
			}
			return (src[0] + " (" + history + ")");
		}
		void FillHistory(vector<string>& src, const string& str)
		{
			if (str == "")
				return ;
			if (src.size() == 0)
				src.push_back(str);
			else if (src[src.size() - 1] != str)
				src.push_back(str);
			return ;
		}
		void FindFullNameHistory(vector<string>& first_name, vector<string>& last_name, int year)
		{
			for (const auto& item : tab)
			{
				if (item.first > year)
					break ;
				FillHistory(first_name, item.second.first);
				FillHistory(last_name, item.second.second);
			}
			reverse(first_name.begin(), first_name.end());
			reverse(last_name.begin(), last_name.end());
			return ;
		}

		map<int, pair<string, string>> tab;
};

int main()
{
	Person person;
	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990})
		cout << person.GetFullNameWithHistory(year) << endl;
  
	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970})
		cout << person.GetFullNameWithHistory(year) << endl;
  
	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970})
    	cout << person.GetFullNameWithHistory(year) << endl;
  
	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;
  
	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;
  
	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967})
		cout << person.GetFullNameWithHistory(year) << endl;
  
	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}
