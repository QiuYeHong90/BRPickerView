//
//  BRDatePickerView.h
//  BRPickerViewDemo
//
//  Created by 任波 on 2017/8/11.
//  Copyright © 2017年 91renb. All rights reserved.
//
//  最新代码下载地址：https://github.com/91renb/BRPickerView

#import "BRBaseView.h"
#import "NSDate+BRPickerView.h"

/// 弹出日期类型
typedef NS_ENUM(NSInteger, BRDatePickerMode) {
    // --- 以下4种是系统自带的样式 ---
    // UIDatePickerModeTime
    BRDatePickerModeTime,              // HH:mm
    // UIDatePickerModeDate
    BRDatePickerModeDate,              // yyyy-MM-dd
    // UIDatePickerModeDateAndTime
    BRDatePickerModeDateAndTime,       // yyyy-MM-dd HH:mm
    // UIDatePickerModeCountDownTimer
    BRDatePickerModeCountDownTimer,    // HH:mm
    // --- 以下7种是自定义样式 ---
    // 年月日时分
    BRDatePickerModeYMDHM,      // yyyy-MM-dd HH:mm
    // 月日时分
    BRDatePickerModeMDHM,       // MM-dd HH:mm
    // 年月日
    BRDatePickerModeYMD,        // yyyy-MM-dd
    // 年月
    BRDatePickerModeYM,         // yyyy-MM
    // 年
    BRDatePickerModeY,          // yyyy
    // 月日
    BRDatePickerModeMD,         // MM-dd
    // 时分
    BRDatePickerModeHM,          // HH:mm
    // 年月日时
    BRDatePickerModeYMDH,      // yyyy-MM-dd HH
    BRDatePickerModeDMYH,      // dd-MM-yyyy HH
    BRDatePickerModeDMY,      // dd-MM-yyyy
    BRDatePickerModeMY,      // MM-yyyy
    BRDatePickerModeDMYHM,      // dd-MM-yyyy HH:mm
};

typedef void(^BRDateResultBlock)(NSString *selectValue);
typedef void(^BRDateCancelBlock)(void);

@interface BRDatePickerView : BRBaseView

/**
 *  1.显示时间选择器
 *
 *  @param title            标题
 *  @param dateType         日期显示类型
 *  @param defaultSelValue  默认选中的时间（值为空/值格式错误时，默认就选中现在的时间）
 *  @param resultBlock      选择结果的回调
 *
 */
+ (void)showDatePickerWithTitle:(NSString *)title
                       dateType:(BRDatePickerMode)dateType
                defaultSelValue:(NSString *)defaultSelValue
                    resultBlock:(BRDateResultBlock)resultBlock;

/**
 *  2.显示时间选择器（支持 设置自动选择 和 自定义主题颜色）
 *
 *  @param title            标题
 *  @param dateType         日期显示类型
 *  @param defaultSelValue  默认选中的时间（值为空/值格式错误时，默认就选中现在的时间）
 *  @param minDate          最小时间，可为空（请使用 NSDate+BRPickerView 分类中和显示类型格式对应的方法创建 minDate）
 *  @param maxDate          最大时间，可为空（请使用 NSDate+BRPickerView 分类中和显示类型格式对应的方法创建 maxDate）
 *  @param isAutoSelect     是否自动选择，即选择完(滚动完)执行结果回调，传选择的结果值
 *  @param themeColor       自定义主题颜色
 *  @param resultBlock      选择结果的回调
 *
 */
+ (void)showDatePickerWithTitle:(NSString *)title
                       dateType:(BRDatePickerMode)dateType
                defaultSelValue:(NSString *)defaultSelValue
                        minDate:(NSDate *)minDate
                        maxDate:(NSDate *)maxDate
                   isAutoSelect:(BOOL)isAutoSelect
                     themeColor:(UIColor *)themeColor
                    resultBlock:(BRDateResultBlock)resultBlock;

/**
 *  3.显示时间选择器（支持 设置自动选择、自定义主题颜色、取消选择的回调）
 *
 *  @param title            标题
 *  @param dateType         日期显示类型
 *  @param defaultSelValue  默认选中的时间（值为空/值格式错误时，默认就选中现在的时间）
 *  @param minDate          最小时间，可为空（请使用 NSDate+BRPickerView 分类中和显示类型格式对应的方法创建 minDate）
 *  @param maxDate          最大时间，可为空（请使用 NSDate+BRPickerView 分类中和显示类型格式对应的方法创建 maxDate）
 *  @param isAutoSelect     是否自动选择，即选择完(滚动完)执行结果回调，传选择的结果值
 *  @param themeColor       自定义主题颜色
 *  @param resultBlock      选择结果的回调
 *  @param cancelBlock      取消选择的回调
 *
 */
+ (void)showDatePickerWithTitle:(NSString *)title
                       dateType:(BRDatePickerMode)dateType
                defaultSelValue:(NSString *)defaultSelValue
                        minDate:(NSDate *)minDate
                        maxDate:(NSDate *)maxDate
                   isAutoSelect:(BOOL)isAutoSelect
                     themeColor:(UIColor *)themeColor
                    resultBlock:(BRDateResultBlock)resultBlock
                    cancelBlock:(BRDateCancelBlock)cancelBlock;


#pragma mark - 初始化时间选择器
- (instancetype)initWithTitle:(NSString *)title
                     dateType:(BRDatePickerMode)dateType
              defaultSelValue:(NSString *)defaultSelValue
                      minDate:(NSDate *)minDate
                      maxDate:(NSDate *)maxDate
                 isAutoSelect:(BOOL)isAutoSelect
                   themeColor:(UIColor *)themeColor
                  resultBlock:(BRDateResultBlock)resultBlock
                  cancelBlock:(BRDateCancelBlock)cancelBlock;

#pragma mark - 弹出视图方法
- (void)showWithAnimation:(BOOL)animation;

/**
 获取日期格式

 @param model BRDatePickerMode
 @return 日期格式
 */
+(NSString *)getDateFormatStr:(BRDatePickerMode)model;
+(NSDate *)getDateWithSlectValue:(NSString *)selectValue format:(NSString *)format;
+(NSString *)getDateStrWithformat:(NSString *)fromat dateStr1:(NSString *)dateStr1 format1:(NSString *)format1;

+(NSDate *)getDateWithSlectValue:(NSString *)selectValue model:(BRDatePickerMode)model;

/**
 获取 最终返回的日期 格式化

 @param myFromat 我的日期格式化
 @param selectValue 日期弹框里面值
 @param model BRDatePickerMode
 @return 我所需要的日期格式
 */
+(NSString *)getMyDateStringWithMyFormat:(NSString *)myFromat slectValue:(NSString *)selectValue model:(BRDatePickerMode)model;

/**
 获取选中的 日期字符串 根据现有的值 进行转换

 @param model BRDatePickerMode
 @param myDateStr 我的日期
 @param myDateFormat 我的日期格式
 @return 转换pickerView 可以用的
 */
+(NSString *)getSelectValueWithModel:(BRDatePickerMode)model myDateStr:(NSString *)myDateStr myDateFormat:(NSString *)myDateFormat;

#pragma mark - ysh_日期格式自定义
+ (void)ysh_showDatePickerWithTitle:(NSString *)title
                           dateType:(BRDatePickerMode)dateType
                    defaultSelValue:(NSString *)defaultSelValue
                    myDateFormatter:(NSString *)myDateFormatter
                            minDate:(NSDate *)minDate
                            maxDate:(NSDate *)maxDate
                       isAutoSelect:(BOOL)isAutoSelect
                         themeColor:(UIColor *)themeColor
                        resultBlock:(void(^)(NSString * value,NSDate * date))resultBlock;


#pragma mark - ysh_日期格式自定义 _unlimitedBtn
+ (void)ysh_showDatePickerUnlimitedWithdateType:(BRDatePickerMode)dateType
                                defaultSelValue:(NSString *)defaultSelValue
                                myDateFormatter:(NSString *)myDateFormatter
                                        minDate:(NSDate *)minDate
                                        maxDate:(NSDate *)maxDate
                                   isAutoSelect:(BOOL)isAutoSelect
                                     themeColor:(UIColor *)themeColor
                                    resultBlock:(void(^)(NSString * value,NSDate * date))resultBlock;
@end
