#include "VulkanPhysicalDevice.h"
#include "VulkanInstance.h"
#include "VulkanLogicalDevice.h"

VulkanPhysicalDevice::VulkanPhysicalDevice()
{

}

VulkanPhysicalDevice::~VulkanPhysicalDevice()
{

}

VkPhysicalDevice VulkanPhysicalDevice::operator()()
{
	return this->_physicalDevice;
}

VulkanPhysicalDevice& VulkanPhysicalDevice::attach(VulkanInstance* instance)
{
	this->_instance = instance;
	return *this;
}

VulkanInstance& VulkanPhysicalDevice::instance()
{
	return *this->_instance;
}

VulkanLogicalDevice& VulkanPhysicalDevice::logicalDevice()
{
	return this->_instance->logicalDevice();
}

VulkanPhysicalDevice& VulkanPhysicalDevice::select(VulkanSelectPhysicalDevice fnSelectDevice)
{
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices((*this->_instance)(), &deviceCount, nullptr);

	if (deviceCount == 0)
	{
		throw std::runtime_error("VulkanPhysicalDevice: No supported device found.");
	}

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices((*this->_instance)(), &deviceCount, devices.data());

	_physicalDevice = fnSelectDevice(devices);

	return *this;
}