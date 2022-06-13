#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int	main(void)
{
	ifstream	input("input.txt");
	string		buf;

	if (input)
		while(getline(input, buf))
			cout << buf << endl;
	return (0);
}