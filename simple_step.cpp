#include "main_functions.hpp"

void simple_step(Board& board, int* cubes, Field::ColorEnum current_turn, std::string& winner) {
    std::string error_msg;
    for (int i = 0; i < 2; i++) {
        do {
            error_msg = make_step(cubes[i], current_turn, board);
        } while (error_msg != "");
        system("cls");
        board.draw_map();
        print_annotation(cubes, current_turn);
        winner = board.to_check_win();
        if (winner != "") break;
    }
}