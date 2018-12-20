#import "CNNKernel.h"
typedef enum : int {
    ColorConvertTypeInvalid     = 0,
    ColorConvertTypeRGBA2YCrCb  = 1,
    ColorConvertTypeYCrCb2RGBA  = 2,
} ColorConvertType;
@interface ColorConvertLayer : CNNKernel
- (instancetype)initWithPara:(ColorConvertPara)para
              inputDimension:(CNNDimension)inputDimension
                      device:(id<MTLDevice>) device
                     library:(id<MTLLibrary>) library;
@end
