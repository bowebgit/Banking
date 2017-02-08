/*
 * Driver.cpp
 *
 */

#include <iostream>
#include <iostream>
#include "include/Customer.h"
#include "include/Checking.h"
#include "include/Savings.h"
#include "include/Bank.h"
#include <iomanip>

using namespace std;

int gen_value = 5234;

int teller();
int gen_acct_number();
int create_customer();
int process_customer();
int administrator();

int main(){
	cout << "******************************************\n";
	cout << "*      Banking Application Demo          *\n";
	cout << "******************************************\n";
	cout << "\n";
	teller();
	return 0;
}

int teller(){
	bool cont = true;

	while(cont){
		cout << "******************************************\n";
		cout << "Select From The Following List." << endl;
		cout << "1. Create Customer Account" << endl;
		cout << "2. Process Customer Transaction" << endl;
		cout << "3. Administrator Actions" << endl;
		cout << "4. End Program" << endl;
		cout << "*******************************************\n";


		int choice = 0;
		cout << "> ";
		cin >> choice;
		cout << endl;

		switch(choice){
		case 1:
			create_customer();
			break;
		case 2:
			process_customer();
			break;
		case 3:
			administrator();
			break;
		default:
			cout << "~End Program~";
			cont = false;
			break;
		}
	}
	return 0;
}

int gen_acct_number(){
	gen_value++;
	return gen_value;
}

int create_customer(){
	cout << "** Create New Customer **\n";
	cout << "Customer Name: ";
	string n = "";
	cin >> n;
	Customer* d = new Customer(n, gen_acct_number());
	Customer c(*d);
	// get opening balances
	double open_ck = 0;
	double open_sv = 0;
	cout << "Opening Balance For Checking: ";
	cin >> open_ck;

	cout << "Opening Balance For Savings: ";
	cin >> open_sv;
	cout << "Savings Interest Rate. Default is .0029. Enter a rate: ";
	cout << "\n";
	double r = 0.0;
	cin >> r;
	if(!(r > 0 && r < 1)){
		r = .0029;
	}


	// create and set accounts
	Checking* ck;
	ck = new Checking(open_ck);
	Savings* sv;
	sv = new Savings(open_sv);
	sv->set_rate(r);
	c.set_checking(*ck);
	c.set_savings(*sv);

	// add customer to bank
	Bank b;
	b.add_customer(c);
	cout << "New Customer: " << c.get_name() << endl;
	cout << "Account Number: " << c.get_acct_number() << endl;
	cout << "\n";
	return 0;

}

int process_customer(){
	cout << "** Process Transaction **\n";
	cout << "Account Number: ";
	int acctNum = 0;
	cin >> acctNum;
	cout << "\n";

	// get customer
	Bank b;
	//Customer& c = b.get_customer(acctNum);

	Customer* d = b.get_customer(acctNum);
	if(d == NULL){
		cout << "Error: Customer Not Found.\n";
		return 0;
	}
	Customer& c = (*d);


	bool flag = true;
	while(flag){
		cout << c.get_name() << " #" << c.get_acct_number() << ": ";

		cout << "Select a transaction.\n";
		cout << "1. Withdrawal\n";
		cout << "2. Deposit\n";
		cout << "3. Check Balance\n";
		cout << "4. Finish Customer\n";
		cout << "> ";
		int choice = 0;
		cin >> choice;
		cout << "\n";

		double amt = 0;
		int which = 0;
		switch(choice){
		case 1:{
			cout << "Withdrawal From: \n";
			cout << "1. Checking \n2. Savings \n";
			cout << "> ";
			cin >> which;
			cout << "\n";
			cout << "Amount: ";
			cin >> amt;
			cout << "\n";

			if(which == 1){
				cout << "Old Balance: $" << fixed << setprecision(2) << c.get_checking()->get_balance() << endl;
				Account* acct = c.get_checking();
				b.withdrawal(amt, *acct);
				cout << "New Balance: $" << fixed << setprecision(2) << c.get_checking()->get_balance() << endl;
				cout << "\n";
			}else if (which == 2){
				cout << "Old Balance: $" << fixed << setprecision(2) << c.get_savings()->get_balance() << endl;
				Account* acct = c.get_savings();
				b.withdrawal(amt, *acct);
				cout << "New Balance: $" << fixed << setprecision(2) << c.get_savings()->get_balance() << endl;
				cout << "\n";
			}else{
				break;
			}
			break;
		}
		case 2:{
			cout << "Deposit Into: \n";
			cout << "1. Checking \n2. Savings \n";
			cout << "> ";
			cin >> which;
			cout << "\n";

			cout << "Amount: ";
			cin >> amt;
			cout << "\n";
			if(which == 1){
				cout << "Old Balance: $" << fixed << setprecision(2) << c.get_checking()->get_balance() << endl;
				Account* acct = c.get_checking();
				b.deposit(amt, *acct);
				cout << "New Balance: $" << fixed << setprecision(2) << c.get_checking()->get_balance() << endl;
				cout << "\n";

			}else if (which == 2){
				cout << "Old Balance: $" << fixed << setprecision(2) << c.get_savings()->get_balance() << endl;
				Account* acct = c.get_savings();
				b.deposit(amt, *acct);
				cout << "New Balance: $" << fixed << setprecision(2) << c.get_savings()->get_balance() << endl;
				cout << "\n";
			}else{
				break;
			}
			break;
		}
		case 3:{
			cout << "Checking $" << fixed << setprecision(2) << c.get_checking()->get_balance() << endl;
			cout << "Savings  $" << fixed << setprecision(2) << c.get_savings()->get_balance() << endl;
			cout << "\n";
			break;
		}
		default:{
			flag = false;
			break;
		}
		}
	}

	return 0;
}

int administrator(){
	cout << "Select Administrator Action: \n";
	cout << "1. End month and apply fees \n";
	cout << "2. Cancel \n";
	int choice = 0;
	cout << "> ";
	cin >> choice;
	cout << "\n";
	switch(choice){
	case 1:{
		Bank b;
		b.end_month();
		break;
	}
	case 2:{
		break;
	}
	default:{
		break;
	}
	}
	return 0;
}



