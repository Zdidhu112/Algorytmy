#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graf;
vector<int> czy_odwiedzone;
void wypiszGraf(const vector<vector<int>> &graf) {
	for(int akt_wierzcholek = 1; akt_wierzcholek < graf.size(); akt_wierzcholek++) {
		cout<< akt_wierzcholek << ": ";
		for(int akt_krawedz = 0; akt_krawedz < graf[akt_wierzcholek].size(); akt_krawedz++)
			cout << graf[akt_wierzcholek][akt_krawedz] << ' ';
		cout << '\n';
	}
}
void DFS(int v) {
    czy_odwiedzone[v] = 1;
    for(int i = 0; i < graf[v].size(); i++){
        if(!czy_odwiedzone[graf[v][i]]) DFS(graf[v][i]);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	int ile_wierzcholkow, ile_krawedzi, u, v, a, b;	
	cin >> ile_wierzcholkow >> ile_krawedzi >> u >> v;
	graf.resize(ile_wierzcholkow + 1);
	czy_odwiedzone.resize(ile_wierzcholkow + 1);
	for(int i = 0; i < ile_krawedzi; i++) {
		cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	DFS(u);
	if(czy_odwiedzone[v] == 1)
	    cout << "TAK" << '\n';
	else 
	    cout << "NIE" << '\n';
// 	wypiszGraf(graf);
	return 0;
}
