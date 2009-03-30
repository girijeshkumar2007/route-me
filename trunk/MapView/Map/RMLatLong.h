//
//  RMLatLong.h
//
// Copyright (c) 2008, Route-Me Contributors
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

#ifndef _RMLATLONG_H_
#define _RMLATLONG_H_

#import <TargetConditionals.h>
#if TARGET_OS_IPHONE
#import <CoreLocation/CoreLocation.h>

/*! \struct RMLatLongBounds
 
 \brief Specifies a rectangle by northwest and southeast corners, given as CLLocationCoordinate2D.

 \deprecated Note: northWest and southEast will change to northeast and southwest (note spelling and corner changes) after 0.5 to keep right-handed coordinate system
 */
typedef struct {
	CLLocationCoordinate2D northWest;
	CLLocationCoordinate2D southEast;
} RMLatLongBounds;

#else

/* From CoreLocation by Apple inc. Copyright 2008 Apple Computer, Inc. All rights reserved. */

/*
 *  CLLocationDegrees
 *  
 *  Discussion:
 *    Type used to represent a latitude or longitude coordinate in degrees under the WGS 84 reference
 *    frame. The degree can be positive (North and East) or negative (South and West).  
 */
typedef double CLLocationDegrees;
/*
 *  CLLocationCoordinate2D
 *  
 *  Discussion:
 *    A structure that contains a geographical coordinate.
 *
 *  Fields:
 *    latitude:
 *      The latitude in degrees.
 *    longitude:
 *      The longitude in degrees.
 */
typedef struct {
	CLLocationDegrees latitude;
	CLLocationDegrees longitude;
} CLLocationCoordinate2D;

#endif

typedef CLLocationCoordinate2D RMLatLong;

static const double kRMMinLatitude = -90.0f;
static const double kRMMaxLatitude = 90.0f;
static const double kRMMinLongitude = -180.0f;
static const double kRMMaxLongitude = 180.0f;

#endif