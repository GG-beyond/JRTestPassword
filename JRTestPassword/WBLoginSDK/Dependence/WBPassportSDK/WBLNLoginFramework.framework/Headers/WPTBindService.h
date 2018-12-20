#ifndef WPTBindService_h
#define WPTBindService_h
#import <Foundation/Foundation.h>
@class WBLoginSDKModel;
@protocol WPTBindService <NSObject>
@required
+ (id<WPTBindService>)initViewController;
- (void)SDKLogin58Finished:(WBLoginSDKModel *)resultModel;
- (void)SDKFetchMobileCodeFinished:(WBLoginSDKModel *)resultModel;
@end
#endif 
