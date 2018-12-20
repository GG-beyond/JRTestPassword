#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZMConfig.h"
@interface ZMCertification : NSObject
- (void)startWithBizNO:(NSString *__nonnull)bizNO
            merchantID:(NSString *__nonnull)merchantID
             extParams:(NSDictionary *__nullable)params
        viewController:(UIViewController *__nonnull)vc
              onFinish:(void(^__nullable)(BOOL isCanceled, BOOL isPassed, ZMStatusErrorType errorCode))callback;
- (void)startVideoWithBizNO:(NSString *__nonnull)bizNO
                 merchantID:(NSString *__nonnull)merchantID
                  extParams:(NSDictionary *__nullable)params
             viewController:(UIViewController *__nonnull)vc
                   onFinish:(void(^__nullable)(BOOL isCanceled, BOOL isPassed, ZMStatusErrorType errorCode, NSString* _Nullable videoPath))callback;
+ (NSString *__nullable)getVersion;
@end
