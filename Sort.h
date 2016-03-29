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
	
	void MergeSort(vector<int>& vec) {
		//can be advanced to natural merge sort. Note here.
		size_t size = vec.size();
		vector<int> vec_merge(9);
		int s = 1;
		while (s < size) {
			MergePass(vec, vec_merge, s, size);
			s += s;
			MergePass(vec_merge, vec, s, size);
		}
	}

	void QuickSort(vector<int>& vec, int l, int r) {
		if (l >= r) { return; }
		int i = l;
		int j = r;

		int pivot = vec[i++];
		while (1) {
			while (i < r && vec[i] < pivot) {
				i++;
			}
			while (j > l && vec[j] > pivot) {
				j--;
			}
			if (i >= j) break;
			else {
				Swap(vec[i], vec[j]);
			}
		}
		vec[l] = vec[j];
		vec[j] = pivot;
		QuickSort(vec, l, j - 1);
		QuickSort(vec, j + 1, r);
	}

	void ShellSort(vector<int>& vec) {
		int gap = vec.size() / 2;
		int i;
		int j;
		while (gap) {
			for (i = 0; i < vec.size();i++) {
				int min = i;
				for (j = i; j < vec.size(); j += gap) {
					if (vec[j] < vec[min])
						min = j;
				}
				if (i != j) {
					Swap(vec[i], vec[min]);
				}
			}
			gap = gap / 2;
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
	
	void MergePass(vector<int>& vec1, vector<int>& vec2, int s, int n) {
		int i = 0;
		while (i < n - 2 * s) {
			Merge(vec1, vec2, i, i + s - 1, i + 2 * s - 1);
			i += 2 * s;
		}
		if (i < n - s)
			Merge(vec1, vec2, i, i + s - 1, n - 1);
		else {
			while (i < n) {
				vec2[i] = vec1[i];
				i++;
			}
		}
	}

	void Merge(vector<int>& vec1, vector<int>& vec2, int left, int middle, int right) {
		int i = left;
		int j = middle + 1;
		int k = left;

		while ((i <= middle) && (j <= right)) {
			if (vec1[i] < vec1[j]) vec2[k++] = vec1[i++];
			else vec2[k++] = vec1[j++];
		}

		if (i > middle) {
			while (j <= right) {
				vec2[k++] = vec1[j++];
			}
		}
		else {
			while (i <= middle) {
				vec2[k++] = vec1[i++];
			}
		}
	}
};

#endif