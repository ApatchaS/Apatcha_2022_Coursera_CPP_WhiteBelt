#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

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

bool	operator< (const Rational& first, const Rational& second)
{
	int	SCM = FindSCM(first.Denominator(), second.Denominator());
	int	first_ratio = SCM / first.Denominator();
	int	second_ratio = SCM / second.Denominator();
	if (first.Numerator() * first_ratio < second.Numerator() * second_ratio)
		return (true);
	return (false);
}

int main()
{
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3)
		{
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs)
		{
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}})
		{
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2)
		{
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
