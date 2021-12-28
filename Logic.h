#pragma once


#include<iostream>
#include<vector>


#ifndef Nardi_h
#define Nardi_h

class Sole_fild {
private:
	int fieldnum; //номер поля
	std::vector<Fishka*> fishki_v_pole;
	bool if_is_a_house;
public:
	void set_state(bool& state)
	{
		if_is_a_house = state;
	}
	bool get_state()
	{
		return if_is_a_house;
	}
	std::vector<Fishka*> get_fishki() {
		return fishki_v_pole;
	}
	int get_num()
	{
		return fieldnum;
	}
	void set_num(int& num)
	{
		fieldnum = num;
	}
	void add_fishka(Fishka* fi)
	{
		fishki_v_pole.push_back(fi);
	}
};

class Fishka {
private:
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
	void Make_move();
};
#endif
