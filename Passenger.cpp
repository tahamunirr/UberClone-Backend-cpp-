#pragma warning(disable: 4996)
#include"passenger.h"
#include"trip.h"
#define _CRT_SECURE_NO_WARNINGS

void passenger::addpayment(payment& p)
{
	if (payno < 3)
	{
		pay[payno].copy(p);
		payno++;
	}
	else
		cout << "Payment method limit has been reached.So no more method can be added." << endl;
}
void passenger::print()
{
	user::print();
	for (int i = 0; i < payno; i++)
	{
		if (pay[i].getcardno() != nullptr)
			cout << pay[i].getcardno() << ", ";
		cout << pay[i].gettype() << endl;
	}
	if (currenttrip->getstatus() == -2)
		cout << "Currently not riding" << endl;
	else if (currenttrip->getstatus() == 0)
		cout << "Currently not riding" << endl;
	else if (currenttrip->getstatus() == 1)
		cout << "Look4Driver" << endl;
	else if (currenttrip->getstatus() == 2)
		cout << "Currently Riding" << endl;
	else if (currenttrip->getstatus() == 3)
		cout << "Ride Completed" << endl;
}
void passenger::printTrips()
{
	for (int i = 0; i < noftrips; i++)
	{
		cout << *trips[i] << endl;
	}
}
trip* passenger::bookride(const char*a, const char*b)
{
	if (currenttrip->getstatus() == 1)
		cout << "Cannot Book two rides at once\n";
	else
	{
		trip* z = new trip(a, b);
		z->setpassenger(*this);
		currenttrip = z;
		noftrips++;
		return z;
	}
}

void passenger::cancelRide()
{
	if (currenttrip == nullptr)
		cout << "No trip to cancel\n";
	else if (currenttrip->getstatus() == 0)
		cout << "Can't cancel\n";
	else 
		if (currenttrip->getstatus() == 1)
		{
			currenttrip->chanegestatus(0);
			trips[noftrips - 1] = new trip();
			*trips[noftrips - 1] = *currenttrip;
		}
		else if (currenttrip->getstatus() == 2)
		{
			currenttrip->chanegestatus(-1);
			trips[noftrips - 1] = new trip();
			*trips[noftrips - 1] = *currenttrip;
			currenttrip->getdriver()->addtrip(currenttrip);
		}
}


void passenger::rateDriver(trip*t, int a)
{
	
	if (t->getstatus() == 3)
	{
		t->setdrating(a);
		trips[noftrips - 1] = new trip();
		*trips[noftrips - 1] = *currenttrip;
		currenttrip->getdriver()->addtrip(currenttrip);

	}
	else
		cout << "Trip not completed\n";
}

void passenger::setmessage(const char* a)
{
	int x = strlen(a);
	message = new char[x + 1];
	strcpy(name, a);
}

float passenger::getAvgRating()
{
	float a = 0.0, b = 0.0;
	for (int i = 0; i < noftrips; i++)
	{
		a+= this->trips[i]->getprating();
		if (this->trips[i]->getstatus() == 3)
			b++;
	}
	return a/b;
}

passenger::passenger(const char* n1, dob d2, const char* n2, const char* n3, payment p) :user(n1, d2, n2, n3)
{
	pay = new payment[3];
	payno = 0;
	addpayment(p);
	currenttrip = new trip (-2);
}
passenger::passenger()
{
	payno = 0;
	pay = nullptr;
}
passenger::~passenger()
{
	/*if (pay != nullptr)
		delete pay;*/
}
void passenger::readmessage()
{
	cout << "Message From Passenger: " << message << endl;
}
void passenger::sendmessage(const char*a)
{
	currenttrip->getdriver()->setmessage(a);
}
ostream& operator << (ostream& cout, const passenger& p)
{
	cout << static_cast<const user&>(p);
	for (int i = 0; i < p.payno; i++)
	{
		if (p.pay[i].getcardno() != nullptr)
			cout << p.pay[i].getcardno() << ", ";
		cout << p.pay[i].gettype() << endl;
	}
	if(p.currenttrip->getstatus() == -2)
		cout << "Currently not riding" << endl;
	else if (p.currenttrip->getstatus() == 0)
		cout << "Currently not riding" << endl;
	else if (p.currenttrip->getstatus() == 1)
		cout << "Look4Driver" << endl;
	else if (p.currenttrip->getstatus() == 2)
		cout << "Currently Riding" << endl;
	else if (p.currenttrip->getstatus() == 3)
		cout << "Ride Completed" << endl;
	return cout;
}