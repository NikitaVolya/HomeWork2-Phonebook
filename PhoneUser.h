#pragma once

#include <iostream>


class PhoneUser
{
private:

	char name[40];
	char homePhone[15];
	char workPhone[15];
	char personePhone[15];
	char description[40];

	const char* getCharLine(char* value);
	void changeCharLine(const char* line, char* value, const int size);
public:

	PhoneUser() : name("\0"),
				  homePhone("\0"),
				  workPhone("\0"),
				  personePhone("\0"),
				  description("\0") {};

	PhoneUser(const char* pName, const char* pHomePhone, const char* pWorkPhone, const char* pPersonePhone, const char* pDescription);

	const char* getName() { return getCharLine(name); };
	const char* getHomePhone() { return getCharLine(homePhone); };
	const char* getWorkPhone() { return getCharLine(workPhone); };
	const char* getPersonePhone() { return getCharLine(personePhone); };
	const char* getDescription() { return getCharLine(description); };

	void setName(const char* pName) { changeCharLine(pName, name, 40); };
	void setHomePhone(const char* pHomePhone) { changeCharLine(pHomePhone, homePhone, 13); };
	void setWorkPhone(const char* pWorkPhone) { changeCharLine(pWorkPhone, workPhone, 13); };
	void setPersonePhone(const char* pPersonePhone) { changeCharLine(pPersonePhone, personePhone, 13); };
	void setDescription(const char* pDescription) { changeCharLine(pDescription, description, 13); };

	void print();
};