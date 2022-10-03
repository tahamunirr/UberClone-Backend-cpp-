#define _CRT_SECURE_NO_WARNINGS
#include"payment.h"
#include<iostream>
using namespace std;
payment::payment()
{
	type = nullptr;
	cardno = nullptr;
}
payment::~payment()
{
	/*if (type != nullptr)
		delete[]type;
	if (cardno != nullptr)
		delete[]cardno;*/
}
void payment::setcardno(const char* a)
{
	int x = strlen(a);
	cardno = new char[x + 1];
	strcpy(cardno, a);
}
char* payment::getcardno()const
{
	return cardno;
}
payment::payment(const char* card, const char* name)
{
	setcardno(card);
	int y = strlen(name);
	type = new char[y + 1];
	strcpy(type, name);
}
payment::payment(const char* a)
{
	int y = strlen(a);
	type = new char[y + 1];
	strcpy(type, a);
	cardno = nullptr;
}
void payment::copy(const payment& p)
{
	int x = strlen(p.type);
	type = new char[x + 1];
	strcpy(type, p.type);
	if (p.cardno != nullptr)
		setcardno(p.cardno);
	else
		cardno = nullptr;
}
char* payment::gettype()const
{
	return type;
}
