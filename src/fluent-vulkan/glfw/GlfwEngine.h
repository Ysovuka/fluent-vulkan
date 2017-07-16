#pragma once

#include <GLFW/glfw3.h>

class GlfwEngine
{
private:
	const int WIDTH = 800;
	const int HEIGHT = 600;


	GLFWwindow* _window;
public:
	GlfwEngine();
	~GlfwEngine();

	void init();
	void main();
	void cleanup();

	GLFWwindow* window();
};