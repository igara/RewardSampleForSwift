//
//  VAMPFrequencyCappedStatus.h
//  VAMP
//
//  Created by AdGeneration on 2018/07/02.
//  Copyright © 2018年 supership inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * フリークエンシーキャップ機能の状態を表します。
 */
@interface VAMPFrequencyCappedStatus : NSObject

/**
 * キャップにかかっているかどうかを取得します。
 */
@property (nonatomic, readonly, getter = isCapped) BOOL capped;
/**
 * フリークエンシーキャップ機能が有効である場合、現在設定されている視聴制限回数を取得します。
 */
@property (nonatomic, readonly) NSUInteger impressionLimit;
/**
 * 現在設定されているフリークエンシーキャップ機能の視聴回数がリセットされるまでの時間を返却します。
 *
 * この時間が経過すると、視聴回数はリセットされます。
 */
@property (nonatomic, readonly) NSUInteger timeLimit;
/**
 * フリークエンシーキャップ機能が有効である場合、現在の視聴回数を返却します。
 */
@property (nonatomic, readonly) NSUInteger impressions;
/**
 * フリークエンシーキャップ機能が有効である場合、次に視聴回数がリセットされるまでの残り時間を返却します。
 */
@property (nonatomic, readonly) NSUInteger remainingTime;

- (id)initWithImpressions:(NSUInteger)impressions
          impressionLimit:(NSUInteger)impressionLimit
                timeLimit:(NSUInteger)timeLimit
                   capped:(BOOL)capped
            remainingTime:(NSUInteger)remainingTime;
@end

NS_ASSUME_NONNULL_END
