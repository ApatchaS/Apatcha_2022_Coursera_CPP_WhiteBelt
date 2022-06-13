#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <regex>
#include <map>
#include <set>
#include <exception>

using namespace std;

struct	Year
{
	int	value;
	explicit Year(int new_value)
	{
		value = new_value;
	}
};

struct	Month
{
	int	value;
	explicit Month(int new_value)
	{
		value = new_value;
	}
};

struct	Day
{
	int	value;
	explicit Day(int new_value)
	{
		value = new_value;
	}
};

class	Date
{
	public:
		Date(Year new_year, Month new_month, Day new_day)
		{
			if (new_month.value < 1 || new_month.value > 12)
				throw invalid_argument("Month value is invalid: " + to_string(new_month.value));
			if (new_day.value < 1 || new_day.value > 31)
				throw runtime_error("Day value is invalid: " + to_string(new_day.value));
			year = new_year.value;
			month = new_month.value;
			day = new_day.value;
		}
		int	GetYear(void) const {return (year);}
		int	GetMonth(void) const {return (month);}
		int	GetDay(void) const {return (day);}
	private:
		int	year;
		int	month;
		int	day;
};

class	DataBase
{
	public:
		void	AddEvent(const Date& date, const string& event)
		{
			tab[date].insert(event);
			return ;
		}
		bool	DeleteEvent(const Date& date, const string& event)
		{
			if (tab.count(date) == 0)
				return (false);
			if (tab[date].count(event) == 0)
				return (false);
			tab[date].erase(event);
			return (true);
		}
		int	DeleteDate(const Date& date)
		{
			size_t	events = 0;
			if (tab.count(date) == 0)
				return (events);
			events = tab[date].size();
			tab.erase(date);
			return (events);
		}
		void	Find(const Date& date) const
		{
			if (tab.count(date) == 0)
				return ;
			for (const auto& event : tab.at(date))
				cout << event << endl;
			return ;
		}
		void	Print() const
		{
			for (const auto& date : tab)
			{
				for (const auto& event : date.second)
				{
					cout << setfill('0');
					cout << setw(4) << date.first.GetYear() << '-'
							<< setw(2) << date.first.GetMonth() << '-'
							<< setw(2) << date.first.GetDay() << ' '
							<< event << endl;
				}
			}
			return ;
		}
	private:
		map<Date, set<string>>	tab;
};

bool	operator< (const Date& LObj, const Date& RObj)
{
	if (LObj.GetYear() == RObj.GetYear() && LObj.GetMonth() == RObj.GetMonth())
		return (LObj.GetDay() < RObj.GetDay());
	if (LObj.GetYear() == RObj.GetYear())
		return (LObj.GetMonth() < RObj.GetMonth());
	return (LObj.GetYear() < RObj.GetYear());
}

Date	ReadDate(istream& stream)
{
	string	bufer;
	stream >> bufer;
	regex	rgx("^[-+]?[0-9]+[-][-+]?[0-9]+[-][-+]?[0-9]+$");
	if (!regex_match(bufer, rgx))
		throw runtime_error("Wrong date format: " + bufer);
	stringstream	ss(bufer);
	int	year, month, day;
	ss >> year;
	ss.ignore(1);
	ss >> month;
	ss.ignore(1);
	ss >> day;
	return (Date(Year(year), Month(month), Day(day)));
}

int	main(void)
{
	DataBase	database;
	while (cin.peek() != EOF)
	{
		try
		{
			string	command;
			cin >> command;
			if (command == "Add")
			{
				Date date = ReadDate(cin);
				string	event;
				cin >> event;
				database.AddEvent(date, event);
			}
			else if (command == "Del")
			{
				Date date = ReadDate(cin);
				if (cin.peek() != '\n')
				{
					string	event;
					cin >> event;
					bool res = database.DeleteEvent(date, event); 
					if (res)
						cout << "Deleted successfully\n";
					else
						cout << "Event not found\n";
				}
				else
				{
					int res = database.DeleteDate(date);
					cout << "Deleted " << res << " events\n";
				}
			}
			else if (command == "Find")
			{
				Date date = ReadDate(cin);
				database.Find(date);
			}
			else if (command == "Print")
				database.Print();
			else
				throw	runtime_error("Unknown command: " + command);
		}
		catch(exception& ex)
		{
			cout << ex.what() << endl;
			return (1);
		}
	}
	return (0);
}