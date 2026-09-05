#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll P = 31;

const int MAXN = 1e6 + 7;
ll power[MAXN];

bool same(int a, int b, int c, int d, vector<ll>& sum) {
    if(d - c != b - a) return 0;
    if(c < a) {
        swap(a, c);
        swap(b, d);
    }
    ll hash1 = (sum[b] - sum[a - 1] + MOD) % MOD;
    ll hash2 = (sum[d] - sum[c - 1] + MOD) % MOD;
    hash1 = (hash1 * power[c - a]) % MOD;
    return hash1 == hash2;
}

int main()
{
    power[0] = 1;
    for(int i = 1; i < MAXN; ++i)
        power[i] = (power[i - 1] * P) % MOD;
    
    string s;
    cin >> s;

    vector<ll> sum;
    sum.push_back(0);
    for(int i = 1; i <= s.size(); ++i) {
        sum.push_back((sum[i - 1] + power[i] * (s[i - 1] - 'a' + 1)) % MOD);
    }
    int q, a, b, c, d;
    cin >> q;
    while(q--) {
        cin >> a >> b >> c >> d;
        cout << same(a, b, c, d, sum) << '\n';
    }
    return 0;
}