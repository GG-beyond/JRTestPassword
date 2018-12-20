#import <UIKit/UIKit.h>
typedef void(^verifySuccess)(NSString *successToken, NSString *extend);
typedef void(^verifyFailure)(NSInteger errorCode, NSString *errorMessage, NSString *extend);
@interface GWEmbedTextField : UITextField
- (void)inputInfoVerifySuccess:(verifySuccess)success orFailure:(verifyFailure)failure;
@end
