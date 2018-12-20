#import "JRConfusionHHJPassportService.h"
#import "JRConfusionHHJMineUserModel.h"
#import "JRConfusionHHJCacheManager.h"
#import "JRConfusionHHJWebViewViewController.h"
#import "JRWindoControlManager.h"
#import "JRRunLog.h"
NSString * const HJLoginSDKLogInNotification            = @"HJLoginSDKLogInNotification";
NSString * const HJLoginSDKLogOutNotification           = @"HJLoginSDKLogOutNotification";
NSString * const HJLoginSDKGetUseInfoNotification       = @"HJLoginSDKGetUseInfoNotification";
NSString * const HJUserInfoServerSuccessfulNotification = @"HJUserInfoServerSuccessfulNotification";
@interface JRConfusionHHJPassportService () <WBLoginSDKDelegate>
@property (nonatomic, copy) HJPassportLoginCallback     loginCallback;
@property (nonatomic, copy) HJPassportBindPhoneCallback bindPhoneCallback;
@end
@implementation JRConfusionHHJPassportService
+ (instancetype)shareInstance
{
    static JRConfusionHHJPassportService *service = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        service = [[JRConfusionHHJPassportService alloc] init];
        [WBLoginSDK setLogoImage:[UIImage imageNamed:@"login_logo"]];
        [WBLoginSDK setProductID:@"58haojie"];
    });
    return service;
}
- (void)showLoginPageWithViewController:(UIViewController *)aViewController
                             completion:(HJPassportLoginCallback)completion
{
    self.loginCallback = completion;
    UIViewController *VC = [[UIViewController alloc] init];
    VC.title = @"Hello World";
    NSDictionary *params = @{
                             LoginSDKUserAgreementName : @"《58秒有钱使用协议》",
                             LoginSDKUserAgreementViewController : VC,};
    [WBLoginSDK handleLoginSDKServiceWithType:WBLoginSDKServiceType_LoginAccount
                                     delegate:self
                      presentByViewController:aViewController params:params];
}
- (void)showPhoneNumLoginPageWithViewController:(UIViewController *)aViewController
                                     completion:(HJPassportLoginCallback)completion
{
    self.loginCallback = completion;
    JRConfusionHHJWebViewViewController *skipAgreement1 = [[JRConfusionHHJWebViewViewController alloc]initWithUrlString:Agreement_Serviceprotocol_URL hideNaviBar:NO hideTabBar:YES];
    JRConfusionHHJWebViewViewController *skipAgreement2 = [[JRConfusionHHJWebViewViewController alloc]initWithUrlString:Agreement_Privacypolicy_URL hideNaviBar:NO hideTabBar:YES];
    JRConfusionHHJWebViewViewController *skipAgreement3 = [[JRConfusionHHJWebViewViewController alloc]initWithUrlString:Agreement_Announcement_URL hideNaviBar:NO hideTabBar:YES];
    NSDictionary *params = @{
                             LoginSDKUserAgreementName : @"《58秒有钱使用协议》",
                             LoginSDKUserAgreementViewController:skipAgreement1,
                             @"LoginSDKUserRegisterAgreementName":@"《58同城使用协议》",
                             @"LoginSDKUserRegisterAgreementViewController":skipAgreement3,
                             @"LoginSDKUserRegisterAgreementSecondName":@"《58同城隐私权条款》",
                             @"LoginSDKUserRegisterAgreementSecondViewController":skipAgreement2,
                             };
    [WBLoginSDK handleLoginSDKServiceWithType:WBLoginSDKServiceType_LoginMobile
                                     delegate:self
                      presentByViewController:aViewController params:params];
}
- (void)showBindPhoneNumPageWithViewController:(UIViewController *)aViewController
                                        params:(NSDictionary *)params
                                    completion:(HJPassportBindPhoneCallback)completion
{
    self.bindPhoneCallback = completion;
    [WBLoginSDK handleLoginSDKServiceWithType:WBLoginSDKServiceType_MobileBind
                                     delegate:self
                      presentByViewController:aViewController params:params];
}
- (void)signOut
{
    [WBLoginSDK handleLoginSDKServiceWithType:WBLoginSDKServiceType_LogOut
                                     delegate:self
                      presentByViewController:nil params:nil];
}
+ (BOOL)isLogin
{
    return [WBLoginSDK isLogin];
}
+ (NSString *)userPPU
{
    return [WBLoginSDK userPPU];
}
+ (NSString *)userName
{
    return [WBLoginSDK userName];
}
+ (NSString *)userID
{
    return [WBLoginSDK userIDWithString];
}
+ (BOOL)isBindPhone
{
    NSString *bindPhoneNum = [WBLoginSDK userBindedPhoneNumber];
    return bindPhoneNum && bindPhoneNum.length;
}
#pragma mark - WBLoginSDKDelegate
- (void)SDKBindPhoneFinished:(WBLoginSDKModel *)resultModel
{
    if (resultModel.isSuccessed) {
        self.bindPhoneCallback(resultModel);
    } else {
        WBLoginSDKModel *model = [[WBLoginSDKModel alloc] init];
        model.isSuccessed      = NO;
        model.msg              = @"绑定手机失败";
        self.bindPhoneCallback(model);
    }
}
- (void)SDKLogOutFinished
{
    [JRConfusionHHFHttpRequestManager deleteCookie:@"isbind"];
    [JRConfusionHHFHttpRequestManager deleteCookie:@"PPU"];
    POST_NOTIFICATION(HJLoginSDKLogOutNotification, nil, nil);
    HJLog(@"账户已退出登录");
}
- (void)SDKLogin58Finished:(WBLoginSDKModel *)resultModel
{
    if (resultModel.isSuccessed) {
        self.loginCallback(resultModel);
        [[JRWindoControlManager shareIntance] appendReportParams:@{@"uid":[JRConfusionHHJPassportService userID]}];
        [[JRRunLog shareIntance] appendReportParams:@{@"uid":[JRConfusionHHJPassportService userID]}];
        POST_NOTIFICATION(HJLoginSDKLogInNotification, resultModel, nil);
        [WMDA event:10000003 cateID:-1 bg:nil andAttributes:nil];
        [self getUserInfo];
        [self completeUserInfo];
    } else {
        WBLoginSDKModel *model = [[WBLoginSDKModel alloc] init];
        model.isSuccessed      = NO;
        model.msg              = @"登录失败";
        self.loginCallback(model);
    }
}
- (void)getUserInfo{
    [[JRConfusionHHFHttpRequestManager SharedHttpRequestManager] postWithUrl:User_Business_URL parameters:@{@"ppu":[JRConfusionHHJPassportService userPPU]} progress:nil successed:^(JRConfusionHHFURLSessionDataTask *task, id response, JRConfusionHHJBaseResponse *baseResponse, id data) {
        if (![response isKindOfClass:[NSDictionary class]]) {
            return;
        }
        if([[response objectForKey:@"code"]integerValue] == 0){
            NSDictionary *dic = [response objectForKey:@"data"];
            JRConfusionHHJMineUserModel *model = [JRConfusionHHJMineUserModel yy_modelWithDictionary:dic];
            if ((model.haojieUser && model.rejectStatus)||(!model.haojieUser)) {
                POST_NOTIFICATION(@"TabBarChildVCChage", nil, @{@"change":@"add"});
                model.showMoreBar = YES;
            }
            HJLog(@"userId =  %@",KCHJUserInfo);
            JRConfusionHHJMineUserModel *oldModel = [[JRConfusionHHJCacheManager defaultManager] objectForKey:KCHJUserInfo];
            if ((oldModel !=nil && oldModel.showMoreBar) &&  !model.showMoreBar) {
                model.showMoreBar = YES;
                POST_NOTIFICATION(@"TabBarChildVCChage", nil, @{@"change":@"add"});
            }
            [[JRConfusionHHJCacheManager defaultManager]setObject:model forKey:KCHJUserInfo];
            POST_NOTIFICATION(HJUserInfoServerSuccessfulNotification, nil, nil);
            return;
        }else if([[response objectForKey:@"code"]integerValue] == 200){
            POST_NOTIFICATION(@"NeedRelogin", nil, nil);
        }else{
            [JRConfusionHHJUtility showHudText:[response objectForKey:@"msg"]];
        }
    }failure:^(JRConfusionHHFURLSessionDataTask *task, NSError *error) {
        HJLog(@"######@@@%@",error);
    }];
}
- (void)completeUserInfo{
    [[JRConfusionHHFHttpRequestManager SharedHttpRequestManager] postWithUrl:User_Complete_URL parameters:@{@"PPU":[JRConfusionHHJPassportService userPPU]} progress:nil successed:^(JRConfusionHHFURLSessionDataTask *task, id response, JRConfusionHHJBaseResponse *baseResponse, id data) {
        if([[response objectForKey:@"code"]integerValue] == 0){
            return;
        }
    }failure:^(JRConfusionHHFURLSessionDataTask *task, NSError *error) {
        HJLog(@"######@@@%@",error);
    }];
}
- (void)SDKLoginClosedWithType:(WBLoginSDKType)aType
{
    HJLog(@"用户取消了登录");
}
- (void)SDKFetchUserInfoFinished:(WBLoginSDKModel *)resultModel
{
    [JRConfusionHHFHttpRequestManager saveCookiesKey:@"isbind" value:[JRConfusionHHJPassportService isBindPhone]?@"true":@""];
    POST_NOTIFICATION(HJLoginSDKGetUseInfoNotification, resultModel, nil);
}
- (void)SDKRegister58Finished:(WBLoginSDKModel *)resultModel
{
}
- (void)SDKResetPasswordFinished:(WBLoginSDKModel *)resultModel
{
}
- (void)SDKFetchMobileCodeFinished:(WBLoginSDKModel *)resultModel
{
}
- (void)SDKFetchVoiceCodeFinished:(WBLoginSDKModel *)resultModel
{
}
- (void)SDKChangePhoneFinished:(WBLoginSDKModel *)resultModel
{
}
- (void)SDKUnBindPhoneFinished:(WBLoginSDKModel *)resultModel
{
}
@end
