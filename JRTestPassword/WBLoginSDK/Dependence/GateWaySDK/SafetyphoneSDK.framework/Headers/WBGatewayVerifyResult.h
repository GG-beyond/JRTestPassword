#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, WBGatewayVerifyErrorCode) {
    WBGatewayVerify_SUCCESS   = 100,         
    WBGatewayVerify_FAILURE   = 101,         
    WBGatewayVerify_CANCELLED = 102          
};
@interface WBGatewayVerifyResult : NSObject
@property (nonatomic, copy) NSString *channel;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, assign) WBGatewayVerifyErrorCode code;
@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, copy) NSString *successToken;
@property (nonatomic, copy) NSDictionary *extendInfo;
@end
