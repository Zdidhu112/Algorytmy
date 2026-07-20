#include <iostream>
#include <vector>
using namespace std;

void count_sort(vector<int> &a, int m) {
	vector<int> count (m + 1, 0);
	
	for(int i = 0; i < a.size(); i++)
		++count[a[i]];
		
	for(int i = 0, w = 0; w <= m; w++) {
		for(int j = 0; j < count[w]; j++)
			a[i++] = w;
	}
}

int main()
{
	vector<int> a = {2, 1, 5, 4, 9, 4, 8, 5, 7, 3, 3, 6, 0};
	count_sort(a, 9);
	
	for(int x : a)
	    cout << x << " ";
	return 0;
}