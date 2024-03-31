#include <iostream>

#include "PhoneUser.h"
#include "HashTable.h"

using namespace std;

unsigned long long PhoneUser::globalID = 0;

int main()
{
	HashTable<PhoneUser*> dict;

	PhoneUser* a = new PhoneUser{ "Nikita", "0981132029", "-", "-", "Nice man" };
	PhoneUser* b = new PhoneUser{ "Artem", "5", "-", "-", nullptr };

	dict.insert("1", a);
	dict.set("1", b);

	cout << dict.get("1")->getHomePhone();

	delete a;
	delete b;

	return 0;
}