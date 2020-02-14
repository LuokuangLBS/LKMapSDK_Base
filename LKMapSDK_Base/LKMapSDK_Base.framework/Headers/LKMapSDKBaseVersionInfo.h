//
//  LKMapSDKBaseVersionInfo.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/11/16.
//  Copyright © 2019 luokung. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LKMapSDKBaseVersionInfo : NSObject
/// 版本号，sv
@property (nonatomic, copy, readonly) NSString *sdkVersion;
/// 版本描述信息
@property (nonatomic, copy, readonly) NSString *sdkVersionDesc;
/// 包名
@property (nonatomic, copy, readonly) NSString *kitName;
/// 请求来源:lkmapsdk_iOS
@property (nonatomic, copy, readonly) NSString *from;

/// 版本信息单例
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
