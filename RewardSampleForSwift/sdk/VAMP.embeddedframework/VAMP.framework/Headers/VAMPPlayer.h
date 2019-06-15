//
//  VAMPPlayer.h
//  VAMP
//
//  Created by AdGeneration on 2017/10/24.
//  Copyright © 2017年 Supership Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "VAMPPlayerEnv.h"

@class VAMPPlayerError;
@protocol VAMPPlayerDelegate;

@interface VAMPPlayer : UIViewController

@property (nonatomic, copy) NSString *pubId;
@property (nonatomic) VAMPPlayerEnv env;
@property (nonatomic, readonly) BOOL isReady;
@property (nonatomic, weak) id <VAMPPlayerDelegate> delegate;

- (id)initWithDelegate:(id <VAMPPlayerDelegate>)delegate;
- (id)initWithDelegate:(id <VAMPPlayerDelegate>)delegate withEnv:(VAMPPlayerEnv)env;
- (void)presentFromRootViewController:(UIViewController *)rootViewController;
- (void)dismiss;
- (void)loadVast:(NSData *)data;
- (void)loadVast:(NSData *)data actualLandingURL:(NSString *)actualLandingURL;
- (void)close;
+ (void)setChildDirected:(BOOL)childDirected;
+ (BOOL)isChildDirected;
@end

@protocol VAMPPlayerDelegate <NSObject>

@optional
- (void)VAMPPlayerDidReady:(NSDictionary *)results;
- (void)VAMPPlayerDidPlay:(NSDictionary *)results;
- (void)VAMPPlayerDidComplete:(NSDictionary *)results;
- (void)VAMPPlayerDidClick:(NSDictionary *)results;
- (void)VAMPPlayerDidUnmute:(NSDictionary *)results;
- (void)VAMPPlayerDidMute:(NSDictionary *)results;
- (void)VAMPPlayerDidClose:(NSDictionary *)results;
- (void)VAMPPlayerDidFail:(NSDictionary *)results withError:(VAMPPlayerError *)error;
- (void)VAMPPlayerDidCancel;
- (UIViewController *)VAMPPlayerWillShowEndCard:(NSDictionary *)results;
- (void)VAMPPlayerWillSendBeacon:(NSString *)beaconType withInfo:(NSDictionary *)info;

@end
