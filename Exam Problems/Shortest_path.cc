/*#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> MI;

MI adj;

void shortest_path(int n, int m){
    //vector para leer, al acabar, el path invertido seguido para ir de 0 a n-1
    vector<int> previo(n);
    //vector de la distancia a la que se encuentra X nodo
    vector<int> distancia(n, -1);
    queue<int> Q; 
    Q.push(0);
    distancia[0] = 0;
    previo[0] = -1;
    while(not Q.empty()){
        int node = Q.front();
        Q.pop();
        for(int x : adj[node]){
            if((distancia[x] == -1) or (distancia[x] != -1 and distancia[x] > distancia[node]+1)){
                distancia[x] = distancia[node] + 1;
                previo[x] = node;
            }
            Q.push(x);
        }
    }

    int last_node = n-1;
    vector<int> sol;
    while(last_node != -1){
        sol.push_back(last_node);
        last_node = previo[last_node];
    }

    bool first = true;
    for(int i = sol.size()-1; i >= 0; --i){
        if(first){
            cout << sol[i];
            first = false;
        }
        else cout << ' ' << sol[i];
    }
    

}

int main(){
    int n, m;
    while(cin >> n >> m){
        adj = MI(n);
        for(int i = 0; i < m; ++i){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }

        shortest_path(n, m);

    }
}*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<VI> VVI;

void path(int xi, int xf, const VI& previos){
    if(xf == xi) cout << xi;
    else{
        path(xi, previos[xf], previos);
        cout << " " << xf;
    }
}

void bfs(const VVI& g, int xi, int xf){
    int n = g.size();
    VI previos(n, -1);
    VB mkd(n, false);
    VI cur, pos;

    cur.push_back(xi);
    mkd[xi] = true;
    while(not cur.empty()){
        for(int x : cur){
            if(x == xf){
                path(xi, xf, previos);
                cout << endl;
                return;
            }
            for(int y : g[x])
                if(not mkd[y]){
                    pos.push_back(y);
                    mkd[y] = true;
                    previos[y] = x;
                }
        }
        swap(pos,cur);
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        VVI g(n);
        for(int k = 0; k < m; ++k){
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
        }

        for(int x = 0; x < n; ++x){
            sort(g[x].begin(), g[x].end());
        }

        bfs(g, 0, n-1);
    }
}