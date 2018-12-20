#import <UIKit/UIKit.h>
#ifndef WBFaceVerifyConst_h
#define WBFaceVerifyConst_h
UIKIT_EXTERN NSString *const WBCloudFaceVerifySDKVersion;
typedef NS_ENUM(NSInteger,WBFaceVerifyLivingType){
    WBFaceVerifyLivingType_Action,
    WBFaceVerifyLivingType_Number,
    WBFaceVerifyLivingType_Light,
};
typedef NS_ENUM(NSInteger,WBFaceVerifyCompareType){
    WBFaceVerifyCompareType_None,
    WBFaceVerifyCompareType_SourceImage,
    WBFaceVerifyCompareType_IDCard,
};
typedef NS_ENUM(NSInteger, WBFaceVerifyCameraPresetType){
    WBFaceVerifyCameraPresetType_DefaultResolution, 
    WBFaceVerifyCameraPresetType_MediumResolution,  
    WBFaceVerifyCameraPresetType_HighResolution,    
};
typedef NS_ENUM(NSInteger, WBFaceVerifyTheme) {
    WBFaceVerifyThemeDarkness,
    WBFaceVerifyThemeLightness,
};
#endif 
