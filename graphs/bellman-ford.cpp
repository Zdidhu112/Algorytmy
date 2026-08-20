#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e6 + 7;

vector<vector<pair<int, int>>> graf;
vector<long long> odleglosci;
int n, m;

void BellmanFord(int v) {
	odleglosci[v] = 0;
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(odleglosci[j] == INF) continue;
			for(auto &[u, w] : graf[j])
				odleglosci[u] = min(odleglosci[u], odleglosci[j] + w);
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, w;
	cin >> n >> m;
	graf.resize(n + 1);
	odleglosci.resize(n + 1, INF);

	for(int i = 0; i < m; ++i) {
		cin >> a >> b >> w;
		graf[a].push_back({b, w});
		graf[b].push_back({a, w});
	}

	BellmanFord(1);

	for(int i = 1; i <= n; ++i)
		cout << odleglosci[i] << " ";

	return 0;
}