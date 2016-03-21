/** Chain.h
 * Create a Chain with template<T> and define some common methods.
 * Author: zclaiqcc
 * Blog: zclaiqcc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#ifndef _CHAIN_H_
#define _CHAIN_H_

#include<iostream>
#include"Exceptions.h"

template<class T>
class Chain;

template<class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data;
	ChainNode<T>* next;
};

template<class T>
class Chain {
public:
	Chain() { head = 0; }
	~Chain() { this->Erase(); }
	bool IsEmpty() const { return nullptr == head; }
	int Length() const;//or maintain a length value to get length more efficientlly.
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T& x);
	void Erase();
	void Output(std::ostream& out) const;

	template<class T>
	friend std::ostream& operator<<(std::ostream& out, const Chain<T>& x);
private:
	ChainNode<T>* head;
};

#endif

template<class T>
inline void 
Chain<T>::Erase()
{
	ChainNode<T>* next = head;
	while (head) {
		next = head->next;
		delete head;
		head = next;
	}
}

template<class T>
inline int 
Chain<T>::Length() const
{
	int length = 0;
	ChainNode<T>* current = head;
	while (current) {
		length++;
		current = current->next;
	}
	return length;
}

template<class T>
inline bool 
Chain<T>::Find(int k, T & x) const
{
	if (k < 1) { return false; }
	ChainNode<T>* current = head;
	while (k-- && current) {
		current = current->next;
	}
	if (current) {
		x = current->data;
		return true;
	}
	return false;
}

template<class T>
inline int 
Chain<T>::Search(const T & x) const
{
	int index = 1;
	ChainNode<T>* current = head;
	while (current) {
		if (x == current->data)
			return index;
		current = current->next;
		index++;
	}
	if (current) return index;
	return 0;
}

template<class T>
inline Chain<T>& 
Chain<T>::Delete(int k, T & x)
{
	if (k < 1) { throw OutOfBounds(); }
	ChainNode<T>* before = head;
	if (k == 1) { 
		head = head->next; 
		x = before->data;
		delete before;
		return *this;
	}
	while (--k > 1 && before) {
		before = before->next;
	}
	if (before) {
		x = before->next->data;
		ChainNode<T>* temp = before;
		before = before->next;
		temp = before->next;
	}
	delete before;
	return *this;
}

template<class T>
inline Chain<T>& 
Chain<T>::Insert(int k, const T & x)
{
	if (k < 0) { throw OutOfBounds(); }
	ChainNode<T>* current = head;
	ChainNode<T>* inserted = new ChainNode<T>();
	inserted->data = x;
	
	if (k == 0) {
		head = inserted;
		head->next = current;
	}
	while (--k && current) {
		current = current->next;
	}
	if (current) {
		inserted->next = current->next;
		current->next = inserted;
	}
	return *this;
}

template<class T>
inline void 
Chain<T>::Output(std::ostream & out) const
{
	ChainNode<T>* current = head;
	while (current) {
		out << current->data << " ";
		current = current->next;
	}
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x) {
	x.Output(out);
	return out;
}