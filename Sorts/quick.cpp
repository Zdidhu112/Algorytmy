#include <iostream>
#include <vector>
using namespace std;

int quick_partition(int start, int finish, vector<int> &a) {
	int pivot = a[finish - 1];
	int i = start - 1;
	for(int j = start; j < finish - 1; ++j) {
		if(a[j] <= pivot) {
			++i;
			int val = a[i];
			a[i] = a[j];
			a[j] = val;
		}
	}
	++i;
	int val = a[i];
	a[i] = a[finish - 1];
	a[finish - 1] = val;
	return i;
}

void quick_sort(int start, int finish, vector<int> &a) {
	if(start >= finish - 1 || start < 0)
		return;
	int p = quick_partition(start, finish, a);
	quick_sort(start, p, a);
	quick_sort(p + 1, finish, a);
}


int main()
{
	vector<int> a = {2, 1, 5, 4, 9, 4, 8, 5, 7, 3, 3, 6, 0};
	quick_sort(0, a.size(), a);

	for(int x : a)
		cout << x << " ";

	return 0;
}