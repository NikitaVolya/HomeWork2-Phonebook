#include <iostream>

#include "HashTable.h"
#include "Stack.h"

using namespace std;

int main()
{
	HashTable<int>* dict = new HashTable<int>();

	dict->insert("lol", 5);
	dict->insert("test", 7);

	int* value = dict->get("lol");

	cout << *value << endl;

	delete dict;

	cout << *value;

	return 0;
}