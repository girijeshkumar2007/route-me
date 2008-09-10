//
//  TileImageCache.h
//  Images
//
//  Created by Joseph Gentle on 30/08/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Tile.h"
#import "TileSource.h"

@class TileImage;

@protocol TileCache<NSObject>

// Returns the cached image if it exists. nil otherwise.
-(TileImage*) cachedImage:(Tile)tile;

@optional

-(void)addTile: (Tile)tile WithImage: (TileImage*)image;

@end


@interface TileCache : NSObject<TileCache>
{
	NSMutableArray *caches;
}

+(TileCache*)sharedCache;

+(NSNumber*) tileHash: (Tile)tile;

// Add tile to cache
-(void)addTile: (Tile)tile WithImage: (TileImage*)image;

@end