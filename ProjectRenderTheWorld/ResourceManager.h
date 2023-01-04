#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <iostream>
#include <unordered_map>
#include "stb_image.h"
#include "Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

enum ShaderEnum {
	DEFAULT,
	TEXTURE
};

enum TextureEnum {
	WALL,
	FOTO,
	GIULIA
};

class ResourceManager {
protected:
	ResourceManager();

	static ResourceManager* m_ResourceManager;
public:
	ResourceManager(ResourceManager& other) = delete;
	void operator=(const ResourceManager&) = delete;

	/* Get instance */
	static ResourceManager* GetInstance();

	Shader GetShader(ShaderEnum value);
	void BindTexture(TextureEnum value, GLenum position = GL_TEXTURE0);

	static uint32_t createVAO();
private:
	std::unordered_map<ShaderEnum, Shader> m_ShaderMap = {};
	std::unordered_map<TextureEnum, uint32_t> m_Textures = {};

	uint32_t loadTexture(const std::string& path);

	void SetupShaders();
	void SetupTextures();
};

#endif // !RESOURCE_MANAGER_H
