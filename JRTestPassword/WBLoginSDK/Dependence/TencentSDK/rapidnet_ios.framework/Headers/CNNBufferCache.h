#import <Foundation/Foundation.h>
#import "CNNTemporaryImage.h"
@interface CNNBufferCache : NSObject
- (void)clean;
- (CNNTemporaryImage *)requestBufferWithDimension:(CNNDimension)dimension
                                      elementSize:(int)elementSize
                                     excludions:(NSArray *)excludions
                                         device:(id<MTLDevice>)device;
@end
