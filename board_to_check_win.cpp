#include "board.hpp"

const int figures_amount = 15;

std::string Board::to_check_win() {
	if (whites_leaved == figures_amount) return "����� ��������";
	if (blacks_leaved == figures_amount) return "׸���� ��������";
	return "";
} // ��������� ������� ������