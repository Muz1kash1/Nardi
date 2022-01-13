#include "field.hpp"

int Field::getAmount() {
	return Nards_in_field.size();
}
ColorEnum Field::getColor() {
	if (Nards_in_field.size() > 0)
		return Nards_in_field[0].getColor();
	else return None;
}
void Field::setField() {
	//...
}