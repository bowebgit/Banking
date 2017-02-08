#include "../include/Customer.h"
#include "../include/Checking.h"
#include "../include/Account.h"
#include "../include/Savings.h"


Customer::Customer(string n, int acct_number){
	name = n;
	this->acct_number = acct_number;

}

void Customer::set_name(string n) {
	name = n;
}

void Customer::set_checking(Checking c){
	checking = c;
}

void Customer::set_savings(Savings s){
	savings = s;
}

void Customer::print() const {
	cout << name << ": #" << acct_number;
}
string Customer::get_name() const{
	return name;
}
Savings* Customer::get_savings(){
	return &savings;
}
Checking* Customer::get_checking(){
	return &checking;
}
int Customer::get_acct_number()const{
	return acct_number;
}




