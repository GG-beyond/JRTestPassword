#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
@interface CNNBuffer : NSObject
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong, readonly) id<MTLBuffer> mtlBuffer;
- (instancetype)initWithBytes:(void *)bytes
                       length:(NSUInteger)length
                       device:(id<MTLDevice>)device;
- (instancetype)initWithBytes:(void *)bytes
                       length:(NSUInteger)length
                       device:(id<MTLDevice>)device
                       option:(MTLResourceOptions)option;
- (instancetype)initWithBytesNoCopy:(void *)bytes
                       length:(NSUInteger)length
                       device:(id<MTLDevice>)device;
- (instancetype)initWithLength:(NSUInteger)length
                       device:(id<MTLDevice>)device;
- (instancetype)initWithLength:(NSUInteger)length
                       device:(id<MTLDevice>)device
                       option:(MTLResourceOptions)option;
- (instancetype)initWithLength:(NSUInteger)length
                     mtlBuffer:(id<MTLBuffer>)mtlBuffer;
- (BOOL)attachToCommandEncoder:(id<MTLComputeCommandEncoder>)encoder
                    withOffset:(NSUInteger)offset
                       atIndex:(NSUInteger)index;
@end
