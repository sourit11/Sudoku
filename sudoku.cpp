#include<iostream>
using namespace std;

bool check(int board[][9], int r, int c, int v){
    for(int k = 0; k < 9; k++){
        if(board[r][k] == v)
            return false;
        if(board[k][c] == v)
            return false;
    }
    int tri = r - r % 3;
    int tci = c - c % 3;
    for(int a = tri; a < tri + 3; a++){
        for(int b = tci; b < tci + 3; b++){
            if(board[a][b] == v)
                return false;
        }
    }
    return true;
}
bool helper(int board[][9], int r, int c){
    if(r == 9)
        return true;
    if(c == 9)
        return helper(board, r + 1, 0);
    if(board[r][c])
        return helper(board, r, c + 1);
    for(int k = 1; k <= 9; k++){
        if(check(board, r, c, k)){
            board[r][c] = k;
            if(helper(board, r, c+ 1))
                return true;
        }
        board[r][c] = 0;
    }
    return false;
}
bool sudoku(int board[][9])
{
    return helper(board, 0, 0);
}
int main(){
    int board[9][9];
    cout << "Enter the sudoku board with zero for blank spaces:\n";
    for(int i = 0; i < 9; i++)
        for(int j = 0; j <  9; j++)
            cin >> board[i][j];
    if(sudoku(board)){
        cout << "The board can be filled as follows:\n";
        for(int i = 0; i < 9; i++){
        	for(int j = 0; j < 9; j++)
            	cout << board[i][j] << ' ';
        	cout << endl;
        }
    }
    else
        cout << "The board cannot be filled!";
    return 0;
}