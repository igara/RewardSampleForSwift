//
//  VAMPARConfiguration.h
//  VAMP
//
//  Created by AdGeneration on 2019/01/22.
//  Copyright © 2019年 supership inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, VAMPARDetectionAccuracy) {
    VAMPARDetectionAccuracyLow = 1,
    VAMPARDetectionAccuracyMiddle = 2,
    VAMPARDetectionAccuracyHigh = 3,
};

typedef NS_ENUM(NSInteger, VAMPARHitTestType) {
    VAMPARHitTestTypePlane,
    VAMPARHitTestTypePoint,
};

@interface VAMPARConfiguration : NSObject
/**
 * スクリーンショットを共有するアプリまたは機能において除外するものを指定します。
 * 詳細は以下を参照してください。
 * https://developer.apple.com/documentation/uikit/uiactivityviewcontroller/1622009-excludedactivitytypes?language=objc
 */
@property (nonatomic, copy) NSArray<UIActivityType> *excludedActivityTypes;

/**
 * シングルトンインスタンスを取得します。
 */
+ (instancetype)sharedConfiguration;
/**
 * AR機能をサポートしているOSバージョンか判定します。
 */
+ (BOOL)isSupported;
@end

NS_ASSUME_NONNULL_END
