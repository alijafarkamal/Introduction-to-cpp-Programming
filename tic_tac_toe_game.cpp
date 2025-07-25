#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class TicTacToe {
private:
    char** board;
    int size;
    
    void initBoard() {
        board = new char* [size];
        for (int i = 0; i < size; ++i) {
            board[i] = new char[size];
            for (int j = 0; j < size; ++j) {
                board[i][j] = '.';
            }
        }
    }
    
public:
    // Default Constructor
    TicTacToe() : size(3) {
        initBoard();
    }

    // Parametrized Constructor
    TicTacToe(int n) : size(n) {
        initBoard();
    }

    // Copy Constructor
    TicTacToe(const TicTacToe& other) : size(other.size) {
        initBoard();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                board[i][j] = other.board[i][j];
            }
        }
    }

    // Destructor
    ~TicTacToe() {
        for (int i = 0; i < size; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    // Print the current board
    friend ostream& operator<<(ostream& os, const TicTacToe& game) {
        for (int i = 0; i < game.size; ++i) {
            for (int j = 0; j < game.size; ++j) {
                os << game.board[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    // Get a move from the user
    bool makeMove(int row, int col, char player) {
        if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == '.') {
            board[row][col] = player;
            return true;
        }
        return false;
    }

    // Check if the move is valid
    bool isValidMove(int row, int col) {
        return row >= 0 && row < size && col >= 0 && col < size && board[row][col] == '.';
    }

    // Determine if there is a winner
    bool isWinner(char player) {
        // Check rows, columns and diagonals
        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < size; ++i) {
            int row = 0, col = 0;
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == player) row++;
                if (board[j][i] == player) col++;
            }
            if (row == size || col == size) return true;
            if (board[i][i] == player) diag1++;
            if (board[i][size - 1 - i] == player) diag2++;
        }
        return diag1 == size || diag2 == size;
    }

    // Save game to file
    void saveGame(const string& filename) {
        ofstream file(filename);
        file << size << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file << board[i][j];
            }
            file << endl;
        }
        file.close();
    }

    // Load game from file
    bool loadGame(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) return false;
        file >> size;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file >> board[i][j];
            }
        }
        file.close();
        return true;
    }
};

int main() {
    int n;
    cout << "Enter the size of the board (N >= 3): ";
    cin >> n;

    TicTacToe game(n);
    cout << "Starting a new Tic-Tac-Toe game with a " << n << "x" << n << " board.\n";

    int playerTurn = 0; // 0 for 'X', 1 for 'O'
    int moves = 0;
    int maxMoves = n * n;

    while (true) {
        cout << game;
        int row, col;
        cout << "Player " << (playerTurn == 0 ? 'X' : 'O') << ", enter row and column to place your mark: ";
        cin >> row >> col;

        if (game.isValidMove(row - 1, col - 1)) {
            game.makeMove(row - 1, col - 1, (playerTurn == 0 ? 'X' : 'O'));
            moves++;

            if (game.isWinner(playerTurn == 0 ? 'X' : 'O')) {
                cout << "Player " << (playerTurn == 0 ? 'X' : 'O') << " wins!\n";
                cout << game;
                break;
            }
            if (moves == maxMoves) {
                cout << "The game is a draw.\n";
                cout << game;
                break;
            }
            playerTurn = 1 - playerTurn; // Switch players
        }
        else {
            cout << "Invalid move, please try again.\n";
        }
    }
    return 0;
} 