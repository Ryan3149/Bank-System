#pragma once


#include <iostream>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsUser.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;


class clsCurrencyExchangeScreen : protected clsScreen
{

private:


	enum enCurrencyExchangeMenuOption
	{
		enListCurrencies = 1, enFindCurrencies = 2, enUpdateRate = 3,
		enCurrencyCalculator = 4, enMainMenu = 5
	};

	
	static short _ReadExchangeCurrencyMenuOption()
	{
		short choice = 0;
		cout << endl << setw(37) << left << "" << "Choose What do you want to do [1 to 5]?  ";
		choice = clsInputValidate::ReadShortNumberBetween(1, 5);

		return choice;

	}


	static void _ShowListCurrenciesScreen()
	{
		clsListCurrenciesScreen::ShowListCurrenciesSCreen();
	}


	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}


	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}


	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}


	static void _GoBackToExchangeCurrencyMenu()
	{
		cout << "\n\t Press any key to go back to Exchange Currencies Screen...";
		system("pause>0");
		ShowCurrencyExcangeMenu();
	}


	static void _PerformExchangeMenuOption(enCurrencyExchangeMenuOption option)
	{

		switch (option)
		{


		case clsCurrencyExchangeScreen::enListCurrencies:

			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToExchangeCurrencyMenu();
			break;

		case clsCurrencyExchangeScreen::enFindCurrencies:

			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToExchangeCurrencyMenu();
			break;

		case clsCurrencyExchangeScreen::enUpdateRate:

			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToExchangeCurrencyMenu();
			break;

		case clsCurrencyExchangeScreen::enCurrencyCalculator:

			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToExchangeCurrencyMenu();
			break;

		case clsCurrencyExchangeScreen::enMainMenu:

			//Nothin it will go back automatically.
			break;

		}


	}



public:


	static void ShowCurrencyExcangeMenu()
	{

		system("cls");

		if (!CheckAccessRights(clsUser::pCurrencyExchange))
		{
			return;
		}

		_DrawScreenHeader("   Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		_PerformExchangeMenuOption(enCurrencyExchangeMenuOption(_ReadExchangeCurrencyMenuOption()));

	}





};