#include "system.h"

GameScreen::GameScreen()
{
    char *input;
	/* Boxes and frames */
	leftFrame = new TCODConsole(50, 51);
	leftFrame->setDefaultBackground(TCODColor::black);
	rightFrame = new TCODConsole(50, 51);
	rightFrame->setDefaultBackground(TCODColor::black);
	descriptionBox = new TCODConsole(160, 42);
	descriptionBox->setDefaultBackground(TCODColor::black);
	contextBox = new TCODConsole(60, 51);
	contextBox->setDefaultBackground(TCODColor::black);
	inputBox = new TCODConsole(160, 3);
	inputBox->setDefaultBackground(TCODColor::black);

	/* Tags and buttons */
	areaDescriptionTag = new AreaDescriptionTagButton();
    creaturesTag = new CreaturesTagButton();
    northButton = new NorthButton();

    descriptionBoxView = 0;
    areaDescriptionTag->setHighlighted(true);
}

void GameScreen::display()
{
	leftFrame->clear();
	rightFrame->clear();
    descriptionBox->clear();
    contextBox->clear();
    inputBox->clear();

	/* Display left frame */
	leftFrame->printFrame(0, 0, 50, 51, false); // Left frame
    leftFrame->printFrame(1, 1, 4, 5, false); // NW Box
    leftFrame->print(2, 3, "NW");
    TCODConsole::blit(leftFrame, 0, 0, 50, 52, TCODConsole::root, 0, 0);
    /* Left frame buttons */
    northButton->display(TCODConsole::root, 5, 1);

    /* Display right frame */
    rightFrame->printFrame(0, 0, 50, 51, false); // Right frame
    rightFrame->print(22, 2, "STATUS");
    TCODConsole::blit(rightFrame, 0, 0, 50, 52, TCODConsole::root, 110, 0);

    /* Display description box */
    descriptionBox->printFrame(0, 0, 160, 42, false); // Description Box
    TCODConsole::blit(descriptionBox, 0, 0, 160, 42, TCODConsole::root, 0, 55);

    /* Display context box */
    contextBox->printFrame(0, 0, 60, 51, false); // Context Box
    TCODConsole::blit(contextBox, 0, 0, 60, 51, TCODConsole::root, 50, 0);

    /* Display tags */
    areaDescriptionTag->display(TCODConsole::root, 0, 51);
    creaturesTag->display(TCODConsole::root, areaDescriptionTag->getWidth(), 51);

    /* Display input box */
    inputBox->printFrame(0, 0, 160, 3, false);
    inputBox->print(1, 1, input);
    TCODConsole::blit(inputBox, 0, 0, 160, 3, TCODConsole::root, 0, 97);
}

void GameScreen::checkButtons(int mouseX, int mouseY)
{
    /* Check area description tag button */
    if (mouseX >= areaDescriptionTag->getX() && mouseX <= areaDescriptionTag->getX() + areaDescriptionTag->getWidth() &&
        mouseY >= areaDescriptionTag->getY() && mouseY <= areaDescriptionTag->getY() + areaDescriptionTag->getHeight())
    {
        resetTagHighlights();
        descriptionBoxView = 0;
        areaDescriptionTag->action();
    }
    /* Check creatures tag button */
    if (mouseX >= creaturesTag->getX() && mouseX <= creaturesTag->getX() + creaturesTag->getWidth() &&
        mouseY >= creaturesTag->getY() && mouseY <= creaturesTag->getY() + creaturesTag->getHeight())
    {
        resetTagHighlights();
        descriptionBoxView = 1;
        creaturesTag->action();
    }
    /* Check move buttons */
    if (mouseX >= northButton->getX() && mouseX <= northButton->getX() + northButton->getWidth() &&
        mouseY >= northButton->getY() && mouseY <= northButton->getY() + northButton->getHeight())
    {
        northButton->action();
    }
}

void GameScreen::resetTagHighlights()
{
    areaDescriptionTag->setHighlighted(false);
    creaturesTag->setHighlighted(false);
}

void GameScreen::recieveInputString(char *inputString)
{
    input = inputString;
}
