#include <iostream>
#include<fstream>
#include<string>

using namespace std;

void signIn();
void signUp();
void forgotPassword();

int main() {
	
	int select;
	
	cout << "\tPlease Login To Continue" << endl;
	cout << "[1] Sign in\n[2] Sign up\nChoose:";
	cin >> select;
	
	switch (select) {
		case 1:
			signIn();
			break;
		case 2:
			signUp();
			break;
		
		default:
			cout << "Wrong choice selected";
	}
	
	return 0;
}

void signIn() {
	
	int exist = 0;
	string userName, password, USN, PASS;
	
	cout << "Username or email: ";
	cin >> userName;
	cout << "Password: ";
	cin >> password;
	
	ifstream read("accounts.txt");
	
	while (read >> USN >> PASS) {
		if (USN == userName && PASS == password) {
			exist = 1;
			break;
		}
	}
	read.close();
	
	if (exist == 1) {
		cout << "Login successful.";
	} else if (exist == 0){
		cout << "\nLogin error!";
		forgotPassword();
	}
	
}
void signUp() {

	int exist = 0;
	string userName, password, USN, PASS;
	
	system("cls");
	
	cout << "\tCreate Account";
	cout << "\nE-mail: ";
	cin >> userName;
	ofstream write("accounts.txt", ios::app); // accounts file created which of append type
	ifstream read("accounts.txt");
	
	while (read >> USN >> PASS) {
		if (USN == userName) {
			exist = 1;
			break;
		}
	}
	
	if (exist == 1) {
		cout << "This email already taken!";
	} else {
		cout << "Password: ";
		cin >> password;
		
		write << userName << "\t" << password << endl;
		cout << "Account created.";
	}
	write.close();
}

void forgotPassword() {
	
	int search;
	
	system("cls");
	
	cout << "Login Error!\n";
	cout << "\nPlease enter your email address." << endl;
	cout << "[1] Username/Email \n[2] Back to Login\nChoose:";
	cin >> search;
	
	switch (search) {
		case 1:
			{
				int exist = 0;
				string userName, USN, PASS;
				
				cout << "Enter username/email: ";
				cin >> userName;
				
				ifstream read("accounts.txt");
				
				while (read >> USN >> PASS) {
					if (userName == USN) {
						exist = 1;
						break;
					}
				}
				read.close();
				
				if (exist == 1) {
					cout << "Account found!";
					cout << "\nYour Password: " << PASS;
				} else {
					cout << "Account not found!" << endl;
				}
				break;
			}
		case 2:
			{
				cout << endl;
				main();
				break;
			}
		default:
			cout << "Wrong choice selected. Press a key to try again!";
			forgotPassword();
	}
}
