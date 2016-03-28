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

//#include"Queue.h"
#include<queue>
#include<stack>

template<class T>
class BinaryTreeNode {
public:
	//Origin function is defined with "friend", couldn't figure out why. So I just use public function member here.
	void Visit();
	void InOrder();
	void PreOrder();
	void PostOrder();
	void LevelOrder();
	void PreOrderWithoutRecrusion();
	void InOrderWithoutRecrusion();
	void PostOrderWithoutRecrusion();

	T getData() { return data; }
	void setData(const T& e) { this->data = e; }
	BinaryTreeNode<T>* getLeftChild() { return leftChild; }
	void setLeftChild(BinaryTreeNode<T>* l) { this->leftChild = l; }
	BinaryTreeNode<T>* getRightChild() { return rightChild; }
	void setRightChild(BinaryTreeNode<T>* r) { this->rightChild = r; }

	//a data must be given when generate a node, otherwise just leave a null pointer.
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
	BinaryTree() { root = nullptr; }
	BinaryTree(const T& element) {
		root = new BinaryTreeNode<T>(element);
	}

	~BinaryTree() {};
	
	BinaryTreeNode<T>* getRoot() { return root; }
	void setRoot(BinaryTreeNode<T>* r) { this->root = r; }
	T getRootData() { return root->getData(); }
	void setRootData(const T& e) { root->setData(e); }
	bool IsEmpty() { return root == 0; }
	bool Root(T& x) const;
	void MakeTree(BinaryTree<T>* left, BinaryTree<T>* right);
	void BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right);
	void PreOrder() { root->PreOrder(); }
	void InOrder() { root->InOrder(); }
	void PostOrder() { root->PostOrder(); }
	void LevelOrder() { root->LevelOrder(); }
	void PreOrderWithoutRecrusion() { root->PreOrderWithoutRecrusion(); }
	void InOrderWithoutRecrusion() { root->InOrderWithoutRecrusion(); }
	void PostOrderWithoutRecrusion() { root->PostOrderWithoutRecrusion(); }
private:
	BinaryTreeNode<T>* root;
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
void 
BinaryTreeNode<T>::LevelOrder()
{
	queue<BinaryTreeNode<T>*> queue;
	BinaryTreeNode<T>* t = this;
	while (t) {
		t->Visit();

		if(t->leftChild) queue.push(t->leftChild);
		if(t->rightChild) queue.push(t->rightChild);

		if (!queue.empty()) {
			t = queue.front();
			queue.pop();
		}
		else break;
	}
}

template<class T>
void
BinaryTreeNode<T>::PreOrderWithoutRecrusion()
{
	stack<BinaryTreeNode<T>*> stack_node;
	BinaryTreeNode<T>* t = this;
	while (t) {
		t->Visit();

		if (t->rightChild) {
			stack_node.push(t->rightChild);
		}

		if (nullptr == (t = t->leftChild)) {
			if (stack_node.empty()) break;
			t = stack_node.top();
			stack_node.pop();
		}
	}
}

template<class T>
void
BinaryTreeNode<T>::InOrderWithoutRecrusion()
{
	stack<BinaryTreeNode<T>*> stack_node;
	BinaryTreeNode<T>* t = this;
	while (!stack_node.empty() || t) {
		//t would always be the rightChild if not null.
		if (t) {
			stack_node.push(t);
			t = t->leftChild;
		}
		else {
			t = stack_node.top();
			t->Visit();
			stack_node.pop();
			t = t->rightChild;
		}
	}
}

template<class T>
void
BinaryTreeNode<T>::PostOrderWithoutRecrusion()
{
	stack<BinaryTreeNode<T>*> stack_node;
	BinaryTreeNode<T>* t = this;
	BinaryTreeNode<T>* pre = nullptr;
	stack_node.push(t);
	while (!stack_node.empty()) {
		t = stack_node.top();
		if ((t->leftChild == nullptr && t->rightChild == nullptr) || (pre != nullptr && (pre == t->leftChild || pre == t->rightChild))) {
			//if left and right children equal to null, visit; if pre != null, whether pre == left or right child, it means the children have been visited both;
			t->Visit();
			stack_node.pop();
			pre = t;
		}
		else {
			if (t->rightChild) {
				stack_node.push(t->rightChild);
			}
			if (t->leftChild) {
				stack_node.push(t->leftChild);
			}
		}
	}
}

template<class T>
inline bool 
BinaryTree<T>::Root(T & x) const
{
	if (root) {
		x = root->data;
		return true;
	}
	return false;
}

template<class T>
inline void 
BinaryTree<T>::MakeTree(BinaryTree<T>* left, BinaryTree<T>* right)
{
	if (left)
		root->setLeftChild(left->getRoot());
	else
		root->setLeftChild(nullptr);
	if (right)
		root->setRightChild(right->getRoot());
	else
		root->setRightChild(nullptr);
}

template<class T>
inline void 
BinaryTree<T>::BreakTree(T & element, BinaryTree<T>& left, BinaryTree<T>& right)
{
	if (!root) throw BadInput();

	element = root->getData();
	left->setRoot(root->getLeftChild());
	right->setRoot(root->getRightChild());

	delete root;
}
