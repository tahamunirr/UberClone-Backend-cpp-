#include"trip.h"
void trip::chanegestatus(int r)
{
	status = r;
}
int trip::getstatus()const
{
	return status;
}
trip::trip(int u)
{
	status=u;
}

trip::trip(const char* a, const char* b)
{
	status = 1;
	int x = strlen(a);
	pickup = new char[x + 1];
	strcpy(pickup, a);
	x = strlen(b);
	dropoff = new char[x + 1];
	strcpy(dropoff, b);
	drating = 0;
	prating = 0;
}

trip::trip()
{
	status = -5;
	pickup = nullptr;
	dropoff = nullptr;
	drating = 0;
	prating = 0;
}

trip::~trip()
{
	/*if (pickup != nullptr)
		delete[]pickup;
	if (dropoff != nullptr)
		delete[]dropoff;*/
}

trip::trip(const trip& t)
{
	status = t.status;
	int x = strlen(t.pickup);
	pickup = new char[x + 1];
	strcpy(pickup, t.pickup);
	
	x = strlen(t.dropoff);
	dropoff = new char[x + 1];
	strcpy(pickup, t.dropoff);
	drating = t.drating;
	prating = t.prating;
}

void trip::operator&=(const trip& t)
{
	status = t.status;
	if (pickup != nullptr)
		delete[]pickup;
	int x = strlen(t.pickup);
	pickup = new char[x + 1];
	strcpy(pickup, t.pickup);
	if (dropoff != nullptr)
		delete[]dropoff;
	x = strlen(t.dropoff);
	dropoff = new char[x + 1];
	strcpy(pickup, t.dropoff);
	drating = t.drating;
	prating = t.prating;
	
}

ostream& operator<<(ostream& cout, const trip& t)
{
	if (t.status == 0||t.status==-1)
		cout << "Cancelled" << endl;
	if (t.status == 1)
		cout << "Looking4Driver" << endl;
	if (t.status == 3)
		cout << "Ride Completed" << endl;
	if (t.status == 2)
		cout << "Currently Riding" << endl;
	t.p.printdob();
	cout << t.pickup << endl << t.dropoff << endl;
	cout << t.p.getname() << endl;
	if (t.status == 3 || t.status == 2|| t.status == -1)
	{
		cout << t.dr.getname() << endl;
	}
	if (t.status == 3)
	{
		cout << "Passenger's Rating: " << t.getprating() << endl;
		cout << "Driver's Rating: " << t.getdrating() << endl;
	}

	return cout;
}
