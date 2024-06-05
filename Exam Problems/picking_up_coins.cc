/*#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;
typedef vector<bool> VB;
typedef vector<VB> MB;

const int DIRS = 4;
const int DI[DIRS] = {-1, -1, 1, 1};
const int DJ[DIRS] = {-1, 1, -1, 1};

int n, m;

void posicions(const MC& mat, MB& vis, char c, int i, int j){
    if(c == 'B'){
        //visitar diagonales y ponerlas a true
        int ni = i, nj = j;

        
    }

    //c == 'K'
    else{

    }
}

void adjusting_MB(const MC& mat, MB& vis){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            if(mat[i][j] == 'T') vis[i][j] = true; //trampa
            else if(mat[i][j] == 'B') posicions(mat, vis, 'B', i, j); //alfil
            else if(mat[i][j] == 'K') posicions(mat, vis, 'K', i, j); //cavall
        }
}

int main(){
    while(cin >> n >> m){
        MC mat(n, VC(m));
        MB vis(n, VB(m, false));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                char c;
                cin >> c;
                mat[i][j] = c;
            }
    }
    int picked_coins = 0;
    adjusting_MB(mat, vis);

}*/