#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h";
#include "clsScreen.h";

using namespace std;

class clsDepositScreen : protected clsScreen
{

private:


    static void _PrintClient(clsBankClient Client)
    {

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.Lastname;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.PhoneNumber;
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.Balance;
        cout << "\n___________________\n";

    }

    	
public:

	static void ShowDepositScreen()
	{

        system("cls");
        _DrawScreenHeader("\t     Deposit Screen");

        cout << "Please Enter Account Number?  ";
        string acc = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(acc))
        {
            cout << "\nClient with Account Number [" << acc << "] Does not Exist\n";
            cout << "\nPlease enter another account number?  ";
            acc = clsInputValidate::ReadString();
        }

        system("cls");
        _DrawScreenHeader("\t     Deposit Screen");
        clsBankClient client = clsBankClient::Find(acc);

        _PrintClient(client);

        double amount = 0;
        cout << "\nPlease enter Deposit Amount?  ";
        amount = clsInputValidate::ReadDblNumber();

        char choice = 'n';
        cout << "\nAre you sure you want to perform this transaction?  Y/N?  ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {
            client.Deposit(amount);

            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance is: " << client.Balance << endl;

        }

        else
            cout << "\nOperaion was cancelled.\n";

	}


};