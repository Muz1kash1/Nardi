#include "main_functions.hpp"

Field::ColorEnum flip_turn(Field::ColorEnum current) {
    return (current == Field::White) ? Field::Black : Field::White;
}