#ifndef BUTTON_H
#define BUTTON_H

#include "system.h"

class Button
{
	public:
		virtual void display(TCODConsole* console, int x, int y) = 0;
		virtual void action() = 0;
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		bool isHighlighted();
		void setHighlighted(bool highlight);
		TCODConsole* getButton();
	protected:
		TCODConsole *button;
		int x;
		int y;
		int width;
		int height;
		bool highlighted;
};

#endif