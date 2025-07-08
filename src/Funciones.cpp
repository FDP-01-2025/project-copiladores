#include "Header.h"

// Added game_finished
// Now it receives the player's position and returns true if they reached or passed the goal
bool game_finished(int player_pos){
    return player_pos >= 20;
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

int roll_die(int player){
    cout << "=== Die Simulator ===\n";
    cout << "Player #" << player << "'s turn";
    cout << "Press ENTER to roll the die...";
    cin.ignore();

    int result = 1 + rand() % 6;

    cout << "\nRolling the die...\n";
    cout << "The number is: " << result << "\n";
    cout << "Player #" << player << " you move " << result << " spaces in the game.\n";
    player = ((player==1)?2:1);

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

void player_advance(string M[][6], int &player_pos, string player, string character1, string character2, int die, int nrows, int ncols){
    int prev_row, prev_col;
    cell_to_coordinates(player_pos, prev_row, prev_col);
    // Restore original number
    M[prev_row][prev_col] = (player_pos < 10 ? " " : " ") + to_string(player_pos) + " ";

    player_pos += die;
    if (player_pos > 20){
        player_pos = 20;
    }

    if (is_trap(player_pos)) {
        cout << "\n CAREFUL! Player #" << player << " you landed on a trap space and move back 3 positions.\n";
        player_pos -= 3;
        if (player_pos < 1)
            player_pos = 1;
    }

    int row, col;
    cell_to_coordinates(player_pos, row, col);
    player = ((player=="1")?character1:character2);
    M[row][col] = player;
    player = ((player=="1")?"2":"1");
}