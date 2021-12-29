#pragma once
struct Field {
	enum ColorEnum {
		None = 0,
		White = 1,
		Black = 2,
	};
	int amount;
	ColorEnum color;
};