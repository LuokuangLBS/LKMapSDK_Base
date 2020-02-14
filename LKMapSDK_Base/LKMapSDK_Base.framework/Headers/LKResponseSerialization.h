//
//  LKResponseSerialization.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/11/18.
//  Copyright © 2019 luokung. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LKResponseSerialization : NSObject
@property (nonatomic, copy) NSSet <NSString *>*acceptableContentTypes;
+ (instancetype)serializer;
@end

@interface LKJSONResponseSerialization : LKResponseSerialization
@property (nonatomic, assign) NSJSONReadingOptions readingOptions; /// 默认使用NSJSONReadingAllowFragments

- (nullable NSDictionary *)responseObjectForResponse:(nullable NSURLResponse *)response
                                                data:(nullable NSData *)data
                                               error:(NSError * _Nullable __autoreleasing)error;
@end

NS_ASSUME_NONNULL_END
