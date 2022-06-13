#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map<string, vector<string>> buses;
	map<string, vector<string>> stops;
	
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		string com;
		cin >> com;
		if (com == "NEW_BUS")
		{
			string bus;
			int stop_count;
			cin >> bus >> stop_count;
			for (int j = 0; j < stop_count; j++)
			{
				string stop;
				cin >> stop;
				buses[bus].push_back(stop);
				stops[stop].push_back(bus);
			}
		}
		if (com == "BUSES_FOR_STOP")
		{
			string stop;
			cin >> stop;
			if (stops.find(stop) == stops.end())
				cout << "No stop\n";
			else
			{
				for (const auto& item : stops[stop])
					cout << item << " ";
				cout << endl;
			}
		}
		if (com == "STOPS_FOR_BUS")
		{
			string bus;
			cin >> bus;
			if (buses.find(bus) == buses.end())
				cout << "No bus\n";
			else
				for (const auto& item : buses[bus])
				{
					cout << "Stop ";
					cout << item <<": ";
					if (stops[item].size() == 1)
						cout << "no interchange\n";
					else
					{
						for (const auto& newitem : stops[item])
							if (newitem == bus)
								continue;
							else
								cout << newitem << " ";
						cout << endl;
					}
				}
		}
		if (com == "ALL_BUSES")
			if (buses.size() == 0)
				cout << "No buses\n";
			else
				for (const auto& item : buses)
				{
					cout << "Bus ";
					cout << item.first<<": ";
					for (const auto& newitem : item.second)
						cout << " " << newitem;
					cout << endl;
				}
	}
	return (0);
}
