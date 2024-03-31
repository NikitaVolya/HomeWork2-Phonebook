#pragma once

#include <iostream>


class PhoneUser
{
private:
	static unsigned long long globalID;
	static unsigned long long newUserId() { return globalID++; };

	unsigned long long userID;
	char* name;
	char* homePhone;
	char* workPhone;
	char* personePhone;
	char* description;

	const char* getCharLine(char* value);
	void changeCharLine(const char* line, char*& value);
public:

	PhoneUser() : userID(newUserId()),
				  name(nullptr),
				  homePhone(nullptr), 
				  workPhone(nullptr), 
				  personePhone(nullptr), 
				  description(nullptr) {};

	PhoneUser(const char* pName, const char* pHomePhone, const char* pWorkPhone, const char* pPersonePhone, const char* pDescription);
	~PhoneUser();

	const int getUserId() { return userID; };
	const char* getName() { return getCharLine(name); };
	const char* getHomePhone() { return getCharLine(homePhone); };
	const char* getWorkPhone() { return getCharLine(workPhone); };
	const char* getPersonePhone() { return getCharLine(personePhone); };
	const char* getDescription() { return getCharLine(description); };

	void setName(const char* pName) { changeCharLine(pName, name); };
	void setHomePhone(const char* pHomePhone) { changeCharLine(pHomePhone, homePhone); };
	void setWorkPhone(const char* pWorkPhone) { changeCharLine(pWorkPhone, workPhone); };
	void setPersonePhone(const char* pPersonePhone) { changeCharLine(pPersonePhone, personePhone); };
	void setDescription(const char* pDescription) { changeCharLine(pDescription, description); };

	void print();
};