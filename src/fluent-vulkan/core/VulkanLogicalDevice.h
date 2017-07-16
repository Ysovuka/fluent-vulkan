#pragma once

#ifndef VulkanLogicalDevice_H
#define VulkanLogicalDevice_H

#include <vulkan\vulkan.h>

#include "VulkanTypeDefs.h"

class VulkanInstance;
class VulkanDeviceQueueFamily;
class VulkanDeviceFeatures;

class VulkanLogicalDevice
{
private:
	VulkanInstance* _instance;
	VulkanDeviceFeatures* _deviceFeatures;

	VkDeviceCreateInfo _logicalDeviceInfo;
	VkDevice _logicalDevice;

	std::map<std::string, VkQueue> _deviceQueues;
	std::map<std::string, VulkanDeviceQueueFamily*> _deviceQueueFamilies;

public:
	VulkanLogicalDevice();
	~VulkanLogicalDevice();

	VkDevice operator()();

	VulkanLogicalDevice& attach(VulkanInstance*);
	VulkanInstance& instance();

	VulkanLogicalDevice& withQueueFamilies(VulkanFindQueueFamilies);
	VulkanLogicalDevice& withExtensions(const std::vector<const char*>&);
	VulkanLogicalDevice& withValidationLayers(const std::vector<const char*>&);
	VulkanLogicalDevice& withFlags(uint32_t);
	VulkanLogicalDevice& withNext(const void*);
	VulkanLogicalDevice& finalize();

	VulkanDeviceFeatures& features();

	VkQueue queue(const std::string);
};

#endif