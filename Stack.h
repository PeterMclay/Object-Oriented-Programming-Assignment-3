#pragma once
#include "MatchCard.h"
#include "MatchGame.h"
#include "Queue.h"
const int DEFAULT_STACK = 20;
template <class T>
class Stack
{
public:
	Stack(unsigned int capacity = DEFAULT_STACK);
	~Stack();
	void push(T k);	//pushes element into stack
	T pop();	//takes element out
	T peek() const; //peeks at front element
	bool isEmpty() const;	//checks if stack is empty
	bool isFull() const;	//checks if stack is full
	int getfront() { return front; }	//returns the value of front
private:
	int front = -1;	//shows where front of stack is
	T *container;	//array 
	int _capacity;	//size of container array
};

template<class T>
inline Stack<T>::Stack(unsigned int capacity)	//Constructor 
{
	_capacity = capacity;	//sets capacity
	container = new T[capacity];	//sets container

}

template<class T>
inline Stack<T>::~Stack()
{
	//delete[] container;	//Program crashes if uncommented -> Dont need it 
}

template<class T>
void Stack<T>::push(T k) //adds element into stack
{
	if (isFull() == 1)	//will go to is full function which will increase the capacity if needed. if not it will return 0
	{
		front++;
	}
	else if (isEmpty() == 1)	//if stack is empty set front to position 0
	{
		front = 0;
	}
	else
	{
		front++;	//increment front everytime element is added
	}
	container[front] = k;	//add element k into position fron 
}

template<class T>
inline T Stack<T>::pop()
{
	int place_holder = front;	//place holder for front
	front--;	//decreases where front is positioned
	return (container[place_holder]);	//returns the element at place holder
}

template<class T>
inline T Stack<T>::peek() const
{
	return (container[front]);	//returns element at position front
}

template<class T>
inline bool Stack<T>::isEmpty() const
{
	if (front == -1) //if front =1 then it is empty
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class T>
inline bool Stack<T>::isFull() const	//passing in MazRank * 4 to constructor therefor stack should never be full
{
	if ((front + 1) == _capacity)
	{
		return 1; //Should never be used since stack will always be initialized with large enough capacity
	}
	else
	{
		return 0;
	}
}

