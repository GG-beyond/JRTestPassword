#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#pragma mark - WBHttpRequest and WBHttpRequestDelegate
@class WBHttpRequest;
@protocol WBHttpRequestDelegate <NSObject>
@optional
- (void)request:(WBHttpRequest *)request didReceiveResponse:(NSURLResponse *)response;
@optional
- (void)request:(WBHttpRequest *)request didFailWithError:(NSError *)error;
@optional
- (void)request:(WBHttpRequest *)request didFinishLoadingWithResult:(NSString *)result;
@optional
- (void)request:(WBHttpRequest *)request didFinishLoadingWithDataResult:(NSData *)data;
@optional
- (void)request:(WBHttpRequest *)request didReciveRedirectResponseWithURI:(NSURL *)redirectUrl;
@end
@interface WBHttpRequest : NSObject
{
    NSURLConnection                 *connection;
    NSMutableData                   *responseData;
}
@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSString *httpMethod;
@property (nonatomic, strong) NSDictionary *params;
@property (nonatomic, weak) id<WBHttpRequestDelegate> delegate;
@property (nonatomic, strong) NSString* tag;
+ (WBHttpRequest *)requestWithURL:(NSString *)url
                       httpMethod:(NSString *)httpMethod
                           params:(NSDictionary *)params
                         delegate:(id<WBHttpRequestDelegate>)delegate
                          withTag:(NSString *)tag;
+ (WBHttpRequest *)requestWithAccessToken:(NSString *)accessToken
                                      url:(NSString *)url
                               httpMethod:(NSString *)httpMethod
                                   params:(NSDictionary *)params
                                 delegate:(id<WBHttpRequestDelegate>)delegate
                                  withTag:(NSString *)tag;
- (void)disconnect;
#pragma mark - block extension
typedef void (^WBRequestHandler)(WBHttpRequest *httpRequest,
                                 id result,
                                 NSError *error);
+ (WBHttpRequest *)requestWithURL:(NSString *)url
                       httpMethod:(NSString *)httpMethod
                           params:(NSDictionary *)params
                            queue:(NSOperationQueue*)queue
            withCompletionHandler:(WBRequestHandler)handler;
+ (WBHttpRequest *)requestWithAccessToken:(NSString *)accessToken
                                      url:(NSString *)url
                               httpMethod:(NSString *)httpMethod
                                   params:(NSDictionary *)params
                                    queue:(NSOperationQueue*)queue
                    withCompletionHandler:(WBRequestHandler)handler;
@end
