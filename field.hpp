#pragma once
#include "color.h"
#include "Narda.h"
#include <vector>
struct Field {
	std::vector<Narda> Nards_in_field;

	int getAmount();
	ColorEnum getColor();
	void setField();
};