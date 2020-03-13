//
//  LKRequest.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/11/28.
//  Copyright © 2019 箩筐. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

/// 请求报文基类
@interface LKRequest : NSObject
@property (nonatomic, copy, readonly) NSString *timestamp;
@property (nonatomic, copy, readonly) NSString *nonce;
@end
