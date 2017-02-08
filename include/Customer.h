// to define a new class, first declare it's public interface.

#ifndef CUSTOMER_H_ 	//directive to ignore multiple imports
#define CUSTOMER_H_

using namespace std;
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include <string>
#include <iostream>

class Customer{

public:
	Customer(string n, int acct_number);
	void set_name(string n);
	void set_savings(Savings s);
	void set_checking(Checking c);

	void print() const;
	string get_name() const;
	Savings* get_savings();
	Checking* get_checking();
	int get_acct_number() const;

private:
	string name;
	int acct_number;
	Savings savings;
	Checking checking;
};

#endif
