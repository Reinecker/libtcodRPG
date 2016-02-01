#ifndef SCREEN_H
#define SCREEN_H

#include "system.h"

class Screen
{
	public:
		virtual void display() = 0;
		virtual void checkButtons(int mouseX, int mouseY) = 0;
		bool isActive();
		void setActive(bool a);
	protected:
		bool active;
};

#endif