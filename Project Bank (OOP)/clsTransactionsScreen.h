#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsShowTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLog.h"

using namespace std;


class clsTransactionsScreen : protected clsScreen
{

private:

	enum enTransactionsMenuOptions
	{
		enDeposit = 1, enWithdraw = 2, enShowTotalBalances = 3, 
		enTransfer = 4, enTransferLog = 5,enShowMainMenu = 6
	};


	static short ReadTransactionsMenuOption()
	{

		short choice = 0;
		cout << endl << setw(37) << left << "" << "Choose What do you want to do [1 to 6]?  ";
		choice = clsInputValidate::ReadShortNumberBetween(1, 6);

		return choice;

	}


	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}


	static void _ShowWithdrawScreen()
	{
		clsWithDrawScreen::ShowWithDrawScreen();
	}


	static void _ShowTotalBalancesScreen()
	{
		clsShowTotalBalancesScreen::ShowTotalBalancesCreen();
	}


	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}
	

	static void _ShowTransferLog()
	{
		clsTransferLog::ShowTransferLogScreen();
	}


	static void _GoBackToTransactionsMenu()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenu();

	}
		

	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
	{

		switch (TransactionsMenuOption)
		{

		case clsTransactionsScreen::enDeposit:

			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;

		case clsTransactionsScreen::enWithdraw:

			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;

		case clsTransactionsScreen::enShowTotalBalances:

			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;

		case clsTransactionsScreen::enTransfer:

			_ShowTransferScreen();
			_GoBackToTransactionsMenu();
			break;

		case clsTransactionsScreen::enTransferLog:

			_ShowTransferLog();
			_GoBackToTransactionsMenu();
			break;

		case clsTransactionsScreen::enShowMainMenu:

			//Do Nothing it will normally take you back to main main menu screen..
			break;
					
		}

	}


public:


	static void ShowTransactionsMenu()
	{

		system("cls");
	
		if (!CheckAccessRights(clsUser::pTransactions))
		{
			return;
		}

		
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfe Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenuOption(enTransactionsMenuOptions(ReadTransactionsMenuOption()));

	}



};