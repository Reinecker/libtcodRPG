#ifndef CREATURES_TAG_BUTTON_H
#define CREATURES_TAG_BUTTON_H

#include "system.h"

class CreaturesTagButton: public Button
{
	public:
		CreaturesTagButton();
		void display(TCODConsole* console, int x, int y);
		void action();
};

#endif
