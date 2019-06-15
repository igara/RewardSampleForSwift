//
//  VAMPPlayerError.h
//  VAMP
//
//  Created by AdGeneration on 2017/10/24.
//  Copyright © 2017年 Supership Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const kVAMPPlayerErrorDomain;

typedef NS_ENUM (NSInteger, VAMPPlayerErrorCode) {
    VAMPPlayerErrorCodeNoAd,
    VAMPPlayerErrorCodePubIdNotFound,
    VAMPPlayerErrorCodeNetworkError,
    VAMPPlayerErrorCodeServerError,
    VAMPPlayerErrorCodeCacheServiceError,
    VAMPPlayerErrorCodeUnspecified,
    VAMPPlayerErrorCodeNotRewardType,
    VAMPPlayerErrorCodeNetworkNotConnected,
    VAMPPlayerErrorCodeNoAdstock,
    VAMPPlayerErrorCodeHTTPRequestTimeout,
    VAMPPlayerErrorCodeFileNotFound,
    VAMPPlayerErrorCodeExceedFileSize,
    VAMPPlayerErrorCodeNotReadyAd,
    VAMPPlayerErrorCodeDeviceNotSupport
};

@interface VAMPPlayerError : NSError

@property (nonatomic, assign) VAMPPlayerErrorCode errCode;
@property (nonatomic, assign) int errNumber;

+ (VAMPPlayerError *)errorWithCode:(VAMPPlayerErrorCode)code;
+ (VAMPPlayerError *)errorWithCode:(VAMPPlayerErrorCode)code number:(int)number;

@end
