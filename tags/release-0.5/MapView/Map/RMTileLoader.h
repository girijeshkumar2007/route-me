//
//  RMTimeImageSet.h
//
// Copyright (c) 2008-2009, Route-Me Contributors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#import <Foundation/Foundation.h>
#import "RMTile.h"
#import "RMTileImageSet.h"
#import "RMMapContents.h"

@class RMTileImage;
@class RMTileImageSet;
@class RMMercatorToScreenProjection;

extern NSString * const RMMapImageRemovedFromScreenNotification;
extern NSString * const RMMapImageAddedToScreenNotification;

extern NSString * const RMSuspendExpensiveOperations;
extern NSString * const RMResumeExpensiveOperations;

extern NSString * const RMTileRetrieved;
extern NSString * const RMTileRequested;

@protocol RMTileSource;

@interface RMTileLoader : NSObject {
	RMMapContents *content;

	CGRect loadedBounds;
	int loadedZoom;
	RMTileRect loadedTiles;
	
	BOOL suppressLoading;
}

/// Designated initialiser
- (id)initWithContent: (RMMapContents *)contents;

- (void)updateLoadedImages;

- (void)moveBy: (CGSize) delta;
- (void)zoomByFactor: (float) zoomFactor near:(CGPoint) center;

- (void)clearLoadedBounds;

- (void)reload;

@property (readonly, nonatomic) CGRect loadedBounds;
@property (readonly, nonatomic) int loadedZoom;
@property (readwrite, assign) BOOL suppressLoading;

//-(BOOL) containsRect: (CGRect)bounds;

@end