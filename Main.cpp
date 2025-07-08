#include ".\src\Funciones.cpp"

int main(){
    Player player1 = {"Player 1", "@", 1};
    Player player2 = {"Player 2", "$", 1};
    int current_turn = 1;
    int option;

    string board[6][6] = {
        {"1  ", "2  ", "3  ", "4  ", "5  ", "6  "},
        {"20 ", "   ", "   ", "   ", "   ", "7  "},
        {"19 ", "   ", "   ", "   ", "   ", "8  "},
        {"18 ", "   ", "   ", "   ", "   ", "9  "},
        {"17 ", "   ", "   ", "   ", "   ", "10 "},
        {"16 ", "15 ", "14 ", "13 ", "12 ", "11 "}
    };

    srand(time(NULL));

    do {
        cout << "===== WELCOME ======\n";
        cout << "== Thief and Policeman ==\n";

        cout << "===== MENU =====\n";
        cout << "1. Play\n2. Choose Character\n3. Exit\n";
        cin >> option;
        cin.ignore();

        switch (option) {
        case 1: {
            int r1, c1, r2, c2;
            cell_to_coordinates(player1.position, r1, c1);
            cell_to_coordinates(player2.position, r2, c2);
            board[r1][c1] = player1.character;
            board[r2][c2] = player2.character;

            while (true) {
                show_board(board, 6, 6);
                int die = (current_turn == 1) ? roll_die(player1) : roll_die(player2);
                showDie(die);

                if (current_turn == 1) {
                    player_advance(board, player1, player2, die, 6, 6);
                    if (game_finished(player1)) {
                        cout << player1.name << " wins!\n";
                        break;
                    }
                } else {
                    player_advance(board, player2, player1, die, 6, 6);
                    if (game_finished(player2)) {
                        cout << player2.name << " wins!\n";
                        break;
                    }
                }

                current_turn = (current_turn == 1) ? 2 : 1;
            }
            break;
        }
        case 2:
            for (int i = 1; i <= 2; i++) {
                int choice;
                cout << "Player #" << i << ", choose your character:\n";
                cout << "1. @\n2. $\n3. !\n4. *\n";
                cin >> choice;

                string selected;
                switch (choice) {
                    case 1: selected = "@"; break;
                    case 2: selected = "$"; break;
                    case 3: selected = "!"; break;
                    case 4: selected = "*"; break;
                    default:
                        cout << "Invalid option. '@' selected by default.\n";
                        selected = "@"; break;
                }

                if (i == 1) player1.character = selected;
                else player2.character = selected;
            }
            break;

        case 3:
            cout << "Thanks for playing. See you next time!\n";
            break;

        default:
            cout << "Invalid option.\n";
        }
    } while (option != 3);

    return 0;
}