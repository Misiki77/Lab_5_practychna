#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;


enum Gender
{
	Male, Female, Non_Binary
};

class Guest
{
 private:
	string name;
	int age;
	string city;
	int phone_number;

	Gender gender;
 public:
	friend void FindAverageAge(vector<Guest> A);
	int id;
	Guest()
	{
		id = 0;
		name = "";
		age = 0;
		city = "";
		phone_number = 0;
	}
	Guest(int id, string name, int age, string city, int phonenumber)
	{
		this->id = id;
		this->name = name;
		this->age = age;
		this->city = city;
		this->phone_number = phonenumber;
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
		int number_of_7_in_phone_number = 0;
		for (int i = 0; i < 7; i++)
		{
			if (phone_number % 10 == 7)
			{
				number_of_7_in_phone_number++;
			}
			phone_number /= 10;
		}
		if (number_of_7_in_phone_number >= 3)
			cout << name << "- your number is Lucky\n";
	}
	void Print()
	{
		cout << "Name - " << name << "\nID - " << id << "\nAge - " << age << "\nCity - " << city << "\nPhonenumber - " << phone_number << endl << endl;
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

void FindAverageAge(vector<Guest> A)
{
	double sum_of_females_ages = 0, sum_of_males_ages = 0;
	int number_of_females_guests = 0, number_of_males_guests = 0;
	for (int i = 0; i < 7; i++)
	{

		if (A[i].GetGender() == Gender::Female)
		{
			sum_of_females_ages += A[i].GetAge();
			number_of_females_guests++;
		}
		if (A[i].GetGender() == Gender::Male)
		{
			sum_of_males_ages += A[i].GetAge();
			number_of_males_guests++;
		}
	}
	sum_of_females_ages /= number_of_females_guests;
	sum_of_males_ages /= number_of_males_guests;
	cout << "\nAvarage girl age - " << sum_of_females_ages << "\nAvarage boy age - " << sum_of_males_ages << endl;
}
