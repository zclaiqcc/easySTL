/** BinaryTree.h
 * Create a BinaryTree with template<T> and define some common methods.
 * main.cpp is just used for easy testing.
 * Author: zclaiqcc
 * Blog: zclaiqcc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */
#pragma once

#include"BinaryTree.h"

//Why E & K?
template<class E, class K>
class BSTree : public BinaryTree<E> {
public :
	bool Search(const K& k, E& e) const;
	BSTree<E, K>& Insert(const E& e);
	BSTree<E, K>& Delete(const K&, E& e);
	void Ascend() { this->InOrder(); }
};

template<class E, class K>
bool
BSTree<E, K>::Search(const K & k, E & e)  const
{
	BinaryTreeNode<E>* t = this->root;
	while (t) {
		if (k < t->getData()) t = t->getLeftChild();
		else if (k > t->getData()) t = t->getRightChild();
		else { e = t->getData(); return true; }
	}
	return false;
}

template<class E, class K>
BSTree<E, K>&
BSTree<E, K>::Insert(const E & e)
{
	BinaryTreeNode<E>* new_node = BinaryTreeNode<E>(e);
	if (root) { root = new_node; return *this; }
	BinaryTreeNode<E>* t = root;
	BinaryTreeNode<E>* pre = nullptr;
	while (t) {
		if (e < t->getData()) { pre = t; t = t->getLeftChild(); }
		else if (e > t->getData()) { pre = t; t = t->getLeftChild(); }
		else throw BadInput();
	}
	
	if (e < pre->getData()) { pre->setLeftChild(new_node); }
	else pre->setRightChild(new_node);

	return *this;
}

template<class E, class K>
BSTree<E, K>&
BSTree<E, K>::Delete(const K &, E & e)
{
	BinaryTreeNode<E>* t = root;
	BinaryTreeNode<E>* pre = nullptr;
	//Search for k.
	while (t && t->getData() != k) {
		pre = t;
		if (k < t->getData()) t = t->getLeftChild();
		else t = t->getRightChild();
	}
	if (!t) throw BadInput();

	//Delete k.
	if (!t->getLeftChild() || !t->getRightChild()) {
		if (!t->getLeftChild()) pre->setRightChild(t->getRightChild();
		else if (!t->getRightChild()) pre->setLeftChild(t->getLeftChild());
		e = t->getData();
		delete t;
	}
	else {
		BinaryTreeNode<E>* t_t = t;
		BinaryTreeNode<E>* pre_t = nullptr;
		while (t_t->getRightChild()) {
			pre_t = t_t;
			t_t = t_t->getRightChild();
		}
		pre_t->setRightChild(t_t->getLeftChild());
		t->setData(t_t->getData());
		e = t->getData();
		delete t_t;
	}

	return *this;
}
