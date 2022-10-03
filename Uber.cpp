#pragma warning(disable: 4996)
#include <iostream>
#include <fstream>
#include "payment.h"
#include "driver.h"
#include "Dob.h"
#include "passenger.h"
#include "trip.h"
using namespace std;

const int SIZE = 20;
//an array of trips to keep pointers of all the trips of uber application
//This array will keep data of all the trips ever created. 
trip** uberTrips = new trip * [SIZE];
user** userarray = new user * [20];
int n = 0, c = 0;

void addToUberTrips(trip* t)// function to add new trips to uberTrips
{
	if (n < SIZE - 1 && t != nullptr)
	{
		uberTrips[n++] = t;
	}
}
void read(const char* a)
{
	ifstream fin;
	fin.open(a);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			char junk = NULL;
			char a[2] = { NULL };
			fin.getline(a, 2, ',');
			if (a[0] == 'p')
			{
				char name[50] = { NULL };
				int d = 0, m = 0, y = 0;
				char email[100] = { NULL };
				char phonenmber[100] = { NULL };
				char type[20] = { NULL };
				fin.getline(name, 100, ',');
				fin >> d >> junk >> m >> junk >> y >> junk;
				fin.getline(email, 100, ',');
				fin.getline(phonenmber, 100, ',');
				fin.getline(type, 100, ',');
				if (strcmp(type, "card") == 0)
				{
					char num[100] = { NULL };
					fin.getline(num, 100,'\n');
					userarray[c++] = new passenger(name, dob(d, m, y), email, phonenmber, payment(num, type));
				}
				else
				{
					char num[100] = { NULL };
					fin.getline(num, 100, '\n');
					userarray[c++] = new passenger(name, dob(d, m, y), email, phonenmber, payment(type));
				}
			}
			else if (a[0] == 'd')
			{
				char name[50] = { NULL };
				int d = 0, m = 0, y = 0;
				char email[100] = { NULL };
				char phonenmber[100] = { NULL };
				char vhnm[100] = { NULL };
				char lcnm[100] = { NULL };
				fin.getline(name, 100, ',');
				fin >> d >> junk >> m >> junk >> y >> junk;
				fin.getline(email, 100, ',');
				fin.getline(phonenmber, 100, ',');
				fin.getline(lcnm, 100, ',');
				fin.getline(vhnm, 100);
				userarray[c++] = new driver(name, dob(d, m, y), email, phonenmber, lcnm, vhnm);
			}
		}
	}
	else
	{
		cout << " File not Found " << endl;
	}
}
void print()
{
	for (int i = 0; i < c; i++)
	{
		cout << endl;
		userarray[i]->print();
		cout << endl;
	}
}
user* highlyrateddriver()
{
	int g = 0;
	int* ind = new int[c];
	for (int i = 0; i < c; i++)
	{
		driver* a = nullptr;
		a = dynamic_cast<driver*>(userarray[i]);
		if (a != nullptr)
		{
			ind[g] = i;
			g++;
		}
	}
	int index = 0;
	float* arr = new float[c];
	float max = 0.0;
	max = userarray[ind[0]]->getAvgRating();
	arr[0] = max;
	for (int i = 1; i < g; i++)
	{
		arr[i] = userarray[ind[i]]->getAvgRating();
	}
	for (int i = 0; i < g; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	for (int i = 0; i < g; i++)
	{
		if (arr[i] == max)
		{
			index = i;
			break;
		}
	}
	index = ind[index];
	delete[]arr;
	delete[]ind;
	return userarray[index];
}
user* highlyratedPassenger()
{
	int g = 0;
	int* ind = new int[c];
	for (int i = 0; i < c; i++)
	{
		passenger* a = nullptr;
		a = dynamic_cast<passenger*>(userarray[i]);
		if (a != nullptr)
		{
			ind[g] = i;
			g++;
		}
	}
	int index = 0;
	float* arr = new float[c];
	float max = 0.0;
	max = userarray[ind[0]]->getAvgRating();
	arr[0] = max;
	for (int i = 1; i < g; i++)
	{
		arr[i] = userarray[ind[i]]-> getAvgRating();
	}
	for (int i = 0; i < g; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	for (int i = 0; i < g; i++)
	{
		if (arr[i] == max)
		{
			index = i;
			break;
		}
	}
	index = ind[index];
	delete[]arr;
	delete[]ind;
	return userarray[index];
}
user* highlyrateduser()
{
	int ind = 0;
	float* arr = new float[c];
	float max = 0.0;
	max = userarray[0]->getAvgRating();
	for (int i = 1; i < c; i++)
	{
		arr[i] = userarray[i]->getAvgRating();
	}
	for (int i = 0; i < c; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	for (int i = 0; i < c; i++)
	{
		if (arr[i] == max)
		{
			ind = i;
			break;
		}
	}
	delete[]arr;
	return userarray[ind];
}
void printUberTrips() //function to print uberTrips
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << *uberTrips[i] << endl;
	}
}
void main()
{

	passenger* p1 = new passenger("P1", dob(10, 10, 1990), "ali@yahoo.com", "0334564334", payment("111-222-333-333", "card"));
	driver* d1 = new driver("D1", dob(16, 1, 1990), "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917");

	//////Test Case 1, user books, driver picks, driver ends (rating can be given only in this case)
	cout << *p1 << endl;
	cout << *d1 << endl;

	addToUberTrips(p1->bookride("A", "B"));// will create a new trip and add it to uberTrips array
	//cout << *uberTrips[n - 1];// will print this trip
	addToUberTrips(p1->bookride("C", "D"));//prints error as p1 has already booked a ride
	d1->pickaRide(uberTrips[n - 1]); //will assign  d1 to uberTrip[0], the status of this ride will also change to InProgress
	d1->ratePassenger(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete

	cout << *p1 << endl;
	cout << *d1 << endl;

	d1->endRide(); //will change the status of uberTrip[0] to Complete

	d1->ratePassenger(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete
	//cout << *uberTrips[n - 1] << endl;
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->pickaRide(uberTrips[n - 1]);//prints error as the ride is completed
	cout << "-------------------------------------" << endl;

	//////Test case 2: User books, driver picks, user cancels, ratings are not applicable to cancelled ride
	addToUberTrips(p1->bookride("C", "D"));
	d1->pickaRide(uberTrips[n - 1]);
	cout << *p1 << endl;
	cout << *d1 << endl;
	p1->cancelRide();
	p1->cancelRide();//error as there is no current ride
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->ratePassenger(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl;

	////Test Case 3: User Books, user Cancels, driver cannot pick this ride now, ratings are not applicable to this ride
	addToUberTrips(p1->bookride("D", "E"));
	p1->cancelRide();
	d1->pickaRide(uberTrips[n - 1]); //error as this ride is not looking for driver
	d1->ratePassenger(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl;

	////Test Case 4: getting avg ratings adn print trip funnction
	//Adding some more test data
	addToUberTrips(p1->bookride("X", "Y"));
	d1->pickaRide(uberTrips[n - 1]);
	d1->endRide();
	d1->ratePassenger(uberTrips[n - 1], 3);
	p1->rateDriver(uberTrips[n - 1], 5);

	addToUberTrips(p1->bookride("X", "Y"));
	d1->pickaRide(uberTrips[n - 1]);
	d1->endRide();
	d1->ratePassenger(uberTrips[n - 1], 6);//error as the rating is not between 1 and 5 
	d1->ratePassenger(uberTrips[n - 1], 4);
	d1->ratePassenger(uberTrips[n - 1], 3);// will upate the passanging rating from 4 to 3
	p1->rateDriver(uberTrips[n - 1], 1);

	p1->printTrips();
	d1->printTrips();
	cout << p1->getAvgRating() << endl;
	cout << d1->getAvgRating() << endl;

	read("input.txt");
	print();



	system("PAUSE");

}