#include <iostream>
using namespace std;
 
const long int base = 1 << 20;
long long tree[base * 2];
 
void update(int pos, int val) {
	int v = pos + base;
	tree[v] = val;
	v /= 2;
	while(v) {
		tree[v] = tree[2 * v] + tree[2 * v + 1];
		v /= 2;
	}
}
long long query(int l, int p) {
	l += base - 1;
	p += base + 1;
 
	long long ans = 0;
 
	while(l / 2 != p / 2) {
		if(l % 2 == 0) ans += tree[l + 1];
		if(p % 2 == 1) ans += tree[p - 1];
		l /= 2;
		p /= 2;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; ++i) {
	    cin >> tree[base + i];
	}
	for(int i = base - 1; i > 0; --i) {
	    tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
    while(q--) {
        long long t, a, b;
        cin >> t >> a >> b;
        if(t == 1) 
            update(a - 1, b);
        else
            cout << query(a - 1, b - 1) << '\n';
    }
	return 0;
}