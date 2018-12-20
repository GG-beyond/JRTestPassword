#ifndef YT_Common_Macro_h
#define YT_Common_Macro_h
#define IncludeUImageCvMat 1
#ifndef YT_DUMMY_CLASS
#define YT_DUMMY_CLASS(name) \
@interface YT_DUMMY_CLASS_##name : NSObject @end \
@implementation YT_DUMMY_CLASS_##name @end
#endif
#ifndef WeakRef
#define WeakRef(weakVar, strongVar) __weak __typeof(&*strongVar) weakVar = strongVar
#endif
#ifndef WeakSelf
#define WeakSelf() WeakRef(weakSelf, self)
#endif
#ifndef StrongRef
#define StrongRef(strongVar, weakVar) __strong __typeof(&*weakVar) strongVar = weakVar
#endif
#ifndef StrongSelf
#define StrongSelf() StrongRef(strongSelf,weakSelf)
#endif
#endif 
