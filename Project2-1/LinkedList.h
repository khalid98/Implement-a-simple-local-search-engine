#pragma once
#include "Node.h"
#include <assert.h>
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedList 
{
private:
	Node<ItemType>* headPtr; // Pointer to first node in the chain;
	int itemCount;           // Current count of list items 

	Node<ItemType>* getNodeAt(int position) const;
public:
	LinkedList();
	~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();

	/** @throw PrecondViolatedExcept if position < 0 or
	position > getLength(). */
	ItemType getEntry(int position) const;//throw(PrecondViolatedExcept);

	/** @throw PrecondViolatedExcept if position < 0 or
	position > getLength(). */
	void setEntry(int position, const ItemType& newEntry);
//		throw(PrecondViolatedExcept);

	void LinkedList<ItemType>::print() const;
}; // end LinkedList

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
} // end destructor


template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
} // end clear

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 0) && (position < itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 0)
		{
			// Remove the first node in the chain
			curPtr = headPtr; // Save pointer to node
			headPtr = headPtr->getNext();
		}
		else
		{
			// Find node that is before the one to remove
			Node<ItemType>* prevPtr = getNodeAt(position - 1);

			// Point to node to remove
			curPtr = prevPtr->getNext();

			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prevPtr->setNext(curPtr->getNext());
		} // end if

		  // Return node to system
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
		itemCount--; // Decrease count of entries
	} // end if

	return ableToRemove;
} // end remove


template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
//throw(PrecondViolatedExcept)
{
	// Enforce precondition
	bool ableToGet = (position >= 0) && (position < itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}/*
	else {
		string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		return message;
	}*/
/*	else
	{
		std::string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcept(message));
	}*/ // end if
} // end getEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	// Debugging check of precondition
	assert((position >= 0) && (position < itemCount));

	// Count from the beginning of the chain
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 0; skip < position; skip++)
		curPtr = curPtr->getNext();

	return curPtr;
}  // end getNodeAt

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 0) && (newPosition <= itemCount );
	if (ableToInsert)
	{
		// Create a new node containing the new entry
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		// Attach new node to chain
		if (newPosition == 0)
		{
			// Insert new node at beginning of chain
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			// Find node that will be before new node
			Node<ItemType>* prevPtr = getNodeAt(newPosition-1);

			// Insert new node after node to which prevPtr points
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		} // end if

		itemCount++; // Increase count of entries
	}  // end if

	return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}  // end getLength

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
	// Enforce precondition
	bool ableToSet = (position >= 0) && (position < itemCount);
	if (ableToSet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		nodePtr->setItem(newEntry);
	}
	else
	{
		std::string message = "setEntry() called with an empty list or ";
		message = message + "invalid position.";
		std::cerr << message << std::endl;
	} // end if
}  // end setEntry

template<class ItemType>
void LinkedList<ItemType>::print() const
{
	cout << "List contains: ";
	Node<ItemType>* curPtr = headPtr;

	while (curPtr->getNext() != nullptr) {
		cout << curPtr->getItem() << ", ";
		curPtr = curPtr->getNext();
	}
	cout << curPtr->getItem() << endl;
	
}//end print
