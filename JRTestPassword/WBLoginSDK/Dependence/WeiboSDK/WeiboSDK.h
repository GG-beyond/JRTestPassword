#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WBHttpRequest.h"
typedef NS_ENUM(NSInteger, WeiboSDKResponseStatusCode)
{
    WeiboSDKResponseStatusCodeSuccess               = 0,
    WeiboSDKResponseStatusCodeUserCancel            = -1,
    WeiboSDKResponseStatusCodeSentFail              = -2,
    WeiboSDKResponseStatusCodeAuthDeny              = -3,
    WeiboSDKResponseStatusCodeUserCancelInstall     = -4,
    WeiboSDKResponseStatusCodePayFail               = -5,
    WeiboSDKResponseStatusCodeShareInSDKFailed      = -8,
    WeiboSDKResponseStatusCodeUnsupport             = -99,
    WeiboSDKResponseStatusCodeUnknown               = -100,
};
@protocol WeiboSDKDelegate;
@protocol WBHttpRequestDelegate;
@class WBBaseRequest;
@class WBBaseResponse;
@class WBMessageObject;
@class WBImageObject;
@class WBBaseMediaObject;
@class WBHttpRequest;
@class PHAsset;
@class WBNewVideoObject;
@interface WeiboSDK : NSObject
+ (BOOL)isWeiboAppInstalled;
+ (BOOL)isCanShareInWeiboAPP;
+ (BOOL)isCanSSOInWeiboApp;
+ (BOOL)openWeiboApp;
+ (NSString *)getWeiboAppInstallUrl;
+ (NSString *)getSDKVersion;
extern NSString * const WeiboSDKGetAidSucessNotification;
extern NSString * const WeiboSDKGetAidFailNotification;
+ (NSString *)getWeiboAid;
+ (BOOL)registerApp:(NSString *)appKey;
+ (BOOL)handleOpenURL:(NSURL *)url delegate:(id<WeiboSDKDelegate>)delegate;
+ (BOOL)sendRequest:(WBBaseRequest *)request;
+ (BOOL)sendResponse:(WBBaseResponse *)response;
+ (void)enableDebugMode:(BOOL)enabled;
+ (void)logOutWithToken:(NSString *)token delegate:(id<WBHttpRequestDelegate>)delegate withTag:(NSString*)tag;
+ (void)linkToUser:(NSString *)uid;
+ (void)linkToSingleBlog:(NSString *)uid blogID:(NSString *)mid;
+ (void)linkToArticle:(NSString *)aid;
+ (void)shareToWeibo:(NSString *)content;
+ (void)commentToWeibo:(NSString *)mid;
+ (void)linkToSearch:(NSString *)keyword;
+ (void)linkToTimeLine;
+ (void)linkToProfile;
@end
@protocol WeiboSDKDelegate <NSObject>
- (void)didReceiveWeiboRequest:(WBBaseRequest *)request;
- (void)didReceiveWeiboResponse:(WBBaseResponse *)response;
@end
#pragma mark - DataTransferObject and Base Request/Response
@interface WBDataTransferObject : NSObject
@property (nonatomic, strong) NSDictionary *userInfo;
@property (strong, nonatomic, readonly) NSString *sdkVersion;
@property (nonatomic, assign) BOOL shouldOpenWeiboAppInstallPageIfNotInstalled;
@end
@interface WBBaseRequest : WBDataTransferObject
+ (id)request;
@end
@interface WBBaseResponse : WBDataTransferObject
@property (strong, nonatomic, readonly) NSDictionary *requestUserInfo;
@property (nonatomic, assign) WeiboSDKResponseStatusCode statusCode;
+ (id)response;
@end
#pragma mark - Authorize Request/Response
@interface WBAuthorizeRequest : WBBaseRequest
@property (nonatomic, strong) NSString *redirectURI;
@property (nonatomic, strong) NSString *scope;
@property (nonatomic, assign) BOOL shouldShowWebViewForAuthIfCannotSSO;
@end
@interface WBAuthorizeResponse : WBBaseResponse
@property (nonatomic, strong) NSString *userID;
@property (nonatomic, strong) NSString *accessToken;
@property (nonatomic, strong) NSDate *expirationDate;
@property (nonatomic, strong) NSString *refreshToken;
@end
#pragma mark - ProvideMessageForWeibo Request/Response
@interface WBProvideMessageForWeiboRequest : WBBaseRequest
@end
@interface WBProvideMessageForWeiboResponse : WBBaseResponse
@property (nonatomic, strong) WBMessageObject *message;
+ (id)responseWithMessage:(WBMessageObject *)message;
@end
#pragma mark - SendMessageToWeibo Request/Response
@interface WBSendMessageToWeiboRequest : WBBaseRequest
@property (nonatomic, strong) WBMessageObject *message;
+ (id)requestWithMessage:(WBMessageObject *)message;
+ (id)requestWithMessage:(WBMessageObject *)message
                authInfo:(WBAuthorizeRequest *)authRequest
            access_token:(NSString *)access_token;
@end
@interface WBSendMessageToWeiboResponse : WBBaseResponse
@property (nonatomic,strong) WBAuthorizeResponse *authResponse;
@end
#pragma mark - MessageObject / ImageObject
@interface WBMessageObject : NSObject
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) WBImageObject *imageObject;
@property (nonatomic, strong) WBBaseMediaObject *mediaObject;
@property (nonatomic, strong) WBNewVideoObject *videoObject;
+ (id)message;
@end
typedef NS_ENUM(NSInteger, WBSDKMediaTransferErrorCode)
{
    WBSDKMediaTransferAlbumPermissionError              = 0,
    WBSDKMediaTransferAlbumWriteError               = 0,
    WBSDKMediaTransferAlbumAssetTypeError               = 0,
};
@protocol WBMediaTransferProtocol <NSObject>
-(void)wbsdk_TransferDidReceiveObject:(id)object;
-(void)wbsdk_TransferDidFailWithErrorCode:(WBSDKMediaTransferErrorCode)errorCode andError:(NSError*)error;
@end
@interface WBImageObject : NSObject
@property (nonatomic, strong) NSData *imageData;
@property (nonatomic) BOOL isShareToStory;
+ (id)object;
- (UIImage *)image;
@property(nonatomic,weak)id<WBMediaTransferProtocol> delegate;
- (void)addImages:(NSArray<UIImage *>*)imageArray;
- (void)addImageAssets:(NSArray<PHAsset*>*)assetArray;
-(NSArray*)finalAssetArray;
@end
@interface WBNewVideoObject : NSObject
+ (id)object;
@property (nonatomic) BOOL isShareToStory;
@property(nonatomic,weak)id<WBMediaTransferProtocol> delegate;
-(void)addVideo:(NSURL*)videoUrl;
-(void)addVideoAsset:(PHAsset*)videoAsset;
-(NSString*)finalAsset;
@end
#pragma mark - Message Media Objects
@interface WBBaseMediaObject : NSObject
@property (nonatomic, strong) NSString *objectID;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *description;
@property (nonatomic, strong) NSData *thumbnailData;
@property (nonatomic, strong) NSString *scheme;
+ (id)object;
@end
#pragma mark - Message WebPage Objects
@interface WBWebpageObject : WBBaseMediaObject
@property (nonatomic, strong) NSString *webpageUrl;
@end
