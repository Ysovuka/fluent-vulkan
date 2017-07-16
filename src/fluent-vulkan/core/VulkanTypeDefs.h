#pragma once

#ifndef VulkanTypeDefs_H
#define VulkanTypeDefs_H

#include <map>
#include <vector>
#include <vulkan\vulkan.h>

class VulkanInstance;

typedef VkPhysicalDevice(*VulkanSelectPhysicalDevice)(std::vector<VkPhysicalDevice>);
typedef const std::map<const std::string, int>(*VulkanFindQueueFamilies)(VulkanInstance);
typedef void(*VulkanCreateSurface)(VkInstance, VkSurfaceKHR&);

#endif