#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
typedef vector<char> VC;
typedef vector<VC> MC;
typedef vector<bool> VB;
typedef vector<VB> MB;
typedef vector<int> VI;
typedef pair<int, int> POS;
typedef vector<POS> VP;
typedef vector<VP> MP;
const int DI[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int DJ[8] = {0, 1, 0, -1, 1, -1, 1, -1};

MC tauler;
MB vis;
MP previos;
POS last_pos;

bool pos_ok(int x, int y){
    if(x < 0 or x >= n or y < 0 or y >= m) return false;
    return true;
}

bool bfs(pair<int, int>& knight_pos){
    int xi = knight_pos.first;
    int yi = knight_pos.second;
    queue<pair<int, int>> q;
    q.push(knight_pos);
    vis[xi][yi] = true;
    while(not q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;

        if(tauler[x][y] == 'F'){
            last_pos = {x, y};
            return true;
        }

        for(int k = 0; k < 8; ++k){
            int ni = x + DI[k];
            int nj = y + DJ[k];
            if(pos_ok(ni, nj) and not vis[ni][nj] and tauler[ni][nj] != 'X'){
                vis[ni][nj] = true;
                previos[ni][nj] = {x, y};
                q.push({ni, nj});
            }
        }

    }
    return false;


}

int main(){
    while(cin >> n >> m){
        tauler = MC(n, VC(m));
        vis = MB(n, VB(m, false));
        pair<int, int> knight_pos;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                char c;
                cin >> c;
                tauler[i][j] = c;
                if(c == 'K') knight_pos = {i,j};
            }

        previos = MP(n, VP(m, {-1, -1}));
        previos[knight_pos.first][knight_pos.second] = {-2, -2};

        
        if(not bfs(knight_pos)) cout << '0' << endl;
        else{
            int lx = last_pos.first;
            int ly = last_pos.second;
            VP cami_invers;
            cami_invers.push_back({lx, ly});
            while(previos[lx][ly] != make_pair(-2, -2)){
                pair<int, int> aux = previos[lx][ly];
                lx = aux.first;
                ly = aux.second;
                cami_invers.push_back({lx, ly});
            }
            cout << cami_invers.size();

            for(int i = cami_invers.size()-1; i >= 0; --i){
                cout << "  " << cami_invers[i].first <<  ' ' << cami_invers[i].second;
            }
            cout << endl;
        }
    }

}