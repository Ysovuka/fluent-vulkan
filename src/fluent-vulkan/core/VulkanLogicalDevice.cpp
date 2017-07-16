#include <set>

#include "VulkanLogicalDevice.h"
#include "VulkanInstance.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanDeviceFeatures.h"
#include "VulkanDeviceQueueFamily.h"

VulkanLogicalDevice::VulkanLogicalDevice()
{
	this->_logicalDeviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
}

VulkanLogicalDevice::~VulkanLogicalDevice()
{
	vkDestroyDevice(this->_logicalDevice, nullptr);
}

VkDevice VulkanLogicalDevice::operator()()
{
	return this->_logicalDevice;
}

VulkanLogicalDevice& VulkanLogicalDevice::attach(VulkanInstance* instance)
{
	this->_instance = instance;
	return *this;
}

VulkanInstance& VulkanLogicalDevice::instance()
{
	return *this->_instance;
}

VulkanDeviceFeatures& VulkanLogicalDevice::features()
{
	if (this->_deviceFeatures == nullptr)
	{
		this->_deviceFeatures = new VulkanDeviceFeatures();
		this->_deviceFeatures->attach(*this);
		this->_logicalDeviceInfo.pEnabledFeatures = this->_deviceFeatures;
	}

	return *this->_deviceFeatures;
}

VulkanLogicalDevice& VulkanLogicalDevice::withQueueFamilies(VulkanFindQueueFamilies fnFind)
{
	this->_deviceQueueFamilies.clear();

	float priority = 1.0;
	for (auto queueFamily : fnFind(this->_instance))
	{
		std::map<std::string, VulkanDeviceQueueFamily*>::iterator it;
		it = this->_deviceQueueFamilies.find(queueFamily.first);

		if (it == this->_deviceQueueFamilies.end())
		{
			VulkanDeviceQueueFamily* deviceQueueFamily = new VulkanDeviceQueueFamily();
			deviceQueueFamily->attach(*this);
			deviceQueueFamily->withFamilyIndex(queueFamily.second);
			deviceQueueFamily->withCount(1);
			deviceQueueFamily->withPriority(priority);

			this->_deviceQueueFamilies.insert(std::pair<std::string, VulkanDeviceQueueFamily*>(queueFamily.first, deviceQueueFamily));
		}
	}

	return *this;
}

VulkanLogicalDevice& VulkanLogicalDevice::withExtensions(const std::vector<const char*>& extensions)
{
	_logicalDeviceInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());

	if (_logicalDeviceInfo.enabledExtensionCount > 0)
	{
		_logicalDeviceInfo.ppEnabledExtensionNames = extensions.data();
	}

	return *this;
}

VulkanLogicalDevice& VulkanLogicalDevice::withValidationLayers(const std::vector<const char*>& layers)
{
	_logicalDeviceInfo.enabledLayerCount = static_cast<uint32_t>(layers.size());

	if (_logicalDeviceInfo.enabledLayerCount > 0)
	{
		_logicalDeviceInfo.ppEnabledLayerNames = layers.data();
	}

	return *this;
}

VulkanLogicalDevice& VulkanLogicalDevice::withFlags(uint32_t flags)
{
	this->_logicalDeviceInfo.flags = flags;
	return *this;
}

VulkanLogicalDevice& VulkanLogicalDevice::withNext(const void* fnNext)
{
	this->_logicalDeviceInfo.pNext = fnNext;
	return *this;
}

VulkanLogicalDevice& VulkanLogicalDevice::finalize()
{
	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
	std::set<int> uniqueQueueFamilies;

	for (auto queueFamily : _deviceQueueFamilies)
	{
		std::set<int>::iterator it = uniqueQueueFamilies.find(queueFamily.second->queueFamilyIndex);

		if (it == uniqueQueueFamilies.end())
		{
			uniqueQueueFamilies.insert(queueFamily.second->queueFamilyIndex);
			queueCreateInfos.push_back(*queueFamily.second);
		}
	}
	this->_logicalDeviceInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
	this->_logicalDeviceInfo.pQueueCreateInfos = queueCreateInfos.data();

	if (this->_deviceFeatures == nullptr)
	{
		features();
	}

	VkResult result = vkCreateDevice((this->_instance->physicalDevice())(), &this->_logicalDeviceInfo, nullptr, &this->_logicalDevice);
	if (result != VK_SUCCESS)
	{
		throw std::runtime_error("VulkanLogicalDevice: Unable to create logical device.");
	}

	for (const auto& queueFamily : this->_deviceQueueFamilies)
	{
		VkQueue queue;
		vkGetDeviceQueue(this->_logicalDevice, queueFamily.second->index(), 0, &queue);
		this->_deviceQueues.insert(std::pair<std::string, VkQueue>(queueFamily.first, queue));
	}

	return *this;
}

VkQueue VulkanLogicalDevice::queue(const std::string queueName)
{
	std::map<std::string, VkQueue>::iterator it;
	it = this->_deviceQueues.find(queueName);

	if (it == this->_deviceQueues.end())
	{
		throw std::runtime_error("VulkanLogicalDevice: Unable to find queue.");
	}

	return it->second;
}