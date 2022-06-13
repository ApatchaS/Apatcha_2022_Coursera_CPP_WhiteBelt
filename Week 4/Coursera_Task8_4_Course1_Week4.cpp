#include <iostream>
#include <sstream>

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
	if (numerator == 0 || denominator == 0 || delim != '/')
		rational = Rational();
	else
		rational = Rational(numerator, denominator);
	return (stream);
}

int main()
{
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4")
		{
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal)
		{
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct)
		{
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct)
		{
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct)
		{
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct)
		{
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    {
        istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct)
		{
            cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
            return 7;
        }
    }

    cout << "OK" << endl;
    return 0;
}
