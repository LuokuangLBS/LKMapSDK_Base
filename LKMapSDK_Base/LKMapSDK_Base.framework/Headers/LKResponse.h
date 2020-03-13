//
//  LKResponse.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/11/28.
//  Copyright © 2019 箩筐. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

/// 响应报文基类
@interface LKResponse : NSObject
@property (nonatomic, assign) NSInteger status;
@property (nonatomic, copy) NSString *message;
@end
