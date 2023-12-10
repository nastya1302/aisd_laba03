#include <iostream>
#include <Sorting.h>

using namespace std;
using namespace sorting;

int main() {
	vector<int> mas{ 4,3,6,2,7,8,5,1,9 };
	cout << mas << endl;
	cout << sorting_inserts(mas);
	cout << mas << endl;
	return 0;
}