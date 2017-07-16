#pragma once

#ifndef VulkanInstance_H
#define VulkanInstance_H

#include <vector>

#include <vulkan\vulkan.h>

class VulkanApplication;
class VulkanDebugger;
class VulkanPhysicalDevice;
class VulkanLogicalDevice;
class VulkanSurface;

class VulkanInstance
{
private:
	VkInstance _instance;
	VkInstanceCreateInfo _instanceInfo;

	VulkanApplication* _application;
	VulkanDebugger* _debugger;
	VulkanPhysicalDevice* _physicalDevice;
	VulkanLogicalDevice* _logicalDevice;
	VulkanSurface* _surface;
public:
	VulkanInstance();
	~VulkanInstance();

	VkInstance operator()();
	VulkanInstance& withExtensions(const std::vector<const char*>&);
	VulkanInstance& withValidationLayers(const std::vector<const char*>&);
	VulkanInstance& withFlags(uint32_t);
	VulkanInstance& withNext(const void*);
	VulkanInstance& finalize();
	void dispose();

	VulkanApplication& application();
	VulkanDebugger& debugger();
	VulkanPhysicalDevice& physicalDevice();
	VulkanLogicalDevice& logicalDevice();
	VulkanSurface& surface();
};

#endif