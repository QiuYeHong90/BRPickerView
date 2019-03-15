//
//  NSBundle+BRPickerView.m
//  BRPickerViewDemo
//
//  Created by shuhui on 2019/3/15.
//  Copyright © 2019 91renb. All rights reserved.
//
#import "BRPickerView.h"
#import "NSBundle+BRPickerView.h"

@implementation NSBundle (BRPickerView)
+ (instancetype)BRPickerView_kitBundle
{
    static NSBundle *refreshBundle = nil;
    if (refreshBundle == nil) {
        // 这里不使用mainBundle是为了适配pod 1.x和0.x
        NSBundle *mainBundle = [NSBundle bundleForClass:[BRDatePickerView class]];
        
        refreshBundle = [NSBundle bundleWithPath:[mainBundle pathForResource:@"BRPickerView" ofType:@"bundle"]];
    }
    return refreshBundle;
}


+ (UIImage *)BRPickerView_imageName:(NSString *)name;
{
    NSString * path  = [[self BRPickerView_kitBundle] pathForResource:name ofType:@"png"];
    
    UIImage *arrowImage = nil;
    if (arrowImage == nil) {
        arrowImage =  [[UIImage imageWithContentsOfFile:path] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
        
        
    }
    return arrowImage;
}



@end
