#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import "CNNImage.h"
#import "YTRapidNetError.h"
@class RapidNetCPU;
@class RapidNetMetal;
@interface RapidNet : NSObject
@property (nonatomic, strong, readonly) RapidNetCPU *netCpu;
@property (nonatomic, strong, readonly) RapidNetMetal *netMetal;
+ (BOOL)isGPUDeviceAvailable;
- (instancetype)initWithProto:(NSString *)protoFile
                        model:(NSString *)modelFile;
- (NSError *)loadGPU;
- (NSError *)loadGPUWithDevice:(id<MTLDevice>) device
                       library:(id<MTLLibrary>) library;
- (void)preloadForDataDimension:(YoutuMetalCNN::CNNDimension)dataDimension
              netInputDimension:(YoutuMetalCNN::CNNDimension)netdimension;
- (CNNImage *)forwardWithCNNImage:(CNNImage *) image
                    commandBuffer:(id<MTLCommandBuffer>)commandBuffer
                            error:(NSError *__autoreleasing *)error;
+ (NSString *)gpuLibraryPath;
+ (void)enableImageDebug;
@end
@interface RapidNet (Overide)
- (Class)rapidNetCPUClass;
- (Class)rapidNetMetalClass;
@end
