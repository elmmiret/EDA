/*#include <iostream>
#include <vector>
using namespace std;

int n;
int min_suma_manies = 1000000;
typedef vector<pair<int, int> > VP;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<VB> MB;

VS names;
MI dislikes;
MB vis;
VI sol;
VP solution;

void cerca(int i, int j, int suma_manies, VP& posiciones){
    if(posiciones.size() == n-1 and suma_manies < min_suma_manies){
        //meter las personas de 'posiciones' en 'solution'
        for(int k = 0; k < n-1; ++k){
            solution[k] = 
        }
        min_suma_manies = suma_manies;
        return;
    }
    if(suma_manies >= min_suma_manies or posiciones.size() >= n) return;
    for(int x = 0; x < n; ++x)
        for(int y = 0; y < n; ++y){
            if(x != y){
                if(not vis[x][y]){
                    vis[x][y] = true;
                    suma_manies += dislikes[x][y];
                    pair<int, int> pos = {x,y};
                    posiciones[x] = (pos);
                    int nx = x;
                    int ny = y;
                    if(ny+1 == n){
                        nx += 1;
                        ny = 0;
                    }
                    cerca(nx, ny, suma_manies, posiciones);
                    vis[x][y] = false;
                    suma_manies -= dislikes[x][y];
                    posiciones.pop_back();

                }
            }
        }

}

int main(){
    cin >> n;
    names = VS(n);
    for(int i = 0; i < n; ++i) cin >> names[i];
    dislikes = MI(n, VI(n));
    vis = MB(n, VB(n, false));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            cin >> n;
            dislikes[i][j] = n;
        }
    
    sol = VI(n);
    VP posiciones(n-1);
    solution = VP(n);
    cerca(0,0,0,posiciones);

}*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int MAX = numeric_limits<int>::max();

void sientalos(const int s, vector<bool> &visitado, const vector<vector<int>> &mania, vector<int> &orden, int res, vector<int> &mejor_orden, int &mejor_res){
    int s2 = orden.size();
    if(s == s2 && res<mejor_res){ //Ya he visitado todas las personas, compruebo si el resultado es mejor que el mejor guardado
        mejor_res = res;
        mejor_orden = orden;
    }
    else if(res<mejor_res){ //Sigo añadiendo las personas que no haya visitado, si res es peor que mejor_res no hace falta que siga por ahi
        for(int i=0; i<s; ++i){ 
            if(!visitado[i]){
                visitado[i]=true;
                int anterior = orden.back();
                orden.push_back(i);
                sientalos(s, visitado, mania, orden, res+mania[i][anterior], mejor_orden, mejor_res);
                orden.pop_back();
                visitado[i]=false;
            }
        }
    }
}

int main(){
    int n;
    while(cin >> n){
        //Leer nombres
        vector<string> persona(n);
        for(int i=0; i<n; ++i){
            string aux;
            cin >> aux;
            persona[i] = aux;
        }

        //Leer matriz con las manias
        vector<vector<int>> mania(n,vector<int>(n));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int aux;
                cin >> aux;
                mania[i][j] = aux;
            }
        }

        vector<int> orden(1,0); //El primero siempre sera el primero en ser leido (segun el enunciado)
        vector<int> mejor_orden(n);
        int mejor_res = 0;
        for(int i=0; i<n; ++i){ //selecionar un orden al azar como mejor combinacion para intentar mejorarlo
            mejor_orden[i] = i;
            if(i!=0) mejor_res+=mania[i][i-1];
        } 
        vector<bool> visitados(n,false);
        visitados[0] = true;

        sientalos(n, visitados, mania, orden, 0, mejor_orden, mejor_res);
        cout << mejor_res << endl;
        bool p=true;
        for(int i=0; i<n; ++i){
            if(p){
                p=false;
                cout << persona[mejor_orden[i]];
            }
            else cout << " " << persona[mejor_orden[i]];
        } 
        cout << endl;
    }
}