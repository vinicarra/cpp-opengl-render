#ifndef CUBE_H
#define CUBE_H

#include "Entity.h"

namespace Game {

	class Cube : public Game::Entity {
	public:
		Cube(const glm::vec3& position) : m_Position(position) {};
		
		virtual void Update() override;
		virtual void Render() override;

		glm::vec3 m_Position;
	};

};

#endif // !CUBE_H

