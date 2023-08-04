/*group members 1.NDAYISHIMIYE Habibu 222005474
                2.UWABABYEYI MBABAZI Aline 222009293
                3.IRADUKUNDA Bonheur 222005615
                */
                //QUESTION
  /*2. Create a C++ program to implement the Power4 board game in the console
(https://en.wikipedia.org/wiki/Connect_Four)*/ 
            //ANSWER             
#include <iostream>
#include <vector>
using namespace std;

const int ROWS = 6;
const int COLS = 7;
const char PLAYER1 = 'H';
const char PLAYER2 = 'C';

// Function to initialize the board
void initializeBoard(vector<vector<char>>& board) {
    board = vector<vector<char>>(ROWS, vector<char>(COLS, ' '));
}

// Function to display the board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-----------------------------" << endl;
}

// Function to check if the move is valid
bool isValidMove(const vector<vector<char>>& board, int col) {
    return col >= 0 && col < COLS && board[0][col] == ' ';
}

// Function to make a move
void makeMove(vector<vector<char>>& board, int col, char currentPlayer) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = currentPlayer;
            break;
        }
    }
}

// Function to check for a winer
bool checkWin(const vector<vector<char>>& board, char currentPlayer) {
    // Check for horizontal win
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == currentPlayer &&
			    board[i][j + 1] == currentPlayer &&
                board[i][j + 2] == currentPlayer &&
			    board[i][j + 3] == currentPlayer) {
                return true;
            }
        }
    }

    // Check for vertical winer
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == currentPlayer &&
			    board[i + 1][j] == currentPlayer &&
                board[i + 2][j] == currentPlayer && 
				board[i + 3][j] == currentPlayer) {
                return true;
            }
        }
    }

    // Check for diagonal winer (top-left to bottom-right)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == currentPlayer &&
			    board[i + 1][j + 1] == currentPlayer &&
                board[i + 2][j + 2] == currentPlayer &&
			     board[i + 3][j + 3] == currentPlayer) {
                return true;
            }
         }
     }
         // Check for diagonal win (bottom-left to top-right)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == currentPlayer &&
			    board[i - 1][j + 1] == currentPlayer &&
                board[i - 2][j + 2] == currentPlayer && 
				board[i - 3][j + 3] == currentPlayer) {
                return true;
            }
        }
    }

    return false;
}

// Function to check for a tie
bool checkTie(int moves) {
    return moves == ROWS * COLS;
}

// Function to switch players
char switchPlayer(char currentPlayer) {
    return (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
}

int main() {
    vector<vector<char>> board;
    initializeBoard(board);
    int moves = 0;
    char current_player = PLAYER1;
    bool game_over = false;

    while (!game_over) {
        displayBoard(board);

        int col;
        do {
            cout << "Player " << current_player << ", enter column (1-7): ";
            cin >> col;
            col--;
        } while (!isValidMove(board, col));

        makeMove(board, col, current_player);

        if (checkWin(board, current_player)) {
            displayBoard(board);
            cout << "Congratulations, Player " << current_player << " wins!" << endl;
            game_over = true;
        }

        moves++;

        if (checkTie(moves)) {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            game_over = true;
        }

        // Switch player for the next turn
        current_player = switchPlayer(current_player);
    }

    return 0;
}

         
