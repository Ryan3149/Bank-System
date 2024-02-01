#pragma once


#include <iostream>;
#include <string>;


using namespace std;


class clsPerson
{

private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _PhoneNumber;

public:


	clsPerson(string firstname, string lastname, string email, string phone)
	{
		_Email = email;
		_PhoneNumber = phone;
		_FirstName = firstname;
		_LastName = lastname;
	}

	void setFirstName(string firstname)
	{
		_FirstName = firstname;
	}

	string getFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

	void setLastName(string lastname)
	{
		_LastName = lastname;
	}

	string getLastname()
	{
		return _LastName;
	}

	__declspec(property(get = getLastname, put = setLastName)) string Lastname;

	void setEmail(string email)
	{
		_Email = email;
	}

	string getEmail()
	{
		return _Email;
	}

	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setPhoneNumber(string phone)
	{
		_PhoneNumber = phone;
	}

	string getPhoneNumber()
	{
		return _PhoneNumber;
	}

	__declspec(property(get = getPhoneNumber, put = setPhoneNumber)) string PhoneNumber;

	string FullName()
	{
		return _FirstName + _LastName;
	}



};