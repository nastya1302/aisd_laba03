#include <iostream>
#include <Sorting.h>

using namespace std;
using namespace sorting;

int main() {
	
	vector<int> mas{4,3,6,2,7,8,5,1,9};
	cout << mas << endl;
	//cout << insert_sort(mas);
	//cout << coctail_sort(mas);
	cout << heap_sort(mas);
	cout << mas << endl;

	return 0;
}