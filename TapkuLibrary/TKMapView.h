//
//  TKMapView.h
//  Created by Devin Ross on 7/11/09.
//
/*
 
 tapku.com || http://github.com/tapku/tapkulibrary/tree/master
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 
 */

#import <MapKit/MapKit.h>
#import "TKPlace.h"


@class TKOverlayView;






@protocol TKOverlayViewDelegate<NSObject>
@optional
- (void) didTouchAtPoint:(CGPoint)point;
@end

@protocol TKMapViewDelegate

- (void) didPlacePinAtCoordinate:(CLLocationCoordinate2D)location;

@end



@interface TKMapView : UIView <TKOverlayViewDelegate> {
	MKMapView *mapView;
	TKOverlayView *overlay;
	BOOL pinMode;
	id <TKMapViewDelegate> delegate;
}
@property (readonly,nonatomic) BOOL pinMode;
@property (retain,nonatomic) MKMapView *mapView;
@property (assign,nonatomic) id <TKMapViewDelegate> delegate;
- (void) setPinMode:(BOOL)pinMode;
@end


@interface TKOverlayView : UIView {
	id <TKOverlayViewDelegate> delegate;
}
@property (assign,nonatomic) id <TKOverlayViewDelegate> delegate;
@end

