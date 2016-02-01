#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "system.h"

class GameScreen: public Screen
{
	public:
		GameScreen();
		void display();
		void checkButtons(int mouseX, int mouseY);
		void recieveInputString(char *inputString);
	private:
		void resetTagHighlights();
		TCODConsole *leftFrame;
		TCODConsole *rightFrame;
		TCODConsole *descriptionBox;
		TCODConsole *contextBox;
		TCODConsole *inputBox;
		AreaDescriptionTagButton *areaDescriptionTag;
		CreaturesTagButton *creaturesTag;
		NorthButton *northButton;
		int descriptionBoxView;
		char *input;
};

#endif