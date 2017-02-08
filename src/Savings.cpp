
#include "../include/Savings.h"

Savings::Savings() : Account(0){
	transactions = 0;
	rate = 0;
}
Savings::Savings(double dep) : Account(dep) {
	transactions = 0;
	rate = 0;
}
void Savings::deposit(double d){
	Account::deposit(d);
	transactions++;
}
void Savings::withdrawal(double d){
	Account::withdrawal(d);
	transactions++;
}
void Savings::add_interest(){
	double interest = rate * Account::get_balance();
	Account::deposit(interest);
}
void Savings::set_rate(double r){
	rate = r;
}
void Savings::zero_transactions(){
	transactions = 0;
}

