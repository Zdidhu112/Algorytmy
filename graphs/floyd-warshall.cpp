#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e6 + 7;
vector<vector<int>> graf;
int n, m;
void FloydWarshall() {
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(graf[i][k] < INF && graf[k][j] < INF) 
                    graf[i][j] = min(graf[i][j], graf[i][k] + graf[k][j]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int a, b, w;
    cin >> n >> m;
    graf.resize(n + 1, vector<int> (n + 1, INF));
    
    for(int i = 1; i <= n; ++i) 
        graf[i][i] = 0;

    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        graf[a][b] = w;
        graf[b][a] = w;
    }
    
    FloydWarshall();
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << graf[i][j] << " "; 
        }
        cout << '\n';
    }
    return 0;
}