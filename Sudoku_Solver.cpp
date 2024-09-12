#include<iostream>
#include<math.h>
using namespace std;

void Print(int board[][9] , int n ){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<board[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isValid(int board[][9] , int i , int j , int num , int n){
    // Row Check
    for(int x = 0 ; x < n ; x++){      //x represent col number
        if(boar[i][x] == num){
            return false;
        }
    }

    // column check
    for(int y = 0 ; y < n ; y++){      //y represent row number
        if(board[y][j] == num){
            return false;
        }
    }

    // Submatrix Check
    int rootn = sqrt(n);
    int startingi = i - i % rootn;
    int startingj = j - j % rootn;
    for(int x = startingi ; x < startingi+rootn ; x++){
        for(int y = startingj ; y < startingj+rootn ; y++){
            if(board[x][y] == num){
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int board[][9] , int i , int j , int n){
    //Base case
    if(i == n){
        Print(board , n);
        return true;
    }

    // if we are not inside the board
    if(j==n){
        return sudokuSolver(board , i+1 , 0 , n );
    }


    // if cell is already filled
    if(board[i][j] != 0 ){
        return sudokuSolver(board , i , j+1 , n);
    }
    
    //try to fill the cell with appropriate number
    for(int num = 1 ; num <= 9 ; num++){
        if(isValid(board , i , j , num , n)){
            board[i][j] = num ;
            bool subAns = sudokuSolver(board , i , j+1 , n);
            if(subAns){
                return true;
            }
            // Backtracking
            board[i][j] = 0 ;   
        }
    }
    return false;

}
int main(){
    int n = 9 ;
    int board[9][9] = {
        {0 , 0 , 7 , 1 , 0 , 0 , 0 , 6 , 0} ,
        {1 , 0 , 5 , 2 , 0 , 8 , 0 , 0 , 0} ,
        {6 , 0 , 0 , 0 , 0 , 7 , 1 , 2 , 0} ,
        {3 , 1 , 2 , 4 , 0 , 5 , 0 , 0 , 8} ,
        {0 , 0 , 6 , 0 , 9 , 0 , 2 , 0 , 0} ,
        {0 , 0 , 0 , 0 , 0 , 3 , 0 , 0 , 1} ,
        {0 , 0 , 1 , 0 , 0 , 4 , 9 , 8 , 6} ,
        {8 , 0 , 3 , 9 , 0 , 6 , 0 , 0 , 0} ,
        {0 , 6 , 0 , 0 , 8 , 2 , 7 , 0 , 3} ,
    };
    sudokuSolver(board, 0 , 0 , n);
}