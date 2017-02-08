
#include "../include/Bank.h"
#include "../include/Account.h"
#include "../include/Savings.h"
#include "../include/Checking.h"


Bank::Bank(){
	//
}

Customer* Bank::get_customer(int acct_number) {
	Customer* c = NULL;
	for(unsigned i = 0; i < cus.size(); i++){
		if(cus[i].get_acct_number() == acct_number){
			c = &cus[i];
			break;
		}
	}
	return c;
}
void Bank::add_customer(Customer c){
	cus.push_back(c);
}
void Bank::deposit(double amt, Account& a){
	a.deposit(amt);
}
void Bank::withdrawal(double amt, Account& a){
	a.withdrawal(amt);
}
double Bank::check_balance( Account& a){
	return a.get_balance();
}
void Bank::end_month(){
	for(unsigned i = 0; i < cus.size(); i++){
		Savings* s = cus[i].get_savings();
		s->add_interest();
		s->zero_transactions();
		Checking* c = cus[i].get_checking();
		c->zero_transactions();
		//cus[i].get_savings().zero_transactions();
		//cus[i].get_checking().zero_transactions();
	}
}
vector<Customer> Bank::cus;

