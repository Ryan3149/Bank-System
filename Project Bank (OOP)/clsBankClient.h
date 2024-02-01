#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsString.h"
#include "clsPerson.h"


using namespace std;


class clsBankClient : public clsPerson
{

private:


	enum _enMode
	{
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 3
	};


	_enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _Balance;
	bool _MarkedForDelete = false;



	static clsBankClient _ConvertLineToClientObject(string line, string Seperator = "#//#")
	{

		vector <string> vClientdata;

		vClientdata = clsString::Split(line, Seperator);

		return clsBankClient(UpdateMode, vClientdata[0], vClientdata[1], vClientdata[2], vClientdata[3], vClientdata[4],
			vClientdata[5], stod(vClientdata[6]));

	}


	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
	}


	static string _ConvertClientObjectToLine(clsBankClient client, string Seperator = "#//#")
	{

		string Clientrecord = "";

		Clientrecord += client.FirstName + Seperator;
		Clientrecord += client.Lastname + Seperator;
		Clientrecord += client.Email + Seperator;
		Clientrecord += client.PhoneNumber + Seperator;
		Clientrecord += client.getAccountNumber() + Seperator;
		Clientrecord += client.PinCode + Seperator;
		Clientrecord += to_string(client.Balance);

		return Clientrecord;

	}


	void _AddDataLineToFile(string dataline)
	{

		fstream myfile;
		myfile.open("myClients.txt", ios::out | ios::app);

		if (myfile.is_open())
		{
			myfile << dataline << endl;
			myfile.close();
		}

	}


	string _ConvertTransferLogToLine(double amount, clsBankClient Reciever, string seperator = "#//#")
	{

		string line = "";
		string DateTime = clsDate::GetSystemDateTimeString();


		line += DateTime + seperator;
		line += getAccountNumber() + seperator;
		line += Reciever.getAccountNumber() + seperator;
		line += to_string(amount) + seperator;
		line += to_string(Balance) + seperator;
		line += to_string(Reciever.Balance) + seperator;
		line += CurrentUser.UserName;

		return line;
	}


	struct stTransferLog;


	static stTransferLog _ConvertLineToTransferLog(string line, string seperator = "#//#")
	{

		vector <string> vtrasnferlog = clsString::Split(line, seperator);

		stTransferLog transfer;
		transfer.DateTime = vtrasnferlog[0];
		transfer.SenderAccount = vtrasnferlog[1];
		transfer.RecieverAccount = vtrasnferlog[2];
		transfer.amount = stod(vtrasnferlog[3]);
		transfer.SenderBalanceAfterAction = stod(vtrasnferlog[4]);
		transfer.RecieverBalanceAfterAction = stod(vtrasnferlog[5]);
		transfer.User = vtrasnferlog[6];

		return transfer;

	}


	void _RegisterTransferLog(double amount, clsBankClient Reciever)
	{

		string line = _ConvertTransferLogToLine(amount, Reciever);

		fstream myfile;
		myfile.open("TransferLog.txt", ios::out | ios::app);

		if (myfile.is_open())
		{
			myfile << line << endl;
			myfile.close();
		}

	}


	void _AddTransferInfoToFile(string line)
	{

		fstream myfile;
		myfile.open("TransferLog.txt", ios::out | ios::app);

		if (myfile.is_open())
		{
			myfile << line << endl;
			myfile.close();
		}

	}
	

	static vector <clsBankClient> _LoadClientsFromDataFile()
	{

		vector <clsBankClient> vClients;

		fstream myfile;
		myfile.open("myClients.txt", ios::in);

		if (myfile.is_open())
		{

			string line;

			while (getline(myfile, line))
			{

				clsBankClient client = clsBankClient::_ConvertLineToClientObject(line);

				vClients.push_back(client);

			}

			myfile.close();

		}

		return vClients;

	}


	static void  _SaveClientsDataToFile(vector <clsBankClient> vclients)
	{

		fstream myfile;
		myfile.open("myClients.txt", ios::out);

		if (myfile.is_open())
		{

			string DataLine;

			for (clsBankClient c : vclients)
			{
				if (c._MarkedForDelete == false)
				{
					DataLine = clsBankClient::_ConvertClientObjectToLine(c);
					myfile << DataLine << endl;
				}
			}

			myfile.close();
		}

	}


	void _Update()
	{

		vector <clsBankClient> vClients = _LoadClientsFromDataFile();

		for (clsBankClient& c : vClients)
		{

			if (c.getAccountNumber() == getAccountNumber())
			{
				c = *this;
				break;
			}

		}

		_SaveClientsDataToFile(vClients);

	}


	void _AddNew()
	{

		_AddDataLineToFile(_ConvertClientObjectToLine(*this));

	}


	
public:



	clsBankClient(_enMode mode, string firstname, string lastname, string email, string phone,
		string accountnumber, string pincode, double balance) : clsPerson(firstname, lastname, email, phone)
	{
		_AccountNumber = accountnumber;
		_PinCode = pincode;
		_Balance = balance;
		_Mode = mode;
	}



	struct stTransferLog
	{
		string DateTime;
		string SenderAccount;
		string RecieverAccount;
		double amount;
		double SenderBalanceAfterAction;
		double RecieverBalanceAfterAction;
		string User;
	};


	bool IsEmpty()
	{
		return (_Mode == EmptyMode);
	}


	string getAccountNumber()
	{
		return _AccountNumber;
	}


	void setPincOde(string pin)
	{
		_PinCode = pin;
	}


	string getPinCode()
	{
		return _PinCode;
	}


	__declspec(property(get = getPinCode, put = setPincOde)) string PinCode;


	void setBalance(double balance)
	{
		_Balance = balance;
	}


	double getBalance()
	{
		return _Balance;
	}

	__declspec(property(get = getBalance, put = setBalance)) double Balance;


	void Print()
	{

		cout << "\nClient Info:";
		cout << "\n__________________________________________";
		cout << "\nFirstName    :       " << FirstName;
		cout << "\nLastName     :       " << Lastname;
		cout << "\nFull Name    :       " << FullName();
		cout << "\nEmail        :       " << Email;
		cout << "\nPhone        :       " << PhoneNumber;
		cout << "\nAcc. Number  :       " << _AccountNumber;
		cout << "\nPin          :       " << _PinCode;
		cout << "\nBalance      :       " << _Balance;
		cout << "\n__________________________________________\n";

	}
	

	static clsBankClient Find(string AccountNumber)
	{

		fstream myfile;
		myfile.open("myClients.txt", ios::in);

		if (myfile.is_open())
		{

			string line;

			while (getline(myfile, line))
			{

				clsBankClient Client = _ConvertLineToClientObject(line, "#//#");

				if (Client.getAccountNumber() == AccountNumber)
				{
					myfile.close();
					return Client;
				}

			}

			myfile.close();

		}

		return _GetEmptyClientObject();

	}


	static clsBankClient Find(string AccountNumber, string PinCode_)
	{

		fstream myfile;
		myfile.open("myClients.txt", ios::in);

		if (myfile.is_open())
		{

			string line;

			while (getline(myfile, line))
			{

				clsBankClient client = _ConvertLineToClientObject(line);

				if (client.getAccountNumber() == AccountNumber && client.PinCode == PinCode_)
				{
					myfile.close();
					return client;
				}


			}

			myfile.close();

		}

		return _GetEmptyClientObject();

	}


	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient client = clsBankClient::Find(AccountNumber);

		if (client.IsEmpty() == false)
		{
			return true;
		}

		else
			return false;

	}


	bool Delete()
	{

		vector <clsBankClient> vClients = _LoadClientsFromDataFile();

		for (clsBankClient& c : vClients)
		{

			if (c.getAccountNumber() == _AccountNumber)
			{
				c._MarkedForDelete = true;
				break;
			}

		}

		_SaveClientsDataToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;

	}


	void Deposit(double amount)
	{
		Balance += amount;
		Save();
	}


	bool WithDraw(double amount)
	{
		
		if (amount > Balance)
		{
			return false;
		}

		else
		{
			Balance -= amount;
			Save();
			return true;
		}

	}


	bool Transfer(double amount, clsBankClient& RecieverClient)
	{

		if (amount > Balance)
		{
			return false;
		}

		else
		{
			WithDraw(amount);
			RecieverClient.Deposit(amount);
			_RegisterTransferLog(amount, RecieverClient);
			
			return true;
		}

	}


	static vector <stTransferLog> GetTransferLog()
	{

		vector <stTransferLog> vTransferLog;

		fstream myfile;
		myfile.open("TransferLog.txt", ios::in);

		if (myfile.is_open())
		{

			string line;

			while (getline(myfile, line))
			{
				stTransferLog TransferLog = _ConvertLineToTransferLog(line);
				vTransferLog.push_back(TransferLog);
			}

			myfile.close();
			return vTransferLog;

		}

	}


	static double GetTotalBalances()
	{

		vector <clsBankClient> vclients = GetClientsList();

		double totalbalances = 0;

		for (clsBankClient c : vclients)
		{
			totalbalances += c.Balance;
		}

		return totalbalances;

	}


	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsFromDataFile();
	}


	static clsBankClient GetAddNewClientObject(string accountNumber)
	{
		return clsBankClient(AddNewMode, "", "", "", "", accountNumber, "", 0);
	}
	

	enum enSave
	{
		svFailedEmptyObject = 1, svSucceeded = 2, svFailedAccountNumberExists = 3
	};


	enSave Save()
	{

		switch (_Mode)
		{

		case _enMode::EmptyMode:

			return svFailedEmptyObject;
			break;

		case _enMode::UpdateMode:

			_Update();
			return svSucceeded;
			break;

		case _enMode::AddNewMode:

			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return svFailedAccountNumberExists;
			}

			else
			{
				_AddNew();
				_Mode = _enMode::UpdateMode;
				return svSucceeded;
			}

			break;

		}

	}


};