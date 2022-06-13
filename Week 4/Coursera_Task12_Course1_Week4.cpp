#include <string>
#include <exception>
#include <iostream>

using namespace std;

/*
string	AskTimeServer()
{
	//throw system_error(error_code());
	//throw invalid_argument("haha");
	return ("10:10:10");
}
*/

class TimeServer
{
	public:
		string GetCurrentTime()
		{
			try
			{
				last_fetched_time = AskTimeServer();
			}
			catch(system_error& ex)
			{
			}
			return (last_fetched_time);
		}
	private:
		string last_fetched_time = "00:00:00";
};

int	main(void)
{
    TimeServer ts;
    try
	{
        cout << ts.GetCurrentTime() << endl;
    }
	catch (exception& e)
	{
        cout << "Exception got: " << e.what() << endl;
    }
	return (0);
}