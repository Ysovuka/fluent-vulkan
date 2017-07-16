#include "GlfwEngine.h"

GlfwEngine::GlfwEngine()
{

}

GlfwEngine::~GlfwEngine()
{

}

void GlfwEngine::init()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	_window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
}

void GlfwEngine::main()
{
	while (!glfwWindowShouldClose(_window)) {
		glfwPollEvents();
	}
}

void GlfwEngine::cleanup()
{
	glfwDestroyWindow(_window);

	glfwTerminate();
}

GLFWwindow* GlfwEngine::window()
{
	return this->_window;
}