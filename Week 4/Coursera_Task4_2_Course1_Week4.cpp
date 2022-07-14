#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int	main(void)
{
	ifstream	input("input.txt");
	ofstream	output("output.txt");
	string		buf;

	if (input)
		while(getline(input, buf))
			output << buf << endl;
	return (0);
}