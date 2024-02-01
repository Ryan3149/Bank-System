#pragma once


#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClient.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"


using namespace std;


class clsMainScreen : protected clsScreen
{


private:
    

    enum enMainMenuOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9 ,eExit = 10
    };


    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "\n\t\t\t\t      Choose what do you want to do?  [1 to 10]? ";
        short choice = clsInputValidate::ReadShortNumberBetween(1, 10, "\t\t\t\t\t\nEnter a Number from [1] to [10]? ");
        return choice;
    }

    
    static void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "\n\n\tPress any key to continue...\n";

        system("pause>0");
        ShowMainMenu();
    }


    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }


    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }


    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }


    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }


    static void _ShowFindClientScreen()
    {
        clsFindClient::ShowFindClientScrren();
    }


    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenu();
    }


    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersScreen();
    }


    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::voidShowLoginRegisterList();
    }


    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExcangeMenu();
    }


    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");        
    }


    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {


        switch (MainMenuOption)
        {

        case clsMainScreen::eListClients:

            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;

        case clsMainScreen::eAddNewClient:

            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;

        case clsMainScreen::eDeleteClient:

            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;

        case clsMainScreen::eUpdateClient:

            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;

        case clsMainScreen::eFindClient:

            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;

        case clsMainScreen::eShowTransactionsMenue:

            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenu();
            break;

        case clsMainScreen::eManageUsers:

            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenu();
            break;

        case clsMainScreen::eLoginRegister:

            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenu();
            break;

        case clsMainScreen::eCurrencyExchange:

            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenu();
            break;

        case clsMainScreen::eExit:

            system("cls");
            _Logout();       
            break;


        }


    }
    


public:

	static void ShowMainMenu()
	{

		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption(enMainMenuOptions(_ReadMainMenuOption()));

	}



};