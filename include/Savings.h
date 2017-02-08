
#ifndef SAVINGS_H_
#define SAVINGS_H_

#include "Account.h"

class Savings : public Account{
private:
	double rate;
	int transactions;

public:
	Savings();
	Savings(double dep);
	virtual void deposit(double amt);
	virtual void withdrawal(double amt);
	void add_interest();
	void set_rate(double rate);
	void zero_transactions();

};

#endif /* SAVINGS_H_ */
