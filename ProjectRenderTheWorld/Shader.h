#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <glad/glad.h>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

class Shader
{
public:
	Shader() = default;
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void use() { glUseProgram(m_ID); }
	uint32_t GetID() { return m_ID; }

	uint32_t GetTransformLocation();
	void SetTransform(glm::mat4 trans);

private:
	uint32_t m_ID = 0;
};

#endif // !SHADER_H
