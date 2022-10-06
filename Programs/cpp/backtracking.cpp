#include<iostream>
using namespace std;
bool isSafe(int board[][9],int row,int col,int num){
    for(int i=0;i<9;i++){
        if(board[row][i]==num)return false;
    }
    for(int i=0;i<9;i++){
        if(board[i][col]==num)return false;
    }
    int box_x=row/3;
    int box_y=col/3;
    for(int i=box_x*3;i<box_x*3+3;i++){
        for(int j=box_y*3;j<box_y*3+3;j++){
            if(board[i][j]==num)return false;
        }
    }
    return true;
}
bool solveSudoku(int board[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                for(int num=1;num<=9;num++){
                    if(isSafe(board,i,j,num)){
                        board[i][j]=num;
                        if(solveSudoku(board))return true;
                        board[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
auto printBoard(int board[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int board[9][9]={
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };
    printBoard(board);
    cout<<endl;
    solveSudoku(board);
    printBoard(board);
}