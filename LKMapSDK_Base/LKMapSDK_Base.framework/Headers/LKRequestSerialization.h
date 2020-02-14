//
//  LKRequestSerialization.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/11/18.
//  Copyright © 2019 luokung. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 网络请求方法
typedef NS_ENUM(NSUInteger, LKNetworkMethod) {
    LKNetworkMethodGET,
    LKNetworkMethodPOST,
};

NS_ASSUME_NONNULL_BEGIN

@interface LKRequestSerialization : NSObject
/// 超时时间，默认使用10秒
@property (nonatomic, assign) NSTimeInterval timeoutInterval;
/// 默认使用NSURLRequestUseProtocolCachePolicy
@property (nonatomic, assign) NSURLRequestCachePolicy cachePolicy;
/// 请求头
@property (nonatomic, strong) NSMutableDictionary <NSString *, NSString *> *HTTPRequestHeaders;

+ (instancetype)serializer;
- (nullable NSURLRequest *)requestWithMethod:(LKNetworkMethod)method
                          URLString:(NSString *)URLString
                         parameters:(NSDictionary *)parameters;
@end

@interface LKJSONRequestSerialization : LKRequestSerialization
@property (nonatomic, assign) NSJSONWritingOptions writingOptions;
+ (instancetype)serializerWithWritingOptions:(NSJSONWritingOptions)writingOptions;
@end
NS_ASSUME_NONNULL_END
