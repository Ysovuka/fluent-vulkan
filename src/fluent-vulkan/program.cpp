#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW\glfw3.h>

#include "fluent-vulkan.h"

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enabledValidationLayers = true;
#endif

const std::vector<const char*> validationLayers = {
	"VK_LAYER_LUNARG_standard_validation"
};


std::vector<const char*> getRequiredExtensions()
{
	std::vector<const char*> extensions;

	unsigned int glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	for (unsigned int i = 0; i < glfwExtensionCount; i++)
	{
		extensions.push_back(glfwExtensions[i]);
	}

	if (enabledValidationLayers) {
		extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
	}

	return extensions;
}


int main(int argc, char *argv[])
{
	VulkanInstance instance;

	instance
		.application()
			->withName("Fluent Vulkan")
			.withVersion(VK_MAKE_VERSION(1, 0, 0))
			.withApiVersion(VK_API_VERSION_1_0)
			.instance()
		->withExtensions(getRequiredExtensions())
		.withValidationLayers(validationLayers)
		.finalize();
}