//
//  Enum.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/11/16.
//  Copyright © 2019 luokung. All rights reserved.
//

#ifndef LKMapSDK_BaseEnum_h
#define LKMapSDK_BaseEnum_h

#import <CoreLocation/CoreLocation.h>
#import <CoreGraphics/CoreGraphics.h>


#pragma mark 网络请求状态码

/**
 * 网络响应状态码
 */
typedef NS_ENUM(NSInteger, LKNetworkCode) {
    
    /// 成功
    LKNetworkCodeSuccess = 0,
    
    /// 服务器内部错误
    LKNetworkCodeServerError = 1,
    
    /// 上传内容超过 8M Post 数据不能超过 8M
    LKNetworkCodeUploadOverLimit = 10,
    
    /// AK获取不到
    LKNetworkCodeAKNotFound = 101,
    
    /// 1、password不存在，服务器未解析到password；2、 或mcode 参数不存在，mobile 类型 mcode 参数 必需。该错误码代表服务器没有解析到 mcode
    LKNetworkCodePasswordOrMCodeNotFound = 102,
    
    /// 鉴权失败，token非法
    LKNetworkCodeTokenInvalid = 103,
    
    /// 鉴权失败，token过期
    LKNetworkCodeTokenExpired = 104,
    
    /// 鉴权失败，未检测到token信息
    LKNetworkCodeTokenNotFound = 106,
    
    /// 签名校验失败
    LKNetworkCodeRequestParamSignInvalid = 108,
    
    /// 参数错误
    LKNetworkCodeParamError = 2,
    
    /// 认证中
    LKNetworkCodeAuthenticating = 3,
    
    /// APP 不存在，根据请求的 username(AK)，找不到对应的 APP
    LKNetworkCodeAppNotFound = 200,
    
    /// APP 使用的服务被用户自己禁用，请在控制台解禁
    LKNetworkCodeAuthModuleAppForbidden = 201,
    
    /// 恶意 APP 被管理员删除
    LKNetworkCodeAppDeleted = 202,
    
    /// APP 类型与 username(AK)类型不符合
    LKNetworkCodeAppNotMatchAK = 203,
    
    /// AK IP 校验失败，WEB API、JS API 专属错误码
    LKNetworkCodeWebAKIPInvalid = 204,
    
    /// AK SN 校验失败，WEB API 专属错误码
    LKNetworkCodeWebAKSNInvalid = 205,
    
    /// password 校验失败。服务器能解析到 password，但和数据库中不一致
    LKNetworkCodePasswordError = 206,
    
    /// 鉴权服务模块，用户不存在
    LKNetworkCodeAuthModuleAccountNotFound = 207,
    
    /// 鉴权服务模块，服务被开放平台禁用
    LKNetworkCodeAuthModuleServiceForbidden = 208,
    
    /// AK IP 校验失败
    LKNetworkCodeAKIPInvalid = 210,
    
    /// AK SN 校验失败
    LKNetworkCodeAKSNInvalid = 211,
    
    /// APP mcode 码校验失败 服务器能解析到 mcode，但和数据库中不一致，请携带正确的 mcode
    LKNetworkCodeMCodeError = 230,
    
    /// 服务被禁用 用户在 API 控制台中创建或设置 某 APP 的时候禁用了某项服务，若需开通权限， 可进入 API 控制台为 AK 勾选对应服务
    LKNetworkCodeAppForbidden = 240,
    
    /// 用户不存在
    LKNetworkCodeAccountNotFound = 250,
    
    /// 服务被开放平台禁用
    LKNetworkCodeServiceForbidden = 261,

    /// 永久配额超限
    LKNetworkCodeNumberOverLimitForever = 301,
    
    /// 天配额超限
    LKNetworkCodeNumberOverLimitDaily = 302,
    
    /// 鉴权服务模块，当前并发量已经超过约定并发配额
    LKNetworkCodeAuthModuleConcurrentNumberOverLimit = 303,
    
    /// 鉴权服务模块，当前并发量已经超过约定并发配额，并且服务总并发量也已经超过设定的总并发配额
    LKNetworkCodeAuthModuleTotalConcurrentNumberOverLimit = 304,
    
    /// 鉴权服务模块，请求超时
    LKNetworkCodeAuthModuleTimeout = 310,
    
    /// 当前并发量已经超过约定并发配额
    LKNetworkCodeConcurrentNumberOverLimit = 401,
    
    /// 当前并发量已经超过约定并发配额，并且服务总并发量也已经超过设定的总并发配额
    LKNetworkCodeTotalConcurrentNumberOverLimit = 402,
    
    /// 请求超时
    LKNetworkCodeTimeout = 403,
    
    /// 通用致命错误
    LKNetworkCodeError = 500,
    
    /// 请求参数解析失败
    LKNetworkCodeRequestParamParseFailed = 10001,
    
    /// 必填请求参数无效或为空
    LKNetworkCodeRequestParamInvalid = 10002,
    
    /// 请求结果为空
    LKNetworkCodeResultNotFound = 20001,
};


#pragma mark Geometry

/**
 * 坐标类型
 */
typedef NS_ENUM(NSUInteger, LKCoordType) {
    
    /// GPS设备采集的原始GPS坐标
    LKCoorTypeWGS84 = 1,
    
    /// google地图、高德地图、soso地图、alliyun地图、mapabc地图所用坐标
    LKCoorTypeGCJ02 = 2,
    
    /// 百度地图所用坐标
    LKCoorTypeBD09LL = 3,
};

/**
 * 地图类型
 */
typedef NS_ENUM(NSUInteger, LKMapType) {
    
    /// 空白地图
    LKMapTypeNone,
    
    /// 标准地图
    LKMapTypeStandard,
    
    /// 卫星地图
    LKMapTypeSatellite,
};

#endif /* LKMapSDK_BaseEnum_h */
