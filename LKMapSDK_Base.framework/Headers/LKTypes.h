//
//  LKTypes.h
//  LKMapSDK_Base
//
//  Created by RD on 2020/3/4.
//  Copyright © 2020 luokung. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

#pragma once

#if TARGET_OS_IPHONE
@class UIImage;
#define LKImage UIImage
#else
@class NSImage;
#define LKImage NSImage
#endif

#if TARGET_OS_IPHONE
@class UIColor;
#define LKColor UIColor
#else
@class NSColor;
#define LKColor NSColor
#endif

#define LK_EXPORT __attribute__((visibility ("default")))


/// 网络响应状态码
typedef NS_ENUM(NSInteger, LKNetworkCode) {
    
    /// 未知错误
    LKNetworkCodeUnknownError = -1,
    
    /// 成功
    LKNetworkCodeSuccess = 0,
    
    /// 服务器内部错误。建议首先检查请求参数是否正确，如果还是无法解决，请提交工单给我们，并填写详细错误信息。
    LKNetworkCodeServerInternalError = 1,
    
    /// 请求参数错误。请检查请求参数是否正确，比如：参数类型、必填参数是否为空。
    LKNetworkCodeParameterError = 2,
    
    /// 请求错误。比如：请求方式错误、请求地址错误。
    LKNetworkCodeRequestError = 3,
    
    /// 请求结果为空
    LKNetworkCodeResultNotFound = 4,
    
    /// 网络错误。比如：网络连接失败
    LKNetworkCodeNetworkError = 5,
    
    /// SDK内部处理错误
    LKNetworkCodeSDKInnerError = 6,
    
    /// mcode 不存在，SDK mcode 参数必需，该错误码代表服务器没有解析到 mcode
    LKNetworkCodeMCodeNotFound = 7,
    
    /// AK 为空。请检查 `- startWithAccessKey:callback:` 是否设置了 AK。
    LKNetworkCodeAKNotFound = 121,
    
    /// AK 错误。请前往箩筐地图开放平台（https://lbs.luokuang.com），检查 AK 是否正确。
    LKNetworkCodeAKNotCorrect = 122,
    
    /// AK 不可用。请前往箩筐地图开放平台（https://lbs.luokuang.com ），检查 AK 是否已经被删除。或者被开放平台封禁，客服邮箱：lbs.kefu@luokung.com
    LKNetworkCodeAKUnavailable = 123,
    
    /// AK 的类型错误，比如，使用的是 Andriod 或 Web 类型的 AK。请前往箩筐地图开放平台（https://lbs.luokuang.com ），检查 AK 的类型是否正确。
    LKNetworkCodeAKTypeError = 124,
    
    /// 服务被禁用。您在箩筐地图开放平台中创建或设置某 APP 的时候禁用了某项服务，若需要开通权限，可以进入控制台为 AK 勾选对应服务。箩筐地图开放平台（https://lbs.luokuang.com)
    LKNetworkCodeServiceForbidden = 141,
    
    /// 访问已超出日访问量。请前往箩筐地图开放平台（https://lbs.luokuang.com ），提升配额。
    LKNetworkCodeDailyPVLimited = 142,
    
    /// 某个 AK 使用某个服务接口 QPS 超出限制。请前往箩筐地图开放平台（https://lbs.luokuang.com ），提升配额。
    LKNetworkCodeQPSLimited = 143,
    
    /// 自定义地图样式不存在或被删除。请前往箩筐地图开放平台（https://lbs.luokuang.com ），重新创建自定义地图样式。
    LKNetworkCodeCustomMapStyleNotFound = 1001,
};


/// 坐标类型
typedef NS_ENUM(NSUInteger, LKCoordType) {
    
    /// GPS设备采集的原始GPS坐标
    LKCoorTypeWGS84 = 1,
    
    /// google地图、高德地图、soso地图、alliyun地图、mapabc地图所用坐标
    LKCoorTypeGCJ02 = 2,
    
    /// 百度地图所用坐标
    LKCoorTypeBD09LL = 3,
};

/// 地图类型
typedef NS_ENUM(NSUInteger, LKMapType) {
    
    /// 标准地图
    LKMapTypeStandard,
};


/// 经纬度范围
typedef struct CG_BOXABLE LKCoordinateSpan {
    
    /// 纬度范围
    CLLocationDegrees latitudeDelta;
    
    /// 经度范围
    CLLocationDegrees longitudeDelta;
} LKCoordinateSpan;

/**
 * 创建LKCoordinateSpan
 *
 * @param latitudeDelta 纬度范围
 * @param longitudeDelta 经度范围
 * @return LKCoordinateSpan
 */
NS_INLINE LKCoordinateSpan LKCoordinateSpanMake(CLLocationDegrees latitudeDelta, CLLocationDegrees longitudeDelta) {
    LKCoordinateSpan span;
    span.latitudeDelta = latitudeDelta;
    span.longitudeDelta = longitudeDelta;
    return span;
}

/**
 * 两个经纬度范围是否相等
 *
 * @param span1 范围1
 * @param span2 范围2
 */
NS_INLINE BOOL LKCoordinateSpanEqualToCoordinateSpan(LKCoordinateSpan span1, LKCoordinateSpan span2) {
    return (span1.latitudeDelta == span2.latitudeDelta &&
            span1.longitudeDelta == span2.longitudeDelta);
}

/// 一个经纬度区域
typedef struct {
    
    /// 中心点经纬度坐标
    CLLocationCoordinate2D center;
    
    /// 经纬度范围
    LKCoordinateSpan span;
    
} LKCoordinateRegion;

/**
 * 创建LKCoordinateRegion
 *
 * @param centerCoordinate 中心点经纬度坐标
 * @param span 经纬度的范围
 * @return 根据指定参数生成的LKCoordinateRegion
 */
NS_INLINE LKCoordinateRegion LKCoordinateRegionMake(CLLocationCoordinate2D centerCoordinate, LKCoordinateSpan span)
{
    LKCoordinateRegion region;
    region.center = centerCoordinate;
    region.span = span;
    return region;
}

/// 地理坐标点，用直角地理坐标表示
typedef struct CG_BOXABLE LKMapPoint {
    
    /// 横坐标
    double x;
    
    /// 纵坐标
    double y;
} LKMapPoint;

/**
 * 创建LKMapPoint
 *
 * @param x 水平坐标
 * @param y 竖直坐标
 * @return LKMapPoint
 */
NS_INLINE LKMapPoint LKMapPointMake(double x, double y) {
    LKMapPoint point;
    point.x = x;
    point.y = y;
    return point;
}

/// 矩形大小，用直角地理坐标表示
typedef struct CG_BOXABLE LKMapSize {
    
    /// 宽度
    double width;
    
    /// 高度
    double height;
} LKMapSize;

/**
 * 创建LKMapSize
 *
 * @param width 宽度
 * @param height 高度
 * @return LKMapSize
 */
NS_INLINE LKMapSize LKMapSizeMake(double width, double height) {
    LKMapSize size;
    size.width = width;
    size.height = height;
    return size;
}

/// 矩形，用直角地理坐标表示
typedef struct CG_BOXABLE LKMapRect {
    
    /// 屏幕左上点对应的直角地理坐标
    LKMapPoint origin;
    
    /// 坐标范围
    LKMapSize size;
} LKMapRect;

/**
 * 创建LKMapRect
 *
 * @param x 水平坐标
 * @param y 竖直坐标
 * @param width 宽度
 * @param height 高度
 * @return LKMapRect
 */
NS_INLINE LKMapRect LKMapRectMake(double x, double y, double width, double height) {
    LKMapPoint point = LKMapPointMake(x, y);
    LKMapSize size = LKMapSizeMake(width, height);
    return (LKMapRect){point, size};
}

/**
 * 判断指定矩形是否为NULL
 *
 * @param rect LKMapRect 矩形
 * @return 如果矩形为NULL，返回YES，否则返回NO
 */
NS_INLINE BOOL LKMapRectIsNull(LKMapRect rect) {
    return isinf(rect.origin.x) || isinf(rect.origin.y);
}

/**
 * 获取指定矩形的x轴坐标最小值
 * @param rect 指定的矩形
 * @return x轴坐标最小值
 */
NS_INLINE double LKMapRectGetMinX(LKMapRect rect) {
    return rect.origin.x;
}

/**
 * 获取指定矩形的y轴坐标最小值
 * @param rect 指定的矩形
 * @return y轴坐标最小值
 */
NS_INLINE double LKMapRectGetMinY(LKMapRect rect) {
    return rect.origin.y;
}

/**
 * 获取指定矩形在x轴中点的坐标值
 * @param rect 指定的矩形
 * @return x轴中点的坐标值
 */
NS_INLINE double LKMapRectGetMidX(LKMapRect rect) {
    return rect.origin.x + rect.size.width / 2.0;
}

/**
 * 获取指定矩形在y轴中点的坐标值
 * @param rect 指定的矩形
 * @return y轴中点的坐标值
 */
NS_INLINE double LKMapRectGetMidY(LKMapRect rect) {
    return rect.origin.y + rect.size.height / 2.0;
}

/**
 * 获取指定矩形的x轴坐标最大值
 * @param rect 指定的矩形
 * @return x轴坐标最大值
 */
NS_INLINE double LKMapRectGetMaxX(LKMapRect rect) {
    return rect.origin.x + rect.size.width;
}

/**
 * 获取指定矩形的y轴坐标最大值
 * @param rect 指定的矩形
 * @return y轴坐标最大值
 */
NS_INLINE double LKMapRectGetMaxY(LKMapRect rect) {
    return rect.origin.y + rect.size.height;
}

/// 经纬度矩形区域
typedef struct CG_BOXABLE LKCoordinateBounds {
    
    /// 西南角经纬度
    CLLocationCoordinate2D sw;
    
    /// 东北角经纬度
    CLLocationCoordinate2D ne;
} LKCoordinateBounds;

/**
 * 创建经纬度矩形区域
 *
 * @param sw 西南角经纬度
 * @param ne 东北角经纬度
 * @return 经纬度矩形区域
 */
NS_INLINE LKCoordinateBounds LKCoordinateBoundsMake(CLLocationCoordinate2D sw, CLLocationCoordinate2D ne) {
    LKCoordinateBounds bounds;
    bounds.sw = sw;
    bounds.ne = ne;
    return bounds;
}

/// 经纬度四边形区域
typedef struct LKCoordinateQuad {
    
    /// 左上角经纬度
    CLLocationCoordinate2D topLeft;
    
    /// 左下角经纬度
    CLLocationCoordinate2D bottomLeft;
    
    /// 右下角经纬度
    CLLocationCoordinate2D bottomRight;
    
    /// 右上角经纬度
    CLLocationCoordinate2D topRight;
} LKCoordinateQuad;

/**
 * 创建经纬度四边形区域
 *
 * @param topLeft 左上角经纬度
 * @param bottomLeft 左下角经纬度
 * @param bottomRight 右下角经纬度
 * @param topRight 右上角经纬度
 * @return 经纬度四边形区域
 */
NS_INLINE LKCoordinateQuad LKCoordinateQuadMake(CLLocationCoordinate2D topLeft, CLLocationCoordinate2D bottomLeft, CLLocationCoordinate2D bottomRight, CLLocationCoordinate2D topRight) {
    LKCoordinateQuad quad;
    quad.topLeft = topLeft;
    quad.bottomLeft = bottomLeft;
    quad.bottomRight = bottomRight;
    quad.topRight = topRight;
    return quad;
}

/**
 * 通过经纬度矩形区域，创建经纬度四边形区域
 *
 * @param bounds 经纬度矩形区域
 * @return 经纬度四边形区域
 */
NS_INLINE LKCoordinateQuad LKCoordinateQuadFromCoordinateBounds(LKCoordinateBounds bounds) {
    LKCoordinateQuad quad;
    quad.topLeft = CLLocationCoordinate2DMake(bounds.ne.latitude, bounds.sw.longitude);
    quad.bottomLeft = bounds.sw;
    quad.bottomRight = CLLocationCoordinate2DMake(bounds.sw.latitude, bounds.ne.longitude);
    quad.topRight = bounds.ne;
    return quad;
}

/**
 * 两个经纬度矩形区域是否相等
 *
 * @param bounds1 经纬度矩形区域1
 * @param bounds2 经纬度矩形区域2
 * @return YES相等，NO不相等
 */
NS_INLINE BOOL LKCoordinateBoundsEqualToCoordinateBounds(LKCoordinateBounds bounds1, LKCoordinateBounds bounds2) {
    return (bounds1.sw.latitude == bounds2.sw.latitude &&
            bounds1.sw.longitude == bounds2.sw.longitude &&
            bounds1.ne.latitude == bounds2.ne.latitude &&
            bounds1.ne.longitude == bounds2.ne.longitude);
}

/**
 * 两个经纬度矩形区域是否相交
 *
 * @param bounds1 经纬度矩形区域1
 * @param bounds2 经纬度矩形区域2
 * @return YES相交，NO不相交
 */
NS_INLINE BOOL LKCoordinateBoundsIntersectsCoordinateBounds(LKCoordinateBounds bounds1, LKCoordinateBounds bounds2) {
    return (bounds1.ne.latitude  > bounds2.sw.latitude  &&
            bounds1.sw.latitude  < bounds2.ne.latitude  &&
            bounds1.ne.longitude > bounds2.sw.longitude &&
            bounds1.sw.longitude < bounds2.ne.longitude);
}

/**
 * 经纬度是否在矩形区域内
 *
 * @param coordinate 经纬度
 * @param bounds 矩形区域
 * @return YES是，NO不是
 */
NS_INLINE BOOL LKCoordinateInCoordinateBounds(CLLocationCoordinate2D coordinate, LKCoordinateBounds bounds) {
    return (coordinate.latitude  >= bounds.sw.latitude  &&
            coordinate.latitude  <= bounds.ne.latitude  &&
            coordinate.longitude >= bounds.sw.longitude &&
            coordinate.longitude <= bounds.ne.longitude);
}

/**
 * 获取矩形区域经纬度范围
 *
 * @param bounds 矩形区域
 */
NS_INLINE LKCoordinateSpan LKCoordinateBoundsGetCoordinateSpan(LKCoordinateBounds bounds) {
    return LKCoordinateSpanMake(bounds.ne.latitude - bounds.sw.latitude,
                                 bounds.ne.longitude - bounds.sw.longitude);
}

/**
 * 获得偏移后的经纬度矩形区域
 *
 * @param bounds 经纬度矩形区域
 * @param offset 偏移范围
 * @return 偏移后的矩形区域
 */
NS_INLINE LKCoordinateBounds LKCoordinateBoundsOffset(LKCoordinateBounds bounds, LKCoordinateSpan offset) {
    LKCoordinateBounds offsetBounds = bounds;
    offsetBounds.sw.latitude += offset.latitudeDelta;
    offsetBounds.sw.longitude += offset.longitudeDelta;
    offsetBounds.ne.latitude += offset.latitudeDelta;
    offsetBounds.ne.longitude += offset.longitudeDelta;
    return offsetBounds;
}

/**
 * 是否为空经纬度矩形区域
 *
 * @param bounds 经纬度矩形区域
 * @return YES空，NO非空
 */
NS_INLINE BOOL LKCoordinateBoundsIsEmpty(LKCoordinateBounds bounds) {
    LKCoordinateSpan span = LKCoordinateBoundsGetCoordinateSpan(bounds);
    return span.latitudeDelta == 0 || span.longitudeDelta == 0;
}

/**
 * 获取经纬度矩形区域格式化字符串
 *
 * @param bounds 经纬度矩形区域
 * @return 经纬度矩形区域格式化字符串
 */
NS_INLINE NSString *LKStringFromCoordinateBounds(LKCoordinateBounds bounds) {
    return [NSString stringWithFormat:@"{ sw = {%.1f, %.1f}, ne = {%.1f, %.1f}}",
            bounds.sw.latitude, bounds.sw.longitude,
            bounds.ne.latitude, bounds.ne.longitude];
}

/**
* 获取经纬度四边形区域格式化字符串
*
* @param quad 经纬度四边形区域
* @return 经纬度四边形区域格式化字符串
*/
NS_INLINE NSString *LKStringFromCoordinateQuad(LKCoordinateQuad quad) {
    return [NSString stringWithFormat:@"{ topleft = {%.1f, %.1f}, bottomleft = {%.1f, %.1f}}, bottomright = {%.1f, %.1f}, topright = {%.1f, %.1f}",
            quad.topLeft.latitude, quad.topLeft.longitude,
            quad.bottomLeft.latitude, quad.bottomLeft.longitude,
            quad.bottomRight.latitude, quad.bottomRight.longitude,
            quad.topRight.latitude, quad.topRight.longitude];
}

/**
 * 角度转换为弧度
 *
 * @param degrees 角度
 * @return 弧度
 */
NS_INLINE CGFloat LKRadiansFromDegrees(CLLocationDegrees degrees) {
    return (CGFloat)(degrees * M_PI) / 180;
}

/**
 * 弧度转换为角度
 *
 * @param radians 弧度
 * @return 角度
 */
NS_INLINE CLLocationDegrees LKDegreesFromRadians(CGFloat radians) {
    return radians * 180 / M_PI;
}

/// 经过投影后的世界范围大小，纬度范围[-85，85]，经度范围[-180, 180]
UIKIT_EXTERN const LKMapSize LKMapSizeWorld;

/// 经过投影后的世界矩形范围
UIKIT_EXTERN const LKMapRect LKMapRectWorld;

/// 空的直角坐标矩形
UIKIT_EXTERN const LKMapRect LKMapRectNull;

/// 过渡
typedef struct __attribute__((objc_boxable)) LKTransition {
    
    /// 时长。单位：秒
    NSTimeInterval duration;
    
    /// 延迟时长。单位：秒
    NSTimeInterval delay;
} LKTransition;

/**
 * 创建过渡
 *
 * @param duration 时长
 * @param delay 延迟时长
 * @return 过渡
 */
NS_INLINE LKTransition LKTransitionMake(NSTimeInterval duration, NSTimeInterval delay) {
    LKTransition transition;
    transition.duration = duration;
    transition.delay = delay;
    
    return transition;
}

/// 异常类型
typedef NSString *LKExceptionName NS_TYPED_EXTENSIBLE_ENUM;

@interface LKTypes : NSObject

@end

