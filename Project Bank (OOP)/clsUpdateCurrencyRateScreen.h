#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
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


public:


	static void ShowUpdateCurrencyRateScreen()
	{

		system("cls");
		_DrawScreenHeader("\t  Update Currency Screen");

		
		string code = "";
		cout << "\n\nPlease enter Currency Code:  ";
		code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(code))
		{
			cout << "\nCurrency wasn't found, Please enter another currency:  ";
			code = clsInputValidate::ReadString();
		}
		
		clsCurrency curr = clsCurrency::FindByCode(code);
		_PrintCurrencyRecord(curr);


		char choice = 'n';
		cout << "\nAre you sure you want to update the rate of this Currency?  y/n?  ";
		cin >> choice;

		if (toupper(choice) == 'Y')
		{
			cout << "\n\nUpdate Currency Rate:";
			cout << "\n__________________________________";

			double Newrate = 0;
			cout << "\n\nPlease enter New Rate:  ";
			Newrate = clsInputValidate::ReadDblNumber();

			curr.UpdateRate(Newrate);

			cout << "\n\nCurrency Rate Updated Successfully.  :-)\n\n";

			_PrintCurrencyRecord(curr);

		}

	}

};