#include "Header.h"

int main()
{
	Party A;
	A.Setter("November 27 ", "Birthday party");
	A.InputParty();
	cout << "Guests:" << endl << endl;
	const int length = 7;
	vector<Guest> guest{
		Guest(346, "Michael", 18, "Lviv", 8776879),
		Guest(128, "George", 21, "Chernigiv", 5647689),
		Guest(48, "Sam", 17, "Lviv", 7658908),
		Guest(568, "Amanda", 20, "Ternopil", 1287677),
		Guest(167, "Sara", 19, "Sambir", 8805535),
		Guest(13, "Edvard", 20, "Kalush", 7897876),
		Guest(777, "Steav", 22, "Kyiv", 3409056)
	};
	guest[0].SetGender(Gender::Male); 
	guest[1].SetGender(Gender::Male); 
	guest[2].SetGender(Gender::Male);
	guest[3].SetGender(Gender::Female);
	guest[4].SetGender(Gender::Female);
	guest[5].SetGender(Gender::Male); 
	guest[6].SetGender(Gender::Male);

	sort(guest.begin(), guest.end(), [](const Guest &p1, const Guest &p2)
		{
			return p1.id < p2.id;
		});
	
		for (int i = 0; i < length; i++)
		{
			guest[i].Print();
		}
		for (int i = 0; i < length; i++)
		{
			guest[i].isLuckyPhoneNumber();
		}

		FindAverageAge(guest);

}