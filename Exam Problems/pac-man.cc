#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;
typedef vector<bool> VB;
typedef vector<VB> MB;
const int DI[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int DJ[8] = {0, 1, 0, -1, 1, -1, 1, -1}; 

bool pos_ok(int x, int y, int f, int c){
    if(x < 0 or x >= f or y < 0 or y >= c) return false;
    return true;
}

bool peligroso(int x, int y, int f, int c, const MC& mat, MB& vis){
    for(int k = 0; k < 8; ++k){
        int II = x + DI[k];
        int JJ = y + DJ[k];
        if(pos_ok(II, JJ, f, c) and mat[II][JJ] == 'F') return true;
    }
    return false;
}

void bfs(const MC& mat, MB& vis, pair<int, int>& pac_pos){
    bool pot_arribar = false;
    if(not peligroso(pac_pos.first, pac_pos.second, mat.size(), mat[0].size(), mat, vis)){
        vis[pac_pos.first][pac_pos.second] = true;
        int f = mat.size();
        int c = mat[0].size();
        queue<pair<int, int> > q;
        q.push(pac_pos);
        while(not q.empty()){
            pair<int, int> pos = q.front();
            q.pop();
            int I = pos.first;
            int J = pos.second;

            if(mat[I][J] == 'B'){
                pot_arribar = true;
                cout << "si" << endl;
                break;
            }

            for(int k = 0; k < 4; ++k){
                int II = I + DI[k];
                int JJ = J + DJ[k];
                if(pos_ok(II, JJ, f, c) and not peligroso(II, JJ, f, c, mat, vis) and not vis[II][JJ] and mat[II][JJ] != 'X'){
                    q.push({II, JJ});
                    vis[II][JJ] = true;
                }
            }
        }
    }
    if(not pot_arribar) cout << "no" << endl;
}

int main(){
    int f, c;
    while(cin >> f >> c){
        MC mat(f, VC(c));
        MB vis(f, VB(c, false));
        pair<int, int> pac_pos;
        for(int i = 0; i < f; ++i)
            for(int j = 0; j < c; ++j){
                char c;
                cin >> c;
                mat[i][j] = c;
                if(c == 'P'){
                    pac_pos.first = i;
                    pac_pos.second = j;
                }
            }

        bfs(mat, vis, pac_pos);
    }
}