#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h";
#include "clsScreen.h";

using namespace std;

class clsFindClient : protected clsScreen
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

    static void ShowFindClientScrren()
    {
        system("cls");

        if (!CheckAccessRights(clsUser::pFindClients))
        {
            return;
        }


        _DrawScreenHeader("\t  Find Client Screen");

        cout << "Please Enter Account Number?  ";
        string acc = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(acc))
        {
            cout << "Account Number not found!\n\n";
            cout << "Please enter another Account number?  ";
            acc = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(acc);

        if (!client.IsEmpty())
        {
            _PrintClient(client);
        }

        else
            cout << "\nClient wasn't Found! \n";

    }

};