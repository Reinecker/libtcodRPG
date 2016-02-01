#include "system.h"
#include <ctype.h>
#include <string.h>

void handleInput(char *inputArray, int *size, int *mouseX, int *mouseY)
{
	char ch;
	TCOD_mouse_t mouse;
	TCOD_event_t ev;
	
	TCOD_key_t key;
	ev = TCODSystem::checkForEvent(TCOD_EVENT_MOUSE|TCOD_KEY_PRESSED, &key, &mouse);

    if (key.vk != TCODK_NONE)
    {
    	if (key.vk == TCODK_BACKSPACE)
    	{
    		*size = *size - 1;
    		inputArray[*size] = '\0';
    	}
    	else if (key.vk == TCODK_SPACE)
    	{
    		inputArray[*size] = ' ';
		    inputArray[*size + 1] = '\0';
		    *size = *size + 1;
    	}
    	else if (key.vk == TCODK_ENTER)
    	{
    		processCommand(inputArray, size);
    		inputArray[0] = '\0';
    		*size = 0;
    	}
    	else if (key.vk == TCODK_CHAR && *size < 256)
    	{
    		if (key.shift == true)
    		{
				ch = key.c;
				ch = toupper(ch);
			    inputArray[*size] = ch;
			    inputArray[*size + 1] = '\0';
			    *size = *size + 1;
    		}
    		else
    		{
    			ch = key.c;
			    inputArray[*size] = ch;
			    inputArray[*size + 1] = '\0';
			    *size = *size + 1;
    		}
    	}
    }
    
    if (mouse.lbutton_pressed == true)
    {
        *mouseX = mouse.cx;
        *mouseY = mouse.cy;
    }
}

void processCommand(char *inputArray, int *size)
{
	if (strcmp(inputArray, "quit") == 0 || strcmp(inputArray, "exit") == 0)
	{
		printf("Exiting game...\n");
		endGame = true;
	}
}