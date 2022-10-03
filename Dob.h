#ifndef dob_H
#define dob_H
#include<iostream>
using namespace std;
class dob
{
private:
	int day;
	int month;
	int year;
public:
	dob();
	friend ostream& operator<<(ostream& cout, const dob& a);
	dob(int, int, int);
	void setday(int);
	int getday()const;
	void setmonth(int);
	int getmonth()const;
	void setyear(int);
	int getyear()const;
};
#endif