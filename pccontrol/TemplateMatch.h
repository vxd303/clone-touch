#ifndef TEMPLATE_MATCH_H
#define TEMPLATE_MATCH_H
#endif 

#ifdef __cplusplus
#undef NO
#undef YES
// OpenCV headers may be installed with different paths depending on how
// opencv2.framework was built/copied into ZXTouch/frameworks.
// Prefer the common <opencv2/opencv.hpp>, but fall back to umbrella headers.
  #if __has_include(<opencv2/opencv.hpp>)
    #include <opencv2/opencv.hpp>
  #elif __has_include(<opencv.hpp>)
    #include <opencv.hpp>
  #elif __has_include(<opencv2.hpp>)
    #include <opencv2.hpp>
  #else
    #error "OpenCV headers not found. Ensure frameworks/opencv2.framework is present and header search paths are set."
  #endif
#endif


//
//  TemplateMatch.hpp
//  OpenCVTest
//
//  Created by Yun CHEN on 2018/2/8.
//  Copyright © 2018年 Yun CHEN. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>
#import <imgcodecs/ios.h>

@interface TemplateMatch : NSObject

@property(nonatomic,strong) UIImage *templateImage;     //模板图片。由于匹配方法会被多次调用，所以模板图片适合单次设定。

//在Buffer中匹配预设的模板，如果成功则返回位置以及区域大小。
//这里返回的Rect基于AVCapture Metadata的坐标系统，即值在0.0-1.0之间，方便AVCaptureVideoPreviewLayer类进行转换。
- (CGRect)templateMatchWithPath:(NSString*)imgPath templatePath:(NSString*)templatePath error:(NSError**)err;
- (CGRect)templateMatchWithUIImage:(UIImage*)img template:(UIImage*)templ;
- (CGRect)templateMatchWithCGImage:(CGImageRef)img templatePath:(NSString*)templatePath error:(NSError**)err;

- (void)setScaleRation:(float)sr;
- (void)setAcceptableValue:(float)av;
- (void)setMaxTryTimes:(int)mtt;

@end
