//
//  LKResponse.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/11/28.
//  Copyright © 2019 箩筐. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LKResponse : NSObject

/// 状态码
@property (nonatomic, assign) NSInteger status;

/// 状态码说明
@property (nonatomic, copy) NSString *message;
@end
