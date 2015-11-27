// CoreBitcoin by Oleg Andreev <oleganza@gmail.com>, WTFPL.

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BTCSecretSharingVersion) {
    // Identifies configuration for compact 128-bit secrets with up to 16 shares.
    BTCSecretSharingVersionCompact128 = 1,
};

@class BTCBigNumber;
@interface BTCSecretSharing : NSObject

@property(nonatomic, readonly) BTCSecretSharingVersion version;
@property(nonatomic, readonly, nonnull) BTCBigNumber* order;
@property(nonatomic, readonly) NSInteger bitlength;

- (id __nonnull) initWithVersion:(BTCSecretSharingVersion)version;

- (NSArray* __nullable) splitSecret:(NSData* __nonnull)secret threshold:(NSInteger)m shares:(NSInteger)n error:(NSError* __nullable * __nullable)errorOut;

- (NSData* __nullable) joinShares:(NSArray* __nonnull)shares error:(NSError* __nullable * __nullable)errorOut;

@end