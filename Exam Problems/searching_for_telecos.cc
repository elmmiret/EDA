#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;
typedef vector<bool> VB;
typedef vector<VB> MB;
typedef vector<pair<int, int> > VP;
typedef vector<VP> MP;
const int DI[4] = {1, 0, -1, 0};
const int DJ[4] = {0, 1, 0, -1};

int n, m;
MC mat;
MB vis;
MP passos_persones;

bool pos_ok(int i, int j){
    if(i < 0 or i >= n or j < 0 or j >= m or mat[i][j] == '#') return false;
    return true;
}

void bfs(int xi, int yi){
    queue<pair<int, int> > Q;
    Q.push({xi, yi});
    passos_persones[xi][yi].first = 0;
    passos_persones[xi][yi].second = (mat[xi][yi] == 'P');
    vis[xi][yi] = true;
    bool found = false;
    while(not Q.empty()){
        pair<int, int> p = Q.front();
        Q.pop();
        int x = p.first;
        int y = p.second;

        if(mat[x][y] == 'T'){
            cout << passos_persones[x][y].first << ' ' << passos_persones[x][y].second << endl;
            found = true;
            break;
        }

        for(int k = 0; k < 4; ++k){
            int ni = x + DI[k];
            int nj = y + DJ[k];
            int nd = passos_persones[x][y].first + 1;
            if(pos_ok(ni,nj) and not vis[ni][nj]){
                vis[ni][nj] = true;
                int np = passos_persones[x][y].second + int(mat[ni][nj] == 'P');
                if(passos_persones[ni][nj].first == INT_MAX){
                    Q.push({ni,nj});
                    passos_persones[ni][nj].first = nd;
                    passos_persones[ni][nj].second = np;
                }
                else if(passos_persones[ni][nj].first == nd and passos_persones[ni][nj].second < np){
                    passos_persones[ni][nj].second = np;
                }
            }
        }
    }

    if(not found) cout << "El telecos esta amagat." << endl;

}

int main(){
    while(cin >> n >> m){
        mat = MC(n, VC(m));
        vis = MB(n, VB(m, false));
        passos_persones = MP(n, VP(m, {INT_MAX, -1}));
        bool exists = false;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                char c;
                cin >> c;
                mat[i][j] = c;
                if(c == 'T') exists = true;
            }



        if(not exists) cout << "El telecos ha fugit." << endl;
        else bfs(0,0);
    }
}