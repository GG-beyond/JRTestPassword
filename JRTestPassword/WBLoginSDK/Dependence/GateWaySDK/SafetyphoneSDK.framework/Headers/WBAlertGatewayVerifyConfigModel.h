#import <UIKit/UIKit.h>
@interface WBAlertGatewayVerifyConfigModel : NSObject
@property (nonatomic, copy)NSString * verifyPhoneTitle;
@property (nonatomic, copy)NSString * verifyMessageCodeTitle;
@property (nonatomic, strong)UIFont * titleLabelFont;
@property (nonatomic, strong)UIColor * titleLabelTextColor;
@property (nonatomic, strong)UIColor * textFieldTextColor;
@property (nonatomic, strong)UIFont * textFont;
@property (nonatomic, strong)UIColor * getVerificationCodeTextAbledColor;
@property (nonatomic, strong)UIColor * getVerificationCodeTextDisabledColor;
@property (nonatomic, copy)NSString * cancelButtonTextStr;
@property (nonatomic, copy)NSString * nextStepButtonTextStr;
@property (nonatomic, strong)UIColor * nextStepButtonTextAbledColor;
@property (nonatomic, strong)UIFont * operateButtonTextFont;
@property (nonatomic, strong)UIColor * operateButtonTextColor;
@end
