#include "VulkanDeviceQueueFamily.h"

#include "VulkanLogicalDevice.h"

VulkanDeviceQueueFamily::VulkanDeviceQueueFamily()
{
	this->sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	this->queueFamilyIndex = -1;
}

VulkanDeviceQueueFamily::~VulkanDeviceQueueFamily()
{

}

VulkanDeviceQueueFamily& VulkanDeviceQueueFamily::attach(VulkanLogicalDevice& logicalDevice)
{
	this->_logicalDevice = &logicalDevice;
	return *this;
}

VulkanLogicalDevice& VulkanDeviceQueueFamily::logicalDevice()
{
	return *this->_logicalDevice;
}

uint32_t VulkanDeviceQueueFamily::index()
{
	return this->queueFamilyIndex;
}

VulkanDeviceQueueFamily& VulkanDeviceQueueFamily::withCount(uint32_t count)
{
	this->queueCount = count;
	return *this;
}

VulkanDeviceQueueFamily& VulkanDeviceQueueFamily::withFamilyIndex(uint32_t index)
{
	this->queueFamilyIndex = index;
	return *this;
}

VulkanDeviceQueueFamily& VulkanDeviceQueueFamily::withPriority(const float& priority)
{
	this->pQueuePriorities = &priority;
	return *this;
}

VulkanDeviceQueueFamily& VulkanDeviceQueueFamily::withFlags(uint32_t flags)
{
	this->flags = flags;
	return *this;
}

VulkanDeviceQueueFamily& VulkanDeviceQueueFamily::withNext(const void* fnNext)
{
	this->pNext = fnNext;
	return *this;
}