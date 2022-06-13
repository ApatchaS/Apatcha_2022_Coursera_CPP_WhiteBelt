#include <iostream>
#include <vector>

using namespace std;

void Worrying(const vector<bool>& p)
{
	int counter = 0;
	for (auto c : p)
		if (c)
			counter++;
	cout << counter << endl;
	return ;
}

int main()
{
	int Q;
	string com;
	int count;
	vector<bool> queue(0, false);
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> com;
		if (com == "WORRY_COUNT")
			Worrying(queue);
		else
		{
			cin >> count;
			if (com == "WORRY")
				queue[count] = true;
			else if (com == "QUIET")
				queue[count] = false;
			else if (com == "COME")
				if (count >= 0)
					queue.insert(queue.cend(), count, false);
				else
					queue.erase(queue.cend() + count, queue.cend());
		}
	}
	return (0);
}
