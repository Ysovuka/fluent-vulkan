#pragma once

#ifndef VulkanTypeDefs_H
#define VulkanTypeDefs_H

#include <vector>
#include <vulkan\vulkan.h>

typedef VkPhysicalDevice(*VulkanSelectPhysicalDevice)(std::vector<VkPhysicalDevice>);

#endif