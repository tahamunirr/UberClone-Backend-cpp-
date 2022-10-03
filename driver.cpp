#define _CRT_SECURE_NO_WARNINGS
#include"driver.h"
#include"trip.h"

driver::driver()
{
	DLN = nullptr;
	VN = nullptr;
}

driver::~driver()
{
	/*if(DLN!=nullptr)
		delete[]DLN;
	if (VN != nullptr)
		delete[]VN;*/
}

void driver::print()
{
	user::print();
	cout << DLN << endl;
	cout << VN << endl;
	if (currenttrip->getstatus() == -2)
		cout << "Currently not driving." << endl;
	else if (currenttrip->getstatus() == 0)
		cout << "Currently not driving." << endl;
	else if (currenttrip->getstatus() == 2)
		cout << "Currently driving." << endl;
	else if (currenttrip->getstatus() == 3)
		cout << "Drive complete." << endl;
}

void driver::pickaRide(trip* p)
{
	if (p->getstatus() == 1)
	{
		p->setdriver(*this);
		p->chanegestatus(2);
		currenttrip = p;
		noftrips++;
	}
	else
		cout << "This ride is not looking for a driver\n";
}

void driver::endRide()
{
	currenttrip->chanegestatus(3);
	//trips[noftrips - 1]->chanegestatus(3);
}

void driver::printTrips()
{
	for (int i = 0; i < noftrips; i++)
	{
		cout << *trips[i] << endl;
	}
}

void driver::addtrip(trip* a)
{
	//if(a->getstatus()==0|| a->getstatus() == -1)
	noftrips++;
	trips[noftrips - 1] = new trip();
	*trips[noftrips - 1] = *a;
}

void driver::ratePassenger(trip* t, int a)
{
	if (t->getstatus() == 3)
	{
		if (a > 0 && a <= 5)
		{
			t->setprating(a);
			
		}
		else
			cout << "Rating can only be between 1-5\n";
	}
	else
		cout << "Trip not completed\n";
}

void driver::setmessage(const char*a)
{
	int x = strlen(a);
	message = new char[x + 1];
	strcpy(name, a);
}


float driver::getAvgRating()
{
	float a = 0.0;
	float b = 0.0;
	for (int i = 0; i < noftrips; i++)
	{
		a += this->trips[i]->getdrating();
		if (this->trips[i]->getstatus() == 3)
			b++;
	}
	return a/b;
}

void driver::readmessage()
{
	cout << "Message From Passenger: " << message << endl;
}

void driver::sendmessage(const char*a)
{
	currenttrip->getpassenger().setmessage(a);
}

driver::driver(const char* n1, dob d1, const char* n2, const char* n3, const char* n4, const char* n5) :user(n1, d1, n2, n3)
{
	int x = strlen(n4);
	DLN = new char[x + 1];
	strcpy(DLN, n4);
	int y = strlen(n5);
	VN = new char[y + 1];
	strcpy(VN, n5);
	currenttrip = new trip(-2);
}
ostream& operator<<(ostream& cout, const driver& d9)
{
	cout << static_cast<const user&>(d9);
	cout << d9.DLN << endl;
	cout << d9.VN << endl;
	if (d9.currenttrip->getstatus() == -2)
		cout << "Currently not driving." << endl;
	else if(d9.currenttrip->getstatus() == 0)
		cout << "Currently not driving." << endl;
	else if (d9.currenttrip->getstatus() == 2)
		cout << "Currently driving." << endl;
	else if (d9.currenttrip->getstatus() == 3)
		cout << "Drive complete." << endl;
	return cout;
}
