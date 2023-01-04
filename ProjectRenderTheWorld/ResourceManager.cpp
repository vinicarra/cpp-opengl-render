#include "ResourceManager.h"

ResourceManager* ResourceManager::m_ResourceManager = nullptr;

ResourceManager::ResourceManager()
{
	std::cout << "Creating resource manager..." << std::endl;
	SetupShaders();
	SetupTextures();
}

ResourceManager* ResourceManager::GetInstance()
{
	if (m_ResourceManager == nullptr)
	{
		m_ResourceManager = new ResourceManager();
	}

	return m_ResourceManager;
}

uint32_t ResourceManager::createVAO()
{
	uint32_t iVao;
	glGenVertexArrays(1, &iVao);
	glBindVertexArray(iVao);

	return iVao;
}

void ResourceManager::SetupTextures()
{
	std::cout << "Load textures" << std::endl;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	m_Textures.insert({ TextureEnum::WALL, loadTexture("textures/wall.jpg") });
	m_Textures.insert({ TextureEnum::FOTO, loadTexture("textures/foto.jpg") });
	m_Textures.insert({ TextureEnum::GIULIA, loadTexture("textures/giulia.jpg") });
}

void ResourceManager::BindTexture(TextureEnum value, GLenum position)
{
	glActiveTexture(position);
	glBindTexture(GL_TEXTURE_2D, m_Textures.at(value));
}

uint32_t ResourceManager::loadTexture(const std::string& path)
{
	stbi_set_flip_vertically_on_load(true);
	int width, height, nrChannels;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

	if (data) {
		uint32_t texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);

		return texture;
	}
	else
	{
		stbi_image_free(data);
		std::cout << "ERROR::TEXTURE::LOAD_FAILED-> " << path << std::endl;
		return -1;
	}
}

void ResourceManager::SetupShaders()
{
	std::cout << "Create shaders" << std::endl;
	m_ShaderMap.insert({ ShaderEnum::DEFAULT, Shader("shaders/defaultShader.vs", "shaders/defaultShader.fs") });
	m_ShaderMap.insert({ ShaderEnum::TEXTURE, Shader("shaders/textureShader.vs", "shaders/textureShader.fs") });
}

Shader ResourceManager::GetShader(ShaderEnum value)
{
	return m_ShaderMap.at(value);
}