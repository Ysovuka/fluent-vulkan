#pragma once

#ifndef VulkanDeubber_H
#define VulkanDebugger_H

#include <vulkan\vulkan.h>

class VulkanInstance;

class VulkanDebugger : VkDebugReportCallbackCreateInfoEXT
{
private:
	VulkanInstance* _instance;

	const VkAllocationCallbacks* _allocatorCallbacks;
	VkDebugReportCallbackEXT _callback;

public:
	VulkanDebugger();
	~VulkanDebugger();

	VulkanDebugger& attach(VulkanInstance*);
	VulkanInstance* instance();

	void dispose();
	VulkanDebugger& withAllocationCallbacks(const VkAllocationCallbacks*);
	VulkanDebugger& withCallback(PFN_vkDebugReportCallbackEXT);
	VulkanDebugger& withFlags(VkDebugReportFlagsEXT);
	VulkanDebugger& withNext(const void*);
	VulkanDebugger& finalize();
};

#endif