#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
typedef enum {
    TCOLogLevel_Disabled = -1,   
    TCOLogLevel_Error = 0,
    TCOLogLevel_Warning,
    TCOLogLevel_Info,
    TCOLogLevel_Debug,
} TCOLogLevel;
typedef enum QQVersion
{
    kQQUninstall,
    kQQVersion3_0,
    kQQVersion4_0,      
    kQQVersion4_2_1,    
    kQQVersion4_5,      
    kQQVersion4_6,      
    kQQVersion4_7,      
} QQVersion;
typedef enum TIMVersion {
    kTIMUinstall,
    kTIMVersion1_1,
}TIMVersion;
typedef enum TencentAuthShareType {
    AuthShareType_QQ,
    AuthShareType_TIM,
}TencentAuthShareType;
typedef enum
{
	URLREQUEST_SUCCEED = 0, 
	URLREQUEST_FAILED = 1,  
} REPONSE_RESULT;
typedef enum
{
    kUpdateFailUnknown = 1,  
    kUpdateFailUserCancel,   
    kUpdateFailNetwork,      
} UpdateFailType;
@interface APIResponse : NSObject<NSCoding> {
    int      _detailRetCode;
	int		 _retCode;
	int		 _seq;
	NSString *_errorMsg;
	NSDictionary *_jsonResponse;
	NSString *_message;
    id       _userData;
}
@property (nonatomic, assign) int detailRetCode;
@property (nonatomic, assign) int retCode;
@property (nonatomic, assign) int seq;
@property (nonatomic, retain) NSString *errorMsg;
@property (nonatomic, retain) NSDictionary *jsonResponse;
@property (nonatomic, retain) NSString *message;
@property (nonatomic, retain) id userData;
@end
FOUNDATION_EXTERN NSString * const PARAM_USER_DATA;
FOUNDATION_EXTERN NSString * const PARAM_APP_ICON;
FOUNDATION_EXTERN NSString * const PARAM_APP_DESC;
FOUNDATION_EXTERN NSString * const PARAM_APP_INVITED_OPENIDS;
FOUNDATION_EXTERN NSString * const PARAM_SENDSTORY_RECEIVER;
FOUNDATION_EXTERN NSString * const PARAM_SENDSTORY_TITLE;
FOUNDATION_EXTERN NSString * const PARAM_SENDSTORY_COMMENT;
FOUNDATION_EXTERN NSString * const PARAM_SENDSTORY_SUMMARY;
FOUNDATION_EXTERN NSString * const PARAM_SENDSTORY_IMAGE;
FOUNDATION_EXTERN NSString * const PARAM_SENDSTORY_URL;
FOUNDATION_EXTERN NSString * const PARAM_SENDSTORY_ACT;
FOUNDATION_EXTERN NSString * const PARAM_SETUSERHEAD_PIC;
FOUNDATION_EXTERN NSString * const PARAM_SETUSERHEAD_FILENAME;
FOUNDATION_EXTERN NSString * const PARAM_RETCODE;
FOUNDATION_EXTERN NSString * const PARAM_MESSAGE;
FOUNDATION_EXTERN NSString * const PARAM_DATA;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorKeyExtraInfo;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorKeyRetCode;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorKeyMsg;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgUnsupportedAPI;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgSuccess;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgUnknown;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgUserCancel;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgReLogin;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgOperationDeny;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgNetwork;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgURL;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgDataParse;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgParam;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgTimeout;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgSecurity;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgIO;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgServer;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgWebPage;
FOUNDATION_EXTERN NSString * const TCOpenSDKErrorMsgUserHeadPicLarge;
typedef enum
{
    kOpenSDKInvalid = -1,                       
    kOpenSDKErrorUnsupportedAPI = -2,                
    kOpenSDKErrorSuccess = 0,                   
    kOpenSDKErrorUnknown,                       
    kOpenSDKErrorUserCancel,                    
    kOpenSDKErrorReLogin,                       
    kOpenSDKErrorOperationDeny,                 
    kOpenSDKErrorNetwork,                       
    kOpenSDKErrorURL,                           
    kOpenSDKErrorDataParse,                     
    kOpenSDKErrorParam,                         
    kOpenSDKErrorConnTimeout,                   
    kOpenSDKErrorSecurity,                      
    kOpenSDKErrorIO,                            
    kOpenSDKErrorServer,                        
    kOpenSDKErrorWebPage,                       
    kOpenSDKErrorUserHeadPicLarge = 0x010000,   
} OpenSDKError;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_ADD_TOPIC;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_ADD_ONE_BLOG;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_ADD_ALBUM;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_UPLOAD_PIC;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_LIST_ALBUM;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_ADD_SHARE;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_CHECK_PAGE_FANS;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_GET_INFO;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_GET_OTHER_INFO;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_GET_VIP_INFO;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_GET_VIP_RICH_INFO;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_GET_USER_INFO;
FOUNDATION_EXTERN NSString *const kOPEN_PERMISSION_GET_SIMPLE_USER_INFO;
typedef NSString *TCOptionalStr;
typedef id TCRequiredId;
@interface TCAPIRequest : NSMutableDictionary
@property (nonatomic, readonly) NSURL *apiURL;
@property (nonatomic, readonly) NSString *method;
@property (nonatomic, retain) TCRequiredId paramUserData;
@property (nonatomic, readonly) APIResponse *response;
- (void)cancel;
@end
@protocol TCAPIRequestDelegate <NSObject>
@optional
- (void)cgiRequest:(TCAPIRequest *)request didResponse:(APIResponse *)response;
@end
