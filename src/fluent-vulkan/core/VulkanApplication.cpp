#include "VulkanApplication.h"
#include "VulkanInstance.h"

VulkanApplication::VulkanApplication()
{
	this->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	this->pApplicationName = "";
	this->applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	this->pEngineName = "";
	this->engineVersion = VK_MAKE_VERSION(1, 0, 0);
	this->apiVersion = VK_API_VERSION_1_0;
}

VulkanApplication::~VulkanApplication()
{

}

VulkanApplication& VulkanApplication::withApiVersion(uint32_t apiVersion)
{
	this->apiVersion = apiVersion;
	return *this;
}

VulkanApplication& VulkanApplication::withEngine(const char* name, uint32_t version)
{
	this->engineVersion = version;
	this->pEngineName = name;
	return *this;
}

VulkanApplication& VulkanApplication::withName(const char* name)
{
	this->pApplicationName = name;
	return *this;
}

VulkanApplication& VulkanApplication::withVersion(uint32_t version)
{
	this->applicationVersion = version;
	return *this;
}

VulkanApplication& VulkanApplication::attach(VulkanInstance* instance)
{
	this->_instance = instance;
	return *this;
}

VulkanInstance& VulkanApplication::instance()
{
	return *this->_instance;
}