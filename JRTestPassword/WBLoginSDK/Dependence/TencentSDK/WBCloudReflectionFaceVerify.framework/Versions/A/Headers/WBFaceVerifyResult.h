#import <UIKit/UIKit.h>
#import "WBFaceError.h"
@interface WBFaceVerifyResult : NSObject
@property (nonatomic, assign, readonly) BOOL isSuccess;
@property (nonatomic, copy, readonly) NSString *orderNo;
@property (nonatomic, copy, readonly) NSString * sign;
@property (nonatomic, copy, readonly) NSString * liveRate;
@property (nonatomic, copy, readonly) NSString * similarity;
@property (nonatomic, copy, readonly) NSString * userImageString;
@property (nonatomic, strong, readonly) WBFaceError * error;
+(instancetype)resultWith:(BOOL)isSuccess error:(WBFaceError *)error;
+(instancetype)resultWith:(BOOL)isSuccess error:(WBFaceError *)error sign:(NSString *)sign;
+(instancetype)resultWith:(BOOL)isSuccess error:(WBFaceError *)error sign:(NSString *)sign liveRate:(NSString *)liveRate similarity:(NSString *)similarity;
+(instancetype)resultWith:(BOOL)isSuccess error:(WBFaceError *)error sign:(NSString *)sign liveRate:(NSString *)liveRate similarity:(NSString *)similarity userImageString:(NSString *)userImageString;
-(NSString *)description;
@end
