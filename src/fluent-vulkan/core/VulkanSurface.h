#pragma once

#ifndef VulkanSurface_H
#define VulkanSurface_H

#include <vulkan\vulkan.h>

#include "VulkanTypeDefs.h"

class VulkanInstance;

class VulkanSurface
{
private:
	VulkanInstance* _instance;

	VkSurfaceKHR _surface;
public:
	VulkanSurface();
	~VulkanSurface();

	VkSurfaceKHR& operator()();

	VulkanSurface& attach(VulkanInstance*);
	VulkanInstance& instance();

	VulkanSurface& create(VulkanCreateSurface);
};

#endif