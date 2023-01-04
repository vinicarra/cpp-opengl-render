#include "Application.h"

Application::Application()
{
	// 1. Initialize OpenGL
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// 2. Create window
	m_Window = glfwCreateWindow(INITIAL_SCREEN_WIDTH, INITIAL_SCREEN_HEIGHT, "Cube World", NULL, NULL);
	if (!m_Window)
	{
		throw std::runtime_error("Could not create window");
	}

	glfwMakeContextCurrent(m_Window);
	glfwSwapInterval(1);

	// 3. Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		throw std::runtime_error("Could not initialize GLAD");
	}

	// 4. Setup viewport and ImGUI
	glViewport(0, 0, 800, 600);
	glEnable(GL_DEPTH_TEST);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	// 5. Create window resize callback
	glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);

		auto renderer = Game::Renderer::GetInstance();

		renderer->SetProjectionMatrix(glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f));
	});
}

Application::~Application()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
}

void Application::run()
{
	auto renderer = Game::Renderer::GetInstance();

	std::vector<Game::Entity*> entities = {
		new Game::Cube(glm::vec3(-3.8f, -2.0f, -12.3f)),
		new Game::Cube(glm::vec3(2.4f, -0.4f, -3.5f)),
		new Game::Cube(glm::vec3(-1.7f, 3.0f, -7.5f))
	};

	float fSpeed = 20.0f;

	while (!glfwWindowShouldClose(m_Window))
	{
		// 1. Create ImGUI frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// 2. Clear background and depth buffer
		glClearColor(0.2f, 0.5f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// 3. Draw application data
		ImGui::Begin("Cube control");
		ImGui::Text("Rotation speed");
		ImGui::SliderFloat("Rotation speed", &fSpeed, 0.0f, 100.f);
		ImGui::End();

		renderer->SetDeltaTime(glfwGetTime());
		
		for (auto& entity : entities)
		{
			entity->Render();
		}

		// 4. Draw ImGUI
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// 5. Swap buffers and pool events
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
}
