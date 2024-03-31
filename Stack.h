#pragma once

template <typename Value>
struct StackElement
{
	Value val;
	StackElement<Value>* next;
};

template <typename Value>
class Stack
{
private:
	StackElement<Value>* firstElement;
	int size;
public:
	Stack() : firstElement(nullptr), size(0) {};
	~Stack();

	int getSize() { return size; }

	void appfirst(Value pValue);
	void popfirst();

	void pop(int index);

	Value getValue(int index);
};

template<typename Value>
Stack<Value>::~Stack()
{
	StackElement<Value>* element = firstElement;
	while (element)
	{
		StackElement<Value>* tmp = element;
		element = element->next;

		delete tmp;
	}
}

template<typename Value>
void Stack<Value>::appfirst(Value pValue)
{
	StackElement<Value>* tmp = new StackElement<Value>{ pValue, nullptr };

	if (firstElement)
		tmp->next = firstElement;
	firstElement = tmp;

	size++;
}

template<typename Value>
void Stack<Value>::popfirst()
{
	if (!firstElement)
		return;

	StackElement<Value>* tmp = firstElement;
	firstElement = firstElement->next;
	delete tmp;

	size--;
}

template<typename Value>
inline void Stack<Value>::pop(int index)
{
	if (size <= index || index < 0)
		return;

	StackElement<Value>* element = firstElement;
	StackElement<Value>* elementNext = firstElement;
	while (index--)
	{
		element = elementNext;
		elementNext = element->next;
	}

	if (element == elementNext)
	{
		firstElement = element->next;
		delete element;
	}
	else
	{
		element->next = elementNext->next;
		delete elementNext;
	}

	size--;
}

template<typename Value>
Value Stack<Value>::getValue(int index)
{
	index = index < 0 ? 0 : index;

	StackElement<Value>* element = firstElement;
	while (index-- && element)
		element = element->next;

	return element->val;
}