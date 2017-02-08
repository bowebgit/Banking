
#include "../include/Checking.h"

Checking::Checking() : Account(0){
	transactions = 0;
}
Checking::Checking(double dep) : Account(dep){
	transactions = 0;
}
void Checking::deposit(double d){
	if(transactions > 3){
		deduct_fees();
	}
	Account::deposit(d);
	transactions++;
}
void Checking::withdrawal(double d){
	if(transactions > 3){
		Account::withdrawal(d + FEE);
	}else{
		Account::withdrawal(d);
	}

	transactions++;
}
void Checking::deduct_fees(){

	Account::withdrawal(FEE);

}
void Checking::zero_transactions(){
	transactions = 0;
}


