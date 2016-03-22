/** BinaryTree.h
 * Create a BinaryTree with template<T> and define some common methods.
 * main.cpp is just used for easy testing.
 * Author: zclaiqcc
 * Blog: zclaiqcc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include"Queue.h"

template<class T>
class BinaryTreeNode {
public:
	//Origin function is defined with "friend", couldn't figure out why. So I just use public function member here.
	void Visit();
	void InOrder();
	void PreOrder();
	void PostOrder();
	void LevelOrder();

	BinaryTreeNode() { leftChild = rightChild = nullptr; }
	BinaryTreeNode(const T& e, BinaryTreeNode<T>* l = nullptr, BinaryTreeNode<T>* r = nullptr) {
		data = e;
		leftChild = l;
		rightChild = r;
	}
private:
	T data;
	BinaryTreeNode<T>* leftChild;
	BinaryTreeNode<T>* rightChild;
};

template<class T>
class BinaryTree {
public:

private:

};

#endif

template<class T>
inline void 
BinaryTreeNode<T>::Visit()
{
	cout << this->data << " ";
}

template<class T>
inline void 
BinaryTreeNode<T>::InOrder()
{
	if (this) {
		leftChild->InOrder();
		this->Visit();
		rightChild->InOrder();
	}
}

template<class T>
inline void 
BinaryTreeNode<T>::PreOrder()
{
	if (this) {
		Visit();
		leftChild->PreOrder();
		rightChild->PreOrder();
	}
}

template<class T>
inline void 
BinaryTreeNode<T>::PostOrder()
{
	if (this) {
		leftChild->PostOrder();
		rightChild->PostOrder();
		Visit();
	}
}

template<class T>
inline void 
BinaryTreeNode<T>::LevelOrder()
{
	Queue<BinaryTreeNode<T>*> queue;
	BinaryTreeNode<T>* t = this;
	while (t) {
		t->Visit();

		if(t->leftChild) queue.Add(t->leftChild);
		if(t->rightChild) queue.Add(t->rightChild);

		if (!queue.IsEmpty()) queue.Delete(t);
	}
}
