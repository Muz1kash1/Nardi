#include "board.hpp"
#include <iostream>
#include "color.h"
int getX(int i) {
	if (i < 12) 
		 return (24-2*i);
	else return (2*i-22);
} // вернуть координату в холсте

// функция отрисовки доски
void Board::draw_map() {
	char canvas[31][29];
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 28; j++)
			canvas[i][j] = ' ';
		canvas[i][28] = '\0';
	}
	for (int i = 0; i < 24; i++) {
		Field field = play_fields[i];
		if (field.amount > 0) {
			char brush = (field.color == ColorEnum{White}) ? 'W' : 'B';
			int x = getX(i);
			if (i < 12) {
				for (int j = 0; j < field.amount; j++) {
					canvas[j][x-1] = '|';
					canvas[j][x] = brush;
					canvas[j][x+1] = '|';
				}
			} // нарды отображаются сверху в низ для верних 12 полей
			else {
				for (int j = 0; j < field.amount; j++) {
					canvas[30-j][x - 1] = '|';
					canvas[30-j][x] = brush;
					canvas[30-j][x + 1] = '|';
				} 
			} // и снизу вверх для нижних 12
		}
	}
	for (int i = 0; i < 12; i++) {
		canvas[0][2 * i + 1] = '|';
		canvas[30][2 * i + 1] = '|';
	}
	for (int i = 0; i < whites_leaved; i++)
		canvas[8 + i][27] = 'W';
	for (int i = 0; i < blacks_leaved; i++)
		canvas[8+i][0] = 'B';

	for (int i = 0; i < 31; i++)
		std::cout << canvas[i] <<"\n"; 

}

