#define _CRT_SECURE_NO_WARNINGS
#include"Dob.h"
#include"driver.h"
#include"passenger.h"
#ifndef TRIP_H
#define TRIP_H
class trip
{
private:
	int status;
	char *pickup;
	char *dropoff;
	int drating;
	int prating;
	driver dr;
	passenger p;

public:
	void chanegestatus(int);
	int getstatus() { return status; }
	int getstatus()const;
	void setpassenger(passenger a) { p = a; }
	void setdriver(driver a) { dr = a; }
	driver* getdriver() { return &dr; }
	void setprating(int a) { prating = a; }
	int getprating()const { return prating; }
	void setdrating(int a) { drating = a; }
	int getdrating()const { return drating; }
	passenger getpassenger() { return p; }
	trip(int);
	trip(const char* a, const char* b);
	trip();
	trip(const trip&);
	friend ostream& operator<<(ostream& cout, const trip& t);
	void operator&=(const trip& t);
	~trip();
};
#endif