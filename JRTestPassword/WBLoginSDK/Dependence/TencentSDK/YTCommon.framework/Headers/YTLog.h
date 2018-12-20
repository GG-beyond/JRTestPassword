#import <Foundation/Foundation.h>
typedef void(^YTLogCallback)(NSString *message);
#ifdef __OPTIMIZE__
#define YTLogD(fmt, ...)
#else
#define YTLogD(fmt, ...) YTLogger(nil, 0, (@"%s[Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif
#define YTLogE(fmt, ...) YTLogger(nil, 1, (@"%s[Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define YTLogCallbackE(callback, fmt, ...) YTLogger(callback, 1, (@"%s[Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
FOUNDATION_EXPORT void YTLogger(YTLogCallback callback, int mode, NSString *format, ...) NS_FORMAT_FUNCTION(3,4) NS_NO_TAIL_CALL;
