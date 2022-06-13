#include <iostream>
#include <string>
#include <fstream> //Header file for working with file streams

using namespace std;

int	main(void)
{
	ifstream	input1("Text_Example_1.txt"); //Class object to read from stream (Constructor takes 1 argument: path to file)
	/*
	*	Function getline
	*	Call: getline([stream where data is read from], [string where data is written to])
	*	Return value: reference to the stream where data is read from -> the stream can be converted to a logical type
	*	When writing stream contents to a string, getline() reads them up to a certain separator that is not included in the string - by default: '\n'
	*
	*	Method is_open
	*	Call: [stream class object].is_open()
	*	Return value:
	*		true - the file stream is open and ready to work
	*		false - the file stream is not open (error)
	*	To check the opening of the stream, you do not need to use this method: any object of the stream class is converted to a logical variable
	*		input.is_open() == input
	*/
	if (!input1.is_open())
	{
		cout << "Error while opening the file Text_Example_1\n";
		return (1);
	}
	cout << "FIRST FILE\n";
	bool		flag1 = 0;
	cout << "Choose option: 0 - mistaken call of getline(); 1 - smart call of getline()\n";
	cin >> flag1;
	string		line;
	if (flag1)
	{
		while(getline(input1, line))
			cout << line << endl;
	}
	else
	{
		getline(input1, line);
		cout << line << endl; //Output of the first line of the file

		getline(input1, line);
		cout << line << endl; //Output of the second line of the file - the file is finished
	
		getline(input1, line);
		cout << line << endl; //The getline function returns nothing because the file is finished; the line remains unchanged after the previous call
	}

	ifstream	input2("Text_Example_2.txt");
	/*
	*	The getline() function has 3 optional delimiter argument, which by default is a line break
	*	getline([stream], [string], [separator])
	*
	*	Method ignore
	*	Call: [stream class object].ignore([number of ignored characters])
	*	The method ignores n characters from the stream
	*/
	if (!input2)
	{
		cout << "Error while opening the file Text_Example_2\n";
		return (2);
	}
	cout << "SECOND FILE\n";
	bool		flag2 = 0;
	cout << "Choose option: 0 - getline(); 1 - >>\n";
	cin >> flag2;
	if (flag2)
	{
		int	year = 0;
		int	month = 0;
		int	day = 0;
		input2 >> year;
		input2.ignore(1);
		input2 >> month;
		input2.ignore(1);
		input2 >> day;
		cout << year << " " << month << " " << day << endl;
	}
	else
	{
		string	year;
		string	month;
		string	day;
		getline(input2, year, '-');
		getline(input2, month, '-');
		getline(input2, day, '-');
		cout << year << " " << month << " " << day << endl;
	}

	/*
	*	Example of writing to a stream
	*	An object of the ofstream class is being created
	*	The path to the file and access modifiers are specified as constructor arguments
	*	Path - "Text_Example_3.txt"; Modifiers - app (append)
	*	Writing to the file is done via the output operator: <<
	*/
	ofstream	output1("Text_Example_3.txt", ios::app);
	output1 << " world!" << endl;

	return (0);
}