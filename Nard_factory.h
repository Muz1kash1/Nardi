#pragma once
#include "Narda.h"
#include "color.h"
class Nard_factory{
private:
	Narda nard_to_return = Narda();
public:
	Narda create_nard(ColorEnum estimated_nard_color){
		nard_to_return.setColor(estimated_nard_color);
		return nard_to_return;
	}
};

