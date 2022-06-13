#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Date
{
	int year;
	int	month;
	int	day;
};

void	EnsureNextSymbolAndSkip(stringstream& stream)
{
	if (stream.peek() != '/') //.peek() is a method of the stream class that returns the next character lying in it
	{
		//throw exception(); //exception - a message to the calling code about unexpected behavior - leads to an emergency termination of the program
		stringstream ss;
		ss << "excepted /, but has: '" << (char)stream.peek() << "'";
		throw runtime_error(ss.str()); //.str() is a method of the stringstream class that returns a string that is in the stream
	}
	stream.ignore(1);
	return ;
}

Date	ParseDate(const string& s)
{
	stringstream	stream(s);
	Date	date;
	stream >> date.year;
	EnsureNextSymbolAndSkip(stream);
	stream >> date.month;
	EnsureNextSymbolAndSkip(stream);
	stream >> date.day;
	return (date);
}

/*
*	exception - class responsible for throwing/handling exceptions
*				all exceptions are inherited from it
*	Error handling
*	Syntax:
*	try
*	{
*		//code potentially causing an exception
*	}
*	catch([caught exception //exception&])
*	{
*		//handler
*	}
*/
int	main(void)
{
	string	data_str = "2017 01/25";
	try
	{
		Date	date = ParseDate(data_str);
		cout << setfill('0');
		cout << setw(2) << date.day << '.' 
				<< setw(2) << date.month << '.'
				<< setw(4) << date.year << endl;
	}
	catch(exception& ex)
	{
		cout << "Exception!\n";
		cout << ex.what() << "!\n"; //.what() is a method of the exception class that returns an error message
	}
	return (0);
}
