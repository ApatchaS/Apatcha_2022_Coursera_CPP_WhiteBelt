#include <iostream>
#include <vector>
#include <map>
#include <set> //library to handle with sets
#include <string>
#include <chrono> //library for manipulating time

using namespace std;
using namespace std::chrono; //namespace to count the time

/*
struct Person {
	string Name;
	string Surname;
	int Age;
};

vector <Person> GetMoscowPopulation(); //function getting the population of Moscow

//output of the number of people in Moscow
//parameter passing by reference is used in order not to create a copy of the array and speed up the execution of the program
//parameter passing by reference implies changing the actual variable
//the result of calling one function cannot be passed to another function by reference
//when passing a parameter by constant reference, a copy of the variable is not created and, at the same time, the possibility of changing this variable is disabled
//the result of calling one function can be passed to another function by a CONSTANT reference

void PrintPopulationSize(const vector<Person>& p)
{ 
	cout << "There are " << p.size() << " people in Moscow" << endl;
	return ;
}
*/

int sum(int x, int y) //example of declaring a function for the sum of 2 numbers
{	
	return (x + y);
}

void pretty() //example of procedure declaration
{
	cout << "\nYou are handsome!\n";
	return ;
}

void swap(int& x, int& y) //& - passing parameters not by value, but by reference
{
	int tmp = x;
	x = y;
	y = tmp;
	return ;
}

void PrintMap(const map<int, string>& m) //output of the dictionary to the screen
{	
	cout << "Map size: " << m.size() << endl; //dictionary size
	for (const auto& item : m) //passing through pairs of dictionary values
		cout << item.first << ": " << item.second << endl; //first-for the key second-for the key value
	return ;
}

void PrintSet(const set<string>& s) //output of the set to the screen
{
	cout << "Set size: " << s.size() << endl; //set size
	for (const auto& item : s) //passing through the elements of the set
		cout << item << endl;
	return ;
}

int main()
{
	setlocale(LC_ALL ,"rus"); //using Russian localization
	int X, Y;
	cin >> X >> Y;
	cout << "Sum of X and Y equals to "<< sum(X, Y); //example of function call

	pretty(); //example of procedure call
	
	swap(X, Y); //exchange of X and Y
	cout << "Result of swap function:" << endl << "X = " << X << endl << "Y = " << Y << endl;

	//auto start = steady_clock::now(); //fixing the time before the function is executed
	//vector<Person> People = GetMoscowPopulation();
	//auto finish = steady_clock::now(); //fixing the time after the function is executed
	//cout << "GetMoscowPopulation\n" << duration_cast<milliseconds>(finish - start).count()<<"ms\n"; //duration output
	//start = steady_clock::now();
	//PrintPopulationSize(People);
	//PrintPopulationSize(GetMoscowPopulation()); //error when transmitting by link
	//finish = steady_clock::now();
	//cout << "PrintPopulationSize\n" << duration_cast<milliseconds>(finish - start).count() << "ms\n";

	int n;
	cout << "Enter the number of vector elements:\n";
	cin >> n;
	vector<string>v(n);
	cout << "Enter the vector elements:\n";
	for (string& s : v)
		cin >> s;
	cout << "The specified vector:\n";
	for (auto i : v)
		cout << i << endl;

	map<int, string> events; //dictionary declaration
	events[1950] = "1 event"; //adding elements to the dictionary
	events[1941] = "2 event";
	events[1970] = "3 event";	
	PrintMap(events);
	cout << "Accessing element: " << events[1970] << endl; //accessing a dictionary element
	events.erase(1970); //deleting a dictionary element
	PrintMap(events);

	set<string> famous_persons; //set declaration
	famous_persons.insert("I"); //adding elements to the set
	famous_persons.insert("YOU");
	famous_persons.insert("WE");
	PrintSet(famous_persons);
	famous_persons.erase("WE"); //removing elements from a set
	return (0);
}
