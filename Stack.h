/** Stack.h
 * A limited LinearList
 * Author: zclaiqcc
 * Blog: zclaiqcc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#ifndef _STACK_H_
#define _STACK_H_

#include"Exceptions.h"

template<class T>
class Stack {
public:
	Stack(int MaxStackSize = 10);
	~Stack() { delete[] stack; }
	bool IsEmpty() { return -1 == top; }
	bool IsFull() { return top == MaxTop; }
	T Top() const;
	Stack<T>& Add(T& x);
	Stack<T>& Delete(T& x);
private:
	int top;
	int MaxTop;
	T* stack;
};


//something wrong with the inherit, I'll fix it later.
//#include"LinearList.h"

//template<class T>
//class Stack : private LinearList<T> {
//	//Last In First Out
//public:
//	Stack(int MaxStackSize = 10) : LinearList<T>(MaxStackSize) {}
//};

#endif

template<class T>
inline Stack<T>::Stack(int MaxStackSize)
{
	top = -1;
	MaxTop = MaxStackSize;
	stack = new T[MaxStackSize];
}

template<class T>
inline T 
Stack<T>::Top() const
{
	if (IsEmpty()) throw OutOfBounds();
	else return stack[top];
}

template<class T>
inline Stack<T>& 
Stack<T>::Add(T & x)
{
	if (IsFull()) throw NoMem();
	stack[++top] = x;
	return *this;
}

template<class T>
inline Stack<T>& 
Stack<T>::Delete(T & x)
{
	if (IsEmpty()) throw OutOfBounds();
	else x = stack[top--];
	return *this;
}
