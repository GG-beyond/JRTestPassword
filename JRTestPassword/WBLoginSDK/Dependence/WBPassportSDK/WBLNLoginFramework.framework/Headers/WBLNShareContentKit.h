#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@protocol WBLNShareContentKitDelegate,WBLNShareCustomDelegate;
@interface WBLNShareContentKit: NSObject
@property (nonatomic, weak) id<WBLNShareContentKitDelegate> delegate;
@property (nonatomic, weak) id<WBLNShareCustomDelegate> shareDelegte;
@property (nonatomic, strong) NSString *qqID;
@property (nonatomic, strong) NSString *qqRedirectURI;
@property (nonatomic, strong) NSString *wechatID;
@property (nonatomic, strong) NSString *sinaID;
@property (nonatomic, strong) NSString *sinaRedirectURI;
@property (nonatomic, assign) BOOL wechatPayNotFromPaySDK;
+ (WBLNShareContentKit *)sharedInstance;
+ (BOOL)isWXAppInstalled;
+ (BOOL)isSinaWeiboAppInstalled;
+ (BOOL)isQQInstalled;
- (BOOL)handleOpenURL:(NSURL *)url;
- (void)getQQUserInfo;
- (void)loginFromQQ;
- (void)loginFromSina;
- (void)loginFromWeChat;
- (void)registerWithQQAppID:(NSString *)qqID
              qqRedirectURI:(NSString *)qqRedURI
                   wechatID:(NSString *)wechatID
                 sinaAppKey:(NSString *)sinaAppKey
            sinaRedirectURI:(NSString *)sinaRedURI;
@end
@protocol WBLNShareCustomDelegate <NSObject>
@optional
- (void)QQShareFinished:(NSMutableDictionary *)dict resultCode:(NSInteger)code msgType:(NSInteger) msgType;
- (void)WechatShareFinished:(NSMutableDictionary *)dict resultCode:(NSInteger)code msgType:(NSInteger) msgType;
- (void)SinaShareFinished:(NSMutableDictionary *)dict resultCode:(NSInteger)code msgType:(NSInteger) msgType;
@end
@protocol WBLNShareContentKitDelegate <NSObject>
@optional
- (void)shareContentKit:(WBLNShareContentKit *)aSharecontentkit qqDidLoginSuccess:(NSDictionary *)dict;
- (void)shareContentKit:(WBLNShareContentKit *)aSharecontentkit qqDidLoginError:(NSError *)error;
- (void)shareContentKit:(WBLNShareContentKit *)aSharecontentkit qqUserInfo:(NSDictionary *)dict;
- (void)shareContentKit:(WBLNShareContentKit *)aSharecontentkit sinaDidLogin:(NSDictionary *)dict;
- (void)shareContentKit:(WBLNShareContentKit *)aSharecontentkit sinaDidLoginError:(NSError *)error;
- (void)shareContentKit:(WBLNShareContentKit *)aSharecontentkit sinaUserInfo:(NSString *)infoStr;
- (void)shareContentKit:(WBLNShareContentKit *)aSharecontentkit wechatDidLoginSuccess:(NSDictionary *)dict;
- (void)shareContentKit:(WBLNShareContentKit *)aSharecontentkit wechatDidLoginError:(NSError *)error;
- (void)shareContentKit:(WBLNShareContentKit *)aSharecontentkit wechatDidFinishPay:(int)code;
- (void)shareContentKit:(WBLNShareContentKit *)aSharecontentkit weChatUserInfo:(NSDictionary *)userInfoDict;
@end
