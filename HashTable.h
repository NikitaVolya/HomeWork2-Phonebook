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
	unsigned int hashFunction(const char* pKey);
public:
	HashTable();
	~HashTable();

	int getCount() { return count; };
	int getSize() { return size; };

	Value get(const char* pKey);
	Value getByIndex(int index);
	void set(const char* pKey, Value val);
	bool remove(const char* pKey);

	Value* getPointer(const char* pKey);

	void insert(const char* pKey, Value pValue);
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
inline unsigned int HashTable<Value>::hashFunction(const char* pKey)
{
	unsigned int sum = 0;
	for (int j = 0; pKey[j]; j++)
		sum += pKey[j];
	return sum % size;
}

template<typename Value>
inline HashTable<Value>::HashTable() : count(0), size(500)
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
			HashElement<Value>* element = table[i]->getValue(j);
			delete element->key;
			delete element;
		}
		delete table[i];
	}
	delete table;
}

template<typename Value>
inline Value HashTable<Value>::get(const char* pKey)
{
	unsigned int index = hashFunction(pKey);

	Stack<HashElement<Value>*>* column = table[index];

	for (int i = 0; i < column->getSize(); i++)
		if (std::strcmp(column->getValue(i)->key, pKey) == 0)
			return column->getValue(i)->value;
}

template<typename Value>
inline Value HashTable<Value>::getByIndex(int index)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i]->getSize() == 0)
			continue;
		else if (index < table[i]->getSize())
			return table[i]->getValue(index)->value;
		else
			index -= table[i]->getSize();
	}
}

template<typename Value>
inline void HashTable<Value>::set(const char* pKey, Value pValue)
{
	Value* val = getPointer(pKey);
	*val = pValue;
}

template<typename Value>
inline bool HashTable<Value>::remove(const char* pKey)
{
	unsigned int index = hashFunction(pKey);

	Stack<HashElement<Value>*>* column = table[index];

	for (int i = 0; i < column->getSize(); i++)
		if (std::strcmp(column->getValue(i)->key, pKey) == 0)
		{
			column->pop(i);
			count--;
			return true;
		}
	return false;
}

template<typename Value>
inline Value* HashTable<Value>::getPointer(const char* pKey)
{
	unsigned int index = hashFunction(pKey);

	Stack<HashElement<Value>*>* column = table[index];

	for (int i = 0; i < column->getSize(); i++)
		if (std::strcmp(column->getValue(i)->key, pKey) == 0)
			return &column->getValue(i)->value;
	return nullptr;
}

template<typename Value>
inline void HashTable<Value>::insert(const char* pKey, Value pValue)
{
	unsigned int index = hashFunction(pKey);

	char* newKey = copyline(pKey);

	if (find(newKey))
	{
		set(newKey, pValue);
		return;
	}

	HashElement<Value>* newElement = new HashElement<Value>{ newKey, pValue };


	for (int i = 0; i < table[index]->getSize(); i++)
		if (std::strcmp(table[index]->getValue(i)->key, pKey) == 0)
		{
			table[index]->pop(i);
			break;
		}

	table[index]->appfirst(newElement);
	count++;
}

template<typename Value>
inline bool HashTable<Value>::find(const char* pKey)
{
	unsigned int index = hashFunction(pKey);

	Stack<HashElement<Value>*>* column = table[index];

	for (int i = 0; i < column->getSize(); i++)
	{
		if (std::strcmp(column->getValue(i)->key, pKey) == 0)
			return true;
	}
	return false;
}