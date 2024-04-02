#include "PhoneUser.h"

const char* PhoneUser::getCharLine(char* value)
{
    if (value[0])
        return value;
    else
        return "None";
}

void PhoneUser::changeCharLine(const char* line, char* value, const int size)
{
    if (!line)
    {
        value[0] = '\0';
        return;
    }

    int len = std::strlen(line) + 1;

    int i = 0;
    for (; i < len && i < size; i++)
        value[i] = line[i];
    value[i + 1] = '\0';
}

PhoneUser::PhoneUser(const char* pName, const char* pHomePhone, const char* pWorkPhone, const char* pPersonePhone, const char* pDescription)
{
    setName(pName);
    setHomePhone(pHomePhone);
    setWorkPhone(pWorkPhone);
    setPersonePhone(pPersonePhone);
    setDescription(pDescription);
}

void PhoneUser::print()
{
    std::cout << getName() << " | " << getHomePhone() << " | " << getWorkPhone() << " | " << getPersonePhone() << " | " << getDescription() << std::endl;
}
