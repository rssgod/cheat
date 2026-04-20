//N Queen backtarcking
#include<iostream>
#include<stdbool.h>
#include<stdlib.h>
using namespace std;
const int maxsize=20;

/**
 * Checks if placing a queen at board[row] = col is safe.
 * We only need to check previous rows because we place queens row by row.
 */
 int board[maxsize];
bool is_safe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        int prev_col = board[i];
        
        // 1. Check same column
        // 2. Check diagonals: if row difference == column difference
        if (prev_col == col || abs(prev_col - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

/**
 * Utility to print the board configuration.
 */
void print_solution(int board[], int n) {
    static int count = 1;
    cout<<"Solution #:\n"<<count++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) cout<<" Q ";
            else cout<<" . ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

/**
 * Recursive backtracking function.
 */
void solve_n_queens(int board[], int row, int n) {
    // Base Case: All queens are placed
    if (row == n) {
        print_solution(board, n);
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col)) {
            board[row] = col;   
            solve_n_queens(board, row + 1, n); 
        }
    }
}

int main() {
    int n;
    cout<<"Enter the number of queens (N=4 or N=8): ";
    cin>>n;
    solve_n_queens(board, 0, n);
    return 0;
}