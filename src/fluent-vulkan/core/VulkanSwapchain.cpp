#include <set>

#include "VulkanSwapchain.h"
#include "VulkanInstance.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanLogicalDevice.h"
#include "VulkanSurface.h"

VulkanSwapchain::VulkanSwapchain()
{
	this->_swapchainInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
}

VulkanSwapchain::~VulkanSwapchain()
{
	vkDestroySwapchainKHR(
		this->_instance->logicalDevice()(),
		this->_swapchain,
		nullptr);
}

VkSwapchainKHR VulkanSwapchain::operator()()
{
	return this->_swapchain;;
}

VulkanSwapchain& VulkanSwapchain::selectExtent2D(VulkanSelectExtent2D fnSelect)
{
	VkSurfaceCapabilitiesKHR capabilities;
	vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
		this->_instance->physicalDevice()(),
		this->_instance->surface()(),
		&capabilities);
	this->_extent2D = fnSelect(capabilities);

	uint32_t imageCount = capabilities.minImageCount + 1;
	if (capabilities.maxImageCount > 0
		&& imageCount > capabilities.maxImageCount)
	{
		imageCount = capabilities.maxImageCount;
	}

	this->_swapchainInfo.preTransform = capabilities.currentTransform;
	this->_swapchainInfo.imageExtent = this->_extent2D;
	this->_swapchainInfo.minImageCount = imageCount;

	return *this;
}

VulkanSwapchain& VulkanSwapchain::selectFormat(VulkanSelectSurfaceFormat fnSelect)
{
	uint32_t formatCount;
	vkGetPhysicalDeviceSurfaceFormatsKHR(
		this->_instance->physicalDevice()(),
		this->_instance->surface()(),
		&formatCount,
		nullptr);

	if (formatCount != 0)
	{
		std::vector<VkSurfaceFormatKHR> surfaceFormats(formatCount);
		vkGetPhysicalDeviceSurfaceFormatsKHR(
			this->_instance->physicalDevice()(),
			this->_instance->surface()(),
			&formatCount,
			surfaceFormats.data());

		this->_format = fnSelect(surfaceFormats);

		this->_swapchainInfo.imageFormat = this->_format.format;
		this->_swapchainInfo.imageColorSpace = this->_format.colorSpace;
	}
	else
	{
		throw std::runtime_error("VulkanSwapchain: No formats available.");
	}
	
	return *this;
}

VulkanSwapchain& VulkanSwapchain::selectPresentationMode(VulkanSelectPresentationMode fnSelect)
{
	uint32_t presentationModesCount;
	vkGetPhysicalDeviceSurfacePresentModesKHR(
		this->_instance->physicalDevice()(),
		this->_instance->surface()(),
		&presentationModesCount,
		nullptr);

	if (presentationModesCount != 0)
	{
		std::vector<VkPresentModeKHR> presentationModes(presentationModesCount);
		vkGetPhysicalDeviceSurfacePresentModesKHR(
			this->_instance->physicalDevice()(),
			this->_instance->surface()(),
			&presentationModesCount,
			presentationModes.data());

			this->_presentationMode = fnSelect(presentationModes);

			this->_swapchainInfo.presentMode = this->_presentationMode;
	}
	else
	{
		throw std::runtime_error("VulkanSwapchain: No presentation modes available.");
	}

	return *this;
}

VulkanSwapchain& VulkanSwapchain::withClip(VkBool32 clipped)
{
	this->_swapchainInfo.clipped = clipped;
	return *this;
}

VulkanSwapchain& VulkanSwapchain::withCompositeAlpha(VkCompositeAlphaFlagBitsKHR alpha)
{
	this->_swapchainInfo.compositeAlpha = alpha;
	return *this;
}

VulkanSwapchain& VulkanSwapchain::withImageArrayLayers(int count)
{
	this->_swapchainInfo.imageArrayLayers = count;
	return *this;
}

VulkanSwapchain& VulkanSwapchain::withImageUsage(uint32_t usage)
{
	this->_swapchainInfo.imageUsage = usage;
	return *this;
}

VulkanSwapchain& VulkanSwapchain::withOldSwapchain(VkSwapchainKHR oldSwapChain)
{
	this->_swapchainInfo.oldSwapchain = oldSwapChain;
	return *this;
}

VulkanSwapchain& VulkanSwapchain::withQueueFamilies(VulkanFindQueueFamilies fnFind)
{
	std::set<int> uniqueQueueFamilies;
	std::vector<uint32_t> deviceQueueFamilies;
	for (auto queueFamily : fnFind(this->_instance))
	{
		std::set<int>::iterator it = uniqueQueueFamilies.find(queueFamily.second);

		if (it == uniqueQueueFamilies.end())
		{
			uniqueQueueFamilies.insert(queueFamily.second);
			deviceQueueFamilies.push_back(queueFamily.second);
		}
	}

	if (uniqueQueueFamilies.size() > 1)
	{
		this->_swapchainInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
		this->_swapchainInfo.queueFamilyIndexCount = static_cast<uint32_t>(deviceQueueFamilies.size());
		this->_swapchainInfo.pQueueFamilyIndices = deviceQueueFamilies.data();
	}
	else
	{
		this->_swapchainInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
		this->_swapchainInfo.pQueueFamilyIndices = nullptr;
		this->_swapchainInfo.queueFamilyIndexCount = 0;
	}
	return *this;
}

VulkanSwapchain& VulkanSwapchain::finalize()
{
	this->_swapchainInfo.surface = this->_instance->surface()();

	if (vkCreateSwapchainKHR(
		this->_instance->logicalDevice()(),
		&this->_swapchainInfo,
		nullptr,
		&this->_swapchain) != VK_SUCCESS)
	{
		throw std::runtime_error("VulkanSwapchain: unable to create swapchain.");
	}

	return *this;
}

VulkanSwapchain& VulkanSwapchain::attach(VulkanInstance* instance)
{
	this->_instance = instance;
	return *this;
}

VulkanInstance& VulkanSwapchain::instance()
{
	return *this->_instance;
}

VkSurfaceFormatKHR VulkanSwapchain::format()
{
	return this->_format;
}

VkPresentModeKHR VulkanSwapchain::presentationMode()
{
	return this->_presentationMode;
}

VkExtent2D VulkanSwapchain::extent2D()
{
	return this->_extent2D;
}