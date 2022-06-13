#include <iostream>

using namespace std;

int	FindGCD(int numerator, int denominator)
{
	numerator = abs(numerator);
	denominator = abs(denominator);
	while (numerator > 0 && denominator > 0)
		if (numerator > denominator)
			numerator %= denominator;
		else
			denominator %= numerator;
	return (numerator + denominator);
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

int main()
{
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10)
		{
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3)
		{
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3)
		{
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3)
		{
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1)
		{
			cout << r.Numerator() << " " << r.Denominator() << endl;
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1)
		{
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
