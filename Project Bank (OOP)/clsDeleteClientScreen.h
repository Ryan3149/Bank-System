#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
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


    static void ShowDeleteClientScreen()
    {

        system("cls");

        if (!CheckAccessRights(clsUser::pDeleteClients))
        {
            return;
        }


        _DrawScreenHeader("\t  Delete Client Screen");

        cout << "Please Enter Account Number?  ";
        string acc = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(acc))
        {
            cout << "Account Number not found!\n\n";
            cout << "Please enter another Account number?  ";
            acc = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(acc);

        _PrintClient(client);

        char choice = 'n';

        cout << "\nAre you sure you want to Delete this client?  Y/N?  ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {

            if (client.Delete())
            {

                cout << "\nClient Deleted Successfully :-)\n";

            }

            else
                cout << "\nError Client wasn't Deleted\n";

        }

    }


};