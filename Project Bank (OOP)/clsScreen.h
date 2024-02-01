#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include "clsDate.h"
#include "Global.h"

using namespace std;


class clsScreen
{

protected:


    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\t\t\t\t\tUser:  " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate:  " << clsDate::DateToString(clsDate()) << endl << endl;
        

    }


    static bool CheckAccessRights(clsUser::enPermissions CurrentScreenPermission)
    {

        if (!CurrentUser.CheckAccessPermission(CurrentScreenPermission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }

        else
            return true;

    }



};