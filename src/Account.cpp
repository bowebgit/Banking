

#include "../include/Account.h"

Account::Account(){
	balance = 0;
}
Account::Account(double dep){
	balance = dep;
}

void Account::deposit(double d){
	balance += d;
}
void Account::withdrawal(double d){
	if(balance - d > 0){
		balance -= d;
	}
}
double Account::get_balance() const{
	return balance;
}



