#pragma once

#ifndef VulkanApplication_H
#define VulkanApplication_H

#include <vulkan\vulkan.h>

class VulkanInstance;

class VulkanApplication : VkApplicationInfo
{
private:
	VulkanInstance* _instance;

public:
	VulkanApplication();
	~VulkanApplication();

	VulkanApplication& attach(VulkanInstance*);
	VulkanInstance* instance();

	VulkanApplication& withName(const char*);
	VulkanApplication& withVersion(uint32_t);
	VulkanApplication& withEngine(const char*, uint32_t);
	VulkanApplication& withApiVersion(uint32_t);

};

#endif