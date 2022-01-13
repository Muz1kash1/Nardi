#include "board.hpp"

const int figures_amount = 15;

std::string Board::to_check_win() {
	if (leaved.getWhites()== figures_amount) return "����� ��������";
	if (leaved.getBlacks() == figures_amount) return "׸���� ��������";
	return "";
} // ��������� ������� ������