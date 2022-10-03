#include"dob.h"
#include<iostream>
using namespace std;
class trip;
#ifndef PERSON_H
#define PERSON_H
class user
{
protected:
	char* name;
	dob DOB;
	char* email;
	char* phonenumber;
	trip** trips;
	trip* currenttrip;
	int noftrips;
	char* message;
public:
	user();
	~user();
	virtual float getAvgRating() = 0;
	virtual void print();
	void setname(const char*);
	void setemail(const char*);
	void setphonenumber(const char*);
	void setmessage(const char* a);
	void printdob() const;
	char* getname() const { return name; }
	char* getmessage() { return message; }
	virtual void readmessage() = 0;
	virtual void sendmessage(const char*) = 0;
	virtual void pickaRide(trip*) = 0;
	virtual void endRide() = 0;
	virtual trip* bookride(const char*, const char*) = 0;
	virtual void cancelRide() = 0;
	user(const char*, dob, const char*, const char*);
	friend ostream& operator<<(ostream&, const user&);
};
#endif