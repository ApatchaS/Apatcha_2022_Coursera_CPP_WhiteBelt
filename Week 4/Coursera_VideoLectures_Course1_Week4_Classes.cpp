#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image
{
	double	quality;
	double	freshness;
	double	rating;
};

struct Params
{
	double	a;
	double	b;
	double	c;
};

class	FunctionPart
{
	public:
		FunctionPart(char new_operation, double new_value)
		{
			operation = new_operation;
			value = new_value;
		}

		double	Apply(double source_value) const
		{
			if (operation == '+')
				return (source_value + value);
			else
				return (source_value - value);
		}
		void	Invert(void)
		{
			if (operation == '+')
				operation = '-';
			else
				operation = '+';
			return ;
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
		double	Apply(double value) const
		{
			for (const FunctionPart& part : parts)
				value = part.Apply(value);
			return (value);
		}
		void	Invert(void)
		{
			for (FunctionPart& part : parts)
				part.Invert();
			reverse(begin(parts), end(parts));
			return ;
		}
	private:
		vector<FunctionPart>	parts;
};

Function	MakeWeightFunction(const Params& params,
								const Image& image)
{
	Function function;
	function.AddPart('-', image.freshness * params.a + params.b);
	function.AddPart('+', image.rating * params.c);
	return (function);
}

/*
*	implicit code duplication
*/
double	ComputeImageWeight (const Params& params,
							const Image& image)
{
	/*
	double weight = image.quality;
	weight -= image.freshness * params.a + params.b;
	weight += image.rating * params.c;
	return (weight);
	*/
	Function function = MakeWeightFunction(params, image);
	return (function.Apply(image.quality));
}

/*
*	implicit code duplication
*/
double	ComputeQualityByWeight (const Params& params,
								const Image& image,
								double weight)
{
	/*
	double quality = weight;
	quality -= image.rating * params.c;
	quality += image.freshness * params.a + params.b;
	return (quality);
	*/
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return (function.Apply(weight));
}

int	main(void)
{
	Image	image = {10, 2, 6};
	Params	params = {4, 2, 6};
	//10 - 2 * 4 - 2 + 6 * 6 = 36
	//36 + 2 * 4 + 2 - 6 * 6 = 10
	double	weight = ComputeImageWeight(params, image);
	cout << "Image Weight: " <<  weight << endl;
	cout << "Image quality by weight: " << ComputeQualityByWeight(params, image, weight) << endl;
	return (0);
}