#import <Foundation/Foundation.h>
#import "rpdnet_api.h"
#import "YTRapidNetError.h"
using namespace rpdnet;
@interface RapidNetCPU : NSObject
- (instancetype)initWithProto:(NSString *)protoFil
                    modelFile:(NSString *)modelFile;
- (unsigned int *)dongleMap;
@end
