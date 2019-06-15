//
//  VAMPConfiguration.h
//  VAMP
//
//  Created by AdGeneration on 2018/06/18.
//  Copyright © 2018年 supership inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * VAMPの設定を変更するためのクラスです。
 */
@interface VAMPConfiguration : NSObject

/**
 * 動画再生中にキャンセルが可能か設定します。
 *
 * この機能は一部のアドネットワークのみ有効です。
 */
@property (nonatomic, getter = isPlayerCancelable) BOOL playerCancelable;
/**
 * キャンセル機能が有効のときに表示するアラートダイアログのタイトルを設定します。
 *
 * この設定は一部のアドネットワークのみ有効です。
 */
@property (nonatomic, copy) NSString *playerAlertTitleText;
/**
 * キャンセル機能が有効のときに表示するアラートダイアログの本文を設定します。
 *
 * この設定は一部のアドネットワークのみ有効です。
 */
@property (nonatomic, copy) NSString *playerAlertBodyText;
/**
 * キャンセル機能が有効のときに表示するアラートダイアログの終了ボタンのテキストを設定します。
 *
 * この設定は一部のアドネットワークのみ有効です。
 */
@property (nonatomic, copy) NSString *playerAlertCloseButtonText;
/**
 * キャンセル機能が有効のときに表示するアラートダイアログの継続視聴ボタンのテキストを設定します。
 * この設定は一部のアドネットワークのみ有効です。
 */
@property (nonatomic, copy) NSString *playerAlertContinueButtonText;

/**
 * VAMPConfiguration インスタンスを取得します。
 *
 * @return VAMPConfiguration インスタンス
 */
+ (instancetype)defaultConfiguration;

@end

NS_ASSUME_NONNULL_END
