//
//  VAMPError.h
//  VAMP
//
//  Created by AdGeneration on 2017/02/03.
//  Copyright © 2017年 Supership Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * VAMP SDKで発生するエラーを定義します。
 */
typedef NS_ENUM (NSUInteger, VAMPErrorCode) {
    /**
     * 非対応OSバージョン
     *
     * 対応していないOSのバージョンなので、ダイアログでユーザーに広告機能が使えない旨の通知をしてください。
     */
    VAMPErrorCodeNotSupportedOsVersion,
    /**
     * 不明なエラー
     *
     * 起動元アプリと接続できなくなりました。
     */
    VAMPErrorCodeUnknown,
    /**
     * サーバー間通信エラー
     *
     * アドジェネのサーバーでエラーが発生しているので、お問合せください。広告枠IDを存在しないものにすると発生します。
     */
    VAMPErrorCodeServerError,
    /**
     * 配信可能アドネットワークがない
     *
     * アドジェネ管理画面でアドネットワークの配信がONになっていない、またはEU圏からのアクセスの場合（GDPR）発生します。
     */
    VAMPErrorCodeNoAdnetwork,
    /**
     * 通信不通
     *
     * ネットワークに接続できない状況（電波状況が悪い、機内モードなど）です。電波状況をご確認ください。
     */
    VAMPErrorCodeNeedConnection,
    /**
     * タイムアウト
     *
     * アドネットワークSDKから返答が得られず、１５秒経過した場合発生。デフォルト１５秒ですが、[setMediationTimeout]([VAMP setMediationTimeout:])で秒数を変更（５秒〜６０秒）できます。
     */
    VAMPErrorCodeMediationTimeout,
    /**
     * ユーザ都合の途中終了
     *
     * AdMobなどで動画を途中でキャンセルできる場合に発生します。
     */
    VAMPErrorCodeUserCancel,
    /**
     * 広告在庫無し
     *
     * 在庫が無いので、再度loadをしてもらう必要があります。連続で発生する場合、時間を置いてからloadをする必要があります。フリクエンシーキャップにかかっている場合があります。
     */
    VAMPErrorCodeNoAdStock,
    /**
     * アドネットワーク側でのエラー
     */
    VAMPErrorCodeAdnetworkError,
    /**
     * 設定エラー
     */
    VAMPErrorCodeSettingError,
    /**
     * 広告がロードされていない時に表示しようとした
     */
    VAMPErrorCodeNotLoadedAd,
    /**
     * パラメータが不正
     */
    VAMPErrorCodeInvalidParameter,
    /**
     * フリークエンシーキャップ
     *
     * 設定した視聴回数以上動画を視聴しました。[setFrequencyCap]([VAMP setFrequencyCap:impressions:minutes:)で設定した時間以上待てばキャップが解除されます。
     */
    VAMPErrorCodeFrequencyCapped
};

#define VAMP_ERROR_CODE_STRINGS @[@"VAMPErrorCodeNotSupportedOsVersion", @"VAMPErrorCodeUnknown", @"VAMPErrorCodeServerError", @"VAMPErrorCodeNoAdnetwork", @"VAMPErrorCodeNeedConnection", @"VAMPErrorCodeMediationTimeout", @"VAMPErrorCodeUserCancel", @"VAMPErrorCodeNoAdStock", @"VAMPErrorCodeAdnetworkError", @"VAMPErrorCodeSettingError", @"VAMPErrorCodeNotLoadedAd", @"VAMPErrorCodeInvalidParameter", @"VAMPErrorCodeFrequencyCapped"]

#define VAMP_ERROR_CODE_STRINGS_JP @[@"サポートされていないOSバージョンです", @"不明なエラー", @"サーバー間通信エラー", @"配信可能アドネットワークが見つかりませんでした", @"ネットワーク通信が行えませんでした", @"タイムアウトしました", @"キャンセルされました", @"広告在庫がありません", @"アドネットワークにてエラーが発生しました", @"設定エラー", @"広告がロードされていません", @"パラメーターが不正です", @"キャップにかかっています"]

UIKIT_EXTERN NSString *const VAMPErrorKeyFailMessage;

/**
 * VAMPError
 */
@interface VAMPError : NSError

+ (NSString *)kVAMPErrorCodetoString:(VAMPErrorCode)code;
+ (instancetype)VAMPErrorWithError:(VAMPErrorCode)code errorDic:(NSDictionary *)errorDic;
- (NSString *)kVAMPErrorString;

@end
