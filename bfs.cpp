#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<vector<int>> graf;
vector<int> odwiedzone;
vector<int> odleglosc;

void BFS(int v) {
    int u;
	deque<int> kolejka;
	odleglosc[v] = 0;
	odwiedzone[v] = 1;
	kolejka.push_back(v);
	while(kolejka.size() > 0){
	    v = kolejka.front();
	    kolejka.pop_front();
	    for(int i = 0; i < graf[v].size(); ++i) {
	        u = graf[v][i];
	        if(!odwiedzone[u]) {
	            odleglosc[u] = odleglosc[v] + 1;
	            odwiedzone[u] = 1;
	            kolejka.push_back(u);
	        }
	    }
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	graf.resize(n+1);
	odwiedzone.resize(n+1, 0);
	odleglosc.resize(n+1, -1);
	for(int i = 0; i < m; ++i) {
		cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	BFS(1);
	for(int i = 1; i <= n; ++i)
		cout << odleglosc[i] << " ";
	return 0;
}
