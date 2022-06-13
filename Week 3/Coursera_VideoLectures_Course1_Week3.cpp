#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //header file for working with algorithmic functions: min/max/count/count_if/sort

using namespace std;

int Min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int Max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void print_vector(const vector<int>& v, const string& title)
{
	cout << title << endl;
	for (auto item : v)
		cout << item << " ";
	cout << endl;
	return ;
}

bool if_even(int v)
{
	if (v % 2 == 0)
		return (true);
	return (false);
}

void print_parity(const int& x)
{
	string parity = (x % 2 == 0) ? "even" : "odd"; //ternary operator
	cout << x << " is " << parity << endl;
	return ;
}

struct	name { //structure declaration
		string FirstName;
		string SecondName;
};

int main()
{
	name I = {"Alexander", "Apatchenko"};
	cout << I.FirstName << " " << I.SecondName << endl;
	
	vector <int> v = { 5, 4, 4, 3, 2, 1, 4 };
	cout << "My Min: " << Min(2, 3) << endl;
	cout << "Standart min: " << min(2, 3) << endl;
	cout << "My Max: " << Max(2, 3) << endl;
	cout << "Standart max: " << max(2, 3) << endl;
	
	print_vector(v, "src");
	sort(begin(v), end(v));
	print_vector(v, "sort");
	
	cout << "Count of \"4\" in vector: " << count(begin(v), end(v), 4) << endl;
	cout << "Count of even elements in vector: " << count_if(begin(v), end(v), if_even) << endl;
	cout << "Count of odd elements in vector: " << count_if(begin(v), end(v), [](int v) {if (v % 2 != 0) return true; return false;}) << endl; //example of lambda expression
	
	int thr;
	cout << "Put the thr: ";
	cin >> thr;
	cout << "Count of elements in vector greater than thr: " << count_if(begin(v), end(v), [thr](int v) {if (v > thr) return true; return false;}) << endl; //example of lambda expression

	print_parity(17);

	return (0);
}
