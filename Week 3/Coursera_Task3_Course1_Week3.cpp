#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class	SortedStrings
{
	public:
  		void	AddString(const string& str)
		{
			tab.push_back(str);
			SortStrings();
			return ;
	 	}
  		vector<string>	GetSortedStrings()
		{
  		  return (tab);
  		}
	private:
  		vector<string>	tab;
		
		void	SortStrings()
		{
			sort(begin(tab), end(tab));
			return ;
		}
};

void	PrintSortedStrings(SortedStrings& strings)
{
  for (const string& s : strings.GetSortedStrings())
    cout << s << " ";
  cout << endl;
  return ;
}

int	main(void)
{
	SortedStrings strings;
  
	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);
  
	strings.AddString("second");
	PrintSortedStrings(strings);

	return (0);
}
