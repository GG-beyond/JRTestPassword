#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WBLoginSDKModel.h"
#import "WBLNBiometricsTypes.h"
#import "WPTBindService.h"
static NSString* const passportSDKVersion = @"2.0.4.1";
PASSPORT_EXTERN NSString * const LoginSDKLoginNotification;
PASSPORT_EXTERN NSString * const LoginSDKFetchedUserInfoNotification;
PASSPORT_EXTERN NSString * const LoginSDKLogoutNotification;
PASSPORT_EXTERN NSString * const LoginSDK3rdBindFinishedNotification;
PASSPORT_EXTERN NSString * const LoginSDKChangePasswordNotification;
PASSPORT_EXTERN NSString * const LoginSDKHideLeftButton; 
PASSPORT_EXTERN NSString * const LoginSDKHideRightButton; 
PASSPORT_EXTERN NSString * const LoginSDKHidePhoneButton; 
PASSPORT_EXTERN NSString * const LoginSDKHideAccountButton; 
PASSPORT_EXTERN NSString * const LoginSDKHideFindPwdButton; 
PASSPORT_EXTERN NSString * const LoginSDKHideThirdLoginView; 
PASSPORT_EXTERN NSString * const LoginSDKShiledIdentifier; 
PASSPORT_EXTERN NSString * const LoginSDKNickName; 
PASSPORT_EXTERN NSString * const LoginSDKHeadUrl; 
PASSPORT_EXTERN NSString * const LoginSDKHeadImage; 
PASSPORT_EXTERN NSString * const LoginSDKClearAccount; 
PASSPORT_EXTERN NSString * const LoginSDKUserAgreementViewController; 
PASSPORT_EXTERN NSString * const LoginSDKUserAgreementName; 
PASSPORT_EXTERN NSString * const LoginSDKUserRegisterAgreementViewController; 
PASSPORT_EXTERN NSString * const LoginSDKUserRegisterAgreementName; 
PASSPORT_EXTERN NSString * const LoginSDKUserRegisterAgreementSecondViewController; 
PASSPORT_EXTERN NSString * const LoginSDKUserRegisterAgreementSecondName; 
PASSPORT_EXTERN NSString * const LoginSDKUserName; 
PASSPORT_EXTERN NSString * const LoginSDKUserPassword; 
PASSPORT_EXTERN NSString * const LoginSDKMobileNumber; 
PASSPORT_EXTERN NSString * const LoginSDKMobileCode; 
PASSPORT_EXTERN NSString * const LoginSDKMobileCodeType; 
PASSPORT_EXTERN NSString * const LoginSDKTokenCode;   
PASSPORT_EXTERN NSString * const LoginSDKPageCloseDelay; 
PASSPORT_EXTERN NSString * const LoginSDKHeadLessHandleHideToast; 
typedef NS_ENUM(NSInteger, WBLoginSDKType){
    WBLoginSDKServiceType_LoginAccount,
    WBLoginSDKServiceType_LoginMobile,
    WBLoginSDKServiceType_LoginFinance,
    WBLoginSDKServiceType_Register,
    WBLoginSDKServiceType_FindPassword,
    WBLoginSDKServiceType_ChangePassword,
    WBLoginSDKServiceType_AccountSwitch,
    WBLoginSDKServiceType_RegisterFinance,
    WBLoginSDKServiceType_LoginShield,
    WBLoginSDKServiceType_MobileBind,
    WBLoginSDKServiceType_MobileChangeBind,
    WBLoginSDKServiceType_MobileUnBind,
    WBLoginSDKServiceType_FillUserDetailInfos,
    WBLoginSDKServiceType_QQBind,
    WBLoginSDKServiceType_QQUnBind,
    WBLoginSDKServiceType_WECHATBind,
    WBLoginSDKServiceType_WECHATUnBind,
    WBLoginSDKServiceType_WECHATAuth,
    WBLoginSDKServiceType_Change3rdBind,
    WBLoginSDKServiceType_UserInfo,
    WBLoginSDKServiceType_UploadImage,
    WBLoginSDKServiceType_UpdateUserInfo,
    WBLoginSDKServiceType_CheckPPU,
    WBLoginSDKServiceType_LogOut,
    WBLoginSDKServiceType_FetchMobileCode,
    WBLoginSDKServiceType_LoginMobileHeadLess,
    WBLoginSDKServiceType_LoginAccountHeadLess,
    WBLoginSDKServiceType_LoginByQQHeadLess,
    WBLoginSDKServiceType_LoginByWechatHeadLess,
    WBLoginSDKServiceType_LoginBySinaHeadLess,
    WBLoginSDKServiceType_OpenBiometricLogin,
    WBLoginSDKServiceType_CloseBiometricLogin,
    WBLoginSDKServiceType_ThirdBindLogin,
    WBLoginSDKServiceType_ThirdReglogin,
    WBLoginSDKServiceType_ThirdBindAccount
};
typedef NS_ENUM(NSInteger, WB3rdBindType){
    WB3rdBindTypeSINA                 = 0,                
    WB3rdBindTypeQQ                      ,                
    WB3rdBindTypeWECHAT                  ,                
    WB3rdBindTypePHONE                   ,                
};
typedef NS_ENUM(NSInteger, WBLoginType){
    WBLoginTypeMermoryDefault              = -99,              
    WBLoginTypeUnknow                      = 0,                
    WBLoginTypeAUTO_UsernameAndPassword       ,                
    WBLoginTypeAUTO_PhoneValidatecode         ,                
    WBLoginTypeAUTO_PhoneRegister             ,                
    WBLoginTypeAUTO_PhoneFindPassword         ,                
    WBLoginTypeAUTO_Shiled                    ,                
    WBLoginTypeAUTO_SINA                      ,                
    WBLoginTypeAUTO_QQ                        ,                
    WBLoginTypeAUTO_WECHAT                    ,                
    WBLoginTypeAUTO_WebView                   ,               
    WBLoginTypeAUTO_CheckPPU                  ,               
};
typedef NS_ENUM(NSInteger, WPTCustomVCServiceType){
    WPTCustomVCServiceType_Bind         = 0,
    WPTCustomVCServiceType_BindAccount  = 1 << 1,
};
@protocol WBLoginSDKDelegate <NSObject>
@optional
- (void)SDKLoginServiceDidPresentedWithType:(WBLoginSDKType)aType;
- (void)SDKLoginClosedWithType:(WBLoginSDKType)aType;
- (void)SDKPictureVerifyCancelled;
- (void)SDKPasswordVerifyCancelled;
- (void)SDKLogOutFinished;
- (void)SDKCheckPPUFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKLogin58Finished:(WBLoginSDKModel *)resultModel;
- (void)SDKLogin3rdCancelled:(NSString *)a3rdType;
- (void)SDKLogin3rdUninstall;
- (void)SDKRegister58Finished:(WBLoginSDKModel *)resultModel;
- (void)SDK3rdBindFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKResetPasswordFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKFetchMobileCodeFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKFetchVoiceCodeFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKBindPhoneFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKChangePhoneFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKUnBindPhoneFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKUnBindQQFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKUnBindWechatFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKAuthWechatFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKFetchUserInfoFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKUpdateUserInfoFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKUploadUserImageFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKLoginShieldFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKChangePasswordFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKLoginWillEnterPictureVerifyFlow:(WBLoginSDKModel *)resultModel;
- (void)SDKLoginWillEnterDangerFlow:(WBLoginSDKModel *)resultModel;
- (void)SDKLoginWillEnterBackfillFlow:(WBLoginSDKModel *)resultModel;
- (void)SDKLoginWillEnterThirdRepeatPasswordFlow:(WBLoginSDKModel *)resultModel;
- (void)SDKLoginWillEnterChallengeBindMobile:(WBLoginSDKModel *)resultModel;
- (void)SDKFillUserDetailInfoFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKLoginThirdBindLoginAccountFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKOpenBiometricsSuccessWillConnect;
- (void)SDKOpenBiometricsFailureWithType:(WBLNBiometricsEvaluateType)type;
- (void)SDKOpenBiometricLoginFinished:(WBLoginSDKModel *)resultModel;
- (void)SDKCloseBiometricLoginFinished:(WBLoginSDKModel *)resultModel;
@end
@protocol WBLoginSDKLogHandleDelegate <NSObject>
@optional
- (void)SDKLogHandleWithPagetype:(NSString *)pagetype
                          action:(NSString *)action
                           param:(NSString *)strParam;
@end
@interface WBLoginSDK : NSObject
+ (void)initLoginSDKWithQQAppID:(NSString *)qqID
                  QQRedirectURI:(NSString *)qqRedURI
                       WechatID:(NSString *)wechatID
                     SinaAppKey:(NSString *)sinaAppKey
                SinaRedirectURI:(NSString *)sinaRedURI;
+ (void)shieldLoginInitWithRSAP12Path:(NSString *)p12Path RSASecImportExportPassphrase:(NSString *)passphrase;
+ (void)initCertWithAppid:(NSString *)appid wxAppid:(NSString *)wxappid;
+ (BOOL)handleShareKitOpenURL:(NSURL *)url;
+ (void)setProductID:(NSString *)anID;
+ (NSString *)productID;
+ (void)setLongitude:(NSString *)longitude Latitude:(NSString *)latitude;
+ (void)handleLoginSDKServiceWithType:(WBLoginSDKType)aSDKServiceType
                             delegate:(id<WBLoginSDKDelegate>)aDelegate
              presentByViewController:(UIViewController *)aViewController
                               params:(NSDictionary *)params;
+ (WBLoginType)loginType;
+ (BOOL)isLogin;
+ (BOOL)isAllowMobileUnbind;
+ (void)setuserPPU:(NSString *)aPpuString;
+ (NSString *)userPPU;
+ (NSString *)userName;
+ (NSString *)userIDWithString;
+ (NSNumber *)userIDWithNumber;
+ (NSString *)userImageUrl;
+ (NSString *)userNickName;
+ (NSInteger )userSex;
+ (NSString *)userBindedPhoneNumber;
+ (NSString *)deviceFinger;
+ (BOOL)isBind3rd:(WB3rdBindType)aBindType;
+ (NSInteger)isDisplayBiometricLogin;
+ (BOOL)isEnableBiometricLoginForCurrentUser;
+ (void)setOverSeasLogin:(BOOL)isOversea;
+ (void)set3rdLoginHidden:(BOOL)isHidden;
+ (void)setLogoImage:(UIImage *)anImage;
+ (void)setFinanceLoginBannerImage:(UIImage *)loginBannerImage;
+ (void)setFinanceRegisterBannerImage:(UIImage *)registerBannerImage;
+ (void)setRegBackFillUserInfoPageHidden:(BOOL)isHidden;
+ (void)setSynchronizeWechatUserInfoBtnHidden:(BOOL)isHidden;
+ (void)setLogHandler:(id <WBLoginSDKLogHandleDelegate>)aHandler;
+(void)registCustomVCService:(NSString*)vcClassString forService:(WPTCustomVCServiceType)type;
+ (NSString*)sdkVersion;
@end
