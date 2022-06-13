#include <iostream>

using namespace std;

int	FindGCD(int first, int second)
{
	first = abs(first);
	second = abs(second);
	while (first > 0 && second > 0)
		if (first > second)
			first %= second;
		else
			second %= first;
	return (first + second);
}

int	FindSCM(int first, int second)
{
	first = abs(first);
	second = abs(second);
	return (first * second / FindGCD(first, second));
}

class Rational
{
	public:
    	Rational()
		{
        	numerator = 0;
			denominator = 1;
			return ;
		}

    	Rational(int new_numerator, int new_denominator)
		{
			if (new_denominator == 0)
				throw invalid_argument("Invalid argument");
			if (new_numerator == 0)
			{
				numerator = 0;
				denominator = 1;
				return ;
			}
			int	new_gcd = FindGCD(new_numerator, new_denominator);
			int sign = 1;
			sign *= new_numerator < 0 ? -1 : 1;
			sign *= new_denominator < 0 ? -1 : 1;
			numerator = sign * abs(new_numerator) / new_gcd;
			denominator = abs(new_denominator) / new_gcd;
			return ;
		}

    	int	Numerator() const
		{
        	return (numerator);
    	}

    	int	Denominator() const
		{
			return (denominator);
    	}

	private:
		int	numerator;
		int	denominator;
};

bool	operator== (const Rational& first, const Rational& second)
{
	int	SCM = FindSCM(first.Denominator(), second.Denominator());
	int	first_ratio = SCM / first.Denominator();
	int	second_ratio = SCM / second.Denominator();

	if (first.Numerator() * first_ratio == second.Numerator() * second_ratio)
		return (true);
	return (false);
}

Rational	operator+ (const Rational& first, const Rational& second)
{
	int	SCM = FindSCM(first.Denominator(), second.Denominator());
	int	first_ratio = SCM / first.Denominator();
	int	second_ratio = SCM / second.Denominator();

	return (Rational(first.Numerator() * first_ratio + second.Numerator() * second_ratio, SCM));
}

Rational	operator- (const Rational& first, const Rational& second)
{
	int	SCM = FindSCM(first.Denominator(), second.Denominator());
	int	first_ratio = SCM / first.Denominator();
	int	second_ratio = SCM / second.Denominator();

	return (Rational(first.Numerator() * first_ratio - second.Numerator() * second_ratio, SCM));
}

Rational	operator* (const Rational& first, const Rational& second)
{
	return (Rational(first.Numerator() * second.Numerator(), first.Denominator() * second.Denominator()));
}

Rational	operator/ (const Rational& first, const Rational& second)
{
	if (second.Numerator() == 0)
		throw domain_error("Division by zero");
	return (Rational(first.Numerator() * second.Denominator(), first.Denominator() * second.Numerator()));
}

ostream&	operator<< (ostream& stream, const Rational& rational)
{
	if (!stream)
		return (stream);
	stream << rational.Numerator() << "/" << rational.Denominator();
	return (stream); 
}

istream&	operator>> (istream& stream, Rational& rational)
{
	if (!stream)
		return (stream);
	int		numerator = 0, denominator = 0;
	char	delim = '\0';
	stream >> numerator;
	stream >> delim;
	stream >> denominator;
	stream.ignore(1);
	if (delim != '/')
		throw invalid_argument("Invalid argument");
	else
		rational = Rational(numerator, denominator);
	return (stream);
}

bool	operator< (const Rational& first, const Rational& second)
{
	int	SCM = FindSCM(first.Denominator(), second.Denominator());
	int	first_ratio = SCM / first.Denominator();
	int	second_ratio = SCM / second.Denominator();
	if (first.Numerator() * first_ratio < second.Numerator() * second_ratio)
		return (true);
	return (false);
}

int	main(void)
{
	Rational	first;
	char		operation;
	Rational	second;
	try
	{
		cin >> first;
		cin >> operation;
		cin >> second;
		if (operation == '+')
			cout << first + second;
		else if (operation == '-')
			cout << first - second;
		else if (operation == '*')
			cout << first * second;
		else if (operation == '/')
			cout << first / second;
	}
	catch(exception& ex)
	{
		cout << ex.what() << endl;
	}
	return (0);
}
