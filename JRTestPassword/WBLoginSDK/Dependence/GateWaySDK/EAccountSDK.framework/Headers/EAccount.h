#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#pragma mark - 主模块功能。
NS_ASSUME_NONNULL_BEGIN
typedef   void (^successHandler) ( NSDictionary * _Nonnull resultDic);
typedef   void (^failureHandler) (NSError * _Nonnull error);
@interface EAccount : NSObject
+ (void)initWithSelfKey:(NSString *)appKey
                      appSecret:(NSString *)appSecrect
                        appName:(NSString *)appName;
+ (void)getMobileVerifyCode:(successHandler)completion failure:(failureHandler)fail;
+ (void)canGetMobile:(successHandler)completion failure:(failureHandler)fail;
+ (UIView*_Nonnull)getEaccountLoginView:(CGPoint)viewOrigin
                           btnSize:(CGSize)btnSize
                       btnBgColor:(UIColor*)btnBgColor
                       btnBgHColor:(UIColor*)btnBgHcolor
                btnCornerRadius:(CGFloat)btnCornerRadius
                       btnTitle:(NSString *_Nonnull)btnTtitle
                   btnTitleFont:(UIFont*)btnTitleFont
                  btnTitleColor:(UIColor*)btnTitleColor
                     agreementTitleFont:(UIFont*)agreementTitleFont
                    agreementTitleColor:(UIColor*)agreementTitleColor
             agreementLabelBgColor:(UIColor *)agreementLabelBgColor
                   hideAgreementTitle:(BOOL)hideAgreementTitle
                           success:(nonnull successHandler)success
                           failure:(nonnull failureHandler)failure;
+ (void)getSmsLoginPage:(NSDictionary *)webConfigureParas
   navigationBarBgColor:(UIColor *)navigationBarBgColor
           leftBtnImage:(UIImage *)leftBtnImage
          leftBtnToEdge:(float)edgeLeft
              viewTitle:(NSString *)viewTitle
          viewTitleFont:(UIFont *)viewTitlefont
         viewTitleColor:(UIColor *)viewTitleColor
          rightBtnTitle:(NSString *)rightBtnTitle
      rightBtnTitleFont:(UIFont *)rightBtnTitleFont
     rightBtnTitleColor:(UIColor *)rightBtnTitleColor
         rightBtnToEdge:(float)edgeRight
    superViewController:(UIViewController *)superViewController
         rightBtnAction:(successHandler)rightBtnAction
                success:(nonnull successHandler)success
                failure:(nonnull failureHandler)failure;
@end
NS_ASSUME_NONNULL_END
