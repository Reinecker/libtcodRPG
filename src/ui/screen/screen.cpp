#include "../system.h"

bool Screen::isActive()
{
	return active;
}

void Screen::setActive(bool a)
{
	active = a;
}
