#include "board.hpp"

const int board_size  = 24;
const int figures_amount = 15;

const int white_verge = 24;
const int black_verge = 12;

bool at_black_home(int x) {
	return 6 <= x && x <= 11;
} // � ���� �� ������ �����

bool at_white_home(int x) {
	return 18 <= x;
} // � ���� �� ����� �����

std::string Board::white_move(int end_cell, int cell) {
	if (end_cell >= white_verge) {
		if (homes.getWhites() != figures_amount) {
			return "������: ����� ����� �� ���� �� �������� ���� ����� � ����";
		}
		else {
			decrement_cell(cell);
			leaved.getWhites()++; // ����� ���� � �����
		}
	}
	else {
		end_cell %= board_size;
		if (play_fields[end_cell].getColor() == Black) {
			return "������: ��� ����� � ������";
		}
		decrement_cell(cell);
		if (!at_white_home(cell) && at_white_home(end_cell))
			homes.getWhites()++; // ����� ������ � ���
		increment_cell(end_cell, White); // ����� �������������
	}
	return "";
}
std::string Board::black_move(int end_cell, int cell) {
	if (cell < black_verge && end_cell >= black_verge) {
		if (homes.getBlacks() != figures_amount) {
			return "������: ����� ������ �� ���� �� �������� ���� ����� � ����";
		}
		else {
			decrement_cell(cell);
			leaved.getBlacks()++; // ����� ���� � �����
		}
	}
	else {
		end_cell %= board_size;
		if (play_fields[end_cell].getColor() == White) {
			return "������: ��� ������ � �����";
		}
		decrement_cell(cell);
		if (!at_black_home(cell) && at_black_home(end_cell))
			homes.getBlacks()++; // ����� ������ � ���
		increment_cell(end_cell, Black); // ����� �������������
	}
	return "";
}

std::string Board::checkmove(int cell, int step, Iplayer* player) {
	int end_cell = cell+step;
	ColorEnum color = play_fields[cell].getColor();
	if (color != player->getColor()) {
		return "������: ���� ����� � ������ �� ������������� ����� ������ (��� ������ �����)";
	}
	std::string res = player->makeMove(*this, cell, end_cell);
	return res;
}