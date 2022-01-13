#pragma once
#include "color.h"
#include "Narda.h"
#include <vector>
struct Field {
	
	
	
	std::vector<Narda> Nards_in_field;
	int amount = Nards_in_field.size(); // колво нард в поле
	ColorEnum color = Nards_in_field[0].getcolor(); // цветовая принадлежность поля

	void Setfield() {

	}
};