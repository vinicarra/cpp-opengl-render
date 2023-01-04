#ifndef APPLICATION_H
#define APPLICATION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "ResourceManager.h"
#include "Renderer.h"
#include "Cube.h"

static int INITIAL_SCREEN_WIDTH = 800;
static int INITIAL_SCREEN_HEIGHT = 600;

class Application {
public:
	Application();
	~Application();

	void run();

private:
	GLFWwindow* m_Window;
};

#endif // APPLICATION_H

