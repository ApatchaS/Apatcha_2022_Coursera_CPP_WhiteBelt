#include <string>
#include <vector>

using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> res;

	for (int i = 0; i < words.size(); i++)
	{
		if (words[i].length() >= minLength)
		{
			bool flag = true;
			for (int j = 0; j < words[i].length() / 2; j++)
				if (words[i][j] != words[i][words[i].length() - 1 - j])
					flag = false;
			if (flag)
				res.push_back(words[i]);
		}
	}
	return (res);
}
