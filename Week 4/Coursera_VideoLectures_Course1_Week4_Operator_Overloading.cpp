#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct	Duration
{
	int hour;
	int min;
	Duration(int new_hour = 0, int new_min = 0)
	{
		int	total = new_hour * 60 + new_min;
		hour = total / 60;
		min = total % 60;
	}
};

//Reading data from a stream without using operator overload
Duration	ReadDuration(istream& stream)
{
	int	h = 0;
	int	m = 0;
	stream >> h;
	stream.ignore(1);
	stream >> m;
	return (Duration{h, m});
}

//Overload of the input operator for the Duration structure
istream&	operator>> (istream& stream, Duration& duration)
{
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;
	return (stream);
}

//Data output to the stream without using operator overload
void	PrintDuration(ostream& stream, const Duration& duration)
{
	stream << setfill('0');
	stream << setw(2) << duration.hour;
	stream << ':';
	stream << setw(2) << duration.min;
	return ;
}

//Overloading the output operator for the Duration structure
ostream&	operator<< (ostream& stream, const Duration& duration)
{
	stream << setfill('0');
	stream << setw(2) << duration.hour;
	stream << ':';
	stream << setw(2) << duration.min;
	return (stream);
}

/*
*	Overload of I/O operators
*	In this case, the output operator is overloaded for more convenient printing of the vector to the console
*	Declaration:
*	[return value: stream reference] operator[operator] ([stream reference], [object passed to stream]) {[body]}
*
*	//stream output operator
*	ostream& operator<<(ostream& s, const Obj& o)
*
*	//stream input operator
*	istream& operator>>(istream& s, Obj& o)
*/
ostream&	operator<< (ostream& stream, const vector<double>& tab)
{
	for (const auto& item : tab)
		stream << item << " ";
	return (stream);
}

/*
*	Overloading the summation operator
*	Declaration:
*	[return value: object] operator+ ([object 1], [object 2]) {[body]}
*/
Duration	operator+ (const Duration& obj1, const Duration& obj2)
{
	return (Duration(obj1.hour + obj2.hour, obj1.min + obj2.min));
}

/*
*	Overloading the "less than" operator
*	Declaration:
*	bool operator< ([object 1], [object 2]) {[body]}
*/
bool		operator< (const Duration& obj1, const Duration& obj2)
{
	if (obj1.hour == obj2.hour)
		return (obj1.min < obj2.min);
	return (obj1.hour < obj2.hour);
}

void	PrintVectorDuration(const vector<Duration>& tab)
{
	for (const auto& item : tab)
		cout << item << " ";
	cout << endl;
	return ;
}

int	main(void)
{
	cout << "Output Duration structure without overloaded operators\n";
	stringstream	dur1_ss("01:50");
	Duration		dur1 = ReadDuration(dur1_ss);
	PrintDuration(cout, dur1);
	cout << endl;
	
	cout << "Output Duration structure with overloaded operators\n";
	stringstream	dur2_ss("14:05");
	Duration		dur2;
	dur2_ss >> dur2;
	cout << dur2 << endl;

	vector<double>	tab = {1, 12, 0.2, 14};
	cout << "Vector:\n" << tab << endl;

	Duration			dur3 = dur1 + dur2;
	vector<Duration>	v = {dur3, dur2, dur1};
	PrintVectorDuration(v);
	sort(begin(v), end(v));
	PrintVectorDuration(v);
	return (0);
}