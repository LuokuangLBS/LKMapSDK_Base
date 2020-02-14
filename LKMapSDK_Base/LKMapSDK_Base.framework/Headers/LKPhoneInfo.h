//
//  LKPhoneInfo.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/11/16.
//  Copyright © 2019 luokung. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LKPhoneInfo : NSObject

/// 屏幕尺寸宽度
@property (nonatomic, strong, readonly) NSNumber *screen_x;

/// 屏幕尺寸高度
@property (nonatomic, strong, readonly) NSNumber *screen_y;

/// 屏幕像素密度，粗略值
@property (nonatomic, copy, readonly) NSString *dpi;

/// 设备类型名称
@property (nonatomic, copy, readonly) NSString *phoneType;

/// APP使用的iOS 版本
@property (nonatomic, copy, readonly) NSString *osv;

/// 用户设备标识
@property (nonatomic, copy, readonly) NSString *uid;

/// 地图SDK标识，固定值"02"
@property (nonatomic, copy, readonly) NSString *resid;

/// 运行时CPU架构类型
@property (nonatomic, copy, readonly) NSString *cpuarc;

/// SDK调用者APP的包名
@property (nonatomic, copy, readonly) NSString *pcn;

/// SDK调用者APP的名称
@property (nonatomic, copy, readonly) NSString *name;


/// 随机字符串，约定长度为 10 位
@property (nonatomic, copy, readonly) NSString *nonce;

/// 请求时的时间戳，精确到毫秒，13 位
@property (nonatomic, copy, readonly) NSString *timestamp;

/// 手机信息单例
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
