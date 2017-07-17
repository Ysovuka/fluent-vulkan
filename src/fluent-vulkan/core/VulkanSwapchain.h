#pragma once

#ifndef VulkanSwapchain_H
#define VulkanSwapchain_H

#include <vulkan\vulkan.h>

#include "VulkanTypeDefs.h"

class VulkanInstance;

class VulkanSwapchain
{
private:
	VulkanInstance* _instance;

	VkSurfaceFormatKHR _format;
	VkPresentModeKHR _presentationMode;
	VkExtent2D _extent2D;

	VkSwapchainCreateInfoKHR _swapchainInfo;
	VkSwapchainKHR _swapchain;
public:
	VulkanSwapchain();
	~VulkanSwapchain();

	VkSwapchainKHR operator()();

	VulkanSwapchain& attach(VulkanInstance*);
	VulkanInstance& instance();

	VulkanSwapchain& selectFormat(VulkanSelectSurfaceFormat);
	VulkanSwapchain& selectPresentationMode(VulkanSelectPresentationMode);
	VulkanSwapchain& selectExtent2D(VulkanSelectExtent2D);

	VulkanSwapchain& withImageArrayLayers(int);
	VulkanSwapchain& withImageUsage(uint32_t);
	VulkanSwapchain& withQueueFamilies(VulkanFindQueueFamilies);
	VulkanSwapchain& withCompositeAlpha(VkCompositeAlphaFlagBitsKHR);
	VulkanSwapchain& withClip(VkBool32);
	VulkanSwapchain& withOldSwapchain(VkSwapchainKHR);
	VulkanSwapchain& finalize();

	VkSurfaceFormatKHR format();
	VkPresentModeKHR presentationMode();
	VkExtent2D extent2D();
};

#endif