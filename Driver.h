#include"User.h"
#ifndef DRIVER_H
#define DRIVER_H
class driver :public user
{
private:
	char* DLN;
	char* VN;
public:
	driver();
	~driver();
	void print();
	trip* bookride(const char*, const char*) { cout << "Driver can't book ride\n"; return nullptr; }
	void cancelRide() { cout << "Driver can't cancel ride\n"; }
	void pickaRide(trip*);
	void endRide();
	void printTrips();
	void addtrip(trip*a);
	void ratePassenger(trip*, int);
	void setmessage(const char*);
	float getAvgRating();
	void readmessage();
	void sendmessage(const char*);
	driver(const char*, dob, const char*, const char*, const char*, const char*);
	friend ostream& operator<<(ostream&, const driver&);
};
#endif 
