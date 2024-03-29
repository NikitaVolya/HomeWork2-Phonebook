#pragma once

#include <iostream>

template <typename Value>
struct StackElement
{
	Value val;
	StackElement<Value>* next;
};

template <typename Value>
class StackP
{
private:
	StackElement<Value>* firstElement;
	int size;
	bool deleteValues;

	void deleteElement(StackElement<Value>* element);
public:
	StackP(bool pDeleteValues = false) : firstElement(nullptr), size(0), deleteValues(pDeleteValues) {};
	~StackP();

	int getSize() { return size; }

	void appfirst(Value pValue);
	void popfirst();

	StackElement<Value>* getElement(int index);
};

template<typename Value>
inline void StackP<Value>::deleteElement(StackElement<Value>* element)
{
	if (deleteValues)
		delete element->val;
	delete element;
}

template<typename Value>
inline StackP<Value>::~StackP()
{
	StackElement<Value>* element = firstElement;
	while (element)
	{
		StackElement<Value>* tmp = element;
		element = element->next;
		
		deleteElement(tmp);
	}
}

template<typename Value>
inline void StackP<Value>::appfirst(Value pValue)
{
	StackElement<Value>* tmp = new StackElement<Value>{ pValue, nullptr };

	if (firstElement)
		tmp->next = firstElement;
	firstElement = tmp;

	size++;
}

template<typename Value>
inline void StackP<Value>::popfirst()
{
	if (!firstElement)
		return;

	StackElement<Value>* tmp = firstElement;
	firstElement = firstElement->next;
	deleteElement(tmp);
}

template<typename Value>
inline StackElement<Value>* StackP<Value>::getElement(int index)
{
	if (size <= index || index < 0)
		return nullptr;

	StackElement<Value>* element = firstElement;
	while (index--)
		element = element->next;

	return element;
}
