#pragma once
#include "color.h"
#include "Narda.h"
#include <vector>
struct Field {
	
	
	
	std::vector<Narda> Nards_in_field;
	int amount = Nards_in_field.size(); // ����� ���� � ����
	ColorEnum color = Nards_in_field[0].getcolor(); // �������� �������������� ����

	void Setfield() {

	}
};