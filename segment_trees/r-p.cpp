#include <iostream>
using namespace std;

const int base = 1 << 20;
long long tree[2 * base];

void update(int l, int r, long long val) {
	l += base - 1;
	r += base + 1;

	while(l / 2 != r / 2) {
		if(l % 2 == 0) tree[l + 1] += val;
		if(r % 2 == 1) tree[r - 1] += val;

		l /= 2;
		r /= 2;
	}
}

long long query (int pos) {
	int v = pos + base;
	long long ans = 0;

	while(v > 0) {
		ans += tree[v];
		v /= 2;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> tree[base + i];
	}
	for(int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if(t == 2) {
			int a, b;
			long long u;
			cin >> a >> b >> u;
			update(a, b, u);
		} else {
			int k;
			cin >> k;
			cout << query(k) << '\n';
		}
	}

	return 0;
}