#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;
typedef vector<bool> VB;
typedef vector<VB> MB;

void maneras(MC& mat, MB& vis, int i, int j){
    int f = mat.size();
    int c = mat[0].size();

    
}

int main(){
    int f, c;
    cin >> f >> c;
    MC mat(f, VC(c));
    for(int i = 0; i < f; ++i)
        for(int j = 0; j < c; ++j){
            mat[i][j] = '.';
        }

    MB vis(f, VB(c, false));
    maneras(mat, vis, 0, 0);    
}   