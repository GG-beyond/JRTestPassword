#import "CNNBuffer.h"
#import "CNNTypes.h"
using namespace YoutuMetalCNN;
@interface CNNImage : CNNBuffer
@property (nonatomic, assign, readonly) CNNDimension dimension;
- (instancetype)initWithBytes:(void *)bytes
                       dimension:(CNNDimension)dimension
                  elementSize:(int)elementSize
                       device:(id<MTLDevice>)device;
- (instancetype)initWithBytes:(void *)bytes
                       dimension:(CNNDimension)dimension
                  elementSize:(int)elementSize
                       device:(id<MTLDevice>)device
                       option:(MTLResourceOptions)option;
- (instancetype)initWithBytesNoCopy:(void *)bytes
                             dimension:(CNNDimension)dimension
                        elementSize:(int)elementSize
                             device:(id<MTLDevice>)device;
- (instancetype)initWithDimension:(CNNDimension)dimension
                      elementSize:(int)elementSize
                        device:(id<MTLDevice>)device;
- (instancetype)initWithDimension:(CNNDimension)dimension
                      elementSize:(int)elementSize
                        device:(id<MTLDevice>)device
                        option:(MTLResourceOptions)option;
- (instancetype)initWithDimension:(CNNDimension)dimension
                      elementSize:(int)elementSize
                        mtlBuffer:(id<MTLBuffer>)mtlBuffer;
@end
