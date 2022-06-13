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

int main()
{
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal)
		{
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal)
		{
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
