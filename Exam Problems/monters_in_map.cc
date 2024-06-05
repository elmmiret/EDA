#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;
typedef vector<bool> VB;
typedef vector<VB> MB;
const int DIRS = 4;
const int DI[DIRS] = {1, 0, -1, 0};
const int DJ[DIRS] = {0, 1, 0, -1};

int n, m;
MC mat;
MB vis;

bool pos_ok(int i, int j){
    if(i < 0 or i >= n or j < 0 or j >= m) return false;
    return true;
}

void bfs(int i, int j){
    queue<pair<int,int> > q;
    q.push({i,j});
    bool arribar = false;
    while(not q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int I = p.first;
        int J = p.second;

        if(mat[I][J] == 'F'){
            arribar = true;
            cout << "SI" << endl;
            break;
        }

        vis[I][J] = true;

        for(int k = 0; k < DIRS; ++k){
            int II = I + DI[k];
            int JJ = J + DJ[k];
            
            if(pos_ok(II,JJ) and not vis[II][JJ]){
                q.push({II,JJ});
            }
        }
    }
    if(not arribar) cout << "NO" << endl;
}

int main(){
    while(cin >> n >> m){
        mat = MC(n, VC(m));
        vis = MB(n, VB(m,false));
        pair<int,int> ini;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                char c;
                cin >> c;
                if(c == 'I'){
                    ini.first = i;
                    ini.second = j;
                }
                if(c == 'M'){
                    vis[i][j] = true;
                    for(int k = 0; k < DIRS; ++k){
                        int I = i + DI[k];
                        int J = j + DJ[k];
                        if(pos_ok(I,J)) vis[I][J] = true;
                    }
                }
                mat[i][j] = c;
            }

        bfs(ini.first, ini.second);

    }
}