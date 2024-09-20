#include <stdio.h>
#include <stdbool.h>

#define N 8  

void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_safe(int board[N][N], int row, int col) {

    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;


    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solve_n_queens(int board[N][N], int row) {
    
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++) {
        if (is_safe(board, row, col)) {
            board[row][col] = 1; 

            if (solve_n_queens(board, row + 1))
                return true;

           
            board[row][col] = 0;
        }
    }

    return false; 
}

int main() {
    int board[N][N] = {0}; 

    if (solve_n_queens(board, 0)) {
        print_board(board);
    } else {
        printf("Solution does not exist\n");
    }

    return 0;
}
