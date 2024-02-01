#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;


class clsTransferLog : protected clsScreen
{

private:


	static void _PrintTransferLogRecord(clsBankClient::stTransferLog Log)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << Log.DateTime;
		cout << "| " << setw(10) << left << Log.SenderAccount;
		cout << "| " << setw(10) << left << Log.RecieverAccount;
		cout << "| " << setw(10) << left << Log.amount;
		cout << "| " << setw(10) << left << Log.SenderBalanceAfterAction;
		cout << "| " << setw(10) << left << Log.RecieverBalanceAfterAction;
		cout << "| " << setw(10) << left << Log.User;

	}


public:


	static void ShowTransferLogScreen()
	{

		vector <clsBankClient::stTransferLog> vTransferLog = clsBankClient::GetTransferLog();

		string title = "\t  Transfer Log List Screen";
		string subtitle = "\t  (" + to_string(vTransferLog.size()) + ") Record(s).";

		system("cls");
		_DrawScreenHeader(title, subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(10) << "S.Acc";
		cout << "| " << left << setw(10) << "R.Acc";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "R.Balance";
		cout << "| " << left << setw(10) << "User";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;


		if (vTransferLog.size() == 0)
			cout << "\t\t\t\tNo Records Available In the System!";

		else
		{

			for (clsBankClient::stTransferLog Log : vTransferLog)
			{
				_PrintTransferLogRecord(Log);
				cout << endl;
			}

		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

	}


};