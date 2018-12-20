#import <Foundation/Foundation.h>
static NSString* licenceStr =@"";
@interface AuthManager : NSObject
+ (void)setLicencePath:(NSString *)licencePath;
+(NSString*)getLicenceStr;
+(int)setLicenceStr:(NSString*)licStr;
+(void)clearLicenceStr;
+(bool)checkIsLicStrExist;
@end
