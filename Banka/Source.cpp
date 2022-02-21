#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
struct CreateAccount {
	int account_number = 0;
	int balance = 0;
	char name[20] = "";
	char address[30] = "";
	char dob[20] = "";
	char account_type[10] = "";

	void deposit(int amount) {
		balance += amount;
		cout << amount << " deposited successfully!\n";
	}
	void withdraw(int amount) {
		if (amount <= balance && balance != 0) {
			balance -= amount;
			cout << amount << " withdrawn successfully!\n";
		}
		else {
			cout << "There is not enough balance to withdraw.\n";
		}

	}

	void readinfo() {
		cout << "Account details: \n" << "Account Number : " << account_number << "\n";
		cout << "Name : " << name << "\n";
		cout << "Adress : " << address << "\n";
		cout << "Date of Birth : " << dob << "\n";
		cout << "Account Type : " << account_type << "\n";
	}
};

int searchAccount(int acc_num_, CreateAccount* accounts) {
	for (int i = 0; i < 20; i++) {
		if (acc_num_ == accounts[i].account_number) {
			return i;
		}
	}
	return -1;
}

int main() {
	struct CreateAccount accounts[20];
	int acc_count = 0;

	while (1) {
		int command;
		cout << "\n";
		cout << "Enter <0> to tarminate the program.\nEnter <1> to creating new account.\nEnter <2> to search an account.\nEnter <3> to print all account names.\nEnter <4> to deposit in a account.\nEnter <5> to withdraw from a account.\nEnter <6> to remove an account.\n";
		cin >> command;
		cout << "==================\n";
		if (command == 0) {
			return 0;
		}
		else if (command == 1) {
			cout << "Name of the account owner : ";
			cin >> accounts[acc_count].name;
			cout << "Address of the account owner : ";
			cin >> accounts[acc_count].address;
			cout << "Date of Birth of the account owner : ";
			cin >> accounts[acc_count].dob;
			cout << "Account type : ";
			cin >> accounts[acc_count].account_type;
			cout << "Account number : ";
			cin >> accounts[acc_count].account_number;
			cout << "\nAccount created successfully!\n\n";

			accounts[acc_count].readinfo();
			acc_count++;
		}
		else if (command == 2) {
			int search_key;
			cout << "Please, enter the account ID : ";
			cin >> search_key;


			if (searchAccount(search_key, accounts) == -1) {
				cout << "Account Not Found!\n";
			}
			else {
				accounts[searchAccount(search_key, accounts)].readinfo();
			}
		}
		else if (command == 3) {
			cout << "\n";
			if (acc_count == 0) {
				cout << "There is no account in the database.\n";
			}
			for (int i = 0; i < 20; i++) {
				if (accounts[i].account_number != 0) {
					cout << accounts[i].name << "(" << accounts[i].account_number << ")" << " : " << accounts[i].balance << "\n";
				}
			}
			cout << "\n";
		}
		else if (command == 4) {
			int temp_id;
			int temp_depo;
			cout << "Enter the account number : ";
			cin >> temp_id;
			if (searchAccount(temp_id, accounts) == -1) {
				cout << "\nAccount Not Found!\n\n";
			}
			else {
				cout << "Enter deposit amount : ";
				cin >> temp_depo;
				accounts[searchAccount(temp_id, accounts)].deposit(temp_depo);
				cout << "\nCurrent balance is : " << accounts[searchAccount(temp_id, accounts)].balance << "\n";
			}
		}
		else if (command == 5) {
			int temp_id;
			int temp_wd;
			cout << "Enter the account number : ";
			cin >> temp_id;
			if (searchAccount(temp_id, accounts) == -1) {
				cout << "\nAccount Not Found!\n\n";
			}
			else {
				cout << "Enter withdraw amount : ";
				cin >> temp_wd;
				accounts[searchAccount(temp_id, accounts)].withdraw(temp_wd);
				cout << "\nCurrent balance is : " << accounts[searchAccount(temp_id, accounts)].balance << "\n";
			}
		}
		else if (command == 6) {
			int temp_id;
			int search_key;
			cout << "Enter the account number : ";
			cin >> search_key;


			if (searchAccount(search_key, accounts) == -1) {
				cout << "Account Not Found!\n";

			}
			else {
				temp_id = searchAccount(search_key, accounts);
				for (int i = temp_id; i < acc_count - 1; i++) {
					accounts[i].account_number = accounts[i + 1].account_number;
					accounts[i].balance = accounts[i + 1].balance;
					strcpy_s(accounts[i].name, accounts[i + 1].name);
					strcpy_s(accounts[i].address, accounts[i + 1].address);
					strcpy_s(accounts[i].dob, accounts[i + 1].dob);
					strcpy_s(accounts[i].account_type, accounts[i + 1].account_type);
				}
				accounts[acc_count - 1].account_number = 0;
				acc_count--;

				cout << "\nAccount removed successfully!\n";
			}



		}
		else {
			cout << "\nYou entered a wrong command!. Try again.\n";
		}
	}
}