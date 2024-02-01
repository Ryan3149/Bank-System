#pragma once


#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h";
#include "clsScreen.h";

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{

private:


    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.Lastname = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.PhoneNumber = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.Balance = clsInputValidate::ReadDblNumber();
    }


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

    static void ShowAddNewClientScreen()
    {

        system("cls");

        if (!CheckAccessRights(clsUser::pAddNewClient))
        {
            return;
        }


        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSave SaveResult;

        SaveResult = NewClient.Save();


        switch (SaveResult)
        {

            case  clsBankClient::enSave::svSucceeded:
            {
                cout << "\nAccount Addeded Successfully :-)\n";
                _PrintClient(NewClient);
                break;
            }
            case clsBankClient::enSave::svFailedEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }
            case clsBankClient::enSave::svFailedAccountNumberExists:
            {
                cout << "\nError account was not saved because account number is used!\n";
                break;

            }

        }

    }




};