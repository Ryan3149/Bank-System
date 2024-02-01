#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;


class clsTransferScreen : protected clsScreen
{

private:

	static void PrintClientInfo(clsBankClient client)
	{

		cout << "\nClient Card: ";
		cout << "\n___________________________________\n";

		cout << "\nFull Name    : " << client.FullName();
		cout << "\nAcc. Number  : " << client.getAccountNumber();
		cout << "\nBalance      : " << client.Balance;

		cout << "\n___________________________________\n";

	}


	static string _ReadAccountNumber(string message)
	{

		string accnum = "";
		cout << message;
		cin >> accnum;


		while (!clsBankClient::IsClientExist(accnum))
		{
			cout << "\n\nClient with account number not found, Please enter another account number?  ";
			cin >> accnum;
		}

		return accnum;

	}


public:

	static void ShowTransferScreen()
	{

		system("cls");

		_DrawScreenHeader("\t  Transfer Screen");

		string accnum = _ReadAccountNumber("\nPlease enter account Number to transfer from:  ");
		clsBankClient TransfererClient = clsBankClient::Find(accnum);
		PrintClientInfo(TransfererClient);

				
		accnum = _ReadAccountNumber("\nPlease enter account Number to transfer To:  ");
		clsBankClient RecieverClient = clsBankClient::Find(accnum);
		PrintClientInfo(RecieverClient);


		double amount = 0;
		cout << "\nPlease enter transfer Amount?  ";
		amount = clsInputValidate::ReadDblNumber();

		while (TransfererClient.Balance < amount)
		{
			cout << "\nAmount Exceeds the available balance, Please enter another amount?  ";
			cin >> amount;
		}

		char choice = 'n';
		cout << "\nAre you sure you want to perform this operation?  Y/N?  ";
		cin >> choice;

		if (toupper(choice) == 'Y')
		{
			TransfererClient.Transfer(amount, RecieverClient);

			cout << "\n\nTransaction Done successfully.\n\n";
			PrintClientInfo(TransfererClient);
			PrintClientInfo(RecieverClient);

		}


	}


};