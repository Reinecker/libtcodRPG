#include "system.h"

bool endGame = false;

int main()
{
    int inputSize = 0;
    char input[256];
    input[0] = '\0';
    int mouseX, mouseY;
    TCODSystem::setFps(60);
    TCODMouse::showCursor(true);

    TCODConsole::initRoot(160, 100, "RPG v0.0.1", false);

    GameScreen *gs = new GameScreen();

    while (!TCODConsole::isWindowClosed() && !endGame)
    {
	    TCODConsole::root->clear();
        gs->recieveInputString(input);
        gs->display();
        gs->checkButtons(mouseX, mouseY);
	    TCODConsole::flush();
        handleInput(input, &inputSize, &mouseX, &mouseY);
    }
    return 0;
}