#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"


using namespace std;


class clsUser : public clsPerson
{


private:

	enum enMode
	{
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
	};


	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;


    static clsUser _ConvertLineToUserObject(string line, string seperator = "#//#")
    {

        vector <string> vUserData = clsString::Split(line, seperator);

        return clsUser(UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4],
           clsUtil::DecryptText(vUserData[5]) , stoi(vUserData[6]));

    }


    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.Lastname + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.PhoneNumber + Seperator;
        UserRecord += User.UserName + Seperator;
        UserRecord += clsUtil::EncryptText(User.Password) + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;

    }


    static vector <clsUser> _LoadUsersFromDataFile()
    {

        fstream myfile;
        myfile.open("myUsers.txt", ios::in);
        
        if (myfile.is_open())
        {

            vector <clsUser> vUsers;
            string line;

            while (getline(myfile, line))
            {

                clsUser user = _ConvertLineToUserObject(line);
                vUsers.push_back(user);

            }
            
            myfile.close();
            return vUsers;

        }

    }


    struct stUserLoginRegisterInfo;


    static stUserLoginRegisterInfo _ConvertLineToRegisterInfoStruct(string line, string seprator  = "#//#")
    {
    
        vector <string> vlogin = clsString::Split(line, seprator);

        stUserLoginRegisterInfo loginRegister;

        loginRegister.DateTime = vlogin[0];
        loginRegister.UserName = vlogin[1];
        loginRegister.PassWord = clsUtil::DecryptText(vlogin[2]);
        loginRegister.Permissions = stoi(vlogin[3]);

        return loginRegister;

    }
        

    static vector <stUserLoginRegisterInfo> _LoadLoginRegisterUsersDataFromFile()
    {
    
        vector <stUserLoginRegisterInfo> vLoginRegister;

        fstream myfile;
        myfile.open("LoginRegister.txt", ios::in);

        if (myfile.is_open())
        {

            string line;

            while (getline(myfile, line))
            {

                stUserLoginRegisterInfo login = _ConvertLineToRegisterInfoStruct(line);
                vLoginRegister.push_back(login);

            }

            myfile.close();
            return vLoginRegister;

        }
    
    }


    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("myUsers.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }


    string _PrepareLoginInRecord(string seperator = "#//#")
    {

        string line = "";
        string DateAndTimeString = clsDate::GetSystemDateTimeString();

        line += DateAndTimeString + seperator;
        line += _UserName + seperator;
        line += clsUtil::EncryptText(_Password) + seperator;
        line += to_string(_Permissions);

        return line;

    }


    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersFromDataFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }


    void _AddNew()
    {
        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }


    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("myUsers.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }


    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }



public:


    enum enPermissions
    {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClients = 4, pUpdateClients = 8,
        pFindClients = 16, pTransactions = 32, pManageUsers = 64, pListLoginRegisters = 128, pCurrencyExchange = 256
    };


    struct stUserLoginRegisterInfo
    {
        string DateTime;
        string UserName;
        string PassWord;
        int Permissions;
    };




	clsUser(enMode mode, string firstname, string lastname, string email, string phone,
		string username, string password, int permissions)	:
		clsPerson(firstname, lastname, email, phone)
	{

		_Mode = mode;
		_UserName = username;
		_Password = password;
		_Permissions = permissions;

	}



	bool isEmpty()
	{
		return (_Mode == EmptyMode);
	}


    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }


    string getUserName()
    {
        return _UserName;
    }


    void setUserName(string UserName)
    {
        _UserName = UserName;
    }


    __declspec(property(get = getUserName, put = setUserName)) string UserName;


    void setPassword(string Password)
    {
        _Password = Password;
    }


    string getPassword()
    {
        return _Password;
    }


    __declspec(property(get = getPassword, put = setPassword)) string Password;


    void setPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }


    int getPermissions()
    {
        return _Permissions;
    }


    __declspec(property(get = getPermissions, put = setPermissions)) int Permissions;


    static clsUser Find(string username)
    {

        fstream MyFile;
        MyFile.open("myUsers.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == username)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();

    }


    static clsUser Find(string username, string password)
    {

        fstream MyFile;
        MyFile.open("myUsers.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == username && User.Password == password)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();

    }


    enum enSaveResults
    {
        svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserExists = 2
    };


    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return (!User.isEmpty());
    }


    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersFromDataFile();
    }


    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersFromDataFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }


    enSaveResults Save()
    {

        switch (_Mode)
        {
        case clsUser::EmptyMode:

            if (isEmpty())
            {
                return svFailedEmptyObject;
            }

            break;

        case clsUser::UpdateMode:

            _Update();
            return svSucceeded;
            break;

        case clsUser::AddNewMode:

            if (IsUserExist(_UserName))
            {
                return svFailedUserExists;
            }

            else
            {
                _AddNew();
                _Mode = UpdateMode;
                return svSucceeded;
            }

            break;
    
        }

    }


    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }


    bool CheckAccessPermission(enPermissions currentscreenpermission)
    {

        if (this->Permissions == eAll)
        {
            return true;
        }

        if ((currentscreenpermission & this->Permissions) == currentscreenpermission)
        {
            return true;
        }

        else
            return false;

    }


    void RegisterLogin()
    {

        string dataline = _PrepareLoginInRecord();

        fstream myfile;
        myfile.open("LoginRegister.txt", ios::out | ios::app);

        if (myfile.is_open())
        {
            myfile << dataline << endl;
            myfile.close();
        }

    }


    static vector <stUserLoginRegisterInfo> GetLoginRegisterList()
    {
        return _LoadLoginRegisterUsersDataFromFile();
    }



};