#include "main_functions.hpp"
#include <iostream>

std::string make_step(int cube, Field::ColorEnum current_turn, Board& board) {
    int x;
    std::cout << "������� ����� ������ ������ ����� ���������� ��� �� " << cube << " �����: ";
    std::cin >> x;
    std::string error_msg = board.checkmove(x, cube, current_turn);
    std::cout << error_msg << "\n";
    return error_msg;
}