#include<iostream.h>
#include<fstream.h>
#include<conio.h>
int no_of_accounts = 0, i = 0, flag;
int ch;
int entered_pin;
int entered_account_number;
class BankAccount {
public:
    char name[50];
    char aadhar_number[4];
    char address[25];
    int age;
    char gender[10];
    char dob[10];
    char account_type[20];
    int pin;
    int account_number;
    float amount;
    void create_account();
    void setaccount_number (){
    account_number = 1000;
    }
    void create_new_account_number(){
    account_number++;
    }
    void set_amount(){
    amount = 0;
    }
};

void BankAccount::create_account() {
    cout << "**************\n";
    cout << "            Create New Account        \n";
    cout << "**************\n";
    cout << "Enter account holder name: ";
    cin >> name;
    cout << "Enter your Aadhar card number [last 4 digits]: ";
    cin >> aadhar_number;
    cout << "Enter your address: ";
    cin >> address;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your gender: ";
    cin >> gender;
    cout << "Enter your date of birth (DD/MM/YY): ";
    cin >> dob;
    cout << "Enter your account type: ";
    cin >> account_type;
    cout << "Create a PIN: ";
    cin >> pin;
    create_new_account_number();
    cout << "Your account number is " << account_number << endl;
    cout << "Account created........\n";
    no_of_accounts++;
    set_amount();
    ofstream accountFile("detail.txt", ios::app);

    if (accountFile) {
	accountFile << "Account Number: " << account_number << "\n";
	accountFile << "Account holder name: " << name << "\n";
	accountFile << "Aadhar Number: " << aadhar_number << "\n";
	accountFile << "Address: " << address << "\n";
	accountFile << "Gender: " << gender << "\n";
	accountFile << "DOB: " << dob << "\n";
	accountFile << "Account type: " << account_type << "\n";
	accountFile << "Balance: " << amount << "\n";
	accountFile << "----------------------------\n";

	accountFile.close();
    }
    else {
	cout << "Error: Unable to open the file for writing.\n";
    }
}

class Transaction : virtual public BankAccount {
public:
    int check_details() {
	cout<<"Enter account number: ";
	cin>>entered_account_number;
	cout << "Enter your pin here: ";
	cin >> entered_pin;
	if (entered_pin != pin || entered_account_number != account_number) {
	    cout << "Invalid account number OR Wrong pin\n";
	    return -1;
	}
	else {
	    return amount;
	}
    }

    void user_menu() {
	do {
	    cout << "**************\n";
	    cout << "               User Menu              \n";
	    cout << "**************\n";
	    cout << "1. Check Balance\n";
	    cout << "2. Deposit\n";
	    cout << "3. Withdraw\n";
	    cout << "4. Exit\n";
	    cout << "Enter your choice: ";
	    cin >> ch;

	    switch (ch) {
	    case 1:
		check_balance();
		break;
	    case 2:
		deposit();
		break;
	    case 3:
		withdraw();
		break;
	    case 4:
		cout << "Exiting user menu.\n";
		break;
	    default:
		cout << "Invalid choice\n";
	    }
	} while (ch != 4);
    }

    void deposit();
    void withdraw();
    void check_balance();
    void user_login();
};
void Transaction::deposit() {
    float damount;
    flag = 0;
    flag = check_details();
    if (flag != -1) {
	cout << "Enter amount to deposit: ";
	cin >> damount;
	amount += damount;
	cout << "Deposited: " << damount << "\n";
    }
}
void Transaction::withdraw() {
    float withdraw_amount;
    flag = 0;
    flag = check_details();
    if (flag != -1) {
	cout << "Enter the amount you want to withdraw: ";
	cin >> withdraw_amount;
	if (withdraw_amount > 0 && withdraw_amount <= amount) {
	    amount -= withdraw_amount;
	    cout << "Withdraw successfully\n";
	}
	else {
	    cout << "Invalid withdrawal amount or insufficient balance!\n";
	}
    }
}

void Transaction::check_balance() {
    amount = check_details();
    cout << "Your balance is: " << amount << endl;
}
void Transaction::user_login() {
	cout<<"Enter account number: ";
	cin>>entered_account_number;
	cout << "Enter your pin here: ";
	cin >> entered_pin;
    if (entered_pin == pin || entered_account_number == account_number) {
	cout << "Account Number: " << account_number << "\n";
	cout << "Account holder name: " << name << "\n";
	cout << "Aadhar Number: " << aadhar_number << "\n";
	cout << "Address: " << address << "\n";
	cout << "Gender: " << gender << "\n";
	cout << "DOB: " << dob << "\n";
	cout << "Account type: " << account_type << "\n";
	cout << "Balance: " << amount << "\n";
	cout << "----------------------------------\n";
    }
    else {
	cout << "Wrong PIN\n";
    }
}
class Manager : virtual public Transaction {
public:
    Transaction t[5];
    int password;

    void checkpassword() {
	int entered_password;
	password = 1234;
	cout << "Enter the password: ";
	cin >> entered_password;
	if (password != entered_password) {
	    cout << "Wrong password\n";
	}
	else {
	    ifstream accountFile("detail.txt");
	    char line [256];
	    if (accountFile) {
		while (accountFile.getline(line,sizeof(line))) {
		    cout << line << endl;
		}
		accountFile.close();
	    }
	    else {
		cout << "Error: Unable to open the file for reading.\n";
	    }
	}
    }
};
class Customer : virtual public BankAccount, virtual public Transaction {
public:
    Customer() {
	int key;
	cout << "*************\n";

	cout << "Welcome to Our Bank Management System\n";
	cout << "*************\n";
	cout << "\n   Press any key to continue.......\n";
	cin.ignore();
    }
};
int main() {
    clrscr();
    Customer c,*cptr;
    cptr = &c;
    Manager manager,*mptr;
    mptr = &manager;
    cptr->setaccount_number();

    do {
	cout << "*************\n";
	cout << "            Main Menu                \n";
	cout << "*************\n";
	cout << "1. Create Account\n";
	cout << "2. Show my Account\n";
	cout << "3. Manager login\n";
	cout << "4. User Menu\n";
	cout << "5. Exit\n";
	cout << "Enter your choice: ";
	cin >> ch;

	switch (ch) {
	case 1:
	    cptr->create_account();
	    break;
	case 2:
	    cptr->user_login();
	    break;
	case 3:
	    mptr->checkpassword();
	    break;
	case 4:
	    cptr->user_menu();
	    break;
	case 5:
	    cout << "Exiting the system.\n";
	    break;
	default:
	    cout << "Invalid choice\n";
	}
    } while (ch != 5);
    return 0;
}

