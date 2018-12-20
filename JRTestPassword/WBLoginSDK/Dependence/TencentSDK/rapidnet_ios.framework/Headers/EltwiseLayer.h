#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import "CNNKernel.h"
#import "CNNTypes.h"
using namespace YoutuMetalCNN;
@interface EltwiseLayer : CNNKernel {
}
- (instancetype)initWithPara:(CNNConvolutionPara)para
              inputDimension:(CNNDimension)inputDimension
                      device:(id<MTLDevice>) device
                     library:(id<MTLLibrary>) library;
- (NSError *)construct;
@end
