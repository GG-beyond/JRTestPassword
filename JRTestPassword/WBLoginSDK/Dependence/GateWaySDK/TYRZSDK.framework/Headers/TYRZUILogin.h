#import <UIKit/UIKit.h>
@interface TYRZUILogin : NSObject
@property (nonatomic,class,readonly) NSString *sdkVersion;
+ (void)initializeWithAppId:(NSString *)appId appKey:(NSString *)appKey;
+ (void)printConsoleEnable:(BOOL)enable;
+ (void)preGetPhonenumber:(void (^)(id sender))complete;
+ (void)customUIWithParams:(NSDictionary *)customUIParams
               customViews:(void(^)(NSDictionary *customAreaView))customViews;
+ (void)enableCustomSMS:(BOOL)flag;
+ (void)getTokenExpWithController:(UIViewController *)vc
                         complete:(void (^)(id sender))complete;
+ (void)getTokenImpWithComplete:(void (^)(id sender))complete;
@end
