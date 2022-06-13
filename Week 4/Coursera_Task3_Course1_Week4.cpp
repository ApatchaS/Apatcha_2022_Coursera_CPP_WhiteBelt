#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
struct	Params
{
	double	a;
	double	b;
	double	c;
};

struct	Image
{
	double	quality;
	double	freshness;
	double	rating;
};
*/
class	FunctionPart
{
	public:
		FunctionPart(const char& new_operation, const double& new_value)
		{
			operation = new_operation;
			value = new_value;
		}
		void	Invert(void)
		{
			if (operation == '+')
				operation = '-';
			else if (operation == '-')
				operation = '+';
			else if (operation == '*')
				operation = '/';
			else if (operation == '/')
				operation = '*';
			return ;
		}
		double	Apply(double source_value) const
		{
			if (operation == '+')
				return (source_value + value);
			if (operation == '*')
				return (source_value * value);
			if (operation == '-')
				return (source_value - value);
			if (operation == '/')
				return (source_value / value);
			return (0);
		}
	private:
		char	operation;
		double	value;
};

class	Function
{
	public:
		void	AddPart(char operation, double value)
		{
			parts.push_back({operation, value});
			return ;
		}
		void	Invert(void)
		{
			for (FunctionPart& part : parts)
				part.Invert();
			reverse(begin(parts), end(parts));
			return ;
		}
		double	Apply(double value) const
		{
			for (const FunctionPart& part : parts)
				value = part.Apply(value);
			return (value);
		}
	private:
		vector<FunctionPart>	parts;
};
/*
Function	MakeWeightFunction(const Params& params,
								const Image& image)
{
	Function	function;
	function.AddPart('*', params.a);
	function.AddPart('-', image.freshness * params.b);
	function.AddPart('+', image.rating * params.c);
	return (function);
}

double	ComputeImageWeight(const Params& params,
							const Image& image)
{
	Function	function = MakeWeightFunction(params, image);
	return (function.Apply(image.quality));
}

double	ComputeQualityByWeight(const Params& params,
								const Image& image,
								double weight)
{
	Function	function = MakeWeightFunction(params, image);
	function.Invert();
	return (function.Apply(weight));
}

int	main(void)
{
	Params params = {4, 2, 6};
	Image image = {10, 2, 6};
	cout << ComputeImageWeight(params, image) << endl;
	cout << ComputeQualityByWeight(params, image, 52) << endl;
	return (0);
}
*/