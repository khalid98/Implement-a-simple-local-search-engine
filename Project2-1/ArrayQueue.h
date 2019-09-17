#pragma once

#pragma warning( disable : 4290 ) 
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayQueue
{
private:
	static const int DEFAULT_CAPACITY = 50;
	ItemType items[DEFAULT_CAPACITY]; // Array of queue items
	int front;                 // Index to front of queue
	int back;                  // Index to back of queue
	int count;                 // Number of items currently in the queue

public:
	ArrayQueue();
	// Copy constructor and destructor supplied by compiler
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();

	/** @throw PrecondViolatedExcept if queue is empty. */
	ItemType peekFront() const throw(PrecondViolatedExcept);
}; // end ArrayQueue

/** ADT queue: Circular array-based implementation.*/

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(DEFAULT_CAPACITY - 1), count(0)
{
} // end default constructor

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
	return count == 0;
} // end isEmpty

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	bool result = false;
	if (count < DEFAULT_CAPACITY)
	{
		// Queue has room for another item
		back = (back + 1) % DEFAULT_CAPACITY;
		items[back] = newEntry;
		count++;
		result = true;
	} // end if

	return result;
} // end enqueue

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		front = (front + 1) % DEFAULT_CAPACITY;
		count--;
		result = true;
	} // end if

	return result;
} // end dequeue

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept)
{
	// Enforce precondition
	if (isEmpty())
		throw PrecondViolatedExcept("peekFront() called with empty queue");

	// Queue is not empty; return front
	return items[front];
} // end peekFront

