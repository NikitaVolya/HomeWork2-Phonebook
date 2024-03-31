#include "PhoneUser.h"

const char* PhoneUser::getCharLine(char* value)
{
    if (value)
        return value;
    else
        return "None";
}

void PhoneUser::changeCharLine(const char* line, char*& value)
{
    if (value)
        delete[] value;

    if (!line)
    {
        value = nullptr;
        return;
    }


    int len = std::strlen(line) + 1;
    value = new char[len];

    for (int i = 0; i < len; i++)
        value[i] = line[i];
}

PhoneUser::PhoneUser(const char* pName, const char* pHomePhone, const char* pWorkPhone, const char* pPersonePhone, const char* pDescription) : userID(newUserId())
{
    setName(pName);
    setHomePhone(pHomePhone);
    setWorkPhone(pWorkPhone);
    setPersonePhone(pPersonePhone);
    setDescription(pDescription);
}

PhoneUser::~PhoneUser()
{
    if (name)
        delete[] name;
    if (homePhone)
        delete[] homePhone;
    if (workPhone)
        delete[] workPhone;
    if (personePhone)
        delete[] personePhone;
    if (description)
        delete[] description;
}

void PhoneUser::print()
{
    std::cout << getName() << " | " << getHomePhone() << " | " << getWorkPhone() << " | " << getPersonePhone() << " | " << getDescription() << std::endl;
}
