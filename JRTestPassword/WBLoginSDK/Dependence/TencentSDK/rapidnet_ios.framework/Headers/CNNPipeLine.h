#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
@class CNNPipeLine;
@protocol CNNPipeLineDelegate <NSObject>
- (CNNPipeLine *)pipelineWithFuncName:(NSString *)funcName
                               device:(id<MTLDevice>)device
                              library:(id<MTLLibrary>)library
                                error:(NSError **)error;
@end
@interface CNNPipeLine : NSObject
@property (nonatomic, strong, readonly) id <MTLComputePipelineState> mtlPipeline;
- (instancetype)initWithPipelineWithFuncName:(NSString *)funcName
                                      device:(id<MTLDevice>)device
                                     library:(id<MTLLibrary>)library
                                       error:(NSError **)error;
@property (readonly) id <MTLDevice> device;
@property (readonly) NSUInteger maxTotalThreadsPerThreadgroup;
@property (readonly) NSUInteger threadExecutionWidth;
@end
@interface CNNPipeLineManager : NSObject <CNNPipeLineDelegate>
- (CNNPipeLine *)pipelineWithFuncName:(NSString *)funcName
                               device:(id<MTLDevice>)device
                              library:(id<MTLLibrary>)library
                                error:(NSError **)error;
@end
