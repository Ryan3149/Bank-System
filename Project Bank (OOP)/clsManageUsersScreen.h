#pragma once

#include <iostream>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsUser.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;


class clsManageUsersScreen : protected clsScreen
{

private:


	enum enManageUsersMenuOptions
	{
		eListUser = 1, eAddUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
	};


	static short _ReadManageUsersMenuOption()
	{
		short choice = 0;
		cout << endl << setw(37) << left << "" << "Choose What do you want to do [1 to 6]?  ";
		choice = clsInputValidate::ReadShortNumberBetween(1, 6);

		return choice;
	}


	static void _GoBackToManageUsersScreen()
	{
		cout << "\n\t Press Any Key to go back to Manage Users Menu....\n";
		system("pause>0");
		ShowManageUsersScreen();
	}

	
	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}


	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}


	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}


	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}


	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}


	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersOption)
	{

		switch (ManageUsersOption)
		{

		case clsManageUsersScreen::eListUser:

			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersScreen();
			break;

		case clsManageUsersScreen::eAddUser:

			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersScreen();
			break;

		case clsManageUsersScreen::eDeleteUser:

			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersScreen();
			break;

		case clsManageUsersScreen::eUpdateUser:

			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersScreen();
			break;

		case clsManageUsersScreen::eFindUser:

			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersScreen();
			break;

		case clsManageUsersScreen::eMainMenu:

			//nothing it will automatically go back to main menu screen;
			break;


		}

	}



public:


	static void ShowManageUsersScreen()
	{

		system("cls");

		if (!CheckAccessRights(clsUser::pManageUsers))
		{
			return;
		}


		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		_PerformManageUsersMenuOption(enManageUsersMenuOptions(_ReadManageUsersMenuOption()));

	}


};