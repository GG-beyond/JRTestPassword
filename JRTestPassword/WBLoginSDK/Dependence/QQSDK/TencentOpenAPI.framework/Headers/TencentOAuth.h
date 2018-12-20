#import <UIKit/UIKit.h>
#import "sdkdef.h"
@protocol TencentSessionDelegate;
@protocol TencentLoginDelegate;
@protocol TencentApiInterfaceDelegate;
@protocol TencentWebViewDelegate;
@class TencentApiReq;
@class TencentApiResp;
typedef enum
{
    kTencentNotAuthorizeState,
    kTencentSSOAuthorizeState,
    kTencentWebviewAuthorzieState,
} TencentAuthorizeState;
typedef enum
{
    kAuthModeClientSideToken,
    kAuthModeServerSideCode,
} TencentAuthMode;
#pragma mark - TencentOAuth(授权登录及相关开放接口调用)
@interface TencentOAuth : NSObject
{
    NSMutableDictionary* _apiRequests;
	NSString* _accessToken;
	NSDate* _expirationDate;
	id<TencentSessionDelegate> _sessionDelegate;
	NSString* _localAppId;
	NSString* _openId;
	NSString* _redirectURI;
	NSArray* _permissions;
}
@property(nonatomic, copy) NSString* accessToken;
@property(nonatomic, copy) NSDate* expirationDate;
@property(nonatomic, assign) id<TencentSessionDelegate> sessionDelegate;
@property(nonatomic, copy) NSString* localAppId;
@property(nonatomic, copy) NSString* openId;
@property(nonatomic, copy) NSString* redirectURI;
@property(nonatomic, retain) NSString* appId;
@property(nonatomic, retain) NSString* uin;
@property(nonatomic, retain) NSString* skey;
@property(nonatomic, copy) NSDictionary* passData;
@property(nonatomic, assign) TencentAuthMode authMode;
@property(nonatomic, retain) NSString* unionid;
@property(nonatomic, assign) TencentAuthShareType authShareType;
- (NSString *)getCachedToken;
- (NSString *)getCachedOpenID;
- (NSDate *)getCachedExpirationDate;
- (BOOL)isCachedTokenValid;
- (BOOL)deleteCachedToken;
+ (NSString*)sdkVersion;
+ (NSString*)sdkSubVersion;
+ (BOOL)isLiteSDK;
+ (TencentAuthorizeState *)authorizeState;
+ (QQVersion)iphoneQQVersion;
+ (QQVersion)iphoneTIMVersion;
- (id)initWithAppId:(NSString *)appId
        andDelegate:(id<TencentSessionDelegate>)delegate;
+ (BOOL)iphoneQQInstalled;
+ (BOOL)iphoneTIMInstalled;
+ (BOOL)iphoneQQSupportSSOLogin;
+ (BOOL)iphoneTIMSupportSSOLogin;
- (BOOL)authorize:(NSArray *)permissions;
- (BOOL)authorize:(NSArray *)permissions
		 inSafari:(BOOL)bInSafari;
- (BOOL)authorize:(NSArray *)permissions
       localAppId:(NSString *)localAppId
		 inSafari:(BOOL)bInSafari;
- (BOOL)incrAuthWithPermissions:(NSArray *)permissions;
- (BOOL)reauthorizeWithPermissions:(NSArray *)permissions;
- (BOOL)RequestUnionId;
+ (BOOL)HandleOpenURL:(NSURL *)url;
+ (BOOL)CanHandleOpenURL:(NSURL *)url;
+ (NSString *)getLastErrorMsg;
- (NSString *)getServerSideCode;
- (void)logout:(id<TencentSessionDelegate>)delegate;
- (BOOL)isSessionValid;
- (BOOL)getUserInfo;
- (BOOL)cancel:(id)userData;
- (TCAPIRequest *)cgiRequestWithURL:(NSURL *)apiURL method:(NSString *)method params:(NSDictionary *)params callback:(id<TCAPIRequestDelegate>)callback;
- (BOOL)sendAPIRequest:(TCAPIRequest *)request callback:(id<TCAPIRequestDelegate>)callback;
- (NSString *)getUserOpenID;
@end
#pragma mark - TencentLoginDelegate(授权登录回调协议)
@protocol TencentLoginDelegate <NSObject>
@required
- (void)tencentDidLogin;
- (void)tencentDidNotLogin:(BOOL)cancelled;
- (void)tencentDidNotNetWork;
@optional
- (NSArray *)getAuthorizedPermissions:(NSArray *)permissions withExtraParams:(NSDictionary *)extraParams;
- (void)didGetUnionID;
@end
#pragma mark - TencentSessionDelegate(开放接口回调协议)
@protocol TencentSessionDelegate<NSObject, TencentLoginDelegate,
                                TencentWebViewDelegate>
@optional
- (void)tencentDidLogout;
- (BOOL)tencentNeedPerformIncrAuth:(TencentOAuth *)tencentOAuth withPermissions:(NSArray *)permissions;
- (BOOL)tencentNeedPerformReAuth:(TencentOAuth *)tencentOAuth;
- (void)tencentDidUpdate:(TencentOAuth *)tencentOAuth;
- (void)tencentFailedUpdate:(UpdateFailType)reason;
- (void)getUserInfoResponse:(APIResponse*) response;
- (void)responseDidReceived:(APIResponse*)response forMessage:(NSString *)message;
- (void)tencentOAuth:(TencentOAuth *)tencentOAuth didSendBodyData:(NSInteger)bytesWritten totalBytesWritten:(NSInteger)totalBytesWritten totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite userData:(id)userData;
- (void)tencentOAuth:(TencentOAuth *)tencentOAuth doCloseViewController:(UIViewController *)viewController;
@end
#pragma mark - TencentWebViewDelegate(H5登录webview旋转方向回调)
@protocol TencentWebViewDelegate <NSObject>
@optional
- (BOOL) tencentWebViewShouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation;
- (NSUInteger) tencentWebViewSupportedInterfaceOrientationsWithWebkit;
- (BOOL) tencentWebViewShouldAutorotateWithWebkit;
@end
