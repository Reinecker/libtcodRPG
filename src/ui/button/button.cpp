#include "system.h"

int Button::getX()
{
	return x;
}

int Button::getY()
{
	return y;
}

int Button::getWidth()
{
	return width;
}

int Button::getHeight()
{
	return height;
}

bool Button::isHighlighted()
{
	return highlighted;
}

void Button::setHighlighted(bool highlight)
{
	highlighted = highlight;
}

TCODConsole* Button::getButton()
{
	return button;
}