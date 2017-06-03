#pragma once
#ifndef __KEEPER_H__
#define __KEEPER_H__

#include <cassert>
#include <iostream>
#include <SDL_render.h>
#include "TextureManager.h"

/* Keeper is the main class of the game engine
	Stores an unique entities such as TextureManager,
	renderer and provides access to them.
	also manage scenes
*/
class TextureManager;

class Keeper 
{
private:
	Keeper();
	Keeper(Keeper const&) = delete;				//forbid to copy and create new instances
	Keeper& operator= (Keeper const&) = delete;
	
	SDL_Renderer* renderer;
	SDL_Window* window;
	TextureManager* texManager;
public:
	static Keeper& getInstance();
	TextureManager* getTextureManager();

	void initRenderer(SDL_Renderer* _renderer);
	SDL_Renderer* getRenderer();

	void initWindow(SDL_Window* _window);
	//SDL_Window* getWindow(); 

	void end(); //End engine, release memory, destroy window
};

#endif // !__KEEPER_H__