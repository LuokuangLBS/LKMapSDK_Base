//
//  LKNetworkManager.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/11/18.
//  Copyright © 2019 luokung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LKRequestSerialization.h"
#import "LKResponseSerialization.h"

NS_ASSUME_NONNULL_BEGIN

/// 网络请求成功回调
typedef void(^LKNetworkSuccessBlock)( NSDictionary * _Nullable response);
/// 网络请求失败回调
typedef void(^LKNetworkFailureBlock)(NSURLResponse * _Nullable response, NSError * _Nullable error);

@interface LKNetworkManager : NSObject

@property (nonatomic, strong, readonly) LKRequestSerialization *requestSerializer;
@property (nonatomic, strong, readonly) LKJSONResponseSerialization *responseSerializer;


/// 返回LKNetworkManager实例，工厂方法
+ (instancetype)manager;

/// GET请求
/// @param URLString url
/// @param parameters 参数
/// @param success 成功回调，主线程
/// @param failure 失败回调，主线程
- (nullable NSURLSessionDataTask *)GET:(NSString *)URLString
                   parameters:(nullable NSDictionary *)parameters
                      success:(nullable LKNetworkSuccessBlock)success
                      failure:(nullable LKNetworkFailureBlock)failure;


/// POST请求
/// @param URLString url
/// @param parameters 参数
/// @param success 成功回调，主线程
/// @param failure 失败回调，主线程
- (nullable NSURLSessionDataTask *)POST:(NSString *)URLString
                    parameters:(nullable NSDictionary *)parameters
                       success:(nullable LKNetworkSuccessBlock)success
                       failure:(nullable LKNetworkFailureBlock)failure;
@end

NS_ASSUME_NONNULL_END
