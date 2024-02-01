#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;


class clsLoginRegisterScreen : protected clsScreen
{


private:

	static void PrintLoginUserRecordLine(clsUser::stUserLoginRegisterInfo user)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << user.DateTime;
		cout << "| " << setw(25) << left << user.UserName;
		cout << "| " << setw(12) << left << user.PassWord;
		cout << "| " << setw(25) << left << user.Permissions;

	}


public:


	static void voidShowLoginRegisterList()
	{

		system("cls");

		if (!CheckAccessRights(clsUser::pListLoginRegisters))
		{
			return;
		}


		vector <clsUser::stUserLoginRegisterInfo> vLoginRegisters = clsUser::GetLoginRegisterList();

		string title = "\t  Login Register List Screen";
		string subtitle = "\t  (" + to_string(vLoginRegisters.size()) + ") Record(s).";

		_DrawScreenHeader(title, subtitle);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(25) << "UserName";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(25) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vLoginRegisters.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";


		else
		{

			for (clsUser::stUserLoginRegisterInfo record : vLoginRegisters)
			{
				PrintLoginUserRecordLine(record);
				cout << endl;
			}

		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;



	}



};