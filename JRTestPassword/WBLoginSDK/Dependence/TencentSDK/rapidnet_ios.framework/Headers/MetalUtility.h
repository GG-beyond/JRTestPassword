#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import "CNNTypes.h"
@interface MetalUtility : NSObject 
+ (id<MTLComputePipelineState>)buildPipelineWithFuncName:(NSString *)funcName
                                                  device:(id<MTLDevice>)device
                                                 library:(id<MTLLibrary>)library
                                                   error:(NSError **)error;
@end
