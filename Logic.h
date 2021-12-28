#pragma once


#include<iostream>
#include<vector>
#include "spisok.h"


#ifndef Nardi_h
#define Nardi_h

class Sole_fild {
private:
	
	std::vector<Fishka*> fishki_v_pole;
	
public:

	std::vector<Fishka*> get_fishki() {
		return fishki_v_pole;
	}
	
	void add_fishka(Fishka* fi)
	{
		fishki_v_pole.push_back(fi);
	}

	void delete_fishka()
	{
		fishki_v_pole.pop_back();
	}
};

class Fishka {
public:
	bool color; // true - белый , false-черный
};

class Board {

	Sole_fild* play_fildes[24];
	void checkmove();
	void reset_map();
};

class Game {
	void getwinner();
	void Not_over();
	void Make_move(list& current_pos, int movestep, Fishka* fi);
};

class Player {
	public:
	bool color;
};
#endif
