#pragma once

#ifndef VulkanTypeDefs_H
#define VulkanTypeDefs_H

#include <map>
#include <vector>
#include <vulkan\vulkan.h>

class VulkanInstance;

// Physical Device
typedef VkPhysicalDevice(*VulkanSelectPhysicalDevice)(std::vector<VkPhysicalDevice>);

// Logical Device
typedef const std::map<const std::string, int>(*VulkanFindQueueFamilies)(VulkanInstance*);

// Surface
typedef void(*VulkanCreateSurface)(VkInstance, VkSurfaceKHR&);

// Swapchain
typedef VkSurfaceFormatKHR(*VulkanSelectSurfaceFormat)(const std::vector<VkSurfaceFormatKHR>);
typedef VkPresentModeKHR(*VulkanSelectPresentationMode)(const std::vector<VkPresentModeKHR>);
typedef VkExtent2D(*VulkanSelectExtent2D)(const VkSurfaceCapabilitiesKHR&);

#endif