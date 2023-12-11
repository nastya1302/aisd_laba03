#include <iostream>
#include <vector>
#include <Sorting.h>

using namespace std;
using namespace sorting;

int main() {
	
	//vector<int> mas{4,3,6,2,7,8,5,1,9};
	//cout << mas << endl;
	//cout << insert_sort(mas);
	//cout << coctail_sort(mas);
	//cout << heap_sort(mas);
	//cout << mas << endl;

	vector<size_t> size{1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,25000,50000,100000};
	/*for (size_t i = 0; i < size.size(); ++i) {
		Stats stats = average_stats(size[i], coctail_sort);
		cout << stats;
	}*/

	for (size_t i = 0; i < size.size(); ++i) {
		vector<int> mas = back_sorted_mas(size[i]);
		Stats stats = insert_sort(mas);
		cout << stats;
	}

	return 0;
}