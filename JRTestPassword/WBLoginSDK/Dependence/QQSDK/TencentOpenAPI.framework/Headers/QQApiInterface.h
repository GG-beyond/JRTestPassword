#import <Foundation/Foundation.h>
#import "QQApiInterfaceObject.h"
@protocol QQApiInterfaceDelegate <NSObject>
- (void)onReq:(QQBaseReq *)req;
- (void)onResp:(QQBaseResp *)resp;
- (void)isOnlineResponse:(NSDictionary *)response;
@end
@interface QQApiInterface : NSObject
+ (BOOL)handleOpenURL:(NSURL *)url delegate:(id<QQApiInterfaceDelegate>)delegate;
+ (QQApiSendResultCode)sendReq:(QQBaseReq *)req;
+ (QQApiSendResultCode)SendReqToQZone:(QQBaseReq *)req;
+ (BOOL)isQQInstalled;
+ (BOOL)isTIMInstalled;
+ (BOOL)isQQSupportApi;
+ (BOOL)isTIMSupportApi;
+ (BOOL)isSupportShareToQQ;
+ (BOOL)isSupportPushToQZone;
+ (BOOL)openQQ;
+ (BOOL)openTIM;
+ (NSString *)getQQInstallUrl;
+ (NSString *)getTIMInstallUrl;
@end
