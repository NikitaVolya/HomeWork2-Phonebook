#pragma once

#include "PhoneUser.h"
#include "HashTable.h"

#include <conio.h>
#include <io.h>

using namespace std;

class Phonebook
{
private:
	HashTable<PhoneUser*> table;

	void loadFile();
	void saveFile();

	PhoneUser* createNewUser();
public:
	Phonebook();
	~Phonebook();
	
	void addPhoneUser();
	void removePhoneUser();
	void seePhoneUsers();
	void findPhoneUser();
	void main();
};