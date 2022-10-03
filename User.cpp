#define _CRT_SECURE_NO_WARNINGS
#include"User.h"
#include"trip.h"
user::user()
{
	trips = new trip * [20];
	currenttrip = nullptr;
	name = nullptr;
	noftrips = 0;
	email = nullptr;
	phonenumber = nullptr;
}
user::~user()
{
	/*if (name != nullptr)
		delete[]name;
	if (email != nullptr)
		delete[]email;
	if (phonenumber != nullptr)
		delete[]phonenumber;
	for (int i = 0; i < noftrips; i++)
		delete trips[i];
	delete []trips;
	if (currenttrip != nullptr)
		delete currenttrip;*/
}
void user::print()
{
	cout << name << endl;
	cout << DOB.getday() << "/" << DOB.getmonth() << "/" << DOB.getyear() << endl;
	cout << email << endl;
	cout << phonenumber << endl;
	cout << "Total Trips: " << noftrips << endl;
}
void user::setname(const char* name1)
{
	int x = strlen(name1);
	name = new char[x + 1];
	strcpy(name, name1);
}
void user::setemail(const char* name2)
{
	int x = strlen(name2);
	email = new char[x + 1];
	strcpy(email, name2);
}
void user::setphonenumber(const char* name3)
{
	int x = strlen(name3);
	phonenumber = new char[x + 1];
	strcpy(phonenumber, name3);
}
void user::setmessage(const char* a)
{
}
void user::printdob() const
{
	cout << DOB.getday() << "/" << DOB.getmonth() << "/" << DOB.getyear() << endl;
}
user::user(const char* n1, dob d, const char* n2, const char* n3)
{
	trips = new trip * [20];
	setname(n1);
	DOB = d;
	setemail(n2);
	setphonenumber(n3);
}
ostream& operator<<(ostream& cout, const user& p9)
{
	cout << p9.name << endl;
	cout << p9.DOB.getday() << "/" << p9.DOB.getmonth() << "/" << p9.DOB.getyear() << endl;
	cout << p9.email << endl;
	cout << p9.phonenumber << endl;
	cout << "Total Trips: " << p9.noftrips << endl;
	return cout;
}