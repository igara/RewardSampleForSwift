//
//  VAMPConstants.h
//  VAMP
//
//  Created by AdGeneration on 2017/02/03.
//  Copyright © 2017年 Supership Inc. All rights reserved.
//

#ifndef VAMPConstants_h
#define VAMPConstants_h

#define kVAMPNonExistentCoordinate 999

// getCountryCode時に国コードを特定できなかった場合に返却されるコード
#define kVAMPUnknownCountryCode @"99"

#endif
/**
 * VAMPの内部状態を定義します。
 */
typedef NS_ENUM (NSInteger, VAMPState) {
    /**
     * 初期状態です。広告のロードを開始するとLoadingへ遷移します
     */
    kVAMPStateIdle = 0,
    /**
     * 広告をロードしている状態です
     */
    kVAMPStateLoading,
    /**
     * 広告のロードが完了した状態です。広告の表示が可能な状態です
     */
    kVAMPStateLoaded,
    /**
     * 広告を表示している状態です
     */
    kVAMPStateShowing
};

/**
 * 性別を定義します。
 */
typedef NS_ENUM (NSInteger, VAMPGender) {
    /**
     * 不明
     */
    kVAMPGenderUnknown,
    /**
     * 男性
     */
    kVAMPGenderMale,
    /**
     * 女性
     */
    kVAMPGenderFemale
};

/**
 * ユーザの同意ステータスを定義します。
 */
typedef NS_ENUM (NSInteger, VAMPConsentStatus) {
    /**
     * 不明
     */
    kVAMPConsentStatusUnknown,
    /**
     * ユーザの同意がある場合
     */
    kVAMPConsentStatusAccepted,
    /**
     * ユーザが拒否した場合
     */
    kVAMPConsentStatusDenied
};

typedef NS_ENUM(NSInteger, VAMPUnderAgeOfConsent) {
    /**
     * 不明
     */
    kVAMPUnderAgeOfConsentUnknown,
    /**
     * 同意年齢未満のユーザに適した広告リクエストをする
     */
    kVAMPUnderAgeOfConsentTrue,
    /**
     * 同意年齢未満のユーザに適した広告リクエストをしない
     */
    kVAMPUnderAgeOfConsentFalse
};
