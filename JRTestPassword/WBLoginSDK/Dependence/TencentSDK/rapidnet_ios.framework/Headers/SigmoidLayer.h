#import <Foundation/Foundation.h>
#import "CNNKernel.h"
#ifdef USE_RPN_LIB
#import <rapidnet_ios/rpdnet_cfg.h>
#else
#import "rpdnet_cfg.h"
#endif
using namespace rpdnet;
@interface SigmoidLayer : CNNKernel {
    rpd_layer_info *_para;
}
- (instancetype)initWithPara:(rpd_layer_info *)para
                      device:(id<MTLDevice>) device
                     library:(id<MTLLibrary>) library;
@end
