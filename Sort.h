/** Sort.h
 * An easy version of Sort by asc. Only for vector<int>.
 * Author: zclaiqcc
 * Blog: zclaiqcc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#ifndef _EASYSTL_H_
#define _EASYSTL_H_

#include<vector>

using namespace std;

class Sort {
public:
	void BubbleSort(vector<int>& vec) {
		size_t size = vec.size();
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				Swap(vec[j], vec[j + 1]);
			}
		}
	}

	void SelectSort(vector<int>& vec) {
		size_t size = vec.size();
		for (int i = 0; i < size; i++) {
			int min = i;
			for (int j = i; j < size; j++) {
				if (Compare(vec[min], vec[j])) {
					min = j;
				}
			}
			Swap(vec[i], vec[min]);
		}
	}
	


private:
	bool Compare(int& num1, int& num2) {
		if (num1 > num2) {
			return true;
		}
		else {
			return false;
		}
	}

	void Swap(int& num1, int& num2) {
		if (Compare(num1, num2)) {
			int temp = num1;
			num1 = num2;
			num2 = temp;
		}
	}
};

#endif