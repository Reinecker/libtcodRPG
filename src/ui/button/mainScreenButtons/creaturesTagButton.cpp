#include "system.h"

CreaturesTagButton::CreaturesTagButton()
{
	highlighted = false;
	width = 16;
	height = 5;
	button = new TCODConsole(width, height);
	button->setDefaultBackground(TCODColor::black);
}

void CreaturesTagButton::display(TCODConsole* console, int pX, int pY)
{
	x = pX;
	y = pY;
	if (highlighted)
	{
		button->setDefaultBackground(TCODColor::grey);
	}
	else
	{
		button->setDefaultBackground(TCODColor::black);
	}
	button->printFrame(0, 0, width, height, false);
	button->rect(1, 1, width - 2, height - 2, false, TCOD_BKGND_SET);
    button->print(1, 2, "Creatures Here");
    TCODConsole::blit(button, 0, 0, width, height, console, pX, pY);
}

void CreaturesTagButton::action()
{
	highlighted = true;
}