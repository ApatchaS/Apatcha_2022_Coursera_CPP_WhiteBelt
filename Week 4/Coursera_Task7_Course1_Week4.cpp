#include <iostream>
#include <vector>

using namespace std;

struct	Student
{
	string	first_name;
	string	last_name;
	int		day;
	int		month;
	int		year;
};

int	main(void)
{
	size_t	N;
	cin >> N;
	vector<Student>	tab(N);
	for (auto& item : tab)
	{
		string	first_name, last_name;
		int		day, month, year;
		cin >> first_name >> last_name >> day >> month >> year;
		item = {first_name, last_name, day, month, year};
	}
	size_t M;
	cin >> M;
	for (size_t iter = 0; iter < M; iter++)
	{
		string	call;
		int		number;
		cin >> call >> number;
		if (call == "name" && number > 0 && number <= N)
			cout << tab[number - 1].first_name << ' ' << tab[number - 1].last_name << endl;
		else if (call == "date" && number > 0 && number <= N)
			cout << tab[number - 1].day << '.' << tab[number - 1].month << '.' << tab[number - 1].year << endl;
		else
			cout << "bad request\n";
	}
	return (0);
}
