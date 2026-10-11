#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 7;
const int LOG = 18;

int n;
vector<vector<int>> jump;
vector<vector<int>> graf;
vector<int> depth;

void dfs(int v, int p) {
	jump[v][0] = p;
	depth[v] = depth[p] + 1;
	for(int u : graf[v]) {
		dfs(u, v);
	}
}
void preprocess() {
	for(int k = 1; k < LOG; ++k) {
		for(int v = 1; v <= n; ++v) {
			jump[v][k] = jump[jump[v][k - 1]][k - 1];
		}
	}
}
int LCA(int a, int b) {
	if(depth[a] < depth[b]) swap(a, b);
	for(int k = LOG - 1; k >= 0; --k) {
		if(depth[a] - (1 << k) >= depth[b]) {
			a = jump[a][k];
		}
	}
	if(a == b) return a;
	for(int k = LOG - 1; k >= 0; --k) {
		if(jump[a][k] != jump[b][k]) {
			a = jump[a][k];
			b = jump[b][k];
		}
	}
	return jump[a][0];

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q, p, a, b;
	cin >> n >> q;
	jump.resize(n + 1, vector<int> (LOG));
	graf.resize(n + 1);
	depth.resize(n + 1);

	jump[1][0] = 1;
	for(int i = 2; i <= n; ++i) {
		cin >> p;
		graf[p].push_back(i);
	}

	dfs(1, 1);
	preprocess();

	while(q--) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}