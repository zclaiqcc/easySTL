/** Queue.h
 * One kind of LinearList
 * Author: zclaiqcc
 * Blog: zclaiqcc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include"Exceptions.h"

template<class T>
class Queue {
	//First In First Out
public:
	Queue(int MaxQueueSize = 10);
	~Queue() { delete[] queue; }
	bool IsEmpty() const { return front == rear; }
	bool IsFull() const { return front == (rear + 1) % MaxSize; }
	T First() const;
	T Last() const;
	Queue<T>& Add(T* x);
	Queue<T>& Delete(T& x);

private:
	int front;
	int rear;
	int MaxSize;
	T* queue;
};

#endif

template<class T>
inline Queue<T>::Queue(int MaxQueueSize)
{
	MaxSize = MaxQueueSize + 1; // to ensure the maxLen is really the maxLen, instead of maxLen - 1, for IsEmpty() would have the same condition with IsFull()
	queue = new T[MaxSize];
	front = rear = 0;
}

template<class T>
inline T 
Queue<T>::First() const
{
	if (IsEmpty()) throw OutOfBounds();
	else return queue[(front + 1) % MaxSize];
}

template<class T>
inline T 
Queue<T>::Last() const
{
	if (IsEmpty()) throw OutOfBounds();
	else return queue[rear];
}

template<class T>
inline Queue<T>& 
Queue<T>::Add(T * x)
{
	if (IsFull()) throw NoMem();
	rear = (rear + 1) % MaxSize;
	queue[rear] = x;
	return *this;
}

template<class T>
inline Queue<T>& 
Queue<T>::Delete(T & x)
{
	if (IsEmpty()) throw OutOfBounds();
	front = (front + 1) % MaxSize;
	x = queue[front];
	return *this;
}