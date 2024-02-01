#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;


class clsUpdateClientScreen : protected clsScreen
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



public:

    static void ShowUpdateClientScreen()
    {


        if (!CheckAccessRights(clsUser::pUpdateClients))
        {
            return;
        }


        _DrawScreenHeader("Update Client Screen");

        cout << "\nPlease Enter Account Number?  ";
        string acc = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(acc))
        {
            cout << "\nAccount Number Not found!\n";
            cout << "\nPlease enter Another Account Number?  ";
            acc = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(acc);

        _PrintClient(client);
        
        char choice = 'n';
        cout << "Are you sure you want to update this client?  Y/N?  ";
        cin >> choice;



        if (toupper(choice) == 'Y')
        {

            system("cls");
            _DrawScreenHeader("Update Client Info");

            _ReadClientInfo(client);

            clsBankClient::enSave SaveResults;

            SaveResults = client.Save();

            switch (SaveResults)
            {

            case clsBankClient::svFailedEmptyObject:

                cout << "Error Account wasn't saved\n";
                break;

            case clsBankClient::svSucceeded:

                cout << "Account updated Successfully :-) \n";
                break;

            case clsBankClient::svFailedAccountNumberExists:

                cout << "Error Account wasn't saved\n";
                break;

            }

        }




    }

};