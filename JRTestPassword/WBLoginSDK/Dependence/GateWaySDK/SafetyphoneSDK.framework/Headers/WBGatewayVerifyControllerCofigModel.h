#import <UIKit/UIKit.h>
@interface WBGatewayVerifyControllerCofigModel : NSObject
@property (nonatomic, strong)UIColor * navigationBarColor;
@property (nonatomic, strong)UIImage * backImage;
@property (nonatomic, copy)NSString * verifyPhoneTitle;
@property (nonatomic, copy)NSString * verifyMessageCodeTitle;
@property (nonatomic, strong)UIFont * titleFont;
@property (nonatomic, strong)UIColor * titleColor;
@property (nonatomic, copy)NSString * rightBarButtonStr;
@property (nonatomic, strong)UIImage * logoImage;
@property (nonatomic, strong)UIColor * viewBackColor;
@property (nonatomic, strong)UIColor * rightBarBtnTextColor;
@property (nonatomic, strong)UIFont * rightBarBtnFont;
@property (nonatomic, copy)NSString * rightBarBtnText;
@property (nonatomic, strong)UIColor * textFieldTextColor;
@property (nonatomic, strong)UIFont * textFont;
@property (nonatomic, strong)UIColor * getVerificationCodeTextAbledColor;
@property (nonatomic, strong)UIColor * getVerificationCodeTextDisabledColor;
@property (nonatomic, strong)UIColor * nextStepButtonNormalBackGroundColor;
@property (nonatomic, strong)UIColor * nextStepButtonHighlightedBackGroundColor;
@property (nonatomic, copy)NSString * nextStepButtonStr;
@property (nonatomic, strong)UIFont * nextStepButtonFont;
@property (nonatomic, strong)UIColor * nextStepButtonTextColor;
@property (nonatomic, assign)CGFloat nextStepButtonCornerRadius;
@end
