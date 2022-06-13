#include <iostream>

using namespace std;

struct Day
{
	int value;
	explicit Day(int new_value)
	{
		value = new_value;
	}
};

struct Month
{
	int value;
	explicit Month(int new_value)
	{
		value = new_value;
	}
};

struct Year
{
	int value;
	explicit Year(int new_value)
	{
		value = new_value;
	}
};

struct Date
{
	int day;
	int month;
	int year;

	Date(Day new_day, Month new_month, Year new_year)
	{
		day = new_day.value;
		month = new_month.value;
		year = new_year.value;
	}
};

void	ft_print_date(const Date& date)
{
	cout << date.day << "." << date.month << "." << date.year << endl;
	return ;
}

/*
*	Ways to create a variable of struct type:
*		Without struct constructor:
*				Date date = {1,1,2017}
*							- easy to forget the meaning of each field
*							- it is possible to change the order of fields
*		With struct constructor (with signature Date(Day new_day, Month new_month, Year new_year)) and supportive structs
*				Date date = {{1},{1},{2017}}
*				Date date({1},{1},{2017})
*							- easy to forget the meaning of each field
*							- it is possible to change the order of fields
*				Date date = {Day{1}, Month{1}, Year{2017}}
*				Date date(Day{1}, Month{1}, Year{2017})
*							- explicit names of structures can be removed that lead to previous situation
*		With struct constructor (with signature Date(Day new_day, Month new_month, Year new_year)) and supportive structs and constructors
*				Date date = {1,1,2017}
*				Date date(1,1,2017)
*				Date date = {{1},{1},{2017}}
*				Date date({1},{1},{2017})
*							- easy to forget the meaning of each field
*							- it is possible to change the order of fields
*				Date date = {Day{1}, Month{1}, Year{2017}}
*				Date date(Day{1}, Month{1}, Year{2017})
*				Date date = {Day(1), Month(1), Year(2017)}
*				Date date(Day(1), Month(1), Year(2017))
*							- explicit names of structures can be removed that lead to previous situation
*		With struct constructor (with signature Date(Day new_day, Month new_month, Year new_year)) and supportive structs and EXPLICIT constructors
*				Date date = {Day{1}, Month{1}, Year{2017}}
*				Date date(Day{1}, Month{1}, Year{2017})
*				Date date = {Day(1), Month(1), Year(2017)}
*				Date date(Day(1), Month(1), Year(2017))
*	explicit - obvious/clear/accurate
*	explicit constructor - specifying an explicit conversion of a built-in type to an object of the structure type
*	Declaration of explicit constructor:
*				explicit [name of the construcor (name of struct/class)]([arguments]) {[body of the construction]}
*/
int	main(void)
{
	Date	date(Day(1), Month(1), Year(2017));
	ft_print_date(date);
	return (0);
}
