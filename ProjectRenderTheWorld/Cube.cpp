#include "Cube.h"

void Game::Cube::Update()
{
}

void Game::Cube::Render()
{
	auto renderer = Renderer::GetInstance();
	renderer->RenderCube(m_Position);
}
