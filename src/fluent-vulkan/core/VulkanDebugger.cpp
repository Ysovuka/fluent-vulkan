#include "VulkanDebugger.h"
#include "VulkanInstance.h"

VulkanDebugger::VulkanDebugger()
{
	this->sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
	this->flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
	this->_allocatorCallbacks = nullptr;
	this->pNext = nullptr;
}

VulkanDebugger::~VulkanDebugger()
{
	if (this->_callback != VK_NULL_HANDLE)
	{
		dispose();
	}
}

void VulkanDebugger::dispose()
{
	auto func = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr((*this->_instance)(), "vkDestroy_debuggerCallbackEXT");
	if (func != nullptr)
	{
		func((*this->_instance)(), this->_callback, this->_allocatorCallbacks);
	}

	this->_callback = VK_NULL_HANDLE;
}

VulkanDebugger& VulkanDebugger::withAllocationCallbacks(const VkAllocationCallbacks* pAllocator)
{
	this->_allocatorCallbacks = pAllocator;
	return *this;
}

VulkanDebugger& VulkanDebugger::withCallback(PFN_vkDebugReportCallbackEXT callback)
{
	this->pfnCallback = callback;
	return *this;
}

VulkanDebugger& VulkanDebugger::withFlags(VkDebugReportFlagsEXT flags)
{
	this->flags = flags;
	return *this;
}

VulkanDebugger& VulkanDebugger::withNext(const void* fnNext)
{
	this->pNext = fnNext;
	return *this;
}

VulkanDebugger& VulkanDebugger::finalize()
{
	auto func = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr((*this->_instance)(), "vkCreate_debuggerCallbackEXT");
	if (func != nullptr)
	{
		if (func((*this->_instance)(), this, this->_allocatorCallbacks, &this->_callback) != VK_SUCCESS)
		{
			throw std::runtime_error("VulkanDebugger: Failed to finalize the initialization of the debug report.");
		}
	}

	return *this;
}

VulkanDebugger& VulkanDebugger::attach(VulkanInstance* instance)
{
	this->_instance = instance;
	return *this;
}

VulkanInstance* VulkanDebugger::instance()
{
	return this->_instance;
}
