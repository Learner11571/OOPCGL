#include <iostream>
using namespace std;

// Base class
class Player {
protected:
    char mark; // 'X' or 'O'
public:
    Player(char m) : mark(m) {} // Constructor to initialize the mark
    virtual ~Player() {} // Virtual destructor

    // Pure virtual function to make a move
    virtual void makeMove(char board[3][3]) = 0;

    char getMark() const {
        return mark;
    }
};

// Derived class for Human Player
class HumanPlayer : public Player {
public:
    HumanPlayer(char m) : Player(m) {}

    void makeMove(char board[3][3]) override {
        int choice;
        int row, column;
        cout << "Player " << mark << ", enter the number of the cell (1-9) where you want to place your mark: ";
        cin >> choice;

        // Check if the chosen cell is valid and empty
        row = (choice - 1) / 3;
        column = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][column] == 'X' || board[row][column] == 'O') {
            cout << "Invalid move. Try again.\n";
            makeMove(board);
        } else {
            board[row][column] = mark; // Place the mark (X or O)
        }
    }
};

// Derived class for AI Player (this is just a placeholder for future expansion)
class AIPlayer : public Player {
public:
    AIPlayer(char m) : Player(m) {}

    void makeMove(char board[3][3]) override {
        // Simple AI: Just choose the first empty cell
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    board[i][j] = mark;
                    cout << "AI places " << mark << " at (" << i+1 << "," << j+1 << ")\n";
                    return;
                }
            }
        }
    }
};

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int choice;
int row, column;
char turn = 'X'; // X starts first
bool draw = false;

void drawBoard() {
    cout << "\n\n\tTic-Tac-Toe\n\n";
    cout << "Player 1 [X] - Player 2 [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "     |     |     \n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true; // Row-wise win
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true; // Column-wise win
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true; // Diagonal (top-left to bottom-right)
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true; // Diagonal (top-right to bottom-left)
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // At least one cell is still empty
            }
        }
    }
    return true; // No empty cells left, so it's a draw
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n\n";
    
    // Create players
    HumanPlayer player1('X');
    HumanPlayer player2('O');
    Player* currentPlayer = &player1; // Start with player 1

    while (true) {
        drawBoard();
        currentPlayer->makeMove(board); // Current player makes a move

        if (checkWin()) {
            drawBoard();
            cout << "Player " << currentPlayer->getMark() << " wins!\n";
            break;
        } else if (checkDraw()) {
            drawBoard();
            cout << "It's a draw!\n";
            break;
        }

        // Switch turn
        currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
    }

    return 0;
}
