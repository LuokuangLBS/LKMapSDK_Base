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

/// 是否启用崩溃日志上传。默认为YES，只有在真机上设置有效。开启崩溃日志上传有助于我们更好的了解SDK的状况，可以帮助我们持续优化和改进SDK。需要注意的是，SDK内部是通过设置NSUncaughtExceptionHandler来捕获异常的，如果您的APP中使用了其他收集崩溃日志的SDK，或者自己有设置NSUncaughtExceptionHandler的话，请保证 LKMapManager 的初始化是在其他设置NSUncaughtExceptionHandler操作之后进行的，我们的handler会在处理完异常后调用前一次设置的handler，保证之前设置的handler会被执行。
@property (nonatomic, assign) BOOL crashReportEnabled;

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
