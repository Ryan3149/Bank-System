#pragma once

#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsInputValidate.h";
#include "clsScreen.h";


using namespace std;



class clsUpdateUserScreen : protected clsScreen
{

private:


    static void _ReadUserInfo(clsUser& User)
    {

        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.Lastname = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.PhoneNumber = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();

    }


    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.Lastname;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.PhoneNumber;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }


    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access?  Y/N?  ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give Access to?  \n";

        cout << "\nShow CLients list?  Y/N?  ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClients;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClients;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nShow Login Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListLoginRegisters;
        }

        cout << "\nCurrency Exchange?  y/n?  ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pCurrencyExchange;
        }


        return Permissions;

    }


public:

    static void ShowUpdateUserScreen()
    {

        _DrawScreenHeader("\t  Update User Screen");


        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        char choice = 'n';
        cout << "\nAre you sure you want to update this user? Y/N?  ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {        

            cout << "\n\nUpdate User Info:\n\n";
            cout << "\n____________________________\n\n";

            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResults;

            SaveResults = User1.Save();

            switch (SaveResults)
            {
            case clsUser::svFailedEmptyObject:

                cout << "\nError User was not saved because it's Empty\n\n";            
                break;

            case clsUser::svSucceeded:
                
                cout << "\nUser Updated Successfully.\n\n";
                _PrintUser(User1);
                break;

            case clsUser::svFailedUserExists:
                
                cout << "\nError USer Already Exists\n\n";
                break;

            }

        }




    }


};