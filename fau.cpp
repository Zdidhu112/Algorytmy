#include <iostream>
#include <vector>
using namespace std;

vector<int> rep;

int Find(int a) {
    if(a == rep[a]) 
        return a;
    rep[a] = Find(rep[a]);
    return rep[a];
}

void Union(int a, int b) {
    rep[Find(a)] = Find(rep[b]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	rep.resize(1e6 + 7);
	for(int i = 1; i < 1e6 + 7; ++i) rep[i] = i;
	
	for(int i = 0; i < n; ++i) {
	    int a, b;
	    cin >> a >> b;
	    if(Find(a) == Find(b)) {
	        cout << 1 << '\n';
	    } else {
	        cout << 0 << '\n';
	        Union(a, b);
	    } 
	}
	return 0;
}