#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HEIGHT 8
#define WIDTH 8
int board[HEIGHT][WIDTH];

void printBoard(){
    for(int y = 0; y < HEIGHT; ++y) {
        for(int x = 0; x < WIDTH; ++x){
            printf(" %d ", board[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkOutOfBound(int x, int y){
    if(x < 0 || x >= WIDTH){
        return 0;
    }
    if(y < 0 || y >= HEIGHT){
        return 0;
    }
    else{
        return board[y][x];
    }
}

int countAliveNeighbours(int x, int y){

    int count = 0;
    count += checkOutOfBound(x-1, y-1);
    count += checkOutOfBound(x, y-1);
    count += checkOutOfBound(x-1, y);
    count += checkOutOfBound(x+1, y);
    count += checkOutOfBound(x, y+1);
    count += checkOutOfBound(x+1, y+1);
    count += checkOutOfBound(x+1, y-1);
    count += checkOutOfBound(x-1, y+1);
    return count;
}

void step(){

    int temporaryBuffer[HEIGHT][WIDTH] = {0};
    for(int y = 0; y < HEIGHT; ++y) {
        for(int x = 0; x < WIDTH; ++x){
            int aliveNeighbours = countAliveNeighbours(x,y);
            if(board[y][x] == 1){
                if(aliveNeighbours < 2){
                temporaryBuffer[y][x] = 0;
            }else if(aliveNeighbours == 2 || aliveNeighbours == 3){
                temporaryBuffer[y][x] = 1;
            }
            else if(aliveNeighbours > 3){
                temporaryBuffer[y][x] = 0;
            }
        }else{
                if(aliveNeighbours == 3){
                   temporaryBuffer[y][x] = 1;
                }
            }
        }
    }
    for(int y = 0; y < HEIGHT; ++y){
        for(int x = 0; x < WIDTH; ++x){
            board[y][x] = temporaryBuffer[y][x];
        }
    }
}

int main() {
    board[4][2] = 1;
    board[4][3] = 1;
    board[4][4] = 1;
    board[1][2] = 1;
    board[2][3] = 1;
    board[3][4] = 1;
    board[5][2] = 1;
    board[5][3] = 1;
    board[5][4] = 1;
    printBoard();
    step();
    printBoard();
    step();
    printBoard();
}
