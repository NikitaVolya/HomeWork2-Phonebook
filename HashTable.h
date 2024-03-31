#pragma once

#include <iostream>
#include "Stack.h"

template <typename Value>
struct HashElement
{
	char* key;
	Value value;
};

template <typename Value>
class HashTable
{
private:
	Stack<HashElement<Value>*>** table;
	int count, size;

	char* copyline(const char* pStr);
	unsigned int hashFunction(char* pKey);
public:
	HashTable();
	~HashTable();

	int getCount() { return count; };
	int getSize() { return size; };
	Value* get(char* pKey);
	Value* get(const char* pKey);

	void insert(char* pKey, Value pValue);
	void insert(const char* pKey, Value pValue);
	bool find(char* pKey);
	bool find(const char* pKey);
};

template<typename Value>
inline char* HashTable<Value>::copyline(const char* pStr)
{
	int strLen = std::strlen(pStr) + 1;
	char* newStr = new char[strLen];
	for (int i = 0; i < strLen; i++)
		newStr[i] = pStr[i];

	return newStr;
}

template<typename Value>
inline unsigned int HashTable<Value>::hashFunction(char* pKey)
{
	unsigned int sum = 0;
	for (int j = 0; pKey[j]; j++)
		sum += pKey[j];
	return sum % size;
}

template<typename Value>
inline HashTable<Value>::HashTable() : count(0), size(100)
{
	table = new Stack<HashElement<Value>*>*[size];
	for (int i = 0; i < size; i++)
		table[i] = new Stack<HashElement<Value>*>;
}

template<typename Value>
inline HashTable<Value>::~HashTable()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < table[i]->getSize(); j++)
		{
			delete element->key;
			delete element;
		}
		delete table[i];
	}
	delete table;
}

template<typename Value>
inline Value* HashTable<Value>::get(char* pKey)
{
	unsigned int index = hashFunction(pKey);

	Stack<HashElement<Value>*>* column = table[index];

	for (int i = 0; i < column->getSize(); i++)
		if (std::strcmp(column->getValue(i)->key, pKey) == 0)
			return &column->getValue(i)->value;
	return nullptr;
}

template<typename Value>
inline Value* HashTable<Value>::get(const char* pKey)
{
	char* newKey = copyline(pKey);
	Value* res = get(newKey);
	delete newKey;
	return res;
}

template<typename Value>
inline void HashTable<Value>::insert(char* pKey, Value pValue)
{
	unsigned int index = hashFunction(pKey);

	char* newKey = copyline(pKey);

	HashElement<Value>* newElement = new HashElement<Value>{ newKey, pValue };

	for (int i = 0; i < table[index]->getSize(); i++)
		if (std::strcmp(table[index]->getValue(i)->key, pKey) == 0)
		{
			table[index]->pop(i);
			break;
		}

	table[index]->appfirst(newElement);
}

template<typename Value>
inline void HashTable<Value>::insert(const char* pKey, Value pValue)
{
	char* newKey = copyline(pKey);
	insert(newKey, pValue);
	delete newKey;
}

template<typename Value>
inline bool HashTable<Value>::find(char* pKey)
{
	unsigned int index = hashFunction(pKey);

	Stack<HashElement<Value>*>* column = table[index];

	for (int i = 0; i < column->getSize(); i++)
		if (std::strcmp(column->getValue(i)->key, pKey) == 0)
			return true;
	return false;
}

template<typename Value>
inline bool HashTable<Value>::find(const char* pKey)
{
	char* newKey = copyline(pKey);
	bool res = find(newKey);
	delete newKey;
	return res;
}