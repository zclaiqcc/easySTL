/** main.cpp
 * An easy version STL. Refer to <<Data Structures and Applications in C++>>
 * main.cpp is just used for easy testing.
 * Author: zclaiqcc
 * Blog: zclaiqcc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#include<iostream>
#include"Sort.h"
#include"LinearList.h"
#include"Chain.h"

using namespace std;

int main() {
	Chain<int> chain;
	chain.Insert(0, 4).Insert(1, 3);
	int x;
	chain.Delete(1, x);
	cout << chain << " " << x << endl;

	//LinearList<int> linearList(3);
	
	//linearList.Insert(0, 2).Insert(1, 3);
	//linearList.Output(cout);
	//cout << linearList << endl;

	//Sort sort;
	//vector<int> vec = { 2, 3, 1, 9, 4, 5, 8, 6, 7 };

	//sort.SelectSort(vec);
	//sort.BubbleSort(vec);

	//for each (auto var in vec){
	//	cout << var << " ";
	//}
	//cout << endl;

	return 0;
}