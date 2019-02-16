//
//  MJExtensionConfig.m
//  SLBaseKit
//
//  Created by CoderSLZeng on 2019/1/16.
//
//

#import "MJExtensionConfig.h"

#import <MJExtension/MJExtension.h>

@implementation MJExtensionConfig

+ (void)load {
    
    [NSObject mj_setupReplacedKeyFromPropertyName:^NSDictionary *{
        return @{
                 @"ID"   : @"id",
                 @"desc" : @"description"
                 };
    }];

}

@end
