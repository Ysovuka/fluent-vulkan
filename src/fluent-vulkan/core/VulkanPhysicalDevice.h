#pragma once

#ifndef VulkanPhysicalDevice_H
#define VulkanPhysicalDevice_H

#include <vulkan\vulkan.h>

#include "VulkanTypeDefs.h"

class VulkanInstance;

class VulkanPhysicalDevice
{
private:
	VulkanInstance* _instance;

	VkPhysicalDevice _physicalDevice;
public:
	VulkanPhysicalDevice();
	~VulkanPhysicalDevice();

	VkPhysicalDevice operator()();
	VulkanPhysicalDevice& select(VulkanSelectPhysicalDevice);

	VulkanPhysicalDevice& attach(VulkanInstance*);
	VulkanInstance* instance();
};

#endif