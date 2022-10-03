#ifndef PAYMENT_H
#define PAYMENT_H
class payment
{
private:
	char* type;
	char* cardno;
public:
	payment();
	~payment();
	void setcardno(const char*);
	char* getcardno()const;
	payment(const char*, const  char*);
	payment(const char*);
	void copy(const payment&);
	char* gettype()const;
};
#endif