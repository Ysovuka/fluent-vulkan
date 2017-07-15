#include "VulkanInstance.h"
#include "VulkanApplication.h"

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

	if (_application != nullptr)
	{
		delete _application;
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
}

VulkanApplication* VulkanInstance::application()
{
	if (this->_application == nullptr)
	{
		this->_application = new VulkanApplication();
		this->_application->attach(this);
	}

	return this->_application;
}