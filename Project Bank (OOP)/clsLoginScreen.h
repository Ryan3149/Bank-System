#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include "clsUser.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"
#include "clsString.h"
#include "clsDate.h"

class clsLoginScreen : protected clsScreen 
{

private:


	

	static bool _Login()
	{

		bool LoginFailed = false;
		short chances = 3;

		string username, password;

		do
		{

			if (chances == 1)
			{
				cout << "\n\n\t\t\t  !!!LOGIN BLOCKED!!!\n\n\n";
				return false;
			}

			if (LoginFailed)
			{
				chances--;
				system("cls");
				_DrawScreenHeader("\t    Login Screen");
				cout << "\nInvalid Username/Password\n\n";
				cout << "You have " << chances << " Trials left!\n";
			}

			cout << "\nEnter Username?  ";
			cin >> username;

			cout << "\nEnter Password?  ";
			cin >> password;


			CurrentUser = clsUser::Find(username, password);

			LoginFailed = CurrentUser.isEmpty();

		} while (LoginFailed);


		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenu();

	}


public:

	static bool ShowLoginScreen()
	{
		
		system("cls");
		_DrawScreenHeader("\t    Login Screen");
		return _Login();

	}



};