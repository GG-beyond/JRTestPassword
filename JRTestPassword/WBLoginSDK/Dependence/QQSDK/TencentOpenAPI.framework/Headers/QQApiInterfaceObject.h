#ifndef QQApiInterface_QQAPIOBJECT_h
#define QQApiInterface_QQAPIOBJECT_h
#import <Foundation/Foundation.h>
typedef enum
{
    EQQAPISENDSUCESS = 0,
    EQQAPIQQNOTINSTALLED = 1,  
    EQQAPIQQNOTSUPPORTAPI = 2,  
    EQQAPIMESSAGETYPEINVALID = 3,
    EQQAPIMESSAGECONTENTNULL = 4,
    EQQAPIMESSAGECONTENTINVALID = 5,
    EQQAPIAPPNOTREGISTED = 6,
    EQQAPIAPPSHAREASYNC = 7,
    EQQAPIQQNOTSUPPORTAPI_WITH_ERRORSHOW = 8,  
    EQQAPIMESSAGEARKCONTENTNULL = 9,  
    EQQAPISENDFAILD = -1,  
    EQQAPISHAREDESTUNKNOWN = -2, 
    EQQAPITIMSENDFAILD = -3,  
    EQQAPITIMNOTINSTALLED = 11, 
    EQQAPITIMNOTSUPPORTAPI = 12, 
    EQQAPIQZONENOTSUPPORTTEXT = 10000,  
    EQQAPIQZONENOTSUPPORTIMAGE = 10001,  
    EQQAPIVERSIONNEEDUPDATE = 10002,  
    ETIMAPIVERSIONNEEDUPDATE = 10004,  
} QQApiSendResultCode;
#pragma mark - QQApiObject(分享对象类型)
enum
{
    kQQAPICtrlFlagQZoneShareOnStart = 0x01,
    kQQAPICtrlFlagQZoneShareForbid = 0x02,
    kQQAPICtrlFlagQQShare = 0x04,
    kQQAPICtrlFlagQQShareFavorites = 0x08, 
    kQQAPICtrlFlagQQShareDataline = 0x10,  
    kQQAPICtrlFlagQQShareEnableArk = 0x20, 
};
typedef enum ShareDestType {
    ShareDestTypeQQ = 0,
    ShareDestTypeTIM,
}ShareDestType;
__attribute__((visibility("default"))) @interface QQApiObject : NSObject
@property(nonatomic,retain) NSString* title; 
@property(nonatomic,retain) NSString* description; 
@property (nonatomic, assign) uint64_t cflag;
@property (nonatomic, assign) ShareDestType shareDestType;
@end
__attribute__((visibility("default"))) @interface ArkObject : NSObject
@property(nonatomic,retain) NSString* arkData; 
@property(nonatomic,assign) QQApiObject* qqApiObject; 
- (id)initWithData:(NSString *)arkData qqApiObject:(QQApiObject*)qqApiObject;
+ (id)objectWithData:(NSString *)arkData qqApiObject:(QQApiObject*)qqApiObject;
@end
__attribute__((visibility("default"))) @interface QQApiResultObject : QQApiObject
@property(nonatomic,retain) NSString* error; 
@property(nonatomic,retain) NSString* errorDescription; 
@property(nonatomic,retain) NSString* extendInfo; 
@end
@interface QQApiTextObject : QQApiObject
@property(nonatomic,retain)NSString* text; 
-(id)initWithText:(NSString*)text; 
+(id)objectWithText:(NSString*)text;
@end
typedef enum QQApiURLTargetType{
    QQApiURLTargetTypeNotSpecified = 0x00,
    QQApiURLTargetTypeAudio   = 0x01,
    QQApiURLTargetTypeVideo   = 0x02,
    QQApiURLTargetTypeNews    = 0x03
}QQApiURLTargetType;
__attribute__((visibility("default"))) @interface QQApiURLObject : QQApiObject
@property(nonatomic)QQApiURLTargetType targetContentType;
@property(nonatomic,retain)NSURL* url; 
@property(nonatomic,retain)NSData* previewImageData;
@property(nonatomic, retain) NSURL *previewImageURL;    
-(id)initWithURL:(NSURL*)url title:(NSString*)title description:(NSString*)description previewImageData:(NSData*)data targetContentType:(QQApiURLTargetType)targetContentType;
-(id)initWithURL:(NSURL*)url title:(NSString*)title description:(NSString*)description previewImageURL:(NSURL*)previewURL targetContentType:(QQApiURLTargetType)targetContentType;
+(id)objectWithURL:(NSURL*)url title:(NSString*)title description:(NSString*)description previewImageData:(NSData*)data targetContentType:(QQApiURLTargetType)targetContentType;
+(id)objectWithURL:(NSURL*)url title:(NSString*)title description:(NSString*)description previewImageURL:(NSURL*)previewURL targetContentType:(QQApiURLTargetType)targetContentType;
@end
@interface QQApiExtendObject : QQApiObject
@property(nonatomic,retain) NSData* data;
@property(nonatomic,retain) NSData* previewImageData;
@property(nonatomic,retain) NSArray* imageDataArray;
- (id)initWithData:(NSData*)data previewImageData:(NSData*)previewImageData title:(NSString*)title description:(NSString*)description;
- (id)initWithData:(NSData *)data previewImageData:(NSData*)previewImageData title:(NSString *)title description:(NSString *)description imageDataArray:(NSArray *)imageDataArray;
+ (id)objectWithData:(NSData*)data previewImageData:(NSData*)previewImageData title:(NSString*)title description:(NSString*)description;
+ (id)objectWithData:(NSData*)data previewImageData:(NSData*)previewImageData title:(NSString*)title description:(NSString*)description imageDataArray:(NSArray*)imageDataArray;
@end
@interface QQApiImageObject : QQApiExtendObject
@end
@interface QQApiImageArrayForQZoneObject : QQApiObject
@property(nonatomic,retain) NSArray* imageDataArray;
@property(nonatomic,retain) NSDictionary* extMap; 
- (id)initWithImageArrayData:(NSArray*)imageDataArray title:(NSString*)title extMap:(NSDictionary *)extMap;
+ (id)objectWithimageDataArray:(NSArray*)imageDataArray title:(NSString*)title extMap:(NSDictionary *)extMap;
@end
@interface QQApiVideoForQZoneObject : QQApiObject
@property(nonatomic, retain) NSString *assetURL;
@property(nonatomic,retain) NSDictionary* extMap; 
- (id)initWithAssetURL:(NSString*)assetURL title:(NSString*)title extMap:(NSDictionary *)extMap;
+ (id)objectWithAssetURL:(NSString*)assetURL title:(NSString*)title extMap:(NSDictionary *)extMap;
@end
@interface QQApiWebImageObject : QQApiObject
@property(nonatomic, retain) NSURL *previewImageURL;    
- (id)initWithPreviewImageURL:(NSURL*)previewImageURL title:(NSString*)title description:(NSString*)description;
+ (id)objectWithPreviewImageURL:(NSURL*)previewImageURL title:(NSString*)title description:(NSString*)description;
@end
@interface QQApiFileObject : QQApiExtendObject
{
    NSString* _fileName;
}
@property(nonatomic, retain)NSString* fileName;
@end
@interface QQApiAudioObject : QQApiURLObject
@property (nonatomic, retain) NSURL *flashURL;      
+(id)objectWithURL:(NSURL*)url title:(NSString*)title description:(NSString*)description previewImageData:(NSData*)data;
+(id)objectWithURL:(NSURL*)url title:(NSString*)title description:(NSString*)description previewImageURL:(NSURL*)previewURL;
@end
@interface QQApiVideoObject : QQApiURLObject
@property (nonatomic, retain) NSURL *flashURL;      
+(id)objectWithURL:(NSURL*)url title:(NSString*)title description:(NSString*)description previewImageData:(NSData*)data;
+(id)objectWithURL:(NSURL*)url title:(NSString*)title description:(NSString*)description previewImageURL:(NSURL*)previewURL;
@end
@interface QQApiNewsObject : QQApiURLObject
+(id)objectWithURL:(NSURL*)url title:(NSString*)title description:(NSString*)description previewImageData:(NSData*)data;
+(id)objectWithURL:(NSURL*)url title:(NSString*)title description:(NSString*)description previewImageURL:(NSURL*)previewURL;
@end
@interface QQApiCommonContentObject : QQApiObject
@property(nonatomic,assign) unsigned int layoutType;
@property(nonatomic,assign) NSData* previewImageData;
@property(nonatomic,retain) NSArray* textArray;
@property(nonatomic,retain) NSArray* pictureDataArray;
+(id)objectWithLayoutType:(int)layoutType textArray:(NSArray*)textArray pictureArray:(NSArray*)pictureArray previewImageData:(NSData*)data;
+(id)objectWithDictionary:(NSDictionary*)dic;
-(NSDictionary*)toDictionary;
@end
@interface QQApiAdItem : NSObject
@property(nonatomic,retain) NSString* title; 
@property(nonatomic,retain) NSString* description;
@property(nonatomic,retain) NSData* imageData;
@property(nonatomic,retain) NSURL* target;
@end
#pragma mark - QQApiObject(关系链对象)
@interface QQApiAddFriendObject : QQApiObject
@property (nonatomic,retain)NSString* openID;
@property (nonatomic,retain)NSString* subID;
@property (nonatomic,retain)NSString* remark;
-(id)initWithOpenID:(NSString*)openID; 
+(id)objecWithOpenID:(NSString*)openID; 
@end
@interface QQApiGameConsortiumBindingGroupObject : QQApiObject
@property (nonatomic,retain)NSString* signature;
@property (nonatomic,retain)NSString* unionid;
@property (nonatomic,retain)NSString* zoneID;
@property (nonatomic,retain)NSString* appDisplayName;
-(id)initWithGameConsortium:(NSString*)signature unionid:(NSString*)unionid zoneID:(NSString*)zoneID appDisplayName:(NSString*)appDisplayName; 
+(id)objectWithGameConsortium:(NSString*)signature unionid:(NSString*)unionid zoneID:(NSString*)zoneID appDisplayName:(NSString*)appDisplayName; 
@end
@interface QQApiJoinGroupObject : QQApiObject
@property (nonatomic,retain)NSString* groupUin;
@property (nonatomic,retain)NSString* groupKey;
- (id)initWithGroupInfo:(NSString*)groupUin key:(NSString*)groupKey; 
+ (id)objectWithGroupInfo:(NSString*)groupUin key:(NSString*)groupKey; 
+ (id)objectWithGroupKey:(NSString*)groupKey; 
@end
#pragma mark - QQApi请求消息类型
enum QQApiInterfaceReqType
{
    EGETMESSAGEFROMQQREQTYPE = 0,   
    ESENDMESSAGETOQQREQTYPE = 1,    
    ESHOWMESSAGEFROMQQREQTYPE = 2,   
    ESENDMESSAGEARKTOQQREQTYPE = 3    
};
enum QQApiInterfaceRespType
{
    ESHOWMESSAGEFROMQQRESPTYPE = 0, 
    EGETMESSAGEFROMQQRESPTYPE = 1,  
    ESENDMESSAGETOQQRESPTYPE = 2    
};
@interface QQBaseReq : NSObject
@property (nonatomic, assign) int type;
@end
@interface QQBaseResp : NSObject
@property (nonatomic, copy) NSString* result;
@property (nonatomic, copy) NSString* errorDescription;
@property (nonatomic, assign) int type;
@property (nonatomic, assign) NSString* extendInfo;
@end
@interface GetMessageFromQQReq : QQBaseReq
+ (GetMessageFromQQReq *)req;
@end
@interface SendMessageToQQReq : QQBaseReq
+ (SendMessageToQQReq *)reqWithContent:(QQApiObject *)message;
+ (SendMessageToQQReq *)reqWithArkContent:(ArkObject *)message;
@property (nonatomic, retain) QQApiObject *message;
@property (nonatomic, retain) ArkObject *arkMessage;
@end
@interface SendMessageToQQResp : QQBaseResp
+ (SendMessageToQQResp *)respWithResult:(NSString *)result errorDescription:(NSString *)errDesp extendInfo:(NSString*)extendInfo;
@end
@interface ShowMessageFromQQReq : QQBaseReq
+ (ShowMessageFromQQReq *)reqWithContent:(QQApiObject *)message;
@property (nonatomic, retain) QQApiObject *message;
@end
#endif
