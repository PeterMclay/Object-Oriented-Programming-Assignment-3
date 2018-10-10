#pragma once
#pragma once
#include "MatchCard.h"

const int DEFAULT_SIZE = 10;
template <class T>
class Queue
{
public:
	Queue(unsigned int capacity = DEFAULT_SIZE);
	~Queue();
	bool isEmpty();	//checks if queueu is empty
	bool isFull() const;	//checks if queue is full
	void enqueue(T k);	//adds element to queue
	T dequeue();	//removes element from queue
	T peek()const;
private:
	int m_front;	//shows front of queue
	int m_rear;    //shows rear of queue	
	int m_size;    //shows size of queue
	int m_capacity;	  // shows capacity of queueu
	T *m_container;   //Queue which is an array
};

template <class T>
Queue<T>::Queue(unsigned int capacity)	//constructor sets positions and creates array of size capacity
{
	m_size = 0;
	m_front = -1;
	m_rear = -1;
	m_capacity = capacity;
	m_container = new T[capacity];
}
template <class T>
Queue<T>::~Queue()	//destructor
{
	delete[]m_container;
}

template<class T>
bool Queue<T>::isEmpty()	//checks if empty
{
	if (m_size == 0)
	{
		m_front = -1;
		m_rear= -1;
		return 1;
	}
	else
		return 0;
}
template<class T>
bool Queue<T>::isFull()const	//checks if full
{
	if (m_size == m_capacity)
		return 1;
	else
		return 0;
}
template<class T>
void Queue<T>::enqueue(T k)	//adds element k to rear of queueu
{
	if (m_front == -1 && m_rear == -1)
	{
		m_front = 0;
		m_rear = 0;
	}
	else
	{
		m_rear++;
	}
	m_container[m_rear] = k;
	m_size++;
}
template <class T>
T Queue<T>::dequeue()	//removes element from queue
{
	int place_holder = m_front;
	m_front++;
	m_size--;
	return m_container[place_holder];
}
template <class T>
T Queue<T>::peek()const	//looks at front element in queue
{
	return m_container[m_front];
}
