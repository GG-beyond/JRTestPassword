#ifndef ZMConfig_h
#define ZMConfig_h
typedef NS_ENUM(NSInteger, ZMStatusErrorType) {
    ZMStatusErrorNone = 100,             
    ZMStatusErrorDeviceNotSupport  = 101,       
    ZMStatusErrorNoPermission = 102,            
    ZMStatusErrorFaceInit = 103,                
    ZMStatusErrorNetwork = 104,                 
    ZMStatusErrorBizNo = 105,                   
    ZMStatusErrorBundleId = 106,                
    ZMStatusErrorDataSource = 107,              
    ZMStatusErrorVerification = 108,            
    ZMStatusErrorInternal = 109,                
    ZMStatusErrorUnmatchedID = 110,             
    ZMStatusErrorNoNetPermission = 111,         
    ZMStatusErrorNoCameraPermission = 112,      
    ZMStatusErrorNoSensorPermission = 113,      
    ZMStatusErrorVersionTooOld = 115,           
    ZMStatusErrorUseInfo = 116,                 
    ZMStatusErrorBiznoLimitExceed = 117,        
    ZMStatusErrorWrongSystemTime =  118,        
};
typedef void(^VoidBlockFinish)(BOOL isCanceled, BOOL isPassed, ZMStatusErrorType errorCode);
typedef void(^VoidBlockVideoFinish)(BOOL isCanceled, BOOL isPassed, ZMStatusErrorType errorCode, NSString* videoPath);
#endif 
