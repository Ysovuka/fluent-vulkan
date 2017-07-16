#pragma once

#ifndef VulkanDeviceQueueFamily_H
#define VulkanDeviceQueueFamily_H

#include <vulkan\vulkan.h>

class VulkanLogicalDevice;

class VulkanDeviceQueueFamily : public VkDeviceQueueCreateInfo
{
private:
	VulkanLogicalDevice* _logicalDevice;

public:
	VulkanDeviceQueueFamily();
	~VulkanDeviceQueueFamily();

	VulkanDeviceQueueFamily& attach(VulkanLogicalDevice& logicalDevice);
	VulkanLogicalDevice& logicalDevice();

	uint32_t index();

	VulkanDeviceQueueFamily& withCount(uint32_t count);
	VulkanDeviceQueueFamily& withFamilyIndex(uint32_t index);
	VulkanDeviceQueueFamily& withFlags(uint32_t flags);
	VulkanDeviceQueueFamily& withNext(const void* fnNext);
	VulkanDeviceQueueFamily& withPriority(const float& priority);
};

#endif