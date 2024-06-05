#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int> > Graf;

bool ciclic(const Graf& g, vector<int>& ge, int n){
    //si es visiten els n vertexs --> NO es ciclic
    queue<int> Q;
    //principi, afegir a la cua vertexs amb grau d'entrada 0
    for(int i = 0; i < n; ++i){
        if(ge[i] == 0) Q.push(i);
    }
    while(not Q.empty()){
        int u = Q.front();
        Q.pop();
        --n;
        for(int v : g[u]){
            --ge[v];
            if(ge[v] == 0) Q.push(v);
        }
    }
    //si n es 0 vol dir que s'han visitat tots els vertexs
    //si es ciclic, en algun moment cap vertex tindra grau de entrada 0 i no s'afegira res a la cua, deixant n > 0
    return n > 0;

}

int main(){
    int n, m;
    while(cin >> n >> m){
        Graf g(n);
        int u, v;
        vector<int> ge(n, 0);
        for(int i = 0; i < m; ++i){
            cin >> u >> v;
            g[u].push_back(v);
            ++ge[v];
        }
        if(ciclic(g,ge,n)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}