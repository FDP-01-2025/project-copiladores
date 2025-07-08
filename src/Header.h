#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream> 
using namespace std;

struct Player{
    string name;
    string character;
    int position;
};

void show_board(string M[][6], int nrows, int ncols);
int roll_die();
void showDie(int num);
void advance(string M[][6]);
void cell_to_coordinates(int cell, int &row, int &col);
void player_advance(string M[][6], int &player_pos, int die, int nrows, int ncols);
bool is_trap(int cell);
bool game_finished(int player_pos);