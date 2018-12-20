#import "CNNKernel.h"
@interface ScaleLayer : CNNKernel
- (instancetype)initWithInputDimension:(CNNDimension)inputDimension
                       outputDimension:(CNNDimension)outputDimension
                                device:(id<MTLDevice>) device
                               library:(id<MTLLibrary>) library;
@end
