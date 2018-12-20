#import <UIKit/UIKit.h>
#import "WBAlertGatewayVerifyConfigModel.h"
#import "WBGatewayVerifyControllerCofigModel.h"
#import "WBEmbedGatewayVerifyConfigModel.h"
#import "WBFreeGatewayVerifyMobileConfigModel.h"
#import "WBGatewayVerifyResult.h"
#import "WBGatewayVerifyConfigModel.h"
UIKIT_EXTERN NSString *const WBGatewayVerifySDKVersion; 
typedef NS_ENUM(NSInteger, WBGatewayType) {
    WBGatewayTypePhoneVerify,                
    WBGatewayTypeMessageVerify,              
};
typedef NS_ENUM(NSInteger, WBVerifyGatewayType) {
    WBVerifyGatewayTypeAlert,                
    WBVerifyGatewayTypeTelecom,              
    WBVerifyGatewayTypeSingVC,               
    WBVerifyGatewayTypeFree,                 
};
@class WBGatewayVerifySDK;
@protocol WBGatewayVerifySDKDelegate<NSObject>
#pragma mark- 返回界面下方可以自定义的View
@optional
- (void)sdkReturnVCCustomView:(UIView *)customView currentNav:(UINavigationController *)nav withVerifyWay:(WBVerifyGatewayType)verifyGatewayType;
#pragma mark- 点击 短信验证/校验号码/事前获取手机号 界面右上角按钮的回调
- (void)sdkClickRightBarBtnWithCurrentNav:(UINavigationController *)nav  withVerifyWay:(WBVerifyGatewayType)verifyGatewayType;
#pragma mark-  事前获取手机号 的准备过程
- (void)sdkFreeGatewayVerifyManagerReadyStartVerify;
- (void)sdkFreeGatewayVerifyManagerStartVerify;
#pragma mark- 校验过程中报错的回调
- (void)sdkVerifyPhoneNumFailedWithShowType:(WBVerifyGatewayType)showType;
- (void)sdkMessageVerifyResultFailedWithShowType:(WBVerifyGatewayType)showType;
#pragma mark- 最终验证的结果回调
- (void)sdkVerifySuccessWithResultDic:(NSDictionary *)dic withVerifyWay:(WBVerifyGatewayType)verifyGatewayType;
- (void)sdkVerifyFailedWithErrorCode:(NSInteger)errorCode errorMsg:(NSString *)errorMsg channel:(NSString *)channel withVerifyWay:(WBVerifyGatewayType)verifyGatewayType;
@required
- (void)wbGatewayVerifyService:(WBGatewayVerifySDK *)verifyService didFinishedVerifyWithResult:(WBGatewayVerifyResult *)verifyResult;
@end
@interface WBGatewayVerifySDK : NSObject
@property (nonatomic, weak) id<WBGatewayVerifySDKDelegate> delegate;
+ (void)alertWayVerifyWithType:(WBGatewayType)type configModel:(WBAlertGatewayVerifyConfigModel *)model  sessionId:(NSString *)sessionId autoSms:(BOOL)autoSms delegate:(id<WBGatewayVerifySDKDelegate>)delegate;
+ (void)singleVCWithType:(WBGatewayType)type model:(WBGatewayVerifyControllerCofigModel *)model sessionId:(NSString *)sessionId autoSms:(BOOL)autoSms controller:(UIViewController *)controller delegate:(id<WBGatewayVerifySDKDelegate>)delegate;
+ (UIView *)embedWithType:(WBGatewayType)type
                   frameX:(CGFloat)x
                   frameY:(CGFloat)y
              configModel:(WBEmbedGatewayVerifyConfigModel *)model
                sessionId:(NSString *)sessionId
                  autoSms:(BOOL)autoSms
                 delegate:(id<WBGatewayVerifySDKDelegate>)delegate;
+ (void)freeGatewayVerifyWithConfigModel:(WBFreeGatewayVerifyMobileConfigModel *)model controller:(UIViewController *)controller sessionId:(NSString *)sessionId autoSms:(BOOL)autoSms delegate:(id<WBGatewayVerifySDKDelegate>)delegate;
+ (void)printConsoleEnable:(BOOL)enable;
+ (instancetype)shareWBGatewayVerifySDK;
- (void)configInitializeWithParam:(WBGatewayVerifyConfigModel *)configModel;
- (void)startVerifyWithType:(WBVerifyGatewayType)type
                     target:(UIViewController *)target
                      appId:(NSString *)appid
           extendParameters:(NSDictionary *)extendParam;
@end
