#include "VulkanInstance.h"
#include "VulkanApplication.h"
#include "VulkanDebugger.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanLogicalDevice.h"
#include "VulkanSurface.h"

VulkanInstance::VulkanInstance()
{
	this->_instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	this->_instanceInfo.pApplicationInfo = nullptr;
	this->_instanceInfo.enabledExtensionCount = 0;
	this->_instanceInfo.enabledLayerCount = 0;
	this->_instanceInfo.flags = 0;
	this->_instanceInfo.pNext = nullptr;
	this->_instanceInfo.ppEnabledExtensionNames = nullptr;
	this->_instanceInfo.ppEnabledLayerNames = nullptr;
}

VulkanInstance::~VulkanInstance()
{
	if (this->_instance != VK_NULL_HANDLE)
	{
		dispose();
	}
}

void VulkanInstance::dispose()
{
	if (this->_logicalDevice != nullptr)
	{
		delete this->_logicalDevice;
	}

	if (this->_physicalDevice != nullptr)
	{
		delete this->_physicalDevice;
	}

	if (this->_surface != nullptr)
	{
		delete this->_surface;
	}

	if (this->_debugger != nullptr)
	{
		delete this->_debugger;
	}

	if (this->_application != nullptr)
	{
		delete this->_application;
	}

	vkDestroyInstance(this->_instance, nullptr);

	this->_instance = VK_NULL_HANDLE;
}

VkInstance VulkanInstance::operator()()
{
	return this->_instance;
}

VulkanInstance& VulkanInstance::withExtensions(const std::vector<const char*>& extensions)
{
	this->_instanceInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	
	if (this->_instanceInfo.enabledExtensionCount > 0)
	{
		this->_instanceInfo.ppEnabledExtensionNames = extensions.data();
	}

	return *this;
}

VulkanInstance& VulkanInstance::withValidationLayers(const std::vector<const char*>& validationLayers)
{
	this->_instanceInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());

	if (this->_instanceInfo.enabledLayerCount > 0)
	{
		this->_instanceInfo.ppEnabledLayerNames = validationLayers.data();
	}

	return *this;
}

VulkanInstance& VulkanInstance::withFlags(uint32_t flags)
{
	this->_instanceInfo.flags = flags;
	return *this;
}

VulkanInstance& VulkanInstance::withNext(const void* fnNext)
{
	this->_instanceInfo.pNext = fnNext;
	return *this;
}

VulkanInstance& VulkanInstance::finalize()
{
	if (vkCreateInstance(&_instanceInfo, nullptr, &_instance) != VK_SUCCESS)
	{
		throw std::runtime_error("VulkanInstance: 'VkInstance' failed to be created.");
	}

	return *this;
}

VulkanApplication& VulkanInstance::application()
{
	if (this->_application == nullptr)
	{
		this->_application = new VulkanApplication();
		this->_application->attach(this);
	}

	return *this->_application;
}

VulkanDebugger& VulkanInstance::debugger()
{
	if (this->_debugger == nullptr)
	{
		this->_debugger = new VulkanDebugger();
		this->_debugger->attach(this);
	}

	return *this->_debugger;
}

VulkanPhysicalDevice& VulkanInstance::physicalDevice()
{
	if (this->_physicalDevice == nullptr)
	{
		this->_physicalDevice = new VulkanPhysicalDevice();
		this->_physicalDevice->attach(this);
	}

	return *this->_physicalDevice;
}

VulkanLogicalDevice& VulkanInstance::logicalDevice()
{
	if (this->_logicalDevice == nullptr)
	{
		this->_logicalDevice = new VulkanLogicalDevice();
		this->_logicalDevice->attach(this);
	}

	return *this->_logicalDevice;
}

VulkanSurface& VulkanInstance::surface()
{
	if (this->_surface == nullptr)
	{
		this->_surface = new VulkanSurface();
		this->_surface->attach(this);
	}

	return *this->_surface;
}