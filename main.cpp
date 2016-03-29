/** main.cpp
 * An easy version STL. Refer to <<Data Structures and Applications in C++>>
 * main.cpp is just used for easy testing.
 * Author: zclaiqcc
 * Blog: zclaiqcc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#include"Sort.h"
#include"LinearList.h"
#include"Chain.h"
#include"Stack.h"
#include"BinaryTree.h"

using namespace std;

int main() {
	//BinaryTree<char> binaryTree_a('A');

	//BinaryTree<char>* leftchild_b = new BinaryTree<char>('B');
	//BinaryTree<char>* rightchild_c = new BinaryTree<char>('C');
	//binaryTree_a.MakeTree(leftchild_b, rightchild_c);

	//BinaryTree<char>* rightchild_d = new BinaryTree<char>('D');
	//leftchild_b->MakeTree(nullptr, rightchild_d);

	//BinaryTree<char>* rightchild_e = new BinaryTree<char>('E');
	//rightchild_c->MakeTree(nullptr, rightchild_e);

	//BinaryTree<char>* leftchild_f = new BinaryTree<char>('F');
	//BinaryTree<char>* rightchild_g = new BinaryTree<char>('G');
	//rightchild_d->MakeTree(leftchild_f, rightchild_g);

	//BinaryTree<char>* rightchild_h = new BinaryTree<char>('H');
	//rightchild_e->MakeTree(nullptr, rightchild_h);

	//leftchild_f->MakeTree(nullptr, nullptr);
	//rightchild_g->MakeTree(nullptr,nullptr);

	//binaryTree_a.PostOrderWithoutRecrusion();
	
	//Stack<int> stack;
	//stack.IsEmpty();

	//Chain<int> chain;
	//chain.Insert(0, 4).Insert(1, 3);
	//int x;
	//chain.Delete(1, x);
	//cout << chain << " " << x << endl;

	//LinearList<int> linearList(3);
	
	//linearList.Insert(0, 2).Insert(1, 3);
	//linearList.Output(cout);
	//cout << linearList << endl;

	Sort sort;
	vector<int> vec = { 2, 3, 1, 9, 4, 5, 8, 6, 7 };

	//sort.SelectSort(vec);
	//sort.BubbleSort(vec);
	//sort.MergeSort(vec);
	//sort.QuickSort(vec, 0, vec.size() - 1);
	sort.ShellSort(vec);

	for each (auto var in vec){
		cout << var << " ";
	}
	cout << endl;

	return 0;
}