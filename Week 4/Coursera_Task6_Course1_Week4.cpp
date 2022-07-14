#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int main(void)
{
	ifstream			input("input.txt");
	size_t				N, M;
	
	input >> N >> M;
	vector<vector<int>>	tab(N, vector<int>(M));
	for (auto& row : tab)
	{
		for(auto& cell : row)
		{
			input >> cell;
			input.ignore(1);
		}
	}
	for (size_t iter = 0; iter < N; iter++)
	{
		for (size_t jter = 0; jter < M; jter++)
		{
			cout << setw(10) << tab[iter][jter];
			if (jter + 1 != M)
				cout << ' ';
		}
		if (iter + 1 != N)
			cout << endl;
	}
	return (0);
}
