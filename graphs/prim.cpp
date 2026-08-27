 #include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e6 + 7;

vector<vector<pair<int, int>>> graf;
vector<int> choice;

void Prim() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> kolejka;
	long long ans = 0;
	choice[1] = 0;
	kolejka.push({0, 1});
	
	while(!kolejka.empty()) {
	    int v = kolejka.top().second;
	    int cost = kolejka.top().first;
	    kolejka.pop();
	    if(choice[v] < cost) continue;
	    ans += cost;
	    for(auto &[u, w] : graf[v]) {
	        if(choice[u] > w) {
	            kolejka.push({w, u});
	            choice[u] = w;
	        }
	    }
	}
	cout << ans << '\n';

}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n, m, a, b, w;
    cin >> n >> m;
    graf.resize(n + 1);
    choice.resize(n + 1, INF);
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        graf[a].push_back({b, w});
        graf[b].push_back({a, w});
        
    }
    Prim();
	return 0;
}