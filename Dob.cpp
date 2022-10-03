#include"Dob.h"
#include<ctime>
#pragma warning( disable : 4996)

void dob::setday(int a)
{
	day = a;
}
void dob::setmonth(int a)
{
	month = a;
}
void dob::setyear(int a)
{
	year = a;
}
int dob::getday()const
{
	return day;
}
int dob::getmonth()const
{
	return month;
}
int dob::getyear()const
{
	return year;
}
dob::dob(int a, int b, int c)
{
	day=a;
	month=b;
	year=c;
}
dob::dob()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	year= 1900 + ltm->tm_year;
	month = 1 + ltm->tm_mon; 
	day = ltm->tm_mday; 
}

ostream& operator<<(ostream& cout, const dob& a)
{
	cout << a.day << "/" << a.month << "/" << a.year << "\n";
	return cout;
}
