#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class ISDCTListModel;
@protocol ISDCertificationDelegate <NSObject>
- (void)certStatusQueryComplement:(NSArray<ISDCTListModel *> *)status;
@end
typedef NS_ENUM(NSInteger, ISDOriginalType) {
    ISDOriginalTypeNomal = 3,         
    ISDOriginalTypeLegalPerson = 100, 
    ISDOriginalTypeAuthList = -1,     
    ISDOriginalTypeZMRealName = 2,    
    ISDOriginalTypeLicense = 501,     
    ISDOriginalTypeBank = 7,          
    ISDOriginalTypePubAccount = 700,  
    ISDOriginalTypePayCert = 9,       
    ISDOriginalTypeCertCancel = -2,   
    ISDOriginalTypeBindChange = 6,    
    ISDOriginalTypeFinancial = -3,    
    ISDOriginalTypeCertCenter = -100, 
    ISDOriginalTypeGateway = 11,      
    ISDOriginalTypeUnknown = 999      
};
typedef NS_ENUM(NSInteger, ISDCertificationStatus) {
    ISDCertificationSucceed  = 100,  
    ISDCertificationFailed   = 101,  
    ISDCertificationCanceled = 102,  
    ISDCertificationOngoing  = 103   
};
@interface ISDCertification : NSObject
@property (nonatomic, copy) NSString *isd_pid;      
@property (nonatomic, copy) NSString *isd_ppu;      
@property (nonatomic, copy) NSString *isd_appid;    
@property (nonatomic, copy) NSString *isd_userid;   
@property (nonatomic, copy) NSString *isd_wxAppId;  
@property (nonatomic, assign, getter=isAlertNeeded) BOOL alertNeeded;
@property (nonatomic, copy, readonly) NSString *ISD_SDKVersion;
@property (nonatomic, copy) void (^ISDCertificationBlock)(ISDCertificationStatus status, NSDictionary *spreadingParam);
@property (nonatomic, weak) id<ISDCertificationDelegate> delegate;
+ (instancetype)sharedInstance;
- (void)authWithTarget:(UIViewController *)viewController
          originalType:(ISDOriginalType)originalType
 andSpreadingParameter:(NSDictionary *)aDictionary;
- (void)authWithTarget:(UIViewController *)viewController
          originalMark:(NSString *)originalMark
     certificationType:(NSString *)certificationType
 andSpreadingParameter:(NSDictionary *)aDictionary;
- (void)certificationStatusQuery;
- (void)payCertHandleOpenURL:(NSURL *)url;
+ (void)AliCloudInitialize;
@end
