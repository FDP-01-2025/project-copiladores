#include ".\src\Funciones.cpp"

int main(){
    int player1_pos = 1;
    int player2_pos = 1;
    string character1 = "@";
    string character2 = "$";
    int current_player = 1;
    int option;

    string board[6][6] = {
        {"1  ", "2  ", "3  ", "4  ", "5  ", "6  "},
        {"20 ", "   ", "   ", "   ", "   ", "7  "},
        {"19 ", "   ", "   ", "   ", "   ", "8  "},
        {"18 ", "   ", "   ", "   ", "   ", "9  "},
        {"17 ", "   ", "   ", "   ", "   ", "10 "},
        {"16 ", "15 ", "14 ", "13 ", "12 ", "11 "}};

    srand(time(NULL));

    do {
        cout << "===== WELCOME ======\n";
        cout << "== Thief and Policeman ==\n";

        cout << "===== MENU =====\n";
        cout << "1. Play\n2. Choose Character\n3. Exit\n";
        cin >> option;
        cin.ignore(); 

        switch (option){
        case 1:
            int row1, col1, row2, col2;
            cell_to_coordinates(player1_pos, row1, col1);
            cell_to_coordinates(player2_pos, row2, col2);
            board[row1][col1] = character1;
            board[row2][col2] = character2;

            while (true) {
                show_board(board, 6, 6);
                int die = roll_die(current_player);
                showDie(die);

                if (current_player == 1) {
                    player_advance(board, player1_pos, "1", character1, character2, die, 6, 6);
                    if (game_finished(player1_pos)) {
                        cout << "Player 1 has won!\n";
                        break;
                    }
                } else {
                    player_advance(board, player2_pos, "2", character1, character2, die, 6, 6);
                    if (game_finished(player2_pos)) {
                        cout << "Player 2 has won!\n";
                        break;
                    }
                }

                current_player = (current_player == 1) ? 2 : 1; // Alternate turn
            }
            break;

        case 2:
            for (int i = 1; i <= 2; i++) {
                int choice;
                cout << "Player #" << i << ", choose your character:\n";
                cout << "1. @\n2. $\n3. !\n4. *\n";
                cin >> choice;

                switch (choice) {
                case 1: (i == 1) ? character1 = "@" : character2 = "@"; break;
                case 2: (i == 1) ? character1 = "$" : character2 = "$"; break;
                case 3: (i == 1) ? character1 = "!" : character2 = "!"; break;
                case 4: (i == 1) ? character1 = "*" : character2 = "*"; break;
                default:
                    cout << "Invalid option, '@' will be used by default.\n";
                    (i == 1) ? character1 = "@" : character2 = "@"; break;
                }
            }
            break;

        case 3:
            cout << "Thanks for playing, see you next time!\n";
            break;

        default:
            cout << "Invalid option.\n";
            break;
        }
    } while (option != 3);

    return 0;
}