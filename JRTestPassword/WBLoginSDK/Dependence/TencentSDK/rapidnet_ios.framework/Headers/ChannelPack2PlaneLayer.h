#import "CNNKernel.h"
@interface ChannelPack2PlaneLayer : CNNKernel
- (instancetype)initWithInputDimension:(CNNDimension)inputDimension
                      device:(id<MTLDevice>) device
                     library:(id<MTLLibrary>) library;
@end
