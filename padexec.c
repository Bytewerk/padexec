#include <stdio.h>
#include <SDL2/SDL.h>

/*
	This program simply executes programs, when a key gets pressed
	from a game pad (or whatever SDL2 detects as joystick).
	
	License: GPLv2
	
	Dependencies:
		- SDL2
		- Very little C/programming knowledge
	
	HOWTO:
	- Compile this program (run make)
	- Attach your device
	- start it to get the device name
	- copy paste the device name from the terminal to the
	  configuration variable below
	- rebuild the program, run it again
	- press keys to get the button IDs
	- adjust the button_action function to run commands
	  that you like, when a certain key gets pressed. Don't
	  forget the return in switch...case!
	- make again, test if it works as desired
	- you can do the same thing for configuring axis actions
	
	HINTS:
	- simulating keypresses and other sick X11 stuff should
	  be possible with xdotool and similar programs
*/


//
// CONFIG START
//

#define CONFIG_JOYSTICK_NAME "YuanChen Game Controller"


void button_action(int id)
{
	switch(id)
	{
		case 9:
			system("mpc toggle");
			return;
		case 5:
			system("mpc next");
			return;
		case 4:
			system("mpc prev");
			return;
		case 2:
			system("mpc stop");
			return;
	}
	
}

void axis_action(int id, int value)
{
	/*
		if(id == 0 && value > 1000)
		{
			system("echo trololo");
			return;
		}
	*/
}

//
// CONFIG END
//


int main(int argc, char* argv[])
{
	// Initialize SDL2
	if(SDL_Init(SDL_INIT_GAMECONTROLLER) < 0)
		return printf("ERROR from SDL: %s\n", SDL_GetError());
	
	// List the config all available joysticks
	int pad_count = SDL_NumJoysticks();
	int found = -1;
	printf("To make any use of this program, you'll need to hack up the source for your needs.\n\n");
	printf("CONFIG_JOYSTICK_NAME: %s\n\n", CONFIG_JOYSTICK_NAME);
	printf("Here's a list of attached joystick(s) (%i total):\n", pad_count);
	for(int i=0;i<pad_count;i++)
	{
		printf("\t#%i: %s\n", i, SDL_JoystickNameForIndex(i));
		if(!strcmp(SDL_JoystickNameForIndex(i), CONFIG_JOYSTICK_NAME))
			found = i;
	}
	printf("\n");
	
	// Quit if it wasn't found
	if(found == -1)
		exit(printf("ERROR: Couldn't find the joystick that is configured. Exiting.\n"));
	
	// On success, print some details
	printf("Yay, found the pad we were looking for \\o/\n");
	SDL_Joystick* joy = SDL_JoystickOpen(found);
	if(!joy) exit(printf("...but opening it has failed. Exiting.\n"));
	printf("Number of Axes: %d\n", SDL_JoystickNumAxes(joy));
	printf("Number of Buttons: %d\n", SDL_JoystickNumButtons(joy));
	
	
	// Wait for keypresses
	while(1)
	{
		SDL_Event e;
		SDL_WaitEvent(&e);
		
		if(e.type == SDL_QUIT) exit(0);
		if(e.type == SDL_JOYBUTTONDOWN)
		{
			printf("Button: %i\n", e.jbutton.button);
			button_action(e.jbutton.button);
		}
		if(e.type == SDL_JOYAXISMOTION)
		{
			// if this goes off all the time, you should define a treshhold here!
			
			printf("Axis: %i, value: %i\n", e.jaxis.axis, e.jaxis.value);
			axis_action(e.jaxis.axis, e.jaxis.value);
		}
	}
}
