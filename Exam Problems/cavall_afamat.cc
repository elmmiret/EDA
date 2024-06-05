#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> dirs = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

bool ok_cell (const vector<vector<char>>& T, int i, int j) {
    return i >= 0 and i < T.size () and j >= 0 and j < T[0]. size () and T[i][ j ] != 'X' ;
}

int pastanaga_propera (const vector<vector<char>>& T, int ini_i, int ini_j ) {
    int n = T. size (), m = T[0]. size ();
    queue<pair<int,int>> Q;
    vector<vector<int>> dist(n, vector<int>(m,-1));
    Q.push({ ini_i , ini_j });
    dist [ ini_i ][ ini_j ] = 0;
    while (not Q.empty()) {
        int i = Q.front (). first ;
        int j = Q.front (). second ;
        Q.pop ();
        for (auto& d : dirs ){
            int n_i = i + d. first ;
            int n_j = j + d.second ;
            if ( ok_cell (T,n_i , n_j ) and dist [ n_i ][ n_j ] == -1) {
                dist [ n_i ][ n_j ] = dist [ i ][ j ] + 1;
                if (T[n_i ][ n_j ] == 'p') return dist [ n_i ][ n_j ];
                Q.push({n_i, n_j });
            }
        }
    }
    return -1;
}
int main ( ){
    int n, m;
    while (cin >> n >> m){
        vector<vector<char>> T(n,vector<char>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) cin >> T[i][ j ];

        int ini_i , ini_j ;
        cin >> ini_i >> ini_j ;
        int result = pastanaga_propera (T, ini_i - 1, ini_j - 1);
        if (result == -1) cout << "no" << endl;
        else cout << result << endl;
    } 
}