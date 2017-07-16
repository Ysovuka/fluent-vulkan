#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW\glfw3.h>

#include "glfw\GlfwEngine.h"
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

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
	VkDebugReportFlagsEXT flags,
	VkDebugReportObjectTypeEXT objType,
	uint64_t obj,
	size_t location,
	int32_t code,
	const char* layerPrefix,
	const char* msg,
	void* userData) {

	std::cerr << "validation layer: " << msg << std::endl;

	return VK_FALSE;
};


bool isDeviceSuitable(VkPhysicalDevice device) {
	VkPhysicalDeviceProperties deviceProperties;
	VkPhysicalDeviceFeatures deviceFeatures;
	vkGetPhysicalDeviceProperties(device, &deviceProperties);
	vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

	return deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU &&
		deviceFeatures.geometryShader;
}

VkPhysicalDevice findSuitableDevice(std::vector<VkPhysicalDevice> devices)
{
	for (const auto& device : devices) {
		if (isDeviceSuitable(device)) {
			return device;
		}
	}

	throw std::runtime_error("Unable to find suitable GPU device.");
}


VkBool32 devicePresentationSupport(VulkanInstance* instance, int queueFamilyIndex)
{
	VkBool32 presentationSupport = false;
	vkGetPhysicalDeviceSurfaceSupportKHR((instance->physicalDevice())(), queueFamilyIndex, (instance->surface())(), &presentationSupport);

	return presentationSupport;
}

const std::map<const std::string, int> deviceQueueFamilies(VulkanInstance* instance, std::vector<VkQueueFamilyProperties> deviceQueueFamilyProperties)
{
	std::map<const std::string, int> returnValue;

	int i = 0;
	int graphicsFamily = -1;
	int presentationFamily = -1;
	for (const auto& queueFamily : deviceQueueFamilyProperties)
	{
		if (queueFamily.queueCount > 0 && queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
		{
			graphicsFamily = i;
		}

		VkBool32 presentationSupport = devicePresentationSupport(instance, i);
		if (queueFamily.queueCount > 0 && presentationSupport)
		{
			presentationFamily = i;
		}

		if (graphicsFamily >= 0
			&& presentationFamily >= 0)
		{
			returnValue.insert(std::pair<std::string, int>("graphics", graphicsFamily));
			returnValue.insert(std::pair<std::string, int>("presentation", presentationFamily));

			return returnValue;
		}

		i++;
	}

	return returnValue;
}

const std::map<const std::string, int> findQueueFamilies(VulkanInstance* instance)
{
	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties((instance->physicalDevice())(), &queueFamilyCount, nullptr);

	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties((instance->physicalDevice())(), &queueFamilyCount, queueFamilies.data());

	return deviceQueueFamilies(instance, queueFamilies);
}


const std::vector<const char*> deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

GlfwEngine* engine;
void createSurface(VkInstance instance, VkSurfaceKHR& surface)
{
	if (glfwCreateWindowSurface(instance, engine->window(), nullptr, &surface) != VK_SUCCESS) {
		throw std::runtime_error("failed to create window surface!");
	}
}

int main(int argc, char *argv[])
{
	engine = new GlfwEngine();
	engine->init();
	VulkanInstance instance;

	instance
		.application()
			.withName("Fluent Vulkan")
			.withVersion(VK_MAKE_VERSION(1, 0, 0))
			.withApiVersion(VK_API_VERSION_1_0)
			.instance()
		.debugger()
			.withCallback(debugCallback)
			.withFlags(VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT)
			.instance()
		.withExtensions(getRequiredExtensions())
		.withValidationLayers(validationLayers)
		.finalize()
		.surface()
			.create(createSurface)
			.instance()
		.physicalDevice()
			.select(findSuitableDevice)
			.logicalDevice()
				.withQueueFamilies(findQueueFamilies)
				.withExtensions(deviceExtensions)
				.withValidationLayers(validationLayers)
				.finalize();

	engine->main();

	instance.dispose();
	engine->cleanup();

	system("pause");
}