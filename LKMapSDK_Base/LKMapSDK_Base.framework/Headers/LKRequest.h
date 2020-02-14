//
//  LKRequest.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/11/28.
//  Copyright © 2019 箩筐. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LKRequest : NSObject
/// 请求时的时间戳，精确到毫秒，13 位
@property (nonatomic, copy, readonly) NSString *timestamp;
/// 随机字符串，约定长度为 10 位
@property (nonatomic, copy, readonly) NSString *nonce;
@end
