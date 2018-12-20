#import <Foundation/Foundation.h>
#import "RapidNetCPU.h"
#import "YTRapidNetError.h"
#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>
#import "CNNImage.h"
#import "CNNBufferCache.h"
#import "CNNPipeLine.h"
#if YT_USE_MPSCNN && !YT_IS_SIMULATOR
#import <MetalPerformanceShaders/MetalPerformanceShaders.h>
#else
#endif
#import "CNNImage.h"
@interface RapidNetMetal : NSObject
@property (nonatomic, strong, readonly) RapidNetCPU *netCpu;
@property (nonatomic, strong, readonly) id<MTLDevice> device;
@property (nonatomic, strong, readonly) id<MTLLibrary> library;
@property (nonatomic, strong, readonly) CNNBufferCache *bufferCache;
@property (nonatomic, strong, readonly) CNNPipeLineManager *pipeLineManager;
@property (nonatomic, strong, readonly) NSString *protoFile;
@property (nonatomic, strong, readonly) NSString *modelFile;
- (instancetype)initWithDevice:(id<MTLDevice>) device
                       library:(id<MTLLibrary>) library;
- (NSError *)constructNetworkWith:(RapidNetCPU *)cpuNetwork;
- (CNNImage *)forwardWithTexture:(id<MTLTexture>) texture
                   commandBuffer:(id<MTLCommandBuffer>)commandBuffer;
- (CNNImage *)forwardWithCNNImage:(CNNImage *) image
                    commandBuffer:(id<MTLCommandBuffer>)commandBuffer;
- (BOOL)destructNetwork;
- (CNNDimension)getNetDataDimension;
- (CNNDimension)getOutputDataDimension;
- (void)preloadForDataDimension:(CNNDimension)dimension;
- (void)preloadForDataDimension:(YoutuMetalCNN::CNNDimension)dataDimension
              netInputDimension:(YoutuMetalCNN::CNNDimension)netdimension;
#if YT_USE_MPSCNN && !YT_IS_SIMULATOR
- (void)forwardWithImage:(MPSImage *) texture
           commandBuffer:(id<MTLCommandBuffer>)commandBuffer;
#endif
@end
