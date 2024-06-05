#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<vector<bool>> MB;
typedef vector<vector<char>> Graph;
const int N_DIRS = 4;
const int DI[N_DIRS] = {1, 0, -1, 0};
const int DJ[N_DIRS] = {0, 1, 0, -1};

bool pos_ok(int f, int c, int i, int j){
    if(i < 0 or i >= f or j < 0 or j >= c) return false;
    return true;
}

void dfs(const Graph& G, int xi, int yi, int xf, int yf, vector<char>& s, MB& vis){
    int f = G.size();
    int c = G[0].size();
    if(xi == xf and yi == yf){
        for(char i : s) cout << i;
        cout << endl;
    }
    else{
        if(not vis[xi][yi]){
            vis[xi][yi] = true;
            for(int i = 0; i < N_DIRS; ++i){
                int II = xi + DI[i];
                int JJ = yi + DJ[i];
                if(pos_ok(f,c,II,JJ)){
                    s.push_back(G[II][JJ]);
                    dfs(G, II, JJ, xf, yf, s, vis);
                    //limpiar el vector s para poder usarlo en la siguiente iteracion (se ejecuta al VOLVER de la llamada recursiva)
                    if(s.size() > 1) s.pop_back();
                }
            }
            //ponemos la primera posicion como no visitada para poder volver a pasar por ella (se ej. al VOLVER de la llamada recursiva
            //al final queda como si no hubiesemos visitado el camino, y asi poder usar las casillas en 
            //futuras iteraciones hacia otras direcciones
            vis[xi][yi] = false;
        }
    }
}

int main(){
    int f, c;
    cin >> f >> c;
    Graph G(f, vector<char>(c));
    for(int i = 0; i < f; ++i)
        for(int j = 0; j < c; ++j){
            char c;
            cin >> c;
            G[i][j] = c;
        }
    int xi, yi, xf, yf;
    cin >> xi >> yi >> xf >> yf;
    vector<char> s;
    s.push_back(G[xi][yi]);
    MB vis(f, vector<bool>(c, false));
    dfs(G, xi, yi, xf, yf, s, vis);
}