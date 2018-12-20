#ifndef WPTBindAccount_h
#define WPTBindAccount_h
#import <Foundation/Foundation.h>
@protocol WPTBindAccountService <NSObject>
@required
+ (id<WPTBindService>)initViewController;
- (void)SDKLogin58Finished:(WBLoginSDKModel *)resultModel;
- (void)SDKLoginBack:(WBLoginSDKModel *)resultModel;
- (void)SDKLoginDanger:(WBLoginSDKModel *)resultModel onlyPassword:(BOOL)isOnlyPassword;
- (void)SDKLoginChallengeBindMobile:(WBLoginSDKModel *)resultModel;
- (void)SDKLoginThirdBindLoginAccountFinished:(WBLoginSDKModel *)resultModel;
@end
#endif 
