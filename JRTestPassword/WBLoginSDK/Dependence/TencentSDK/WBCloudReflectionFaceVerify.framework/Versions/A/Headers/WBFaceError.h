#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
UIKIT_EXTERN NSString *const WBFaceErrorDomainInputParams;
UIKIT_EXTERN NSString *const WBFaceErrorDomainLoginNetwork;
UIKIT_EXTERN NSString *const WBFaceErrorDomainLoginServer;
UIKIT_EXTERN NSString *const WBFaceErrorDomainGetInfo;
UIKIT_EXTERN NSString *const WBFaceErrorDomainNativeProcess;
UIKIT_EXTERN NSString *const WBFaceErrorDomainCompareNetwork;
UIKIT_EXTERN NSString *const WBFaceErrorDomainCompareServer;
@interface WBFaceError: NSObject
@property (nonatomic, readonly, copy) NSString *domain;
@property (nonatomic, readonly, assign) NSInteger code; 
@property (nonatomic, readonly, copy) NSString *desc; 
@property (nonatomic, readonly, copy) NSString *reason; 
@property (nonatomic, readonly, copy) NSDictionary * _Nullable otherInfo;
+ (instancetype)errorWithDomain:(NSString *)domain code:(NSInteger)code desc:(NSString *)desc;
+ (instancetype)errorWithDomain:(NSString *)domain code:(NSInteger)code desc:(NSString *)desc reason:(NSString *)reason;
+ (instancetype)errorWithDomain:(NSString *)domain code:(NSInteger)code desc:(NSString *)desc reason:(NSString *)reason otherInfo:(nullable NSDictionary *)otherInfo;
@end
NS_ASSUME_NONNULL_END
