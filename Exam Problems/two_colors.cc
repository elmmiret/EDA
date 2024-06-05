#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> V;
typedef vector<V> Graph;

int main(){
    int n, m;
    while(cin >> n >> m){
        Graph G(n);
        for(int i = 0; i < m; ++i){
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        V color(n, -1);
        bool es_coloreable = true;
        for(int i = 0; i < n; ++i){
            if(color[i] == -1){
                color[i] = 0; //pintamos el primer nodo de color 0
                V pila;       //pila para hacer dfs iterativo
                pila.push_back(i);
                while(not pila.empty()){
                    int node = pila.back();
                    pila.pop_back();
                    for(int vecino : G[node]){
                        if(color[vecino] == -1){
                            color[vecino] = 1 - color[node];
                            pila.push_back(vecino);
                        }
                        else if(color[vecino] == color[node]){
                            es_coloreable = false;
                            break;
                        }
                    }
                }
            }
        }
        if(es_coloreable) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}