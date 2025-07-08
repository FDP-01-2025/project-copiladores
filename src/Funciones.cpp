#include "Header.h"

// Added game_finished
// Now it receives the player's position and returns true if they reached or passed the goal
bool game_finished(const Player& player) {
    return player.position >= 20;
}

void show_board(string M[][6], int nrows, int ncols){
    for (int i = 0; i < nrows; i++){
        cout << "[ ";
        for (int j = 0; j < ncols; j++){
            cout << M[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "\n";
}

void showDie(int num){
    cout << "\n+-------+\n";
    switch (num){
    case 1:
        cout << "|       |\n";
        cout << "|   *   |\n";
        cout << "|       |\n";
        break;
    case 2:
        cout << "| *     |\n";
        cout << "|       |\n";
        cout << "|     * |\n";
        break;
    case 3:
        cout << "| *     |\n";
        cout << "|   *   |\n";
        cout << "|     * |\n";
        break;
    case 4:
        cout << "| *   * |\n";
        cout << "|       |\n";
        cout << "| *   * |\n";
        break;
    case 5:
        cout << "| *   * |\n";
        cout << "|   *   |\n";
        cout << "| *   * |\n";
        break;
    case 6:
        cout << "| *   * |\n";
        cout << "| *   * |\n";
        cout << "| *   * |\n";
        break;
    }
    cout << "+-------+\n";
}

int roll_die(Player& player) {
    cout << "=== Die Simulator ===\n";
    cout << "Turn of " << player.name << endl;
    cout << "Press ENTER to roll the die...";
    cin.ignore();

    int result = 1 + rand() % 6;

    cout << "\nRolling the die...\n";
    cout << "The number is: " << result << "\n";
    cout << player.name << " moves " << result << " spaces.\n";

    return result;
}

void cell_to_coordinates(int cell, int &row, int &col){
    if (cell >= 1 && cell <= 6) { // Top row
        row = 0;
        col = cell - 1;
    }
    else if (cell >= 7 && cell <= 11) { // Right column
        row = cell - 6;
        col = 5;
    }
    else if (cell >= 12 && cell <= 16) { // Bottom row
        row = 5;
        col = 17 - cell;
    }
    else if (cell >= 17 && cell <= 20) { // Left column
        row = 21 - cell;
        col = 0;
    }
}

bool is_trap(int cell) {
    int traps[] = {5, 10, 14, 18};
    int trap_count = sizeof(traps) / sizeof(traps[0]);
    for (int i = 0; i < trap_count; i++) {
        if (cell == traps[i])
            return true;
    }
    return false;
}

void player_advance(string M[][6], Player& player, const Player& opponent, int die, int nrows, int ncols) {
    int prev_row, prev_col;
    cell_to_coordinates(player.position, prev_row, prev_col);
    M[prev_row][prev_col] = (player.position < 10 ? " " : " ") + to_string(player.position) + " ";

    player.position += die;
    if (player.position > 20)
        player.position = 20;

    if (is_trap(player.position)) {
        cout << "\nCARE! " << player.name << " landed on a trap and goes back 3 positions.\n";
        player.position -= 3;
        if (player.position < 1)
            player.position = 1;
    }

    int row, col;
    cell_to_coordinates(player.position, row, col);
    M[row][col] = player.character;
}