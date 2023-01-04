#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Renderer.h"

namespace Game {

	class Entity {
	public:
		Entity();
		Entity(Entity& other) = delete;
		void operator=(const Entity&) = delete;

		virtual void Update() = 0;
		virtual void Render() = 0;
	};
}

#endif // !GAME_OBJECT_H
