#include <iostream> //library with input and output functions
#include <string> //library to handle with strings
#include <vector> //library to handle with vectors (dynamic arrays)
#include <map> //library to handle with maps (dictionaries)
#include <algorithm> //library with algorithm functions


using namespace std; //connecting a namespace

struct Person //custom variable type (structure)
{
    string name;
    string surname;
    int age;
};

int main() //major function in each programm on cpp
{
    cout << "Hello, World\n"; //output "Hello, World" with moving to the next line

    int z = -5; //integer type
    double pi = 3.14; //fractional type
    bool logical_value = true; //logical type (yes (1) / no (0))
    char symbol = 'Z'; //symbol type

    string hw = "Hello, World"; //string type

    vector<int> nums = {1, 3, 5, 7, 0, -12, 0, 154, 5, 1234}; //declaring and initializing a vector (dynamic array)
    cout << nums.size() << "\n"; //function to output number of items in vector

    map<string, int> name_to_value; //declaring a dictionary
    name_to_value["one"] = 1; //adding an item to the dictionary
    name_to_value["two"] = 2;
    cout << "two is " << name_to_value["two"] << "\n"; //example of output from the dictionary

    vector<Person> staff; //example of implementing a custom variable type
    staff.push_back({"Ivan", "Ivanov", 25}); //adding a custom type value to the end of the vector
    staff.push_back({"Petr", "Petrov", 32});
    cout << staff[0].name << "\n"; //аccessing the structure field ([name of the structure].[name of the field])
    
    string a = "aaa";
    string b = "aaZ";
    if (a < b) //implementation of lexicographic comparison
        cout << "less\n";
    else
        cout << "not less\n";

    for (auto c : nums) //foreach loop for passing through all elements of the container with automatic definition of the container variable type (auto)
        cout << c << "|";
    cout << "\n";

    cout << "count of '0': " << count(begin(nums), end(nums), 0) << "\n"; //number of required container elements
    sort(begin(nums), end(nums)); //sorting the container in ascending order
    for(auto c : nums)
        cout << c << "|";
	cout << "\n";
    
    string s1, s2;
    cin >> s1 >> s2;
    cout << "first input: " << s1 << "; second input: " << s2 << endl;

	int	x = 4;
	cout << endl;
	cout << "X value: " << x << endl;
	cout << "postfix increment of X: " << x++ << endl; //postfix increment
	cout << "prefix increment of X: " << ++x << endl; //prefix increment
	cout << "postfix decrement of X: " << x-- << endl; //postfix decrement
	cout << "prefix decrement of X: " << --x << endl; //prefix decrement

	int n = 10;
	while (n > 0) //while loop
	{
		char c = 65 + rand() % 26; // % - the remainder of the division
		cout << c;
		n--;
	}
	
	do //do-while loop
		cout << "\nDo-while loop\n"; // n is already 0, therefore do-while loop performs only one iteration  
	while (n > 0);

    map <string, int> c = {{"a",1}, {"b", 2}, {"c", 3}}; //example of a dictionary declaration with initialization
    for (auto i : c)
	{
        cout << i.first << endl; //keywords "first" and "second"
        cout << i.second << endl;
    }

	vector<string> names = {"Alexander", "Kirill", "Regina", "Gleb", "Ivan"};
	for (size_t iter = 0; iter < names.size(); iter++) //for loop 
		cout << iter << ": " << names[iter] << endl;

    return (0);
}
