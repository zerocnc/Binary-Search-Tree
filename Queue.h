// For NULL
#include <stddef.h>
#pragma once

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>* next;
};

template<class ItemType>
class Queue
{
public:
	Queue();
	~Queue();
	void MakeEmpty();
	void Enqueue(ItemType);
	void Dequeue(ItemType&);
	bool IsFull() const;
	bool IsEmpty() const;

private:
	NodeType<ItemType>* qFront;
	NodeType<ItemType>* qRear;
};

template<class ItemType>
Queue<ItemType>::Queue()
{
	qFront = NULL;
	qRear = NULL;
}

template<class ItemType>
Queue<ItemType>::~Queue()
{
	MakeEmpty();
}

template<class ItemType>
void Queue<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* tempPtr;

	while (qFront != NULL)
	{
		tempPtr = qFront;
		qFront = qFront->next;
		delete tempPtr;
	}
	qFront = NULL;
}

template<class ItemType>
void Queue<ItemType>::Enqueue(ItemType newItem)
{
	NodeType<ItemType>* newNode;

	newNode = new NodeType<ItemType>;
	newNode->info = newItem;
	newNode->next = NULL;

	if (qRear == NULL)
		qFront = newNode;
	else
		qRear->next = newNode;

	qRear = newNode;

}

template<class ItemType>
void Queue<ItemType>::Dequeue(ItemType& item)
{
	NodeType<ItemType>* tempPtr;

	tempPtr = qFront;
	item = qFront->info;
	qFront = qFront->next;

	if (qFront == NULL)
		qRear = NULL;
	delete tempPtr;
}

template<class ItemType>
bool Queue<ItemType>::IsFull() const
{
	NodeType<ItemType>* ptr;

	ptr = new NodeType<ItemType>;

	if (ptr == NULL)
	{
		return true;
	}
	else
	{
		delete ptr;
		return false;
	}
}

template<class ItemType>
bool Queue<ItemType>::IsEmpty() const
{
	return (qFront == NULL);
}
