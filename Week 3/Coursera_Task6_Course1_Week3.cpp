#include <iostream>

using namespace std;

class	ReversibleString
{
	public:
		ReversibleString(const string& source_str)
		{
			str = source_str;
		}
		ReversibleString()
		{
			str = "";
		}

		void	Reverse(void)
		{
			size_t size = str.size();
			for (size_t iter = 0; iter < size / 2; iter++)
			{
				char tmp = str[iter];
				str[iter] = str[size - iter - 1];
				str[size - iter - 1] = tmp;
			}
			return ;
		}
		string	ToString(void) const
		{
			return (str);
		}
	private:
		string str;
};

int	main(void)
{
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return (0);
}