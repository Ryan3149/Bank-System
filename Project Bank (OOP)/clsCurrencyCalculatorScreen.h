#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{

private:


	static void _PrintCurrencyRecord(clsCurrency c)
	{

		cout << "\n_____________________________________________________\n";

		cout << "\nCountry       : " << c.getCountry();
		cout << "\nCode          : " << c.getCurrencyCode();
		cout << "\nCountry Name  : " << c.getCurrencyName();
		cout << "\nRate(1$) =    : " << c.getRate();

		cout << "\n_____________________________________________________\n";

	}


	static clsCurrency _GetCurrency(string message)
	{

		string code1 = "";
		cout << endl << endl << message;
		code1 = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(code1))
		{
			cout << "\nCurrency wasn't found, Please enter another Currency?  ";
			code1 = clsInputValidate::ReadString();
		}

		clsCurrency curr1 = clsCurrency::FindByCode(code1);
		return curr1;

	}




public:


	static void ShowCurrencyCalculatorScreen()
	{

		char choice = 'n';

		do
		{

			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");


			clsCurrency curr1 = _GetCurrency("Please enter Currency 1 Code: ");
			clsCurrency curr2 = _GetCurrency("Please enter Currency 2 Code: ");

			double amount = 0;
			cout << "\n\nEnter amount of Exchange:  ";
			amount = clsInputValidate::ReadDblNumber();


			cout << "\n\nConvert From:";
			_PrintCurrencyRecord(curr1);

			cout << amount << " " << curr1.getCurrencyCode() << " = " << curr1.ConvertToUSD(amount) << " USD\n";

			if (curr2.getCurrencyCode() != "USD")
			{
				cout << "\n\n Converting from USD To: ";
				_PrintCurrencyRecord(curr2);

				cout << amount << " " << curr1.getCurrencyCode() << " = " << curr1.ConvertToOtherCurrency(amount, curr2) << " " << curr2.getCurrencyCode() << endl;
			}


			cout << "\n\nDo you want to perform another Calculation?  y/n?  ";
			cin >> choice;


		} while (toupper(choice) == 'Y');

	}

};