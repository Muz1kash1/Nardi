#pragma once
#include "Narda.h"
#include "color.h"
class Nard_factory
{
private:
	Narda nard_to_return;
public:
	 Narda create_nard(ColorEnum estimated_nard_color){
		 switch (estimated_nard_color)
		 {
		 case None:
			 nard_to_return.setcolor(ColorEnum{ None });
			 break;

		 case White:
			 nard_to_return.setcolor(ColorEnum{ White });

		 case Black:
			 nard_to_return.setcolor(ColorEnum{ Black});
		 }
		 return nard_to_return;
	}

};

