class Incognizable
{
	public:
		Incognizable()
		{
			value_first = 0;
			value_second = 0;
		}
		Incognizable(const int& first_value)
		{
			value_first = first_value;
			value_second = 0;
		}
		Incognizable(const int& first_value, const int& second_value)
		{
			value_first = first_value;
			value_second = second_value;
		}
	private:
		int	value_first;
		int	value_second;
};
int main()
{
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  
  return 0;
}