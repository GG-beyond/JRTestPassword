#import "CNNKernel.h"
#ifdef USE_RPN_LIB
#include <rapidnet_ios/rapidnet_ios.h>
#else
#include "rpdnet_api.h"
#endif
using namespace rpdnet;
@interface AddPadingLayer : CNNKernel
- (instancetype)initWithPara:(CNNAddPadingPara)para
              inputDimension:(CNNDimension)inputDimension
                      device:(id<MTLDevice>) device
                     library:(id<MTLLibrary>) library;
- (NSError *)constructWithLayerData:(const layer_res *)layerData;
@end
