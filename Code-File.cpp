#include <iostream>
#include <windows.h>          //For changing colors
#include <fstream>            //For saving User Data.
using namespace std;

struct DATA
{
  int accountNumber = 1122;     //Here , i personally formed Account# & Pin# for my Account.
  int pinNumber = 2211;
};

  int balance = 0;              //Initial balance is 0.

bool login ()                 //This function make sure that USER entered id & pass is same to the Account# & Pin#
{
	struct DATA OP;
	int *ptr=&OP.accountNumber;
	int *ptrr=&OP.pinNumber;
	int givenAccountNumber = -1;
	int givenPinNumber = -1;
	bool isAccountInvalid = true;
	bool isPinInvalid = true;
	
	         cout<<"\t\t\t\t   ***********************************"<<endl;
             cout<<"\t\t\t\t   *           WELCOME !             *"<<endl;
             cout<<"\t\t\t\t   ***********************************"<<endl;
	
	while (isAccountInvalid) 
	{
		
		cout << "\nPlease enter your account number: ";
		cin >> givenAccountNumber;
		
		if (givenAccountNumber == *ptr) 
		{
			isAccountInvalid = false;
		} 
		
		else 
		{
			cout << "Invalid account number! Try again." << endl;
		}
		
		ofstream my_file;                 //Every Account# data is stored in external file.
	    my_file.open("Account#OfUSERS.txt");
	   
	   for(int i=1;i<=10;i++)
	   {
	   	my_file<<"Account# of User"<<i<<" is : "<<givenAccountNumber<<endl;
	   	break;
	   }
	   my_file.close();
	}

	while (isPinInvalid) 
	{
		
		cout << "Enter your PIN: ";
		cin >> givenPinNumber;
		
		if (givenPinNumber == *ptrr) 
		{
			isPinInvalid = false;
		} 
		else 
		{
			cout << "Invalid PIN number! Try again." << endl;
		}
    
	ofstream my_file; 
	   my_file.open("Pin#OfUSERS.txt");             //Every Pin# data is stored in external file.
	   for(int i=1;i<=10;i++)
	   {
	   my_file<<"Pin# of User"<<i<<" is : "<<givenPinNumber<<endl;
	   break;
       }
       my_file.close();
	}

	return true;
		
}

int getUserOption ()     //Main menu interface for USER.
{

	int selectedOption = -1;

	cout << "\nMain menu:" << endl;
	cout << "	1 - View my balance" << endl;
	cout << "	2 - Withdraw cash" << endl;
	cout << "	3 - Deposit funds" << endl;
	cout << "	4 - Exit" << endl;
	cout << "Enter a choice: " << endl;
	cin >> selectedOption;
	
	return selectedOption;
	
}

void viewBalance () 
{

	cout << "\nYou have:" << endl;
	cout << "$" << balance << endl;

}

void withdrawCash()        //Function for Withdrawal of Money.
{
	
	int selectedOption = -1;
	int valueToWithdraw = 0;
	bool isNotFinished = true;

	do 
	{
		
		cout << "\nWithdrawal options:" << endl;
		cout << "1 - $20" << endl;
		cout << "2 - $40" << endl;
		cout << "3 - $60" << endl;
		cout << "4 - $100" << endl;
		cout << "5 - $200" << endl;
		cout << "6 - cancel transaction" << endl;
		cout << "choose a withdrawal option (1-6)" << endl;

		cin >> selectedOption;
		switch (selectedOption) 
		{
			case 1:
				valueToWithdraw = 20;
				break;
			case 2:
				valueToWithdraw = 40;
				break;
			case 3:
				valueToWithdraw = 60;
				break;
			case 4:
				valueToWithdraw = 100;
				break;
			case 5:
				valueToWithdraw = 200;
				break;
			case 6:
				isNotFinished = false;
				break;
			default:
				cout << "\nInvalid option! Try again." << endl;
				break;
		} 
		
		if (valueToWithdraw != 0) 
		{
			if (valueToWithdraw > balance) 
			{
				cout << "You just have $" << balance << ". You can't withdraw $" << valueToWithdraw << endl;
			} 
			else 
			{
				balance = balance - valueToWithdraw;
				isNotFinished = false;
			}
			valueToWithdraw = 0;
		}

	} while (isNotFinished);	

}

void depositFunds()   ////Function for Depositing Money.
{

	int selectedOption = -1;	
	bool isNotFinished = true;

	do 
	{
		
		cout << "\nDeposit options:" << endl;
		cout << "1 - $20" << endl;
		cout << "2 - $40" << endl;	
		cout << "3 - $60" << endl;
		cout << "4 - $100" << endl;
		cout << "5 - $200" << endl;
		cout << "6 - cancel transaction" << endl;
		cout << "Choose a deposit option (1-6)" << endl;

		cin >> selectedOption;
		switch (selectedOption) 
		{
			case 1:
				balance = balance + 20;
				isNotFinished = false;
				break;
			case 2:
				balance = balance + 40;
				isNotFinished = false;
				break;
			case 3:
				balance = balance + 60;
				isNotFinished = false;
				break;
			case 4:
				balance = balance + 100;
				isNotFinished = false;
				break;
			case 5:
				balance = balance + 200;
				isNotFinished = false;	
				break;
			case 6:
				isNotFinished = false;
				break;
			default:
				cout << "\nInvalid option! Try again." << endl;
				break;
		} 
		
	} while (isNotFinished);

}

int main ()    //Main Body.
{
	system("Color A4");  //Specifing which color will use
	if (login()) 
	{
		
		int isNotFinished = true;

		do 
		{
			
			switch (getUserOption()) 
			{
				case 1:
					viewBalance();
					break;
				case 2:
					withdrawCash();
					break;
				case 3:
					depositFunds();
					break;
				case 4:
					cout<<"\n\nTHANK YOU FOR WITHDRAWAL : STAY HAPPY :-)";
					isNotFinished = false;
					break;
				default:
					cout << "\nInvalid option! Try again." << endl;
					break;
			}

		} while (isNotFinished);

	}

	return 0;

}
