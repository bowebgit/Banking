/*
 * Bank.h
 *
 *  Created on: Aug 22, 2016
 *      Author: Jesse
 */

#ifndef BANK_H_
#define BANK_H_


#include "../include/Customer.h"
#include <string>
#include <vector>
using namespace std;

class Bank{

public:
	Bank();
	Customer* get_customer(int acct_number);
	void add_customer(Customer c);
	void deposit(double amt,  Account& a);
	void withdrawal(double amt,  Account& a);
	double check_balance( Account& a);
	void end_month();
private:
	static vector<Customer> cus;
};



#endif /* BANK_H_ */
