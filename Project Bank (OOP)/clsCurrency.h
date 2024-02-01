#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsString.h"



class clsCurrency
{

private:


	enum enMode
	{
		EmptyMode = 0, UpdateMode = 1
	};

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static string _ConvertCurrencyObjectToLine(clsCurrency curr, string seperator = "#//#")
	{

		string line = "";

		line += curr.getCountry() + seperator;
		line += curr.getCurrencyCode() + seperator;
		line += curr.getCurrencyName() + seperator;
		line += to_string(curr.getRate());

		return line;

	}


	static clsCurrency _ConvertLineToCurrencyObject(string line, string seperator = "#//#")
	{

		vector <string> curr = clsString::Split(line, seperator);

		return clsCurrency(UpdateMode, curr[0], curr[1], curr[2], stof(curr[3]));

	}


	static vector <clsCurrency> _LoadCurrenciesFromFile()
	{

		vector <clsCurrency> vCurr;

		fstream myfile;
		myfile.open("Currencies.txt", ios::in);

		if (myfile.is_open())
		{

			string line;

			while (getline(myfile, line))
			{
				clsCurrency curinfo = _ConvertLineToCurrencyObject(line);
				vCurr.push_back(curinfo);
			}

			myfile.close();
			return vCurr;

		}

	}


	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurr)
	{

		fstream myfile;
		myfile.open("Currencies.txt", ios::out);

		if (myfile.is_open())
		{

			string line;

			for (clsCurrency cur : vCurr)
			{
				line = _ConvertCurrencyObjectToLine(cur);
				myfile << line << endl;
			}

			myfile.close();

		}

	}


	void _Update()
	{

		vector <clsCurrency> vCurr = _LoadCurrenciesFromFile();
		
		for (clsCurrency& cur : vCurr)
		{
			if (cur.getCurrencyCode() == getCurrencyCode())
			{
				cur = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(vCurr);

	}


	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(EmptyMode, "", "", "", 0);
	}



public:


	clsCurrency(enMode mode, string countryname, string currencycode, string currencyname, float rate)
	{
		_Mode = mode;
		_Country = countryname;
		_CurrencyCode = currencycode;
		_CurrencyName = currencyname;
		_Rate = rate;
	}


	bool IsEmpty()
	{
		return (_Mode == EmptyMode);
	}


	string getCountry()
	{
		return _Country;
	}


	string getCurrencyCode()
	{
		return _CurrencyCode;
	}


	string getCurrencyName()
	{
		return _CurrencyName;
	}


	float getRate()
	{
		return _Rate;
	}


	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}


	static clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream myfile;
		myfile.open("Currencies.txt", ios::in);

		if (myfile.is_open())
		{

			string line;

			while (getline(myfile, line))
			{

				clsCurrency curr = _ConvertLineToCurrencyObject(line);

				if (curr.getCurrencyCode() == CurrencyCode)
				{
					myfile.close();
					return curr;
				}

			}

			myfile.close();
			return _GetEmptyCurrencyObject();

		}

	}


	static clsCurrency FindByCountry(string CountryName)
	{

		CountryName = clsString::UpperAllString(CountryName);

		fstream myfile;
		myfile.open("Currencies.txt", ios::in);

		if (myfile.is_open())
		{

			string line;

			while (getline(myfile, line))
			{

				clsCurrency curr = _ConvertLineToCurrencyObject(line);

				if (clsString::UpperAllString(curr.getCountry()) == CountryName)
				{
					myfile.close();
					return curr;
				}

			}

			myfile.close();
			return _GetEmptyCurrencyObject();

		}

	}


	static bool IsCurrencyExist(string CurrencyCode)
	{

		clsCurrency curr = FindByCode(CurrencyCode);

		if (curr.IsEmpty() == true)
		{
			return false;
		}

		else
			return true;

	}


	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesFromFile();
	}


	float ConvertToUSD(float amount)
	{
		return float(amount / getRate());
	}


	float ConvertToOtherCurrency(float amount, clsCurrency curr2)
	{
		float AmountInUsd = ConvertToUSD(amount);

		if (curr2.getCurrencyCode() == "USD")
		{
			return AmountInUsd;
		}

		return float(AmountInUsd * curr2.getRate());
	
	}


};