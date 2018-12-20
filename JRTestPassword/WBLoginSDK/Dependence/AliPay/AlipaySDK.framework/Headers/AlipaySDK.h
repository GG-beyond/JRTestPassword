#import "APayAuthInfo.h"
typedef void(^CompletionBlock)(NSDictionary *resultDic);
@interface AlipaySDK : NSObject<UIAlertViewDelegate>
+ (AlipaySDK *)defaultService;
- (void)payOrder:(NSString *)orderStr
      fromScheme:(NSString *)schemeStr
        callback:(CompletionBlock)completionBlock;
- (void)processOrderWithPaymentResult:(NSURL *)resultUrl standbyCallback:(CompletionBlock)completionBlock;
- (BOOL)isLogined;
- (NSString *)currentVersion;
- (void)setUrl:(NSString *)url;
- (void) authWithInfo:(APayAuthInfo *)authInfo
             callback:(CompletionBlock)completionBlock;
- (void)processAuthResult:(NSURL *)resultUrl standbyCallback:(CompletionBlock)completionBlock;
@end
