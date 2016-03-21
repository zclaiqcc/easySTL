/** LinearList.h
 * Create a linearList with template<T> and define some common methods.
 * Author: zclaiqcc
 * Blog: zclaiqcc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_

#include<iostream>
#include"Exceptions.h"

template<class T>
class LinearList {
public:
	LinearList(int MaxListSize = 10);
	~LinearList() {	delete[] element; }
	bool IsEmpty() { return 0 == length; }
	int Length() const { return length; }
	bool Find(int k, T& x) const; // put No.k into x
	int Search(const T& x) const; // return the position of x
	LinearList<T>& Delete(int k, T& x); // delete No.k and put it into x
	LinearList<T>& Insert(int k, const T& x);// insert after k
	void Output(std::ostream& out) const;

	template<class T>
	friend std::ostream& operator << (std::ostream& out, const LinearList<T>& x);

private:
	int length;
	int maxSize;
	T* element;
};

template<class T>
LinearList<T>::LinearList(int MaxListSize) {
	this->maxSize = MaxListSize;
	this->element = new T[MaxListSize];
	this->length = 0;
}

template<class T>
bool
LinearList<T>::Find(int k, T & x) const
{
	if (k < 1 || k > length) return false;
	x = this->element[k - 1];
	return false;
}

template<class T>
int 
LinearList<T>::Search(const T & x) const
{
	for (int i = 0; i < length; i++) {
		if (this->element[i] == x) {
			return i + 1;
		}
	}
	return 0;
}

template<class T>
LinearList<T>& 
LinearList<T>::Delete(int k, T & x)
{
	if (Find(k, x)) {
		for (int i = k; i < length; i++) {
			this->element[i - 1] = this->element[i];
		}
		this->length--;
		return *this;
	}
	else throw OutOfBounds();
}

template<class T>
LinearList<T>& 
LinearList<T>::Insert(int k, const T & x)
{
	if (k < 0 || k > length) throw OutOfBounds();
	if (length == maxSize) throw NoMem();
	for (int i = length - 1; i >= k; i--) {
		this->element[i + 1] = this->element[i];
	}
	this->element[k] = x;
	length++;
	return *this;
}

template<class T>
void 
LinearList<T>::Output(std::ostream & out) const
{
	for (int i = 0; i < length; i++) {
		out << this->element[i] << " ";
	}
}

template<class T>
std::ostream & operator<<(std::ostream& out, const LinearList<T>& x)
{
	x.Output(out);
	return out;
}


#endif