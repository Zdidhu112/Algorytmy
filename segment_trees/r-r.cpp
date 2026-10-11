#include <iostream>
using namespace std;

const int base = 1 << 20;

int tree[2 * base];
int dodane[2 * base];

void push(int v, int l, int r) {
	tree[v] += dodane[v] * (r - l + 1);
	if(l != r) {
		dodane[2 * v] += dodane[v];
		dodane[2 * v + 1] += dodane[v];
	}
	dodane[v] = 0;
}
void update(int v, int l, int r, int uL, int uR, int x) {
	push(v, l, r);
	if(uL <= l && uR >= r) {
		dodane[v] += x;
		push(v, l, r);
		return;
	}

	if(r < uL || l > uR)
		return;
	int mid = (l + r) / 2;
	update(2 * v, l, mid, uL, uR, x);
	update(2 * v + 1, mid + 1, r, uL, uR, x);
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}
int query(int v, int l, int r, int uL, int uR) {
	push(v, l, r);
	if(uL <= l && uR >= r)
		return tree[v];

	if(r < uL || l > uR)
		return 0;

	int mid = (l + r) / 2;
	return query(2 * v, l, mid, uL, uR) + query(2 * v + 1, mid + 1, r, uL, uR);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; ++i)
	    cin >> tree[i + base];
	for(int i = base - 1; i > 0; --i)
	    tree[i] = tree[i * 2] + tree[i * 2 + 1];
	    
	 while(q--) {
	     int t, l, r, val;
	     cin >> t >> l >> r;
	     if(t == 1) {
	         cin >> val;
	         update(1, 1, base, l, r, val);
	     } else {
	         cout << query(1, 1, base, l, r) << '\n';
	     }
	 }

	return 0;
}