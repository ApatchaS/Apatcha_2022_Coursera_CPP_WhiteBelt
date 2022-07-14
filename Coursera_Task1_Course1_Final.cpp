#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <regex>
#include <map>
#include <set>

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

bool	operator< (const Date& LObj, const Date& RObj)
{
	if (LObj.GetYear() == RObj.GetYear() && LObj.GetMonth() == RObj.GetMonth())
		return (LObj.GetDay() < RObj.GetDay());
	if (LObj.GetYear() == RObj.GetYear())
		return (LObj.GetMonth() < RObj.GetMonth());
	return (LObj.GetYear() < RObj.GetYear());
}

ostream&	operator<< (ostream& stream, const Date& date)
{
	stream << setfill('0');
	stream << setw(4) << date.GetYear() << '-'
			<< setw(2) << date.GetMonth() << '-'
			<< setw(2) << date.GetDay();
	return (stream);
}

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
				for (const auto& event : date.second)
					cout << date.first << ' ' << event << endl; 
			return ;
		}
	private:
		map<Date, set<string>>	tab;
};

Date	ReadDate(istringstream& stream)
{
	string	bufer;
	stream >> bufer;
	istringstream	ss(bufer);
	int year, month, day;
	ss >> year;
	if (ss.fail() || ss.peek() != '-')
		throw runtime_error("Wrong date format: " + bufer);
	ss.ignore(1);

	ss >> month;
	if (ss.fail() || ss.peek() != '-')
		throw runtime_error("Wrong date format: " + bufer);
	ss.ignore(1);

	ss >> day;
	if (ss.fail() || ss.peek() != EOF)
		throw runtime_error("Wrong date format: " + bufer);

	return (Date(Year(year), Month(month), Day(day)));
}

int	main(void)
{
	DataBase	database;
	string		line;
	while (getline(cin, line))
	{
		try
		{
			istringstream	ss(line);
			string	command = "\0";
			ss >> command;
			if (command == "\0")
				continue;
			else if (command == "Add")
			{
				Date date = ReadDate(ss);
				string	event = "\0";
				ss >> event;
				database.AddEvent(date, event);
			}
			else if (command == "Del")
			{
				Date date = ReadDate(ss);
				if (ss.peek() != -1)
				{
					string	event = "\0";
					ss >> event;
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
				Date date = ReadDate(ss);
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