#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WBLNLoginFramework/WBLoginSDK.h>
UIKIT_EXTERN NSString * const HJLoginSDKLogInNotification;
UIKIT_EXTERN NSString * const HJLoginSDKLogOutNotification;
UIKIT_EXTERN NSString * const HJLoginSDKGetUseInfoNotification;
UIKIT_EXTERN NSString * const HJUserInfoServerSuccessfulNotification;
typedef void(^HJPassportLoginCallback)(WBLoginSDKModel *resultModel);
typedef void(^HJPassportBindPhoneCallback)(WBLoginSDKModel *resultModel);
@interface JRConfusionHHJPassportService : NSObject
+ (instancetype)shareInstance;
- (void)showLoginPageWithViewController:(UIViewController *)aViewController
                             completion:(HJPassportLoginCallback)completion;
- (void)showPhoneNumLoginPageWithViewController:(UIViewController *)aViewController
                                     completion:(HJPassportLoginCallback)completion;
- (void)showBindPhoneNumPageWithViewController:(UIViewController *)aViewController
                                        params:(NSDictionary *)params
                                    completion:(HJPassportBindPhoneCallback)completion;
-(void)getUserInfo;
- (void)signOut;
+ (BOOL)isLogin;
+ (NSString *)userPPU;
+ (NSString *)userName;
+ (NSString *)userID;
+ (BOOL)isBindPhone;
@end
