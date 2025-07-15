#include <iostream>
using namespace std;

// Board state
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Globals
int choice;
int row, column;
char turn = 'X';
bool draw = false;

// Display the board
void display_board() {
    cout << "\n\nPLAYER 1 [X]  -  PLAYER 2 [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "     |     |     \n\n";
}

// Handle a player's move
void player_turn() {
    if (turn == 'X')
        cout << "Player 1 [X], enter your move (1-9): ";
    else
        cout << "Player 2 [O], enter your move (1-9): ";

    cin >> choice;

    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move!\n";
            return;
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Box already filled! Choose another.\n";
        player_turn();  // retry
    }

    display_board();
}

// Check for win or draw
bool gameover() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
            return false;
    }

    // Diagonals
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
        return false;

    // Check for ongoing game
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

// Main function
int main() {
    cout << "\n=== T I C   T A C   T O E ===\n";
    cout << "      2 Player Game\n";

    display_board();

    while (gameover()) {
        player_turn();
    }

    if (draw)
        cout << "It's a DRAW!\n";
    else
        cout << "Congratulations! Player " << ((turn == 'X') ? "2 [O]" : "1 [X]") << " wins!\n";

    return 0;
}
