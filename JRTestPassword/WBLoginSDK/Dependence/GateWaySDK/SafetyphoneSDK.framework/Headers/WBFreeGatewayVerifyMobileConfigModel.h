#import <UIKit/UIKit.h>
@interface WBFreeGatewayVerifyMobileConfigModel : NSObject
@property (nonatomic, strong)UIColor * navigationBarColor;
@property (nonatomic, strong)UIImage * backImage;
@property (nonatomic, copy)NSString * verifyPhoneTitle;
@property (nonatomic, copy)NSString * verifyMessageCodeTitle;
@property (nonatomic, strong)UIFont * titleFont;
@property (nonatomic, strong)UIColor * titleColor;
@property (nonatomic, strong)UIImage * logoImage;
@property (nonatomic, strong)UIColor * rightBarBtnTextColor;
@property (nonatomic, strong)UIFont * rightBarBtnFont;
@property (nonatomic, copy)NSString * rightBarBtnText;
@property (nonatomic, assign)BOOL isHiddenChangeBtn;
@property (nonatomic, strong)UIColor * textFailedBGColor;
@property (nonatomic, strong)UIColor * operateBtnNormalBackGroundColor;
@property (nonatomic, strong)UIColor * operateBtnTextColor;
@property (nonatomic, strong)UIFont * operateBtnTextFont;
@property (nonatomic, assign)CGFloat operateBtnCornerRadius;
@property (nonatomic, copy)NSString * phoneVerifyOperateBtnStr;
@property (nonatomic, copy)NSString * messageVerifyOperateBtnStr;
@end
