#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1e6 + 7;
vector<vector<pair<int, int>>> graf;
vector<int> odleglosc;
vector<int> odwiedzone;
vector<int> skad_przychodzimy;
void Dijkstra(int v) {
    int u;
    priority_queue<pair<int, int>> kolejka;
    odleglosc[v] = 0;
    skad_przychodzimy[v] = v;
    kolejka.push({0, v});
    while(kolejka.size() > 0) {
        v = kolejka.top().second;
        kolejka.pop();
        for(int i = 0; i < graf[v].size(); ++i){
            u = graf[v][i].first;
           if(odleglosc[u] <= odleglosc[v] + graf[v][i].second) continue;
               odleglosc[u] = odleglosc[v] + graf[v][i].second;
               kolejka.push({odleglosc[u], u});
               skad_przychodzimy[u] = v;
        }
    }
}
int main()
{
    i.os_base::sync_with_stdio(0);
	  cin.tie(0);
    int n, m;
    int a, b, w;
    cin >> n >> m;
    graf.resize(n+1);
    odleglosc.resize(n+1, MAX);
    odwiedzone.resize(n+1, 0);
    skad_przychodzimy.resize(n+1, -1);
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> w;
        graf[a].push_back({b,w});
        graf[b].push_back({a,w});
    }
    Dijkstra(1);
    if(odleglosc[n] != MAX) 
        cout << odleglosc[n] << "\n";
    else
        cout << -1 << "\n";
    return 0;
}
