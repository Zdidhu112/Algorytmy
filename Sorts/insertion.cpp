#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &a) {
    for(int i = 1; i < a.size(); ++i) {
        int val = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > val) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = val;
    }
}

int main()
{
	vector<int> a = {10, 5, 4, 6,1, 8, 11, 1, 9, 4, 2, 4, 0, 7, 3};
	insertion_sort(a);
	
	for(int x : a)
	    cout << x << " ";
	return 0;
}