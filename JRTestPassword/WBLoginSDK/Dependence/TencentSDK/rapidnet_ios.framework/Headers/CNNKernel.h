#ifndef BaseLayer_h
#define BaseLayer_h
#import "CNNMacro.h"
#import "CNNTypes.h"
#import "YTRapidNetError.h"
#import "CNNBufferCache.h"
#import "CNNImage.h"
#import "CNNPipeLine.h"
#import <Metal/Metal.h>
using namespace YoutuMetalCNN;
#ifdef USE_RPN_LIB
#include <rapidnet_ios/rapidnet_ios.h>
#else
#include "rpdnet_api.h"
#endif
using namespace rpdnet;
namespace rpdnet {
    class layer_param;
    class conv_layer_param;
    class rpd_layer_info;
    struct layer_res;
    struct rpd_net_param;
}
typedef NS_ENUM(int, YTPixelFormat)
{
    YTPixelFormatInvalid  = 0,
    YTPixelFormatRGBA8888 = 1,
    YTPixelFormatFloatPlane = 100,
};
@interface CNNKernel : NSObject{
    CNNDimension _inputDimension;
    CNNDimension _outputDimension;
    CNNPipeLine *_pipelineState;
}
@property (nonatomic, weak) id<MTLDevice> device;
@property (nonatomic, weak) id<MTLLibrary> library;
@property(nonatomic, assign, readonly) CNNDimension inputDimension;
@property(nonatomic, assign, readonly) CNNDimension outputDimension;
@property (nonatomic, strong) CNNPipeLine *pipelineState;
@property (nonatomic, weak) id<CNNPipeLineDelegate> pipeLineDelegate;
- (instancetype)initWithDevice:(id<MTLDevice>) device
                       library:(id<MTLLibrary>) library;
- (void)preloadWithInputDimension:(CNNDimension)dimension;
- (BOOL)encodeWithCommandBuffer:(id<MTLCommandBuffer>)commandBuffer
                    sourceImage:(CNNImage*)sourceImage
               destinationImage:(CNNImage*)destinationImage;
- (BOOL)encodeWithCommandBuffer:(id<MTLCommandBuffer>)commandBuffer
                   sourceImages:(NSArray<CNNImage*> *)sourceImage
              destinationImages:(NSArray<CNNImage*> *)destinationImage;
- (void)findBestThreadgroupsPerGrid:(MTLSize &)threadgroupsPerGrid
            threadsPerThreadgroup:(MTLSize &)threadsPerThreadgroup;
- (NSError *)constructWithLayerData:(const rpdnet::layer_res *)layerData;
+ (CNNDimension)outputDimensionWithPara:(void*)para
                         inputDimension:(CNNDimension)inputDimension;
@end
#endif 
