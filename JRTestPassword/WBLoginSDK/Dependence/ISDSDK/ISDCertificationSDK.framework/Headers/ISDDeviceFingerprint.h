#import <Foundation/Foundation.h>
@interface ISDDeviceFingerprint : NSObject
@property (nonatomic, copy) void(^ISDFingerprintBlock)();
+ (void)deviceFingerprintCreateWithAppId:(NSString *)appid
                                  userId:(NSString *)userid;
+ (NSString *)deviceIdQuery;
+ (NSString *)smartIdQuery;
@end
