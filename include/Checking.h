
#ifndef CHECKING_H_
#define CHECKING_H_

#include "Account.h"

class Checking : public Account{

private:
	int transactions;
	static const double FEE = 1.50;

public:
	Checking();
	Checking(double dep);
	virtual void deposit(double amt);
	virtual void withdrawal(double amt);
	void deduct_fees();
	void zero_transactions();

};

#endif /* CHECKING_H_ */
