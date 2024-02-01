#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsUtil.h"

using namespace std;

class clsShowTotalBalancesScreen : protected clsScreen
{

private:

    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Balance;
    }


public:

	static void ShowTotalBalancesCreen()
	{

        system("cls");

        vector <clsBankClient> vclients = clsBankClient::GetClientsList();
        string Title = "\t  Balances List Screen";
        string subtitle = "\t   (" + to_string(vclients.size()) + ")  client(s).";


        _DrawScreenHeader(Title, subtitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vclients.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available In the System!";
        }

        else
        {        
            for (clsBankClient c : vclients)
            {
                PrintClientRecordBalanceLine(c);
                cout << endl;
            }
        }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::NumberToText(TotalBalances) << ")";

	}

};