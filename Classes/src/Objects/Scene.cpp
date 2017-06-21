#include "..\..\include\Objects\Scene.h"
#include <iostream>

void Scene::draw()
{
	Node::draw();
}

void Scene::update(float dt)
{
	if (_update != nullptr) {
		const Uint8* state = SDL_GetKeyboardState(NULL);
		try {
			_update(state, dt);
		}
		catch (const std::bad_function_call& e) {
			std::cout << e.what() << '\n';
		}
	}
}