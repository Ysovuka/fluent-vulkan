#pragma once

#ifndef VulkanDeviceFeatures_H
#define VulkanDeviceFeatures_H

#include <vulkan\vulkan.h>

class VulkanLogicalDevice;

class VulkanDeviceFeatures : public VkPhysicalDeviceFeatures
{
private:
	VulkanLogicalDevice* _logicalDevice;

public:
	VulkanDeviceFeatures();
	~VulkanDeviceFeatures();

	VulkanDeviceFeatures& attach(VulkanLogicalDevice& logicalDevice);
	VulkanLogicalDevice& logicalDevice();

	VulkanDeviceFeatures& withRobustBufferAccess(VkBool32 robustBufferAccess = VK_TRUE);
	VulkanDeviceFeatures& withFullDrawIndexUInt32(VkBool32 fullDrawIndexUInt32 = VK_TRUE);
	VulkanDeviceFeatures& withImageCubeArray(VkBool32 imageCubeArray = VK_TRUE);
	VulkanDeviceFeatures& withIndependentBlend(VkBool32 independentBlend = VK_TRUE);
	VulkanDeviceFeatures& withGeometryShader(VkBool32 geometryShader = VK_TRUE);
	VulkanDeviceFeatures& withTessellationShader(VkBool32 tessellationShader = VK_TRUE);
	VulkanDeviceFeatures& withSampleRateShading(VkBool32 sampleRateShading = VK_TRUE);
	VulkanDeviceFeatures& withDualSourceBlend(VkBool32 dualSourceBlend = VK_TRUE);
	VulkanDeviceFeatures& withLogicOperations(VkBool32 logicOperations = VK_TRUE);
	VulkanDeviceFeatures& withMultiDrawIndirect(VkBool32 multiDrawIndirect = VK_TRUE);
	VulkanDeviceFeatures& withDrawIndirectFirstInstance(VkBool32 drawIndirectFirstInstance = VK_TRUE);
	VulkanDeviceFeatures& withDepthClamp(VkBool32 depthClamp = VK_TRUE);
	VulkanDeviceFeatures& withDepthBiasClamp(VkBool32 depthBiasClamp = VK_TRUE);
	VulkanDeviceFeatures& withFillModeNonSolid(VkBool32 fillModeNonSolid = VK_TRUE);
	VulkanDeviceFeatures& withDepthBounds(VkBool32 depthBounds = VK_TRUE);
	VulkanDeviceFeatures& withWideLines(VkBool32 wideLines = VK_TRUE);
	VulkanDeviceFeatures& withLargePoints(VkBool32 largePoints = VK_TRUE);
	VulkanDeviceFeatures& withAlphaToOne(VkBool32 alphaToOne = VK_TRUE);
	VulkanDeviceFeatures& withMultiViewport(VkBool32 multiViewport = VK_TRUE);
	VulkanDeviceFeatures& withSamplerAnisotrophy(VkBool32 samplerAnisotrophy = VK_TRUE);
	VulkanDeviceFeatures& withTextureCompressionBC(VkBool32 textureCompressionBC = VK_TRUE);
	VulkanDeviceFeatures& withTextureCompressionETC2(VkBool32 textureCompressionETC2 = VK_TRUE);
	VulkanDeviceFeatures& withTextureCompressionASTC_LDR(VkBool32 textureCompressionASTC_LDR = VK_TRUE);
	VulkanDeviceFeatures& withOcclusionQueryPrecise(VkBool32 occlusionQueryPrecise = VK_TRUE);
	VulkanDeviceFeatures& withPipelineStatisticsQuery(VkBool32 pipelineStatisticsQuery = VK_TRUE);
	VulkanDeviceFeatures& withVertexPipelineStoresAndAtomics(VkBool32 vertexPipelineStoresAndAtmoics = VK_TRUE);
	VulkanDeviceFeatures& withFragmentStoresAndAtomics(VkBool32 fragmentStoresAndAtomics = VK_TRUE);
	VulkanDeviceFeatures& withShaderTessellationAndGeometryPointSize(VkBool32 shaderTessellationAndGeometryPointSize = VK_TRUE);
	VulkanDeviceFeatures& withShaderImageGatherExtended(VkBool32 shaderImageGatherExtended = VK_TRUE);
	VulkanDeviceFeatures& withShaderStorageImageExtendedFormats(VkBool32 shaderStorageImageExtendedFormats = VK_TRUE);
	VulkanDeviceFeatures& withShaderStorageImageMultisample(VkBool32 shaderStorageImageMultisample = VK_TRUE);
	VulkanDeviceFeatures& withShaderStorageImageReadWithoutFormat(VkBool32 shaderStorageImageReadWithoutFormat = VK_TRUE);
	VulkanDeviceFeatures& withShaderStorageImageWriteWithoutFormat(VkBool32 shaderStorageImageWriteWithoutFormat = VK_TRUE);
	VulkanDeviceFeatures& withShaderUniformBufferArrayDynamicIndexing(VkBool32 shaderUniformBufferArrayDynamicIndexing = VK_TRUE);
	VulkanDeviceFeatures& withShaderSampledImageArrayDynamicIndexing(VkBool32 shaderSampledImageArrayDynamicIndexing = VK_TRUE);
	VulkanDeviceFeatures& withShaderStorageBufferArrayDynamicIndexing(VkBool32 shaderStorageBufferArrayDynamicIndexing = VK_TRUE);
	VulkanDeviceFeatures& withShaderStorageImageArrayDynamicIndexing(VkBool32 shaderStorageImageArrayDynamicIndexing = VK_TRUE);
	VulkanDeviceFeatures& withShaderClipDistance(VkBool32 shaderClipDistance = VK_TRUE);
	VulkanDeviceFeatures& withShaderCullDistance(VkBool32 shaderCullDistance = VK_TRUE);
	VulkanDeviceFeatures& withShaderFloat64(VkBool32 shaderFloat64 = VK_TRUE);
	VulkanDeviceFeatures& withShaderInt64(VkBool32 shaderInt64 = VK_TRUE);
	VulkanDeviceFeatures& withShaderInt16(VkBool32 shaderInt16 = VK_TRUE);
	VulkanDeviceFeatures& withShaderResourceResidency(VkBool32 shaderResourceResidency = VK_TRUE);
	VulkanDeviceFeatures& withShaderResourceMinLod(VkBool32 shaderResourceMinLod = VK_TRUE);
	VulkanDeviceFeatures& withSparseBinding(VkBool32 sparseBinding = VK_TRUE);
	VulkanDeviceFeatures& withSparseResidencyBuffer(VkBool32 sparseResidencyBuffer = VK_TRUE);
	VulkanDeviceFeatures& withSparseResidencyImage2D(VkBool32 sparseResidencyImage2D = VK_TRUE);
	VulkanDeviceFeatures& withSparseResidencyImage3D(VkBool32 sparseResidencyImage3D = VK_TRUE);
	VulkanDeviceFeatures& withSparseResidency2Samples(VkBool32 sparseResidency2Samples = VK_TRUE);
	VulkanDeviceFeatures& withSparseResidency4Samples(VkBool32 spraseResidency4Samples = VK_TRUE);
	VulkanDeviceFeatures& withSparseResidency8Samples(VkBool32 spraseResidency8Samples = VK_TRUE);
	VulkanDeviceFeatures& withSparseResidency16Samples(VkBool32 spraseResidency16Samples = VK_TRUE);
	VulkanDeviceFeatures& withSparseResidencyAliased(VkBool32 spraseResidencyAliased = VK_TRUE);
	VulkanDeviceFeatures& withVariableMultisampleRate(VkBool32 variableMultisampleRate = VK_TRUE);
	VulkanDeviceFeatures& withInheritedQueries(VkBool32 inheritedQueries = VK_TRUE);
};

#endif