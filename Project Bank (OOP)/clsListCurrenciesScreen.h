#pragma once


#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;


class clsListCurrenciesScreen : protected clsScreen
{


private:

	static void PrintCurrencyRecord(clsCurrency curr)
	{

		cout << setw(8) << left << "" << "| " << setw(40) << left << curr.getCountry();
		cout << "| " << setw(10) << left << curr.getCurrencyCode();
		cout << "| " << setw(50) << left << curr.getCurrencyName();
		cout << "| " << setw(15) << left << curr.getRate();

	}



public:


	static void ShowListCurrenciesSCreen()
	{

		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string title = "\t  Currencies List Screen";
		string subtitle = "\t  (" + to_string(vCurrencies.size()) + ") Currency.";

		system("cls");
		_DrawScreenHeader(title, subtitle);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(40) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(50) << "Currency Name";
		cout << "| " << left << setw(15) << "Rate/(1$)";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________________________________\n" << endl;

		for (clsCurrency c : vCurrencies)
		{
			PrintCurrencyRecord(c);
			cout << endl;
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________________________________\n" << endl;


	}

};