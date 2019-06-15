//
//  VAMP.h
//  VAMP
//
//  Created by AdGeneration on 2016/11/12.
//  Copyright © 2016年 Supership Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "VAMPConfiguration.h"
#import "VAMPConstants.h"
#import "VAMPError.h"
#import "VAMPPlayer.h"
#import "VAMPPlayerEnv.h"
#import "VAMPPlayerError.h"
#import "VAMPFrequencyCappedStatus.h"
#import "VAMPARConfiguration.h"

@protocol VAMPDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
  VAMP SDKで動画リワードを使用するための基本的な機能を提供します。
 */
@interface VAMP : NSObject

@property (nonatomic, weak, nullable) id <VAMPDelegate> delegate;

/**
  アドジェネ広告枠IDをセットします。
 
  @param placementId  使用する広告枠ID
 */
- (void)setPlacementId:(NSString *)placementId;

/**
  ViewControllerをセットします。
 
  指定したViewControllerから広告画面が表示されます。
 
  @param rootViewController 広告画面を表示するViewController
 */
- (void)setRootViewController:(nullable UIViewController *)rootViewController;
/**
  事前に広告を取得します。
 
  広告を取得するのに時間がかかるため（動画ファイル、プレイアブルのダウンロード）、
  事前に在庫を確保しておき、ユーザを待たせることなく広告を表示するための機能です。
 
  ※load との違いとして、preloadを実行した結果（[vampLoadResult]([VAMPDelegate vampLoadResult:success:adnwName:message:])、[didFailToLoadWithError]([VAMPDelegate vamp:didFailToLoadWithError:withPlacementId:])など）はリスナーで受け取ることはできません。
 */
- (void)preload;
/**
  広告の取得を開始します。
 
  ※各アドネットワークに在庫の確認、動画ファイルやエンドカード素材のダウンロードなど
 */
- (void)load;
/**
  広告を表示します。
 
  ※動画が再生されます。
 
  show実行時には、[vampdDidClose]([VAMPDelegate vampDidClose:adnwName:])を受け取るまでは load を実行しないでください。
 
  @return 広告の表示に成功したかどうか
 */
- (BOOL)show;
/**
  広告を表示する準備が完了しているか確認します。
 
  show で広告を表示する前に、load 済みかどうかを確認するためのメソッドです。
 
  @return 広告表示をする準備が完了していればYES、そうでなければNO
 */
- (BOOL)isReady;
/**
  VAMP SDKのバージョンを返します。例）v1.2.1
 
  @return VAMPのSDKバージョン
 */
+ (NSString *)SDKVersion;
/**
  VAMP SDKがサポートするiOSの最低バージョンを返します。
 
  返却されたOSバージョン以上で動作します。
 
  例）9.0。
 
  @return 対応OSバージョン
 */
+ (float)SupportedOSVersion;
/**
  VAMP SDKのサポート対象OSかどうか、確認できます。
 
  ※ added on v1.2.4
 
  @return サポート対象OSならYES、対象外ならNO
 */
+ (BOOL)isSupportedOSVersion;
/**
  テストモードの設定をします。
 
  YESを指定すると収益が発生しないテスト広告が配信されるようになります。
 
  ストアに申請する際は**コメントアウト**か**NO**に設定してください。
 
  各アドネットワークのテストモードと連動します。
 
  対象: AdMob、AppLovin、FAN、maio、nend、UnityAds、Mintegral、MoPub
 
  デフォルトはNO。テストモードの場合はRTB案件は配信されません。
 
  @param enableTest テストモードを有効にするかどうか。
 */
+ (void)setTestMode:(BOOL)enableTest;
/**
  テストモードに設定されているかどうかを確認します。
 
  @return テストモードが有効の場合はYES、無効の場合はNO
 */
+ (BOOL)isTestMode;
/**
  ログを詳細に出力するデバッグモードを設定します（デフォルトはNO）。
 
  以下のアドネットワークのデバッグモードと連動します。
 
  対象:RTB、AppLovin、FAN、nend、UnityAds、Vungle、Tapjoy、MoPub
 
  @param enableDebug YESならデバッグモードを有効に、NOなら無効にします。
*/
+ (void)setDebugMode:(BOOL)enableDebug;
/**
  デバッグモードの設定状況を返却します。
 
  @return  デバッグモードが有効な場合はYES、無効の場合はNO
 */
+ (BOOL)isDebugMode;
/**
  アドネットワーク側の広告取得を待つタイムアウト時間を設定します。
 
  @param timeout アドネットワーク側の広告取得を待つタイムアウト時間(秒)。最小5秒、最大60秒。デフォルトは15秒。
 */
+ (void)setMediationTimeout:(float)timeout;
/**
  アドネットワーク側の広告取得を待つタイムアウト時間(秒)を返します。
 
  @return アドネットワーク側の広告取得を待つタイムアウト時間
 */
+ (float)getMediationTimeout;
/**
  2文字の国コード(JP,USなど)を取得します。
 
  IPから国を判別できなかった、リクエストがタイムアウトしたなど、
  正常に値が返せない場合は"99"が返却されます。
 
  [UnityPluginで国判定するサンプル](https://gist.github.com/mukae-ss/9131fa350e09db77dbab247500c94750)
 
  ※ added on v1.2.4
 
  @param completionHandler 国コードを取得するためのハンドラー
 */
+ (void)getCountryCode:(void (^)(NSString *countryCode))completionHandler;
/**
  ユーザ属性の性別をセットします。
 
  アドネットワークSDKのユーザー属性ターゲティング機能に性別を設定します。
 
  対応アドネットワーク：<s>AdMob</s>（v7.31.0でdeprecated）、nend、Mintegral
 
  @param gender 設定するユーザの性別（ VAMPGender を参照）
*/
+ (void)setGender:(VAMPGender)gender;
/**
  アドネットワークSDKのユーザ属性ターゲティング機能に誕生日を設定します。
 
  年、月、日を指定します。
 
  対応アドネットワーク：AdMob、nend、Mintegral
 
    NSDateComponents *components = [NSDateComponents new];
    components.year = 1980;
    components.month = 2;
    components.day = 20;
    NSDate *birthday = [[[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian]
    dateFromComponents:components];
    [VAMP setBirthday:birthday];

  @param birthday 設定するユーザの誕生日
 */
+ (void)setBirthday:(nullable NSDate *)birthday;
/**
  ユーザの同意ステータスを設定します。
  ユーザの同意がある場合はkVAMPConsentStatusAcceptedをセットします。
 
  @param consentStatus 同意ステータス( VAMPConsentStatus 参照)
 */
+ (void)setUserConsent:(VAMPConsentStatus)consentStatus;
/**
 特定の年齢未満のユーザからのアクセスかどうかを設定します。
 YESに設定した場合はIDFAを送りません。
 COPPA、GDPRでは特定の年齢未満のユーザに対するデータの取り扱いについて
 いくつかの義務が課せられています。
 これらの対象の国ユーザが特定の年齢未満の場合にはYESを設定してください。
 以下のアドネットワークの特定の年齢未満のユーザからのアクセスかどうかを設定する機能と連動します。
 (AdMob、FAN、AppLovin、Tapjoy)
 ※非推奨です。代わりに setChildDirected を使用してください。
 @param childDirected ユーザの年齢が特定の年齢未満かどうか
 */
+ (void)setCoppaChildDirected:(BOOL)childDirected DEPRECATED_ATTRIBUTE;
/**
 特定の年齢未満のユーザからのアクセスであるかどうかを取得します。
 [setCoppaChildDirected](setCoppaChildDirected:)で設定した値を返却します。
 ※非推奨です。代わりに isChildDirected を使用してください。
 
 @return 特定の年齢未満のユーザからのアクセスかどうか
 */
+ (BOOL)isCoppaChildDirected DEPRECATED_ATTRIBUTE;

/**
 COPPA対象ユーザであるかどうかを設定します。
 これらの対象の国ユーザが特定の年齢未満の場合にはYESを設定してください。
 以下のアドネットワークの特定の年齢未満のユーザからのアクセスかどうかを設定する機能と連動します。
 (AdMob、FAN、Tapjoy)
 
 @param childDirected ユーザの年齢が特定の年齢未満かどうか
 */
+ (void)setChildDirected:(BOOL)childDirected;
/**
 特定の年齢未満のユーザからのアクセスであるかどうかを取得します。
 [setChildDirected](setChildDirected:)で設定した値を返却します。
 
 @return [setChildDirected](setChildDirected:)で設定した値
 */
+ (BOOL)isChildDirected;
/**
 GDPRの対象ユーザで特定の年齢未満であるかどうかを設定します。
 以下のアドネットワークと連動します。
 (AdMob、AppLovin、Tapjoy)

 @param underAgeOfConsent 特定の年齢未満のユーザかどうか
 */
+ (void)setUnderAgeOfConsent:(VAMPUnderAgeOfConsent)underAgeOfConsent;
/**
  EU圏アクセス判定をします（YESならEU圏からのアクセス）。
 
  IPを元に以下の国からのアクセスかを判定します。
 
  ベルギーBE, ブルガリアBG, チェコCZ, デンマークDK,ドイツDE, エストニアEE, アイルランドIE, ギリシャGR, スペインES, フランスFR, クロアチアHR, イタリアIT, キプロスCY, ラトビアLV, リトアニアLT, ルクセンブルクLU, ハンガリーHU, マルタMT, オランダNL, オーストリアAT, ポーランドPL, ポルトガルPT, ルーマニアRO, スロベニアSI, スロバキアSK, フィンランドFI, スウェーデンSE, イギリスGB、アイスランドIS、リヒテンシュタインLI、ノルウエーNO、ギアナGF、ポリネシアPF、フランス領南方・南極地域TF、サン・マルタン（フランス領）MF、シント・マールテン（オランダ領）SX、イギリス領ヴァージン諸島VG、イギリス領インド洋地域IO
 
  ※IPから国が判別できなかった場合もYESに判定されます。
 
  @param completionHandler 通知を受け取るためのハンドラー。accessがYESならEU圏からのアクセス
 */
+ (void)isEUAccess:(void (^)(BOOL access))completionHandler;
/**
  特定の広告枠IDに対してフリークエンシーキャップの設定をします。
 
  impressionsは視聴制限回数です。その回数視聴を行うと、showを呼んだ際にdidFailToShowWithErrorでVAMPErrorCodeFrequencyCappedエラーが通知されます。
 
  minutesは制限時間です。キャップ解除後、最初の視聴からこの時間経過すると視聴回数がリセットされ、キャップにかかっていた場合はキャップが解除されます。
 
  一度設定済みの場合には設定を上書きしません。
 
  ここで設定した値はアプリ再起動後も保持され続けるため、値を書き換えたい場合は[clearFrequencyCap](clearFrequencyCap:)を呼んでから[setFrequencyCap](setFrequencyCap:impressions:minutes:)を呼んでください。
 
  @param placementId フリークエンシーキャップを設定する広告枠ID
  @param impressions 視聴制限回数（1以上の値で設定可能)
  @param minutes 視聴回数がリセットされるまでの制限時間（1分〜1440分の間で設定可能）
 */
+ (void)setFrequencyCap:(NSString *)placementId impressions:(NSUInteger)impressions minutes:(NSUInteger)minutes;
/**
  特定の広告枠IDの現在の視聴回数をリセットします。
 
  [setFrequencyCap](setFrequencyCap:impressions:minutes:)でフリークエンシーキャップの設定をしており、キャップにかかった場合はこのメソッドを呼ぶことでキャップを解除できます。
 
  値を書き換えたい場合は、このメソッドを呼んでから[setFrequencyCap](setFrequencyCap:impressions:minutes:)を呼んでください。
 *
  @param placementId 視聴回数をリセットする広告枠ID
 */
+ (void)clearFrequencyCap:(NSString *)placementId;
/**
  特定の広告枠IDにおいて、現在キャップにかかっている状態かどうか確認することができます。
 
  @param placementId  キャップにかかっている状態かどうか確認する広告枠ID
  @return キャップにかかっていればYES、かかっていなければNO
 */
+ (BOOL)isFrequencyCapped:(NSString *)placementId;
/**
  特定の広告枠IDの現在のフリークエンシーキャップの状態( VAMPFrequencyCappedStatus )を取得します。
 
  @param placementId フリークエンシーキャップの状態を取得する広告枠ID
 
  @return VAMPFrequencyCappedStatus インスタンス
 */
+ (VAMPFrequencyCappedStatus *)getFrequencyCappedStatus:(NSString *)placementId;
/**
  特定の広告枠IDのフリークエンシーキャップの設定を解除します。
 
  再度フリークエンシーキャップ機能を利用する場合は setFrequencyCap を呼んでください。
 
  @param placementId フリークエンシーキャップ機能を無効にする広告枠ID
 */
+ (void)resetFrequencyCap:(NSString *)placementId;
/**
  全ての広告枠IDのフリークエンシーキャップの設定を解除します。
 */
+ (void)resetFrequencyCapAll;

@end

/**
  VAMPデリゲートプロトコル
 */
@protocol VAMPDelegate <NSObject>
@optional

/**
  広告表示が可能になると通知されます。（優先順位よりスピード優位）。
 
  @param placementId 広告枠ID
  @param adnwName アドネットワーク名
 */
- (void)vampDidReceive:(NSString *)placementId adnwName:(NSString *)adnwName;
/**
  インセンティブ付与が可能になると通知されます。
 
  ※ユーザが途中で再生をスキップしたり、動画視聴をキャンセルすると発生しません。
 
  アドネットワークによって発生タイミングが異なります。
 
  通常は動画再生が完了したタイミングで発生しますが、
  UnityAds、Vungleのみエンドカードを閉じたタイミングで発生します。
 
  @param placementId 広告枠ID
  @param adnwName アドネットワーク名
 */
- (void)vampDidComplete:(NSString *)placementId adnwName:(NSString *)adnwName;
/**
  動画プレーヤー、エンドカードが閉じられたタイミングで通知されます。
 
  ユーザキャンセルなどの場合も通知されますので、インセンティブ付与は[vampDidComplete](vampDidComplete:adnwName:)で判定してください。
 
  @param placementId 広告枠ID
  @param adnwName アドネットワーク名
 */
- (void)vampDidClose:(NSString *)placementId adnwName:(NSString *)adnwName;
/**
  広告の取得に失敗すると通知されます。
 
  広告取得時のタイムアウトや、全てのアドネットワークの在庫がない(フリクエンシーキャップ含む)場合など。
 
  EU圏からのアクセスの場合（VAMPErrorCodeNoAdnetwork）が発生します。2018-05-23現在 ※本仕様は変更する可能性があります。
 
  @param vamp VAMP オブジェクト
  @param error VAMPError
  @param placementId 広告枠ID
 */
- (void)vamp:(VAMP *)vamp didFailToLoadWithError:(VAMPError *)error withPlacementId:(nullable NSString *)placementId;
/**
  広告の表示に失敗したときに通知されます。
 
  @param vamp VAMP オブジェクト
  @param error VAMPError
  @param placementId 広告枠ID
 */
- (void)vamp:(VAMP *)vamp didFailToShowWithError:(VAMPError *)error withPlacementId:(NSString *)placementId;
/**
  load完了から１時間以上経過するとRTB案件が無効になる関係から、再度loadを実行してもらうために通知されます。
 
  通知を受け取ってから[isReady]([VAMP isReady])を実行するとfalseが返却されます。
 
  通知を受け取ってから[show]([VAMP show])を実行すると、[didFailToShowWithError](vamp:didFailToShowWithError:withPlacementId:)のVAMPErrorCodeNotLoadedAdが返却されます。
 
  @param placementId 広告枠ID
 */
- (void)vampDidExpired:(NSString *)placementId;
/**
  アドネットワークの広告取得が開始されたときに通知されます。
 
  @param placementId 広告枠ID
  @param adnwName アドネットワーク名
 */
- (void)vampLoadStart:(NSString *)placementId adnwName:(NSString *)adnwName;
/**
  アドネットワークの広告取得結果が通知されます。
 
  成功時はsuccess=YESとなりロード処理は終了します。
 
  success=NOのとき、次位のアドネットワークがある場合はロード処理は継続されます。
 
  @param placementId 広告枠ID
  @param success loadに成功したかどうか
  @param adnwName アドネットワーク名
  @param message メッセージ
 */
- (void)vampLoadResult:(NSString *)placementId success:(BOOL)success adnwName:(NSString *)adnwName
               message:(nullable NSString *)message;
/**
  VAMPの内部状態が遷移したときに通知されます。
 
  @param oldState 前のState
  @param newState 次のState
  @param placementId 広告枠ID
 */
- (void)vampDidChangeState:(VAMPState)oldState intoState:(VAMPState)newState
           withPlacementId:(nullable NSString *)placementId;

@end

NS_ASSUME_NONNULL_END
