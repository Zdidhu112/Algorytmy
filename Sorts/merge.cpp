#include <iostream>
#include <vector>
using namespace std;

void merge_parts(vector<int> &a, int start, int mid, int finish, vector<int> &b) {
    int i_left = start, i_right = mid, i_target = start;
    while(i_target < finish) {
        if(i_left == mid) 
            b[i_target++] = a[i_right++];
        else if(i_right == finish)
            b[i_target++] = a[i_left++];
        else if(a[i_left] <= a[i_right])
            b[i_target++] = a[i_left++];
        else
            b[i_target++] = a[i_right++];
    }
    for(int i = start; i < finish; ++i)
        a[i] = b[i];
}

void merge_split(vector<int> &a, int start, int finish, vector<int> &b) {
	if(finish - start < 2) return;
	int mid = (finish + start) / 2;
	merge_split(a, start, mid, b);
	merge_split(a, mid, finish, b);
	merge_parts(a, start, mid, finish, b);

}


int main()
{
	vector<int> a = {2, 1, 5, 4, 9, 4, 8, 5, 7, 3, 3, 6, 0};
	vector<int> b (a.size());
	merge_split(a, 0, a.size(), b);
	
	for(int x : a)
	    cout << x << " ";
	    
	return 0;
}