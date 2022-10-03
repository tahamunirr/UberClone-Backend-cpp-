#include"User.h"
#include"payment.h"
#ifndef PASEENGER_H
#define PASEENGER_H
class passenger :public user
{
private:
	payment* pay;
	int payno;
public:

	void addpayment(payment&);
	void print();
	void printTrips();
	void pickaRide(trip*) { cout << "Passenger can,t pick ride\n"; }
	void endRide(){ cout << "Passenger can,t end ride\n"; }
	trip* bookride(const char*, const char*);
	void cancelRide();
	void rateDriver(trip*,int);
	void setmessage(const char* a);
	float getAvgRating();
	passenger(const char*, dob, const char*, const char*, payment);
	passenger();
	~passenger();
	void readmessage();
	void sendmessage(const char*);
	friend ostream& operator<<(ostream&, const passenger&);
};
#endif