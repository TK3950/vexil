#pragma once
#ifndef CANVAS_H
#define CANVAS_H
#include <SDL.h>
#include "codes.h"
#define TK_WINDOW_HEIGHT 500
#define TK_WINDOW_WIDTH 809

namespace Vexil {
	class Canvas {

		SDL_Renderer*			renderer;
		SDL_Surface*			surface;
		SDL_Window*				window;
		SDL_Event*				events;
		SDL_Texture*			texture;

	public:
		Canvas(SDL_Renderer* r, SDL_Surface* s, SDL_Window* w, SDL_Event* e);
		SDL_Renderer* getRenderer();
		SDL_Window* getWindow();
		void UpdateToScreen();
		int GetAllEvents();
		bool SaveImage();

	};
}
#endif