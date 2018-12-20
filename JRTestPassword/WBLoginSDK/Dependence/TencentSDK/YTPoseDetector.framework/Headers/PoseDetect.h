#import <Foundation/Foundation.h>
#import <YTTrackPro/TC_FaceAlignment.h>
@interface PoseDetect: NSObject
+ (PoseDetect *)sharedManager;
- (BOOL)livePoseDetect:(TC_FaceShape)shape withbLiveNessDetect:(BOOL&)bLivenessDetect withLiveType:(int)liveType withImg:(ncv::Mat&)img withRes:(int*)res;
- (void)resetPoseDetect;
@end
