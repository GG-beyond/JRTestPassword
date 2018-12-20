#ifndef YTRapidNetError_h
#define YTRapidNetError_h
#import <Foundation/Foundation.h>
static NSString *YTRapidNetErrorDomain = @"yt.rapidnet.error.domain";
typedef enum : int {
    YTRapidNetErrorOK                    = 0,
    YTRapidNetErrorInvalidData           = 1,
    YTRapidNetErrorInvalidModel          = 2,
    YTRapidNetErrorInternalError         = 3,
    YTRapidNetErrorInvalidLayerParam     = 100,
    YTRapidNetErrorInvalidLayerData      = 100 + 1,
    YTRapidNetErrorLowSystemVersion   = 1000,
    YTRapidNetErrorNoGPUDevice        = 1000 + 1,
    YTRapidNetErrorNoGPULibrary       = 1000 + 2,
} YTRapidNetError;
#endif 
