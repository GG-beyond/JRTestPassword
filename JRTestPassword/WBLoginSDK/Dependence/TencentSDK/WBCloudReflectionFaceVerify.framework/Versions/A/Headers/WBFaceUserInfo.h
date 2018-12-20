#import <Foundation/Foundation.h>
@interface WBFaceUserInfo : NSObject
@property (nonatomic,copy) NSString *name;    
@property (nonatomic,copy) NSString *idType;  
@property (nonatomic,copy) NSString *idNo;    
- (BOOL)isIDStringValid;
@end
