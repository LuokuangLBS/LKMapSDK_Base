//
//  LKLocation.h
//  LKMapSDK_Base
//
//  Created by RD on 2019/12/23.
//  Copyright © 2019 luokung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/// 途经点类
@interface LKLocation : NSObject

/// 途经点地理坐标
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 * 创建途径点实例
 *
 * @param coordinate 地理坐标
 * @return 途经点实例
 */
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate;
@end

