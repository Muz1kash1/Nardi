#include "board.hpp"

const int figures_amount = 15;

std::string Board::to_check_win() {
	if (leaved.getWhites()== figures_amount) return "Белые победили";
	if (leaved.getBlacks() == figures_amount) return "Чёрные победили";
	return "";
} // проверить условие победы