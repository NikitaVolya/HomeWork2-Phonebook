#include "Phonebook.h"

void Phonebook::loadFile()
{
	FILE* f = nullptr;
	fopen_s(&f, "phonebookData", "ab");
	fclose(f);
	fopen_s(&f, "phonebookData", "rb");

	int length = _filelength(_fileno(f));
	int count = length / sizeof(PhoneUser);

	if (count != 0)
	{
		for (int i = 0; i < count; i++)
		{
			PhoneUser* user = new PhoneUser;
			fread(user, sizeof(PhoneUser), 1, f);
			table.insert(user->getName(), user);
		}
	}

	fclose(f);
}

void Phonebook::saveFile()
{
	FILE* f = nullptr;
	fopen_s(&f, "phonebookData", "wb");
	for (int i = 0; i < table.getCount(); i++)
		fwrite(table.getByIndex(i), sizeof(PhoneUser), 1, f);
	fclose(f);
}

PhoneUser* Phonebook::createNewUser()
{
	PhoneUser* newPhoneUser = new PhoneUser;

	char fullName[40];
	char homePhone[15];
	char workPhone[15];
	char personePhone[15];
	char description[40];

	cout << "Enter full name: ";
	cin.get();
	cin.getline(fullName, 40);
	newPhoneUser->setName(fullName);

	cout << "Enter home phone: ";
	cin.get();
	cin.getline(homePhone, 15);
	newPhoneUser->setHomePhone(homePhone);

	cout << "Enter work phone: ";
	cin.get();
	cin.getline(workPhone, 15);
	newPhoneUser->setWorkPhone(workPhone);

	cout << "Enter persone phone: ";
	cin.get();
	cin.getline(personePhone, 15);
	newPhoneUser->setPersonePhone(personePhone);

	cout << "Enter description: ";
	cin.get();
	cin.getline(description, 40);
	newPhoneUser->setDescription(description);

	return newPhoneUser;
}

Phonebook::Phonebook()
{
	loadFile();
}

Phonebook::~Phonebook()
{
	for (int i = 0; i < table.getCount(); i++)
		delete table.getByIndex(i);
}

void Phonebook::addPhoneUser()
{
	int numberNewUsers;

	cout << "How many users do you want to add?: ";
	cin >> numberNewUsers;

	for (int i = 0; i < numberNewUsers; i++)
	{
		PhoneUser* newPhoneUser = createNewUser();

		if (table.find(newPhoneUser->getName()))
		{
			int choice;
			cout << "this user exists. Do you want to rewrite this user?\n1. yes or 2. not?\n";
			cin >> choice;
			if (choice == '1')
				table.insert(newPhoneUser->getName(), newPhoneUser);
			else 
				delete newPhoneUser;
		}
		else
		{
			table.insert(newPhoneUser->getName(), newPhoneUser);
		}
	}

	saveFile();
}

void Phonebook::removePhoneUser()
{
	char fullName[40];
	cout << "Write full name user for remove: ";
	cin.getline(fullName, 40);

	if (table.remove(fullName))
		cout << "User removed";
	else
		cout << "User is not found";

	saveFile();
	_getch();
}

void Phonebook::seePhoneUsers()
{
	system("cls");
	for (int i = 0; i < table.getCount(); i++)
	{
		PhoneUser* user = table.getByIndex(i);
		user->print();
	}
	_getch();
}

void Phonebook::findPhoneUser()
{
	system("cls");
	char fullName[40];
	cout << "Write full name user for found: ";
	cin.getline(fullName, 40);

	if (table.find(fullName))
	{
		PhoneUser* user = table.get(fullName);
		user->print();
	}
	else
		cout << "User is not found";

	_getch();
}

void Phonebook::main()
{
	char menu[][25]{
		"1. add new phone user\n",
		"2. remove phone user\n",
		"3. wath phone users\n",
		"4. find phone user\n",
		"5. exit\n"
	};

	while (true)
	{
		system("cls");
		cout << "Select option:\n";
		for (int i = 0; i < 5; i++)
			cout << menu[i];

		char choice = _getch();

		switch (choice)
		{
			case '1':
				addPhoneUser();
				break;
			case '2':
				removePhoneUser();
				break; 
			case '3':
				seePhoneUsers();
				break;
			case '4':
				findPhoneUser();
				break; 
			case '5':
				return;
		}
	}
}
