//
//  LKMapManager.h
//  LKMapSDK_Base
//
//  Created by RD on 2019/11/19.
//  Copyright © 2019 luokung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LKTypes.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^LKMapManagerStartResultBlock)(LKNetworkCode code);

/// 地图引擎管理器
@interface LKMapManager : NSObject

/// SDK使用的坐标类型，默认为GCJ02
@property (nonatomic, assign) LKCoordType coordType;

/// SDK是否使用https网络请求协议，默认YES
@property (nonatomic, assign, getter=isHttpsEnable) BOOL httpsEnable;

/// 打开某模块的日志，默认关闭
@property (nonatomic, assign) BOOL logEnable;

/// 获取当前SDK的版本号
@property (nonatomic, copy, readonly) NSString *sdkVersion;

/// 箩筐地图开放平台申请的AK
@property (nonatomic, copy, readonly) NSString *accessKey;

/**
 * 获取单例对象
 */
+ (instancetype)sharedInstance;

/**
 * 启动引擎，初始化引擎及鉴权
 *
 * @param ak AK
 * @param callback 回调
 */
- (void)startWithAccessKey:(NSString *)ak
                  callback:(nullable LKMapManagerStartResultBlock)callback;

/**
 * 停止引擎
 *
 * @return YES成功，NO失败
 */
- (BOOL)stop;
@end

NS_ASSUME_NONNULL_END
