#ifndef RENDERER_H
#define RENDERER_H

#include "ResourceManager.h"

namespace Game {

	struct Vertex {
		float x, y, z;
		float r, g, b;
	};

	struct TexVertex {
		float x, y, z;
		float ux, uy;
	};

	static std::vector<Vertex> CubeVertexes = {
		{ -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f },
		{  0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f },
		{  0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f },
		{  0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f },
		{ -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f },
		{ -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f },
										   
		{ -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f },
		{  0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f },
		{  0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f },
		{  0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f },
		{ -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f },
		{ -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f },
	 									   
		{ -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f },
		{ -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 1.0f },
		{ -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f },
		{ -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f },
		{ -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f },
		{ -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f },
	 									   
		{  0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f },
		{  0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f },
		{  0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f },
		{  0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f },
		{  0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f },
		{  0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f },
	 									   
		{ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f },
		{  0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f },
		{  0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f },
		{  0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f },
		{ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f },
		{ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f },
										   
		{ -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f },
		{  0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f },
		{  0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f },
		{  0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f },
		{ -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f },
		{ -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f }
	};

	static std::vector<TexVertex> TexturedCubeVertexes = {
		{ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f },
		{  0.5f, -0.5f, -0.5f,  1.0f, 0.0f },
		{  0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
		{  0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
		{ -0.5f,  0.5f, -0.5f,  0.0f, 1.0f },
		{ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f },
										 
		{ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
		{  0.5f, -0.5f,  0.5f,  1.0f, 0.0f },
		{  0.5f,  0.5f,  0.5f,  1.0f, 1.0f },
		{  0.5f,  0.5f,  0.5f,  1.0f, 1.0f },
		{ -0.5f,  0.5f,  0.5f,  0.0f, 1.0f },
		{ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
										 
		{ -0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
		{ -0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
		{ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
		{ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
		{ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
		{ -0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
										 
		{  0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
		{  0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
		{  0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
		{  0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
		{  0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
		{  0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
										 
		{ -0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
		{  0.5f, -0.5f, -0.5f,  1.0f, 1.0f },
		{  0.5f, -0.5f,  0.5f,  1.0f, 0.0f },
		{  0.5f, -0.5f,  0.5f,  1.0f, 0.0f },
		{ -0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
		{ -0.5f, -0.5f,  -0.5f, 0.0f, 1.0f },
										 
		{ -0.5f,  0.5f, -0.5f,  0.0f, 1.0f },
		{  0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
		{  0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
		{  0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
		{ -0.5f,  0.5f,  0.5f,  0.0f, 0.0f },
		{ -0.5f,  0.5f, -0.5f,  0.0f, 1.0f }
	};

	static std::vector<glm::vec3> cubePositions = {
		glm::vec3( 0.0f,  0.0f,  0.0f),
		glm::vec3( 2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3( 2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3( 1.3f, -2.0f, -2.5f),
		glm::vec3( 1.5f,  2.0f, -2.5f),
		glm::vec3( 1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	static std::vector<Vertex> TileVertexes = {
		{  0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f }, // Top right
		{  0.5f, -0.5f, 0.0f, 1.0f, 0.5f, 1.0f }, // Bottom right
		{ -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.5f }, // Bottom left
		{ -0.5f,  0.5f, 0.0f, 0.5f, 1.0f, 1.0f }, // Top left
	};

	static std::vector<uint32_t> TileEBO = {
		0, 1, 3, // 1st triangle
		1, 2, 3, // 2nd triangle
	};

	class Renderer {
	protected:
		Renderer();

		static Renderer* m_Renderer;
	public:
		Renderer(Renderer& other) = delete;
		void operator=(const Renderer&) = delete;

		static Renderer* GetInstance();

		void SetDeltaTime(const double& newValue);
		double GetDeltaTime();

		void RenderCube(const glm::vec3& position);

		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjectionMatrix();

		void SetViewMatrix(glm::mat4 newValue);
		void SetProjectionMatrix(glm::mat4 newValue);

	private:
		/* Setup will create necessary VAOs and VBOs to render 
		*  duplicate objects.
		*/
		void setup();

		double m_DeltaTime = 0;
		uint32_t m_TileVAO, m_TileVBO, m_TileEBO;
		uint32_t m_CubeVAO, m_CubeVBO;
		uint32_t m_TexCubeVAO, m_TexCubeVBO;

		glm::mat4 m_ViewMatrix, m_ProjectionMatrix;
	};

}

#endif // !RENDERER_H
