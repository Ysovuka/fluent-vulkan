#include "VulkanSurface.h"
#include "VulkanInstance.h"

VulkanSurface::VulkanSurface()
{

}

VulkanSurface::~VulkanSurface()
{
	vkDestroySurfaceKHR((*this->_instance)(), this->_surface, nullptr);
}

VkSurfaceKHR& VulkanSurface::operator()()
{
	return this->_surface;
}

VulkanSurface& VulkanSurface::attach(VulkanInstance* instance)
{
	this->_instance = instance;
	return *this;
}

VulkanInstance& VulkanSurface::instance()
{
	return *this->_instance;
}

VulkanSurface& VulkanSurface::create(VulkanCreateSurface fnCreateSurface)
{
	fnCreateSurface((*this->_instance)(), this->_surface);
	return *this;
}