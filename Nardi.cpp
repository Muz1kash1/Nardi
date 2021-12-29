#include "board.hpp"
#include <iostream>
#include <locale>


int roll_cube() {
    return rand() % 6 + 1;
}

void print_annotation(int* cubes, Field::ColorEnum current_turn) {
    std::cout << "Ходят ";
    std::cout << (current_turn == Field::White ? "белые" : "чёрные") << "\n";
    std::cout << "Выпали кости: " << cubes[0] << " и " << cubes[1] << "\n";
}

std::string make_step(int cube, Field::ColorEnum current_turn, Board& board) {
    int x;
    std::cout << "Введите номер ячейки откуда будет осуществлён ход на " << cube << " шагов: ";
    std::cin >> x;
    std::string error_msg = board.checkmove(x, cube, current_turn);
    std::cout << error_msg << "\n";
    return error_msg;
}

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

void double_cubes_step(Board& board, int* cubes, Field::ColorEnum current_turn, std::string& winner) {
    std::string error_msg;
    for (int i = 0; i < 4; i++) {
        do {
            error_msg = make_step(cubes[0], current_turn, board);
        } while (error_msg != "");
        system("cls");
        board.draw_map();
        print_annotation(cubes, current_turn);
        winner = board.to_check_win();
        if (winner != "") break;
    }
}

Field::ColorEnum flip_turn(Field::ColorEnum current) {
    return (current == Field::White) ? Field::Black : Field::White;
}

int main(){
    setlocale(LC_ALL, "Russian");

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

