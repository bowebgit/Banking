
#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class Account{

public:
	Account();
	Account(double dep);
	virtual void deposit(double amt);
	virtual void withdrawal(double amt);
	double get_balance() const;

private:
	double balance;

};

#endif /* ACCOUNT_H_ */
