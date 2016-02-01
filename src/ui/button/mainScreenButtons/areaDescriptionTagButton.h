#ifndef AREA_DESCRIPTION_TAG_BUTTON_H
#define AREA_DESCRIPTION_TAG_BUTTON_H

#include "system.h"

class AreaDescriptionTagButton: public Button
{
	public:
		AreaDescriptionTagButton();
		void display(TCODConsole* console, int x, int y);
		void action();
};

#endif
