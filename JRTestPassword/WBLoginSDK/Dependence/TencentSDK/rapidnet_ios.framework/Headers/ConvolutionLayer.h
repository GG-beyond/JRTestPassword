#import <Foundation/Foundation.h>
#import "CNNKernel.h"
#import "CNNTypes.h"
extern CNNConvolutionPara CNNConvolutionParaFromLayerParam(conv_layer_param *layerParam);
#if YT_USE_MPSCNN && !YT_IS_SIMULATOR
#import <MetalPerformanceShaders/MetalPerformanceShaders.h>
@interface ConvolutionLayer : MPSCNNConvolution
#else
@interface ConvolutionLayer : CNNKernel {
}
@property(nonatomic, assign, readonly) CNNConvolutionPara convolutionPara;
- (instancetype)initWithPara:(CNNConvolutionPara)para
              inputDimension:(CNNDimension)inputDimension
                      device:(id<MTLDevice>) device
                     library:(id<MTLLibrary>) library;
- (NSError *)constructWithConvolutionData:(const layer_res *)convData
                            batchNormPara:(const layer_param *)batchNormPara
                            batchNormData:(const layer_res *)batchNormData
                                preluPara:(const layer_param *)preluPara
                                preluData:(const layer_res *)preluData;
- (void)printInfo;
@end
#endif
