#import <Foundation/Foundation.h>
#import "WBFaceVerifyConst.h"
NS_ASSUME_NONNULL_BEGIN
@interface WBFaceVerifySDKConfig : NSObject
@property (nonatomic, assign) NSUInteger windowLevel;
@property (nonatomic, assign) BOOL showSuccessPage;
@property (nonatomic, assign) BOOL showFailurePage;
@property (nonatomic, assign) BOOL recordVideo;
@property (nonatomic, assign) WBFaceVerifyTheme theme;
@property (nonatomic, copy) NSString *bundlePath;
+(instancetype)sdkConfig;
@end
NS_ASSUME_NONNULL_END
