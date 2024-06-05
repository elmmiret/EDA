#include <iostream>
#include <vector>

using namespace std;

void escriu(int f, int c, const vector<int>& col){
    for(int i = 0; i < f; ++i){
        for(int j = 0; j < c; ++j)
            if(col[i] == j) cout << "R";
            else cout << ".";
        cout << endl;
    }
    cout << endl;
}

void torres(int f, int c, int i, vector<int>& col, vector<bool>& marked){
    if(i == f) escriu(f, c, col);
    else
        for(int j = 0; j < c; ++j)
            if(not marked[j]){
                col[i] = j;
                marked[j] = true;
                torres(f, c, i+1, col, marked);
                marked[j] = false;
            }
}

int main(){
    int f, c;
    cin >> f >> c;
    vector<int> col(f);
    vector<bool> marked(c, false);
    torres(f, c, 0, col, marked);
}