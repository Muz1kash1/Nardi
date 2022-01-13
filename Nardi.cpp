#include "board.hpp"
#include <iostream>
#include <locale>


int roll_cube() {
    return rand() % 6 + 1;
} // бросок куба

void print_annotation(int* cubes, ColorEnum current_turn) {
    std::cout << "Ходят ";
    std::cout << (current_turn == ColorEnum::White ? "белые" : "чёрные") << "\n";
    std::cout << "Выпали кости: " << cubes[0] << " и " << cubes[1] << "\n";
} // информация о ходе

std::string make_step(int cube, ColorEnum current_turn, Board& board) {
    int x;
    std::cout << "Введите номер ячейки откуда будет осуществлён ход на " << cube << " шагов: ";
    std::cin >> x;
    std::string error_msg = board.checkmove(x, cube, current_turn);
    std::cout << error_msg << "\n";
    return error_msg;
} // сделать ход

void simple_step(Board& board, int* cubes, ColorEnum current_turn, std::string& winner) {
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
} // ход если не дубль

void double_cubes_step(Board& board, int* cubes, ColorEnum current_turn, std::string& winner) {
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
} // ход если дубль(в 2 раза больше)

ColorEnum flip_turn(ColorEnum current) { 
    return (current == ColorEnum::White) ? ColorEnum::Black : ColorEnum::White;
} // Смена хода

int main(){
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    Board board;
    board.init();
    std::string winner = "";
    ColorEnum current_turn = ColorEnum::White;
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

