//
//  LKTypes.h
//  LKMapSDK_Base
//
//  Created by hao on 2020/3/4.
//  Copyright © 2020 luokung. All rights reserved.
//

#ifndef LKTypes_h
#define LKTypes_h

#import <CoreLocation/CoreLocation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>


/// 网络响应状态码
typedef NS_ENUM(NSInteger, LKNetworkCode) {
    
    /// 成功
    LKNetworkCodeSuccess,
    
    /// 请求结果为空
    LKNetworkCodeResultNotFound,
    
    /// SDK内部处理错误
    LKNetworkCodeSDKInnerError,
    
    /// 网络错误
    LKNetworkCodeNetworkError,
    
    /// 服务器内部错误
    LKNetworkCodeServerInternalError,
    
    /// 参数错误
    LKNetworkCodeParameterError,
    
    /// 请求错误
    LKNetworkCodeRequestError,
    
    /// mcode不存在，SDK mcode参数必需，该错误码代表服务器没有解析到mcode
    LKNetworkCodeMCodeNotFound,
    
    /// APP的AK类型错误
    LKNetworkCodeAKTypeError,
    
    /// 服务被禁用，用户在API控制台中创建或设置某APP的时候禁用了某项服务，若需要开通权限，可以进入API控制台为AK勾选对应服务
    LKNetworkCodeServiceForbidden,
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
 * 创建LKCoordinateSpan实例
 *
 * @param latitudeDelta 纬度范围
 * @param longitudeDelta 经度范围
 * @return LKCoordinateSpan实例
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
    
    /// 中心坐标
    CLLocationCoordinate2D center;
    
    /// 经纬度范围
    LKCoordinateSpan span;
    
} LKCoordinateRegion;

/**
 * 创建LKCoordinateRegion实例
 * @param centerCoordinate 中心点经纬度坐标
 * @param span 经纬度的范围
 * @return 根据指定参数生成的BMKCoordinateRegion对象
 */
NS_INLINE LKCoordinateRegion LKCoordinateRegionMake(CLLocationCoordinate2D centerCoordinate, LKCoordinateSpan span)
{
    LKCoordinateRegion region;
    region.center = centerCoordinate;
    region.span = span;
    return region;
}

/// 墨卡托投影坐标
typedef struct CG_BOXABLE LKMapPoint {
    
    /// 水平坐标
    CGFloat x;
    
    /// 竖直坐标
    CGFloat y;
} LKMapPoint;

/**
 * 创建墨卡托投影坐标
 *
 * @param x 水平坐标
 * @param y 竖直坐标
 * @return 墨卡托坐标
 */
NS_INLINE LKMapPoint LKMapPointMake(CGFloat x, CGFloat y) {
    LKMapPoint point;
    point.x = x;
    point.y = y;
    return point;
}

/**
 * 地理坐标（默认GCJ02）转换为墨卡托投影坐标
 *
 * @param coordinate 地理坐标
 * @return 墨卡托投影坐标
 */
UIKIT_EXTERN LKMapPoint LKMapPointForCoordinate(CLLocationCoordinate2D coordinate);

/**
 * 墨卡托投影坐标转换为地理坐标（默认GCJ02）
 *
 * @param mapPoint 墨卡托投影坐标
 * @return 地理坐标
 */
UIKIT_EXTERN CLLocationCoordinate2D LKCoordinateForMapPoint(LKMapPoint mapPoint);

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
#endif /* LKTypes_h */
