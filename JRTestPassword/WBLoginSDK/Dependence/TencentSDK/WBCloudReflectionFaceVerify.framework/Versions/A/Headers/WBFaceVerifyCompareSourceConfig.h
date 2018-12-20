#import <Foundation/Foundation.h>
@interface WBFaceVerifyCompareSourceConfig: NSObject
@property (nonatomic, strong, readonly) UIImage * sourceImage;
@property (nonatomic, assign, readonly) BOOL isHDImage;
@property (nonatomic, assign, readonly) BOOL canCompressSourceImage;
-(void)setSourceImage:(UIImage *)sourceImage;
+(instancetype)compareSouceConfigWithImage:(UIImage *)sourceImage;
+(instancetype)compareSouceConfigWithImage:(UIImage *)sourceImage isHDImage:(BOOL)isHDImage canCompressSourceImage:(BOOL)canCompressSourceImage;
@end
