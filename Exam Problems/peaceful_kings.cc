#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<vector<char> > board;

bool pos_ok(int row, int column){
    //si ninguno de estos casos se cumple, la posicion es valida
    if(row-1 >= 0 and board[row-1][column] == 'K') return false; //arriba
    if(row+1 < n and board[row+1][column] == 'K') return false; //abajo
    if(column-1 >= 0 and board[row][column-1] == 'K') return false; //izquierda
    if(column+1 < n and board[row][column+1] == 'K') return false; //derecha
    if(row-1 >= 0 and column-1 >= 0 and board[row-1][column-1] == 'K') return false; //diagonal arriba izquierda
    if(row-1 >= 0 and column+1 < n and board[row-1][column+1] == 'K') return false; //diagonal arriba derecha
    if(row+1 < n and column-1 >= 0 and board[row+1][column-1] == 'K') return false; //diagonal abajo izquierda
    if(row+1 < n and column+1 < n and board[row+1][column+1] == 'K') return false; //diagonal abajo derecha
    return true;
}

void kings(int row, int column, int count){
    if(count == k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'K') cout << 'K';
                else cout << '.';
            }
            cout << endl;
        }
        cout << "----------" << endl;
    }
    else{
        //si la columan se pasa y la fila no, pasamos a la siguiente fila
        if(column >= n and row < n){
            column = 0;
            ++row;
        }
        //si ninguno se pasa y estamos en una posicion sin rey
        if(row < n and column < n and board[row][column] == '.'){
            if(pos_ok(row,column)){
                board[row][column] = 'K';
                kings(row, column+1,count+1);
                //cuando volvemos atras, ponemos la casilla a '.'
                board[row][column] = '.';
            }
        }
        //si estamos en una posicion con rey
        if(row < n and column < n) kings (row, column+1, count);
    }
}

int main(){
    cin >> n >> k;
    board = vector<vector<char> >(n, vector<char>(n, '.'));
    kings(0,0,0);
}