#include<iostream>
using namespace std;
//const int ROWS = 100;
//const int COLS = 100;
# define ROWS 100
# define COLS 100

int paths(int arr[][COLS], int row, int col, int maxMove, int startR, int startC) {
	int sum = 0;
	
	// Check right direction
	for (int j = startC + 1, moves = 1; j < col && moves <= maxMove; j++, moves++) {
		if (arr[startR][j] != 2 && arr[startR][j] != 1) {
			sum++;
			break;
		}
	}
	
	// Check left direction
	for (int j = startC - 1, moves = 1; j >= 0 && moves <= maxMove; j--, moves++) {
		if (arr[startR][j] != 2 && arr[startR][j] != 1) {
			sum++;
			break;
		}
	}
	
	// Check up direction
	for (int i = startR - 1, moves = 1; i >= 0 && moves <= maxMove; i--, moves++) {
		if (arr[i][startC] != 2 && arr[i][startC] != 1) {
			sum++;
			break;
		}
	}
	
	// Check down direction
	for (int i = startR + 1, moves = 1; i < row && moves <= maxMove; i++, moves++) {
		if (arr[i][startC] != 2 && arr[i][startC] != 1) {
			sum++;
			break;
		}
	}
	
	return sum;
}

int main() {
	int arr[ROWS][COLS];
	int row = 0;
	int col = 0;
	
	cout << "Enter number of rows: ";
	cin >> row;
	cout << "Enter number of columns: ";
	cin >> col;
	
	// Initialize array with 1s
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = 1;
		}
	}
	
	int maxMove = 0;
	int startRow = 0;
	int startCol = 0;
	
	cout << "Enter maximum moves: ";
	cin >> maxMove;
	cout << "Enter starting row: ";
	cin >> startRow;
	cout << "Enter starting column: ";
	cin >> startCol;
	
	// Mark starting position
	arr[startRow][startCol] = 2;
	
	cout << "Total paths = " << paths(arr, row, col, maxMove, startRow, startCol) << endl;
	
	return 0;
}