#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
typedef NS_ENUM(NSUInteger, ISDCaptchaVerifyStatus) {
    ISDCaptchaVerifyPassed   = 100,
    ISDCaptchaVerifyFailed   = 101,
    ISDCaptchaVerifyCanceled = 102
};
@protocol ISDCaptchaManagerDelegate;
@interface ISDCaptchaManager : NSObject
@property (nonatomic, assign) BOOL automaticHide;
@property (nonatomic, assign) CGFloat delayTime;
@property (nonatomic, weak) id<ISDCaptchaManagerDelegate> delegate;
@property (nonatomic, readonly, copy) NSString *captchaVersion;
@property (nonatomic, readonly, copy) NSString *responseId;
@property (nonatomic, readonly, copy) NSString *successToken;
+ (instancetype)sharedManager;
- (void)startVerifyWithSessionID:(NSString *)session;
@end
@protocol ISDCaptchaManagerDelegate <NSObject>
- (void)captcha:(ISDCaptchaManager *)captchaManager verifyEndWithStatus:(ISDCaptchaVerifyStatus)status;
@end
