#include "main_functions.hpp"
#include <iostream>

void print_annotation(int* cubes, Field::ColorEnum current_turn) {
    std::cout << "����� ";
    std::cout << (current_turn == Field::White ? "�����" : "������") << "\n";
    std::cout << "������ �����: " << cubes[0] << " � " << cubes[1] << "\n";
}