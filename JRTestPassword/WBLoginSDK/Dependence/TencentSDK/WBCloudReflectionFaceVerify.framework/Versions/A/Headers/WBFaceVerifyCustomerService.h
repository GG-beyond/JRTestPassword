#import <UIKit/UIKit.h>
#import "WBFaceVerifyConst.h"
#import "WBFaceVerifySDKConfig.h"
#import "WBFaceVerifyCompareSourceConfig.h"
#import "WBFaceVerifyResult.h"
#import "WBFaceUserInfo.h"
NS_ASSUME_NONNULL_BEGIN
UIKIT_EXTERN NSString *const WBFaceVerifyCustomerServiceDidFinishedNotification;
@class WBFaceVerifyCustomerService;
@protocol WBFaceVerifyCustomerServiceDelegate  <NSObject>
@required
-(void)wbfaceVerifyCustomerServiceDidFinishedWithFaceVerifyResult:(WBFaceVerifyResult *)faceVerifyResult;
@end
@interface WBFaceVerifyCustomerService : NSObject
@property (nullable,nonatomic,weak) id<WBFaceVerifyCustomerServiceDelegate> delegate;
@property (nonatomic, assign, readonly) BOOL isService;
+(instancetype)sharedInstance;
-(void)startLoginLiveCheckAndCompareServiceWithUserid:(NSString *)userid
                                          nonce:(NSString *)nonce
                                           sign:(NSString *)sign
                                          appid:(NSString *)appid
                                        orderNo:(NSString *)orderNo
                                     apiVersion:(NSString *)apiVersion
                                        licence:(NSString *)licence
                                 faceverifyType:(WBFaceVerifyLivingType)facetype
                                       userInfo:(WBFaceUserInfo *)userInfo
                                      configure:(WBFaceVerifySDKConfig *)configure
                                        success:(void (^)())success
                                        failure:(void (^)(WBFaceError *error))failure;
-(void)startLoginLiveCheckAndCompareServiceWithUserid:(NSString *)userid
                                                nonce:(NSString *)nonce
                                           sign:(NSString *)sign
                                          appid:(NSString *)appid
                                        orderNo:(NSString *)orderNo
                                     apiVersion:(NSString *)apiVersion
                                        licence:(NSString *)licence
                                 faceverifyType:(WBFaceVerifyLivingType)facetype
                            compareSourceConfig:(WBFaceVerifyCompareSourceConfig *)compareSoureConfig
                                      configure:(WBFaceVerifySDKConfig *)configure
                                        success:(void (^)())success
                                        failure:(void (^)(WBFaceError *error))failure;
-(void)startLoginLiveCheckServiceWithUserid:(NSString *)userid
                                          nonce:(NSString *)nonce
                                           sign:(NSString *)sign
                                          appid:(NSString *)appid
                                        orderNo:(NSString *)orderNo
                                     apiVersion:(NSString *)apiVersion
                                        licence:(NSString *)licence
                                 faceverifyType:(WBFaceVerifyLivingType)facetype
                                      configure:(WBFaceVerifySDKConfig *)configure
                                        success:(void (^)())success
                                        failure:(void (^)(WBFaceError *error))failure;
@end
NS_ASSUME_NONNULL_END
