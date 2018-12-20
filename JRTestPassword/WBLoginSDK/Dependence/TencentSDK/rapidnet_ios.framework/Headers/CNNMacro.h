#ifndef YoutuCNNMacro_h
#define YoutuCNNMacro_h
#undef USE_RPN_LIB
#ifdef __OPTIMIZE__
#define YT_DEBUG 0
#else
#define YT_DEBUG 1
#endif
#define USE_FAST_VERSION 1
#if YT_DEBUG
#define METAL_BUILD_MODE 0
#else
#define METAL_BUILD_MODE 0
#endif
#ifdef __OPTIMIZE__
#define YTLog(fmt, ...)
#else
#define YTLog(fmt, ...) NSLog((@"%s [Line %d]" fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif
#define YTBreakIf(cond) if(cond) break
#ifdef __OPTIMIZE__
#define YTBreakIfMsg(cond, msg)  if(cond) break
#else
#define YTBreakIfMsg(cond, msg)  if(cond) YTLog(msg); if(cond) break
#endif
#define YTWeakRef(weakVar, strongVar) __weak __typeof(&*strongVar) weakVar = strongVar
#define YTWeakSelf() YTWeakRef(weakSelf, self)
#define YTStrongRef(strongVar, weakVar) __strong __typeof(&*weakVar) strongVar = weakVar
#define YTStrongSelf() YTStrongRef(strongSelf,weakSelf)
#ifdef __arm64__
#define YT_ARM64 1
#endif
#if TARGET_IPHONE_SIMULATOR
#define YT_IS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define YT_IS_SIMULATOR 0
#endif
#define YT_USE_MPSCNN 0
#endif 
