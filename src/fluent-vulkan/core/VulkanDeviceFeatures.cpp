#include "VulkanDeviceFeatures.h"
#include "VulkanLogicalDevice.h"

VulkanDeviceFeatures::VulkanDeviceFeatures()
{

}

VulkanDeviceFeatures::~VulkanDeviceFeatures()
{

}

VulkanDeviceFeatures& VulkanDeviceFeatures::attach(VulkanLogicalDevice& logicalDevice)
{
	this->_logicalDevice = &logicalDevice;
	return *this;
}

VulkanLogicalDevice& VulkanDeviceFeatures::logicalDevice()
{
	return *this->_logicalDevice;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withAlphaToOne(VkBool32 alphaToOne)
{
	this->alphaToOne = alphaToOne;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withDepthBiasClamp(VkBool32 depthBiasClamp)
{
	this->depthBiasClamp = depthBiasClamp;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withDepthBounds(VkBool32 depthBounds)
{
	this->depthBounds = depthBounds;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withDepthClamp(VkBool32 depthClamp)
{
	this->depthClamp = depthClamp;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withDrawIndirectFirstInstance(VkBool32 drawIndirectFirstInstance)
{
	this->drawIndirectFirstInstance = drawIndirectFirstInstance;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withDualSourceBlend(VkBool32 dualSourceBlend)
{
	this->dualSrcBlend = dualSourceBlend;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withFillModeNonSolid(VkBool32 fillModeNonSolid)
{
	this->fillModeNonSolid = fillModeNonSolid;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withFragmentStoresAndAtomics(VkBool32 fragmentStoresAndAtomics)
{
	this->fragmentStoresAndAtomics = fragmentStoresAndAtomics;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withFullDrawIndexUInt32(VkBool32 fullDrawIndeUInt32)
{
	this->fullDrawIndexUint32 = fullDrawIndeUInt32;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withGeometryShader(VkBool32 geometryShader)
{
	this->geometryShader = geometryShader;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withImageCubeArray(VkBool32 imageCubeArray)
{
	this->imageCubeArray = imageCubeArray;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withIndependentBlend(VkBool32 independentBlend)
{
	this->independentBlend = independentBlend;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withInheritedQueries(VkBool32 inheritedQueries)
{
	this->inheritedQueries = inheritedQueries;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withLargePoints(VkBool32 largePoints)
{
	this->largePoints = largePoints;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withLogicOperations(VkBool32 logicOperations)
{
	this->logicOp = logicOperations;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withMultiDrawIndirect(VkBool32 multiDrawIndirect)
{
	this->multiDrawIndirect = multiDrawIndirect;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withMultiViewport(VkBool32 multiViewport)
{
	this->multiViewport = multiViewport;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withOcclusionQueryPrecise(VkBool32 occlusionQueryPrecise)
{
	this->occlusionQueryPrecise = occlusionQueryPrecise;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withPipelineStatisticsQuery(VkBool32 pipelineStatisticsQuery)
{
	this->pipelineStatisticsQuery = pipelineStatisticsQuery;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withRobustBufferAccess(VkBool32 robustBufferArray)
{
	this->robustBufferAccess = robustBufferAccess;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSamplerAnisotrophy(VkBool32 samplerAnisotrophy)
{
	this->samplerAnisotropy = samplerAnisotrophy;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSampleRateShading(VkBool32 sampleRateShading)
{
	this->sampleRateShading = sampleRateShading;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderClipDistance(VkBool32 shaderClipDistance)
{
	this->shaderClipDistance = shaderClipDistance;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderCullDistance(VkBool32 shaderCullDistance)
{
	this->shaderCullDistance = shaderCullDistance;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderFloat64(VkBool32 shaderFloat64)
{
	this->shaderFloat64 = shaderFloat64;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderImageGatherExtended(VkBool32 shaderImageGatherExtended)
{
	this->shaderImageGatherExtended = shaderImageGatherExtended;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderInt16(VkBool32 shaderInt16)
{
	this->shaderInt16 = shaderInt16;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderInt64(VkBool32 shaderInt64)
{
	this->shaderInt64 = shaderInt64;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderResourceMinLod(VkBool32 shaderResourceMinLod)
{
	this->shaderResourceMinLod = shaderResourceMinLod;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderResourceResidency(VkBool32 shaderResourceResidency)
{
	this->shaderResourceResidency = shaderResourceResidency;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderSampledImageArrayDynamicIndexing(VkBool32 shaderSampledImageArrayDynamicIndexing)
{
	this->shaderSampledImageArrayDynamicIndexing = shaderSampledImageArrayDynamicIndexing;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderStorageBufferArrayDynamicIndexing(VkBool32 shaderStorageBufferArrayDynamicIndexing)
{
	this->shaderStorageBufferArrayDynamicIndexing = shaderStorageBufferArrayDynamicIndexing;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderStorageImageArrayDynamicIndexing(VkBool32 shaderStorageImageArrayDynamicIndexing)
{
	this->shaderStorageImageArrayDynamicIndexing = shaderStorageImageArrayDynamicIndexing;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderStorageImageExtendedFormats(VkBool32 shaderStorageImageExtendedFormats)
{
	this->shaderStorageImageExtendedFormats = shaderStorageImageExtendedFormats;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderStorageImageMultisample(VkBool32 shaderStorageImageMultisample)
{
	this->shaderStorageImageMultisample = shaderStorageImageMultisample;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderStorageImageReadWithoutFormat(VkBool32 shaderStorageImageReadWithoutFormat)
{
	this->shaderStorageImageReadWithoutFormat = shaderStorageImageReadWithoutFormat;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderStorageImageWriteWithoutFormat(VkBool32 shaderStorageImageWriteWithoutFormat)
{
	this->shaderStorageImageWriteWithoutFormat = shaderStorageImageWriteWithoutFormat;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderTessellationAndGeometryPointSize(VkBool32 shaderTessellationAndGeometryPointSize)
{
	this->shaderTessellationAndGeometryPointSize = shaderTessellationAndGeometryPointSize;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withShaderUniformBufferArrayDynamicIndexing(VkBool32 shaderUniformBufferArrayDynamicIndexing)
{
	this->shaderUniformBufferArrayDynamicIndexing = shaderUniformBufferArrayDynamicIndexing;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSparseBinding(VkBool32 sparseBinding)
{
	this->sparseBinding = sparseBinding;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSparseResidency16Samples(VkBool32 sparseResidency16Samples)
{
	this->sparseResidency16Samples = sparseResidency16Samples;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSparseResidency2Samples(VkBool32 sparseResidency2Samples)
{
	this->sparseResidency2Samples = sparseResidency2Samples;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSparseResidency4Samples(VkBool32 sparseResidency4Samples)
{
	this->sparseResidency4Samples = sparseResidency4Samples;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSparseResidency8Samples(VkBool32 sparseResidency8Samples)
{
	this->sparseResidency8Samples = sparseResidency8Samples;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSparseResidencyAliased(VkBool32 sparseResidencyAliased)
{
	this->sparseResidencyAliased = sparseResidencyAliased;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSparseResidencyBuffer(VkBool32 sparseResidencyBuffer)
{
	this->sparseResidencyBuffer = sparseResidencyBuffer;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSparseResidencyImage2D(VkBool32 sparseResidencyImage2D)
{
	this->sparseResidencyImage2D = sparseResidencyImage2D;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withSparseResidencyImage3D(VkBool32 sparseResidencyImage3D)
{
	this->sparseResidencyImage3D = sparseResidencyImage3D;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withTessellationShader(VkBool32 tessellationShader)
{
	this->tessellationShader = tessellationShader;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withTextureCompressionASTC_LDR(VkBool32 textureCompressionASTC_LDR)
{
	this->textureCompressionASTC_LDR = textureCompressionASTC_LDR;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withTextureCompressionBC(VkBool32 textureCompressionBC)
{
	this->textureCompressionBC = textureCompressionBC;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withTextureCompressionETC2(VkBool32 textureCompressionETC2)
{
	this->textureCompressionETC2 = textureCompressionETC2;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withVariableMultisampleRate(VkBool32 variableMultisampleRate)
{
	this->variableMultisampleRate = variableMultisampleRate;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withVertexPipelineStoresAndAtomics(VkBool32 vertexPipelineStoresAndAtomics)
{
	this->vertexPipelineStoresAndAtomics = vertexPipelineStoresAndAtomics;
	return *this;
}

VulkanDeviceFeatures& VulkanDeviceFeatures::withWideLines(VkBool32 wideLines)
{
	this->wideLines = wideLines;
	return *this;
}