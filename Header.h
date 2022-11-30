#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;


enum Gender
{
	Male, Famele, Non_Binary
};

class Guest
{
private:
	string name;
	int age;
	string city;
	int phonenumber;

	Gender gender;
public:
	friend void FindAvarageAge(vector<Guest> A);
	int id;
	Guest()
	{
		id = 0;
		name = "";
		age = 0;
		city = "";
		phonenumber = 0;
	}
	Guest(int id, string name, int age, string city, int phonenumber)
	{
		this->id = id;
		this->name = name;
		this->age = age;
		this->city = city;
		this->phonenumber = phonenumber;
	}
	void SetGender(Gender gender)
	{
		this->gender = gender;
	}
	Gender GetGender()
	{
		return gender;
	}
	int GetAge()
	{
		return age;
	}
	int GetID()
	{
		return id;
	}
	void isLuckyPhoneNumber()
	{
		int res = 0;
		for (int i = 0; i < 7; i++)
		{
			if (phonenumber % 10 == 7)
			{
				res++;
			}
			phonenumber /= 10;
		}
		if (res >= 3)
			cout << name << "- your number is Lucky\n";
	}
	void Print()
	{
		cout << "Name - " << name << "\nID - " << id << "\nAge - " << age << "\nCity - " << city << "\nPhonenumber - " << phonenumber << endl << endl;
	}
};
class Party
{
	friend Guest;
private:
	string day;
	string reason;

public:
	void Setter(string day, string reason)
	{
		this->day = day;
		this->reason = reason;
	}
	void InputParty()
	{
		cout << "Day - " << day << "Reason - " << reason << endl << endl;
	}
};

void FindAvarageAge(vector<Guest> A)
{
	double result1 = 0, result2 = 0;
	int k1 = 0, k2 = 0;
	for (int i = 0; i < 7; i++)
	{

		if (A[i].GetGender() == Gender::Famele)
		{
			result1 += A[i].GetAge();
			k1++;
		}
		if (A[i].GetGender() == Gender::Male)
		{
			result2 += A[i].GetAge();
			k2++;
		}
	}
	result1 /= k1;
	result2 /= k2;
	cout << "\nAvarage girl age - " << result1 << "\nAvarage boy age - " << result2 << endl;
}