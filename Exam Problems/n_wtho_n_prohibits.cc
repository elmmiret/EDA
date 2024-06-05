#include <iostream>
#include <vector>
using namespace std;

int n, m;
typedef vector<int> VI;
VI divisores;

bool es_divisible(int x){
    for(int i = 0; i < m; ++i){
        if(x % divisores[i] == 0){
            return true;
        }
    }
    return false;
}

void backtracking(int solucion, int contador){
    if(contador == n){
        cout << solucion << endl;
        return;
    }
    
    else{
        for(int j = 0; j <= 9; ++j){
            int temp = solucion * 10 + j;
            if(not es_divisible(temp)){
                backtracking(temp, contador + 1);
            }
        }
    }
}

int main(){
    while(cin >> n >> m){
        divisores = VI(m);
        for(int i = 0; i < m; ++i){
            int x;
            cin >> x;
            divisores[i] = x;
        }

        backtracking(0, 0);
        cout << "----------" << endl;

    }
}