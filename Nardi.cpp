#include "main_functions.hpp"
#include <iostream>
#include <locale>

int main(){
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    Board board;
    board.init();
    std::string winner = "";
    Field::ColorEnum current_turn = Field::White;
    while (winner == "") {
        int cubes[2] = { roll_cube(), roll_cube() };
        system("cls");
        board.draw_map();
        print_annotation(cubes, current_turn);
        if (cubes[0] == cubes[1]) {
            double_cubes_step(board, cubes, current_turn, winner);
        }
        else{
            simple_step(board, cubes, current_turn, winner);
        }
        current_turn = flip_turn(current_turn);
    }
    system("cls");
    board.draw_map();
    std::cout <<winner;
    system("pause");
}
