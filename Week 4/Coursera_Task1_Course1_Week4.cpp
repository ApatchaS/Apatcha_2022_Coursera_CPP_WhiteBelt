#include <iostream>

using namespace std;

struct Specialization
{
	string value;

	explicit Specialization(const string& new_value)
	{
		value = new_value;
	}
};

struct Course
{
	string value;

	explicit Course(const string& new_value)
	{
		value = new_value;
	}
};

struct Week
{
	string value;

	explicit Week(const string& new_value)
	{
		value = new_value;
	}
};

struct LectureTitle
{
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization new_specialization, Course new_cource, Week new_week)
  {
	  specialization = new_specialization.value;
	  course = new_cource.value;
	  week = new_week.value;
  }
};

int main(void)
{
	LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
	);

	cout << title.specialization << endl << title.course << endl << title.week << endl;
	
	return (0);
}