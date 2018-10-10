#pragma once
#include "List.h"
#include "Functors.h"
#include "MatchCard.h"
#include "Queue.h"
template <class T, class Order = IsLess>
class OrderedList {
private:
	List<T> container;	//array of list
public:
	OrderedList(unsigned capacity = DEFAULT_LIST);
	~OrderedList();
	bool isEmpty() const;	//checks if empty
	int getLength() const;	//checks if full
	T remove(int pos);	//removes element
	T retrieve(int pos) const;	//shows element
	int insert(T item);	//inserts element
	int find(T item) const;	//calls functor function to sort elements 
};

template<class T, class Order>
inline OrderedList<T, Order>::OrderedList(unsigned capacity)	//constructor
	:container(capacity)
{
}

template<class T, class Order>
inline OrderedList<T, Order>::~OrderedList()	//destructor
{
}

template<class T, class Order>
inline bool OrderedList<T, Order>::isEmpty() const	//calls list isempty
{
	return container.isEmpty();
}

template<class T, class Order>
inline int OrderedList<T, Order>::getLength() const	//calls list get length
{
	return container.getLength();
}

template<class T, class Order>
inline T OrderedList<T, Order>::remove(int pos)	//calls list remove
{
	return container.remove(pos);
}

template<class T, class Order>
inline T OrderedList<T, Order>::retrieve(int pos) const	//calls list retrieve
{
	return container.retrieve(pos);
}

template<class T, class Order>
inline int OrderedList<T, Order>::insert(T item)	//returns position of first occurence of T, returns -1 if item isnt found
{
	int k;
	for (k = 1; k <= getLength(); k++)
	{
		if (Order::compare(item, retrieve(k)))
			break;
	}
	container.insert(k, item);
	return k;
}

template<class T, class Order>
inline int OrderedList<T, Order>::find(T item) const	//used to compare to order list
{
	int k;
	for (k = 1; k <= getLength(); k++)
	{
		if (!(Order::compare(item, retrieve(k))) && !(Order::compare(retrieve(k), item)))
		{
			return k;
		}
	}
	return -1;
}
