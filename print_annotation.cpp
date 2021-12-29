#include "main_functions.hpp"
#include <iostream>

void print_annotation(int* cubes, Field::ColorEnum current_turn) {
    std::cout << "Ходят ";
    std::cout << (current_turn == Field::White ? "белые" : "чёрные") << "\n";
    std::cout << "Выпали кости: " << cubes[0] << " и " << cubes[1] << "\n";
}