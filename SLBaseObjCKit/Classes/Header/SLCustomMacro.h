//
//  SLCustomMacro.h
//  SLBaseKit
//
//  Created by CoderSLZeng on 2019/1/16.
//  基本配置宏定义
//

#ifndef SLCustomMacro_h
#define SLCustomMacro_h

#ifdef __OBJC__

/*** 日志打印 ***/
#ifdef DEBUG

/** [--13:44:25:794000--]*[--xxx.m:89--]*[--msg--] */
#define SLLog(FORMAT, ...) {\
NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];\
[dateFormatter setDateStyle:NSDateFormatterMediumStyle];\
[dateFormatter setTimeStyle:NSDateFormatterShortStyle];\
[dateFormatter setDateFormat:@"HH:mm:ss:SSSSSS"]; \
NSString *str = [dateFormatter stringFromDate:[NSDate date]];\
fprintf(stderr, "[--%s--]*[--%s:%d--]*[--%s--]\n\n", [str UTF8String], [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:@#FORMAT, ##__VA_ARGS__] UTF8String]);\
}

#define SLLogFunc SLLog(@"%s", __func__)

#else
#define SLLog(FORMAT, ...)
#define SLLogFunc
#endif

/*** 颜色 ***/
#define SLColorA(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)/255.0]
#define SLColor(r, g, b) SLColorA((r), (g), (b), 255)
#define SLRandomColor SLColor(arc4random_uniform(255), arc4random_uniform(255), arc4random_uniform(255))
#define SLrayColor(v) SLColor((v), (v), (v))
#define SLCommonBgColor SLrayColor(206)

/**** weak/strongOBJ ****/
#define SLWeakObj(o) autoreleasepool{} __weak typeof(o) o##Weak = o;
#define SLStrongObj(o) autoreleasepool{} __strong typeof(o) o = o##Weak;

// 写入plist文件
#define SLWriteToPlist(data, path, filename) [data writeToFile:[NSString stringWithFormat:@"%@%@.plist", @#path @#filename] atomically:YES];

// 加载图片
#define PNGIMAGE(NAME)          [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"png"]]
#define JPGIMAGE(NAME)          [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"jpg"]]

// 字体大小(常规/粗体)
#define BOLDSYSTEMFONT(FONTSIZE)[UIFont boldSystemFontOfSize:FONTSIZE]
#define SYSTEMFONT(FONTSIZE)    [UIFont systemFontOfSize:FONTSIZE]
#define FONT(NAME, FONTSIZE)    [UIFont fontWithName:(NAME) size:(FONTSIZE)]

// View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]

/** 状态栏 */
#define STATUS_BAR_FRAME    [[UIApplication sharedApplication] statusBarFrame]
#define STATUS_BAR_HEIGHT   [[UIApplication sharedApplication] statusBarFrame].size.height
#define NAV_BAR_FRAME       self.navigationController.navigationBar.frame
#define NAV_BAR_MAX_Y       CGRectGetMaxY(self.navigationController.navigationBar.frame)
#define NAV_BAR_HEIGHT      self.navigationController.navigationBar.frame.size.height
#define TAB_BAR_HEIGHT      ([[UIApplication sharedApplication] statusBarFrame].size.height > 20 ? 83 : 49) // 适配全面屏底栏高度

#define SCREEN_WIDTH  [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

#define MinX(v)                 CGRectGetMinX((v).frame)
#define MinY(v)                 CGRectGetMinY((v).frame)

#define MidX(v)                 CGRectGetMidX((v).frame)
#define MidY(v)                 CGRectGetMidY((v).frame)

#define MaxX(v)                 CGRectGetMaxX((v).frame)
#define MaxY(v)                 CGRectGetMaxY((v).frame)

#define kInch6_5 (SLScreenH == 896) // iPhone Xs Max（分辨率为1242*2688）@3
#define kInch6_1 (SLScreenH == 896) // iPhone XR （分辨率为828*1792）@2
#define kInch5_8 (SLScreenH == 812) // iPhone X,Xs（分辨率为1125*2436）@3
#define kInch5_5 (SLScreenH == 736) // iPhone 6,6s,7,8 Plus
#define kInch4_7 (SLScreenH == 667) // iPhone 6,6s,7,8
#define kInch4   (SLScreenH == 568) // iPhone 5,5c,5s,SE
#define kInch3_5 (SLScreenH == 480) // iPhone 4s和之前的机型

// 判断机型是否是全面屏
#define IS_FULL_SCREEN (NAV_BAR_MAX_Y > 64 ? YES : NO)
// 底部指示器的高度
#define HOME_INDICATOR_AREA_HEIGHT 34

// 一个获取某View安全区域范围的宏
#define VIEW_SAFE_AREA_INSETS(view) ({UIEdgeInsets insets; if(@available(iOS 11.0, *)) {insets = view.safeAreaInsets;} else {insets = UIEdgeInsetsZero;} insets;})
/* Use Demo 使用起来比较简洁
 VIEW_SAFE_AREA_INSETS(view).left
 VIEW_SAFE_AREA_INSETS(self.view).right
 */

// 当前设备的系统版本号
#define SYSTEM_VESION [UIDevice currentDevice].systemVersion
// 当前设备型号名称 iPhone or iPad
#define DEVICE_TYPE_NAME [UIDevice currentDevice].localizedModel
// 应用程序版本号
#define APP_VERSION [[NSBundle bundleForClass:[self class]] objectForInfoDictionaryKey:@"CFBundleShortVersionString"]

#endif


#endif /* SLCustomMacro_h */
