#include "canvas.h"
#include <iostream>
#include "flag.h"

extern bool TK_QUIT = false;

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING); // initialize all SDL layers
	SDL_Renderer* r = NULL;
	SDL_Surface* s = NULL;
	SDL_Window* w = NULL;
	SDL_Event e;
	Vexil::Canvas *canvas = new Vexil::Canvas(r, s, w, &e);
	SDL_SetRenderDrawColor(canvas->getRenderer(), 255, 255, 255, 255);
	SDL_RenderClear(canvas->getRenderer());

	int response = 0;
	printf("\n= Ready = \n");
	printf("\nPress G on the main window to generate a flag with OpenSimplexNoise\n");
	SDL_RestoreWindow(canvas->getWindow());
	SDL_RenderClear(canvas->getRenderer());

	Vexil::Flag* flag = new Vexil::Flag(canvas);

	while (!TK_QUIT)
	{
		response = canvas->GetAllEvents();


		if (response == TK_CODE_QUITTING)
		{
			TK_QUIT = true;
		}
		else if (response == TK_CODE_SAVE)
		{
			canvas->SaveImage();
		}
	}

	if (TK_QUIT)
	{
		SDL_Delay(500);
		SDL_Quit();
	}



	return 0;
}