//
//  EGMonitor.h
//
//  Created by sysylana on 2015/5/22.
//  Copyright © 2015年 Analysys. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>



#define EGConfigInstance [EGMonitorConfig shareInstance]

/**
 SDK配置信息，定义配置参数，如：
    EGConfigInstance.appKey = @"097ju86543728197y";
    EGConfigInstance.channelId = @"App Store";
    EGConfigInstance.debugEnable = YES;
    [EGMonitor startWithConfigure:EGConfigInstance];
 */
@interface EGMonitorConfig : NSObject

+ (instancetype)shareInstance;

/** 必填项，易观方舟平台申请 http://dev.analysys.cn/static/ */
@property (nonatomic, copy) NSString *appKey;

/** 渠道名称, 默认渠道：App Store */
@property (nonatomic, copy) NSString *channelId;

/**
 是否调试模式，默认：NO
 若为YES，调试模式，SDK将统计数据发送到回传测试服务器供查看、调试是否配置正确；同时会打开SDK日志打印功能；
 若为NO，非调试模式，SDK将统计数据发送到正式环境；同时关闭SDK日志打印功能。
 ---- 正式发布,Release模式下一定将此属性设置为非debug模式，即：NO ----
 */
@property (nonatomic, assign) BOOL debugEnable;


@end




@interface EGMonitor : NSObject

#pragma mark - 配置SDK信息
/**
 初始化易观统计

 @param configure EGMonitorConfig实例
 */
+ (void)startWithConfigure:(EGMonitorConfig *)configure;

/**
 是否调试模式，默认：NO
 若为YES，调试模式，SDK将统计数据发送到回传测试服务器供查看、调试是否配置正确；同时会打开SDK日志打印功能；
 若为NO，非调试模式，SDK将统计数据发送到正式环境；同时关闭SDK日志打印功能。
 ---- 正式发布,Release模式下一定将此属性设置为非debug模式，即：NO ----
 */
+ (void)setDebugEnable:(BOOL)debugEnable;


#pragma mark - 统计信息

/**
 * 页面统计
 *
 *  @param pageName   页面名称(不能为nil或@"")
 *  @param contentTag 页面内容标签
 */
+ (void)beginLogPageView:(NSString *)pageName contentTag:(NSString *)contentTag;
+ (void)endLogPageView:(NSString *)pageName contentTag:(NSString *)contentTag;

/**
 *  自定义事件统计.
 *
 *  @param eventID      事件ID(不能为nil或@"")
 *  @param eventName    事件名称
 *  @param eventPropertyDictionary 事件属性字典
 */
+ (void)eventID:(NSString *)eventID eventName:(NSString *)eventName eventPropertyDictionary:(NSDictionary *)eventPropertyDictionary;

/**
 Hybrid应用页面信息统计

 @param request request对象
 @param webView webview/WKWebView对象
 @return 统计结果
 */
+ (BOOL)h5InfoStatEnterWithRequest:(NSURLRequest *)request webView:(id)webView;

/**
 *  唤醒信息统计入口
 *  @param url url
 *  @return 如果url里包含统计信息，返回YES
 */
+ (BOOL)wakeupInfoStatEnterWithOpenURL:(NSURL *)url;


#pragma mark - 账号统计
/**
 使用signIn函数后，建议在用户退出，或切换用户时调用signOff函数，结束对该用户的统计跟踪。
 
 @param puid   账号信息 长度小于64字节
 @param provider 账号来源，如果用户通过第三方账号登陆，可以调用此接口进行统计，不能以下划线"_"开头，使用大写字母和数字标识，长度小于32 字节 ; 如果是上市公司，建议使用股票代码
 */
+ (void)signInWithPUID:(NSString *)puid provider:(NSString *)provider;
+ (void)signInWithPUID:(NSString *)puid;

/**
 停止用户统计跟踪
 */
+ (void)signOff;






@end

