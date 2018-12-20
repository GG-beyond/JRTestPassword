#import <Foundation/Foundation.h>
#ifdef __cplusplus
#define PASSPORT_EXTERN         extern "C" __attribute__((visibility ("default")))
#else
#define PASSPORT_EXTERN	        extern __attribute__((visibility ("default")))
#endif
@interface WBLoginSDKModel : NSObject
@property (nonatomic, assign) BOOL                isSuccessed;  
@property (nonatomic, copy) NSString            * uid;          
@property (nonatomic, copy) NSString            * username;     
@property (nonatomic, copy) NSString            * nickname;     
@property (nonatomic, assign)NSInteger            sex;          
@property (nonatomic, assign)NSInteger             code;         
@property (nonatomic, copy) NSString            * msg;          
@property (nonatomic, copy) NSString            * mobile;       
@property (nonatomic, copy) NSString            * faceurl;      
@property (nonatomic , copy  ) NSString                   * tokenCode;
@property (nonatomic , assign) BOOL                         isThirdBindExist;
@end
