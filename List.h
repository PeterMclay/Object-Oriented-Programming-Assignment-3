#pragma once
#include "Functors.h"
#include "MatchCard.h"
#include "Queue.h"
const int DEFAULT_LIST = 200;
template <class T>
class List
{
public:
	List(unsigned capcity = DEFAULT_LIST);
	~List();
	bool isEmpty() const;
	bool isFull() const;
	int getLength() const;
	void insert(int pos, T item);
	T remove(int pos);
	T replace(int pos, T item);
	T retrieve(int pos) const;
	void swap(int i, int j);
private:
	T *container;
	int max_capacity;
	int size;
	inline unsigned translate(unsigned pos) const { return pos - 1; } //converts a list position to the corresponding array index
	void replaceContainer();
};

template<class T>
inline List<T>::List(unsigned capcity)	//creates empty list of capacity
{
	max_capacity = capcity;
	container = new T[max_capacity];
	size = 0;
}

template<class T>
inline List<T>::~List() //destrctor
{
	//delete[] container;
}

template<class T>
inline bool List<T>::isEmpty() const //checks if empty
{
	if (size == 0)
	{
		cout << "List is Empty" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class T>
inline bool List<T>::isFull() const //checks if full (not needed since capacity increases once full)
{
	return false;
}

template<class T>
inline int List<T>::getLength() const //prints length of list
{
	return size;
}

template<class T>
inline void List<T>::insert(int pos, T item)	//inserts item into lis at location pos
{
	if (pos < 1 && pos >(size + 1))	//pos must be between 1 and size + 1

	{
		cout << "Cannot insert element" << endl;
		return;
	}
	if (size == max_capacity)
	{
		replaceContainer();
	}
	for (int k = size; k >= pos; k--)
	{
		container[translate(k + 1)] = container[translate(k)];
	}
	container[translate(pos)] = item;
	size++;
}

template<class T>
inline T List<T>::remove(int pos)	//removes item in list a location pos
{
	T returnValue = container[translate(pos)];
	for (int k = pos + 1; k <= size; k++)
	{
		container[translate(k - 1)] = container[translate(k)];
	}
	size--;
	return returnValue;
}

template<class T>
inline T List<T>::replace(int pos, T item) //replaces value at location pos with item
{
	T returnVal = container[translate(pos)];
	container[translate(pos)] = item;
	return returnVal;
}

template<class T>
inline T List<T>::retrieve(int pos) const //retrieves item at location pos
{
	return container[translate(pos)];
}

template<class T>
inline void List<T>::swap(int i, int j) //swaps items at location i and j
{
	T temp = container[translate(i)];
	container[translate(i)] = container[translate(j)];
	container[translate(j)] = temp;
}

template<class T>
inline void List<T>::replaceContainer() //private function, is called when size == capacity to create new list of double capacity
{
	T *newList;
	newList = new T[2 * max_capacity];
	for (int i = 0; i < size; i++)
	{
		newList[i] = container[i];
	}
	max_capacity = 2 * max_capacity;
	delete[] container;
	container = newList;
}
