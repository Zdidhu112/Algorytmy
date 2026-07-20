#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selection_sort(vector<int> &a) {
    for(int i = 0; i < a.size() - 1; ++i) {
        int val = a[i];
        int idx = i;
        int j;
        for(j = i; j < a.size(); ++j) {
            if(a[j] < a[idx]) {
                idx = j;
            }
        }
        a[i] = a[idx];
        a[idx] = val;
    }
}

int main()
{
	vector<int> a = {10, 5, 4, 6,1, 8, 11, 1, 9, 4, 2, 4, 0, 7, 3};
	selection_sort(a);
	
	for(int x : a)
	    cout << x << " ";
	return 0;
}