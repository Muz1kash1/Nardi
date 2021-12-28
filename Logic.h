#pragma once


#include<iostream>
#include<vector>
#include "spisok.h"


#ifndef Nardi_h
#define Nardi_h

struct Field{
	enum ColorEnum {
		None = 0,
		White = 1,
		Black = 2,
	};
	int amount;
	ColorEnum color;
};

class Board {
	Field play_fildes[24];
	int white_home;
	int black_home;

	void init_board();

	void checkmove(int cell, int step);
	void draw_map();
};



Board::checkmove(int cell, int step){
	int end_cell = cell+step;
	if(end_cell)
}

class Player {
	public:
	bool color;
};
#endif
