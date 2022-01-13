#pragma once
#include "color.h"
class Narda{
	ColorEnum color = None;
public:
	void setColor(ColorEnum color_to_set);
	ColorEnum getColor();
};

