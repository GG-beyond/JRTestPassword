#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WXApi.h"
typedef enum EPay58Type {
	EPayment58 = 0,
	EPay58Recharge
} EPay58Type;
typedef enum Pay58ResultCode {
    Pay58Success           = 0,
    Pay58ErrCodeCommon     = -1,
} Pay58ResultCode;
#pragma mark - 58支付订单
@interface Pay58Order : NSObject
@property (nonatomic, copy) NSString *balancePaid;
@property (nonatomic, copy) NSString *cookie;
@property (nonatomic, copy) NSString *starttime;
@property (nonatomic, copy) NSString *endtime;
@property (nonatomic, copy) NSString *payfrom;
@property (nonatomic, copy) NSString *buyAccountId;
@property (nonatomic, copy) NSString *merId;
@property (nonatomic, copy) NSString *sign;
@property (nonatomic, copy) NSString *cityId;
@property (nonatomic, copy) NSString *orderId;
@property (nonatomic, copy) NSString *orderMoney;
@property (nonatomic, copy) NSString *accountType;
@property (nonatomic, copy) NSString *IAPProductID;
@property (nonatomic ,assign) NSUInteger IAPProductCount;
@property (nonatomic, copy) NSString *validPayTime;
@property (nonatomic, copy) NSString *productName;
@property (nonatomic, copy) NSString *productDesc;
@property (nonatomic, copy) NSString *userTrueName;
@property (nonatomic, copy) NSString *userCreId;
@property (nonatomic, copy) NSString *notifyUrl;
@property (nonatomic, copy) NSString *extensionInfo;
@property (nonatomic, assign) BOOL isShowAccountInfo;
@property (nonatomic, assign) BOOL isShowWXPay;
@property (nonatomic, assign) BOOL isShowAliPay;
@property (nonatomic, assign) BOOL isShowIAP;
@property (nonatomic, assign) BOOL isHidenBalancePay;
@property (nonatomic, assign) BOOL isShowPayResultTips;
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIColor *titleColor;
@end
#pragma mark - 58充值订单
@interface Pay58RechargeOrder : NSObject
@property (nonatomic, copy) NSString *cookie;
@property (nonatomic, copy) NSString *buyAccountId;
@property (nonatomic, copy) NSString *merId;
@property (nonatomic, copy) NSString *payfrom;
@property (nonatomic, copy) NSString *orderMoney;
@property (nonatomic, copy) NSString *accountType;
@property (nonatomic, copy) NSString *productDesc;
@property (nonatomic, copy) NSString *productName;
@property (nonatomic, copy) NSString *notifyUrl;
@property (nonatomic, copy) NSString *orderId;
@property (nonatomic, copy) NSString *extensionInfo;
@property (nonatomic, assign) BOOL isMoneyEditable;
@property (nonatomic, assign) BOOL isShowWXPay;
@property (nonatomic, assign) BOOL isShowAliPay;
@property (nonatomic, assign) BOOL isShowWapPay;
@property (nonatomic, assign) BOOL isShowPayResultTips;
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIColor *titleColor;
@end
#pragma mark - 58支付和充值 结果
@interface Pay58Result : NSObject
@property (nonatomic, assign) Pay58ResultCode code ;
@property (nonatomic, copy) NSString *desc ;
@property (nonatomic, copy) NSString *cashMoney;
@end
#pragma mark - 支付点击事件对象
@interface Pay58Click : NSObject
@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *pageID;
@property (nonatomic, strong) NSNumber *time;
@property (nonatomic, strong) NSDictionary *data;
@end
#pragma mark - Pay58Delegate
@protocol Pay58Delegate <NSObject>
@required
- (void)pay58ViewDidDisappear:(Pay58Result *)payResult isUserClosed:(BOOL)isUserClose;
- (void)pay58ViewDidAppear;
@end
#pragma mark - Pay58
typedef void(^Pay58CallbackBlock)(Pay58Result *result);
typedef void(^Pay58ClickBlock)(Pay58Click *click);
@interface Pay58 : NSObject<WXApiDelegate>
@property (nonatomic, strong) UIImage *navigationBarBgImage;
@property (nonatomic, strong) UIButton *navigationBarBackButton;
@property (nonatomic, strong) UIColor *navigationBarBackgroundColor;
@property (nonatomic, strong) UIColor *navigationBarTitleColor;
@property (nonatomic, assign) UIStatusBarStyle statusBarStyle;
@property (nonatomic, copy) NSString *balanceType;
@property (nonatomic, weak) id<Pay58Delegate> delegate;
+ (Pay58 *)pay58DefaultService;
+ (Pay58 *)pay58DefaultServiceWithWXAppId:(NSString *)appid;
- (void)initWeiXinAppID:(NSString *)appid;
- (void)initAliAppURLScheme:(NSString *)urlScheme;
- (void)pay58:(Pay58Order*)payOrder fromViewcontroller:(UIViewController*)fromViewCon nativeCallback:(Pay58CallbackBlock)nativeCallbackblock;
- (void)pay58Recharge:(Pay58RechargeOrder*)payOrder fromViewcontroller:(UIViewController*)fromViewCon nativeCallback:(Pay58CallbackBlock)nativeCallbackblock;
- (void)pay58handleOpenURL:(NSURL *)orderUrl;
- (void)registerCallback:(Pay58CallbackBlock)nativeCallbackblock;
- (void)paymentCallback:(Pay58Result *)result;
- (void)closePaymentViewController;
- (void)finishedPayment:(Pay58Result *)payResult isUserClosed:(BOOL)isUserClose;
+ (void)checkIAPUnVefifiedReceipt;
- (void)regisiterClickCallBack:(Pay58ClickBlock)clickCallBack;
- (void)executeClick:(Pay58Click *)click;
@end
