#import "CNNKernel.h"
struct MakeBorderPara {
    int left;
    int top;
    int right;
    int bottom;
};
@interface MakeBorderLayer : CNNKernel
- (instancetype)initWithPara:(MakeBorderPara)para
              inputDimension:(CNNDimension)inputDimension
                      device:(id<MTLDevice>) device
                     library:(id<MTLLibrary>) library;
@end
