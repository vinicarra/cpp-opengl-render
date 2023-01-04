#include "Renderer.h"

Game::Renderer* Game::Renderer::m_Renderer = nullptr;

Game::Renderer::Renderer()
{
	std::cout << "Creating renderer..." << std::endl;
	setup();
}

Game::Renderer* Game::Renderer::GetInstance()
{
	if (m_Renderer == nullptr) {
		m_Renderer = new Game::Renderer();
	}
	return m_Renderer;
}

void Game::Renderer::SetDeltaTime(const double& newValue)
{
	m_DeltaTime = newValue;
}

double Game::Renderer::GetDeltaTime()
{
	return m_DeltaTime;
}

void Game::Renderer::RenderCube(const glm::vec3& position)
{
	auto shader = ResourceManager::GetInstance()->GetShader(ShaderEnum::TEXTURE);
	shader.use();

	glBindVertexArray(m_TexCubeVAO);

	ResourceManager::GetInstance()->BindTexture(TextureEnum::WALL);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::rotate(model, (float)GetDeltaTime() * glm::radians(20.0f), glm::vec3(0.5f, 1.0f, 0.0f));

	glm::mat4 mvp = GetProjectionMatrix() * GetViewMatrix() * model;

	shader.SetTransform(mvp);

	glDrawArrays(GL_TRIANGLES, 0, TexturedCubeVertexes.size());
}

void Game::Renderer::setup()
{
	// 1. Setup view & projection matrices
	m_ViewMatrix = glm::mat4(1.0f);
	m_ViewMatrix = glm::translate(m_ViewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
	m_ProjectionMatrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	// Tile render setup
	m_TileVAO = ResourceManager::createVAO();
	glGenBuffers(1, &m_TileVBO);
	glGenBuffers(1, &m_TileEBO);

	glBindBuffer(GL_ARRAY_BUFFER, m_TileVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * TileVertexes.size(), &TileVertexes.front(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_TileEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * TileEBO.size(), &TileEBO.front(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Cube render setup
	m_CubeVAO = ResourceManager::createVAO();
	glGenBuffers(1, &m_CubeVBO);

	glBindBuffer(GL_ARRAY_BUFFER, m_CubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * CubeVertexes.size(), &CubeVertexes.front(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Cube textured setup
	m_TexCubeVAO = ResourceManager::createVAO();
	glGenBuffers(1, &m_TexCubeVBO);

	glBindBuffer(GL_ARRAY_BUFFER, m_TexCubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(TexVertex) * TexturedCubeVertexes.size(), &TexturedCubeVertexes.front(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

glm::mat4 Game::Renderer::GetViewMatrix()
{
	return m_ViewMatrix;
}

glm::mat4 Game::Renderer::GetProjectionMatrix()
{
	return m_ProjectionMatrix;
}

void Game::Renderer::SetViewMatrix(glm::mat4 newValue)
{
	m_ViewMatrix = newValue;
}

void Game::Renderer::SetProjectionMatrix(glm::mat4 newValue)
{
	m_ProjectionMatrix = newValue;
}
