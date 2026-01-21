// NOTE:
// The OpenCV iOS framework bundled in this repo can have different header
// layouts depending on how it was built/copied. Some distributions expose:
//   opencv2.framework/Headers/opencv2/opencv.hpp
// others expose a flat layout under Headers/.
//
// To keep builds working across both layouts (local + CI), we:
//   1) Add -I.../opencv2.framework/Headers (and /Headers/opencv2) in Makefile.
//   2) Use tolerant includes here.

#ifndef TEMPLATE_MATCH_H
#define TEMPLATE_MATCH_H

#ifdef __cplusplus
  #undef NO
  #undef YES
  #import <opencv2/opencv.hpp>
#endif // __cplusplus

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
#if __has_include(<opencv2/imgcodecs/ios.h>)
  #import <opencv2/imgcodecs/ios.h>
#elif __has_include(<imgcodecs/ios.h>)
  #import <imgcodecs/ios.h>
#else
  // Some OpenCV builds omit iOS helpers; keep optional.
#endif

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

#endif /* TEMPLATE_MATCH_H */
