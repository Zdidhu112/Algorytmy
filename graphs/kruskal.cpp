#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int a, b, w;
    edge(int aa, int bb, int ww) {
        a = aa;
        b = bb;
        w = ww;
    }
    edge()
    {}
};

vector<int> rep;
vector<edge> e;

bool komp (const edge &a, const edge &b) {
    return a.w < b.w;
}

void make_set(int n) {
    rep.resize(n + 1);
    for(int i = 1; i <= n; ++i)
        rep[i] = i;
}

int Find(int a) {
    if(a == rep[a]) return a;
    rep[a] = Find(rep[a]);
    return rep[a];
}
void Union(int a, int b) {
    rep[Find(a)] = Find(rep[b]);
}
long long MST (int n, vector<edge> &MST_edges) {
    make_set(n);
    long long ans = 0;
    for(auto z : e) {
        int a = z.a, b = z.b;
        if(Find(a) != Find(b)) {
            MST_edges.push_back(z);
            Union(a, b);
            ans += z.w;
        } 
    }
    return ans;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    e.resize(m);
    for(int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = edge(a, b,w);
    }
    sort(e.begin(), e.end(), komp);
    vector<edge> MST_edges;
    long long mst_weight = MST(n, MST_edges);
    cout << mst_weight << '\n';
    for(auto z : MST_edges) 
        cout << z.a << " " << z.b << " " << z.w << '\n';
    return 0;
}
//test przykładowy:
// 11 20
// 6 11 9
// 6 10 6
// 6 4 7
// 10 11 5
// 10 1 7
// 10 4 6
// 10 9 6
// 7 10 7
// 9 4 2
// 11 4 3
// 4 1 8
// 4 5 10
// 1 5 4
// 1 8 9
// 8 5 6
// 4 8 5
// 8 3 2
// 8 2 3
// 2 3 4
// 9 5 4