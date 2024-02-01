#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h";
#include "clsScreen.h";

using namespace std;

class clsWithDrawScreen : protected clsScreen 
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

    static void ShowWithDrawScreen()
    {

        system("cls");
        _DrawScreenHeader("\t     WithDraw Screen");

        cout << "Please Enter Account Number?  ";
        string acc = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(acc))
        {
            cout << "\nClient with Account Number [" << acc << "] Does not Exist\n";
            cout << "\nPlease enter another account number?  ";
            acc = clsInputValidate::ReadString();
        }

        system("cls");
        _DrawScreenHeader("\t     WithDraw Screen");
        clsBankClient client = clsBankClient::Find(acc);

        _PrintClient(client);

        double amount = 0;
        cout << "\nPlease enter WithDraw Amount?  ";
        amount = clsInputValidate::ReadDblNumber();

        char choice = 'n';
        cout << "\nAre you sure you want to perform this transaction?  Y/N?  ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {

            if (client.WithDraw(amount))
            {
                cout << "\nAmount WithDrawed Successfully.\n";
                cout << "\nNew Balance is: " << client.Balance << endl;
            }

            else
            {
                cout << "\nCannot WithDraw, Insuffecient Balance!\n";
                cout << "\nAmout to WithDraw is: " << amount;
                cout << "\nYour Balance is: " << client.Balance << endl;
            }

        }

        else
            cout << "\nOperation was Cancelled.\n";

    }


};