#include <iostream>
#include <vector>

using namespace std;

int	ft_compute_distance(const string& source, const string& destination)
{
	return (10 + (rand() % 11) * (rand() % (source.length() + destination.length())));
}

/*
*	Class Declaration:
*	Access to class fields is private - there is no way to change them from the outside (source, destination, length)
*	Access to private class fields is carried out through public methods (get_source, get_destination, get_length)
*/
class	Class_Route
{
	public:
		/*
		*	Declaration of a parameterized class constructor:
		*	Differences from the method:
		*		There is no return value
		*		The name of the constructor is the same as the name of the class
		*	Thanks to the constructor, it is much faster and more convenient to create a class object in one line
		*	[Class Name] [Class Object name] ([Constructor arguments]);
		*/
		Class_Route(const string& new_source, const string& new_destination)
		{
			source = new_source;
			destination = new_destination;
			update_length();
		}
		
		/*
		*	Default constructor declaration:
		*	In the body of this constructor defined general
		*	*for calling: Class_Route [object name];
		*	field values
		*/
		Class_Route()
		{
			source = "Kaminskiy";
			destination = "Ivanovo";
			update_length();
		}

		string	get_source() const {return source;}
		string	get_destination() const {return destination;}
		int		get_length() const {return length;}

		void	set_source(const string& new_source)
		{
			source = new_source;
			update_length();
			return ;
		}
		void	set_destination(const string& new_destination)
		{
			destination = new_destination;
			update_length();
			return ;
		}

		/*
		*	Destructor declaration:
		*	~[class name](arguments){destructor body}
		*	Called when an object of the class is destroyed
		*	Can be both public and private
		*/
		~Class_Route()
		{
			for (const auto& item : compute_distance_log)
				cout << item << endl;
			cout << "end of logs\n";
		}
	private:
		string			source;
		string			destination;
		int				length;
		vector<string>	compute_distance_log;

		void	update_length(void)
		{
			length = ft_compute_distance(source, destination);
			compute_distance_log.push_back(source + " - " + destination);
			return ;
		}
};

/*
*	Structure Declaration:
*	Access to the fields of the structure is public - it is possible to change them where the variable is visible
*	There is a high probability of making a mistake - forget to change the length field when changing the source or destination
*/
struct	Struct_Route
{
	string	source;
	string	destination;
	int		length;
};

/*
*	Illustration of the use of constant methods of the class:
*	The class object is passed by constant link - i.e. the function has no right to change it
*	If the called methods of the class in this function do not have constancy, the code will not compile
*	(since the methods do not explicitly state that they do not have the right to change the fields of the class)
*	[return type] [method name]([arguments]) const {[method body]}
*/
void ft_print_class_example(const Class_Route& Class_Example)
{
	cout << "Route from " << Class_Example.get_source() << " to " << Class_Example.get_destination() << " : " << Class_Example.get_length() << " kilometers\n";
	return ;
}

/*
*	The class object is passed by a non-constant link - i.e. the function has the right to change it
*	When transmitting via a non-constant link, it is possible to use both constant and non-constant methods
*	In this case:
*	get_source() and get_destination() methods are constant
*	the set_source() and set_destination() methods are nonconstant
*/
void ft_reverse_route(Class_Route& Class_Example)
{
    string old_source = Class_Example.get_source();
    string old_destination = Class_Example.get_destination();
    Class_Example.set_source(old_destination);
    Class_Example.set_destination(old_source);
	return ;
}

int	main(void)
{
	Struct_Route	Struct_Example; //Declaration of a user-defined type (structure) variable
	//Initialization of structure fields
	Struct_Example.source = "Saratov";
	Struct_Example.destination = "Tokyo";
	Struct_Example.length = ft_compute_distance(Struct_Example.source, Struct_Example.destination);
	
	cout << "Route from " << Struct_Example.source << " to " << Struct_Example.destination << " : " << Struct_Example.length << " kilometers\n";
	
	Class_Route		Class_Example("Ivanovo", "Moscow"); //Declaring a class object and initializing its fields using the constructor
	
	ft_print_class_example(Class_Example);
	ft_reverse_route(Class_Example);
	ft_print_class_example(Class_Example);

	//Passing to the function an object created by the default constructor
	ft_print_class_example({});
	ft_print_class_example(Class_Route());

	//Passing an object created by a parameterized constructor to a function
	ft_print_class_example({"Madrid", "Omsk"});
	ft_print_class_example(Class_Route("Madrid", "Omsk"));
	
	return (0);
}