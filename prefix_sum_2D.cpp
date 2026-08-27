#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> tab;
    int n, m, q;
    cin >> n >> m >> q;
    tab.resize(n + 1, vector<int> (m + 1));
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> tab[i][j];
        }
    }
    
    vector<vector<int>> sum;
    sum.resize(n + 1, vector<int> (m + 1, 0));
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + tab[i][j];
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << sum[i][j] << " ";
        }
        cout << '\n';
    }
    
    
    for(int i = 0; i < q; ++i) {
        // x - numer wiersza, y - numer kolumny
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int w = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
        cout << w << '\n';
    }
    return 0;
}