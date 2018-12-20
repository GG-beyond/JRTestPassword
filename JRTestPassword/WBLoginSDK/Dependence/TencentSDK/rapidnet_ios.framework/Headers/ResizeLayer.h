#import "CNNKernel.h"
struct ResizePara {
    float scaleX;
    float scaleY;
    YTPixelFormat inputFormat;
    YTPixelFormat outputFormat;
};
@interface ResizeLayer : CNNKernel
- (instancetype)initWithPara:(ResizePara)para
              inputDimension:(CNNDimension)inputDimension
                      device:(id<MTLDevice>) device
                     library:(id<MTLLibrary>) library;
- (void)preloadWithPara:(ResizePara)para
         inputDimension:(CNNDimension)inputDimension;
@end
