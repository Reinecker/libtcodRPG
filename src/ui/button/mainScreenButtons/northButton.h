#ifndef NORTH_BUTTON_H
#define NORTH_BUTTON_H

#include "system.h"

class NorthButton: public Button
{
	public:
		NorthButton();
		void display(TCODConsole* console, int x, int y);
		void action();
};

#endif
