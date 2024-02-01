#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{

private:


	static void _PrintCurrencyRecord(clsCurrency c)
	{

		cout << "\nCurrency Card:";
		cout << "\n_____________________________________________________\n";

		cout << "\nCountry       : " << c.getCountry();
		cout << "\nCode          : " << c.getCurrencyCode();
		cout << "\nCountry Name  : " << c.getCurrencyName();
		cout << "\nRate(1$) =    : " << c.getRate();

		cout << "\n_____________________________________________________\n";

	}


	static short _ReadChoice()
	{

		short choice;
		cout << "\n\nFind by [1] Code or [2] Country  ?  ";
		choice = clsInputValidate::ReadShortNumberBetween(1, 2);

		return choice;

	}


	enum enChoice
	{
		code = 1, country = 2
	};


	static void _FindByCode()
	{

		string code = "";
		cout << "\n\nPlease enter Currency Code:  ";
		code = clsInputValidate::ReadString();

		clsCurrency curr = clsCurrency::FindByCode(code);
		
		if (!curr.IsEmpty())
		{
			cout << "\n\nCurrency Found :-)  \n\n";
			_PrintCurrencyRecord(curr);
		}

		else
		{
			cout << "\n\nCurrency Not Found :-(  \n\n";
		}


	}


	static void _FindByCountry()
	{

		string country = "";
		cout << "\n\nPlease enter currency Country Name:  ";
		country = clsInputValidate::ReadString();

		clsCurrency curr = clsCurrency::FindByCountry(country);

		if (!curr.IsEmpty())
		{
			cout << "\n\nCurrency Found :-)  \n\n";
			_PrintCurrencyRecord(curr);
		}

		else
		{
			cout << "\n\nCurrency Not Found :-(  \n\n";
		}


	}



public:


	static void ShowFindCurrencyScreen()
	{

		system("cls");
		_DrawScreenHeader("\t  Find Currency Screen");

		enChoice choice = enChoice(_ReadChoice());
		switch (choice)
		{

			case clsFindCurrencyScreen::code:
				_FindByCode();
				break;
			
			case clsFindCurrencyScreen::country:				
				_FindByCountry();
				break;

		}

	}

};