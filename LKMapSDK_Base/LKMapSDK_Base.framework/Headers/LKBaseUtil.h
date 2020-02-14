//
//  LKBaseUtil.h
//  LKMapSDK_Base
//
//  Created by hao on 2019/12/3.
//  Copyright © 2019 箩筐. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LKMapSDK_BaseEnum.h"

@interface LKBaseUtil : NSObject

/**
 *  数组转为字符串。例如：@[@(116), @(30)]转为@"[116,30]"
 *
 * @param pairs 数组，数组元素必须为2
 * @return 字符串
 */
+ (NSString *)stringWithPairs:(NSArray *)pairs;

/**
 *  字典转为字符串，并加盐。例如：@{@"key" : @"value"}转为@”keyvalue盐"。仅供网络请求报文使用
 *
 * @param dictionary 字典
 * @return 加盐后的字符串
 */
+ (NSString *)saltStringWithDictionary:(NSDictionary <NSString *, id>*)dictionary;

/**
 *  字符串转为小写16位md5字符串
 *
 * @param string 字符串
 * @return 小写16位md5字符串
 */
+ (NSString *)lowercase16BitMD5String:(NSString *)string;

/**
 *  字符串转为大写16位md5字符串
 *
 * @param string 字符串
 * @return 大写16位md5字符串
 */
+ (NSString *)uppercase16BitMD5String:(NSString *)string;

/**
 *  字符串转为小写32位md5字符串
 *
 * @param string 字符串
 * @return 小写32位md5字符串
 */
+ (NSString *)lowercase32BitMD5String:(NSString *)string;

/**
 * 字符串转为大写32位md5字符串
 *
 * @param string 字符串
 * @return 大写32位md5字符串
 */
+ (NSString *)uppercase32BitMD5String:(NSString *)string;

/**
 * 本地化网络请求状态码
 *
 * @param code 网络请求状态码
 * @return 本地化状态码
 */
+ (LKNetworkCode)localizeNetworkCode:(NSInteger)code;
@end
