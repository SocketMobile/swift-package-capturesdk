/**
    @file CaptureSDK.h
    @brief Main entry point for the Capture API

    @copyright Copyright © 2017 Socket Mobile, Inc.

*/

#ifndef SktCapture_h
#define SktCapture_h

#import <Foundation/Foundation.h>
#import "SktCaptureErrors.h"

/** define the Capture Result type */
typedef SKTCaptureErrors SKTResult;

/** define the Capture Handle type */
typedef void* SKTHandle;

#import "SktCaptureDataSource.h"
#import "SktCaptureVersion.h"
#import "SktCaptureProperty.h"
#import "SktCaptureDeviceTypes.h"
#import "SktCaptureEventIds.h"

/**
 @brief regroup the Application Information to
 be able to open Capture.
 */
@interface SKTAppInfo : NSObject
/** @brief should be set to the platform prefix followed by a colon and the app Bundle ID: example: "ios: com.mycompany.myapp"
*/
@property (strong) NSString* _Nonnull AppID;

/** @brief should be set to the Socket Mobile Developer ID: 07ef56c4-7acc-323b-7821-5c0ab2122243*/
@property (strong) NSString* _Nonnull DeveloperID;

/** @brief should be set to the application AppKey: MCwCFBsP4MDTmN+fBzsWLxYBsBmGalwTAhR56dMFyCEdzlxKd1zNWfdACsXjuA== */
@property (strong) NSString* _Nonnull AppKey;

/** @brief should be set to the application's primary bundle. */
@property (strong) NSBundle* _Nullable mainBundle;

-(bool) verifyWithBundleId:(NSString* _Nonnull) bundleId;
@end

@class SKTCapture;

/**
 @protocol SKTCaptureDelegate
 @brief protocol to define the delegates called by Capture for each event that
        can be received.
 */
@protocol SKTCaptureDelegate <NSObject>

/**
 @brief this delegate is called each time an event is received from Capture

 @param event contains the event received
 @param capture contains a reference to the Capture object for which the event
 @param result contains the result of receiving this event
 */
-(void) didReceiveEvent:(SKTCaptureEvent* _Nonnull) event forCapture:(SKTCapture* _Nonnull) capture withResult:(SKTResult) result;

@end

/**
 @class SKTCapture

 @brief The SKTCapture class is the main entry point to Capture.

    This class must be instanciated with init or initWithDelegate, and
    then open with the AppInfo. The open result can be retrieved in the
    completion block to check if it was successful.

    Once open and a delegate has been specified, the application can
    receive notifications from Capture.

    If a Socket Mobile scanner connects to the iOS device, a device
    arrival event is received through the delegate containing the
    scanner information such as the scanner GUID.

    The scanner must be opened in order to receive the decoded data.
    This is accomplished by calling the <b>openDeviceWithGuid</b> with
    the scanner GUID retrieved from the device arrival event.

    The scanner configuration can be read or set using the capture
    instance that was received in the completion block of the <b>openDeviceWithGuid</b>
    method. The configuration read is done by calling the method <b>getProperty:completionHandler</b>
    from the capture instance representing the scanner. Same thing for writing
    a configuration to the scanner, this time by using the method <b>setProperty:completionHandler</b>
    of the capture instance representing the scanner.

    Once the scanner is no longer needed by the application, the method
    <b>closeWithCompletionHandler</b> can be called from the capture instance
    of the scanner to close. <b>NOTE:</b> Closing the scanner won't actually
    disconnect from the iOS device.


 */
@interface SKTCapture : NSObject


@property (nonatomic, strong, readonly) NSString* _Nullable  guid;// guid of the device, this SKTCapture object is created upon device arrival

/**
 @brief initialize Capture object without delegate.
 */
-(nonnull instancetype)init;

/**
 @brief initialize Capture object with delegate.
 @param delegate reference to an object instance implementing the SKTCaptureDelegateProtocol.
 @return the capture instance.
 @remark this is the recommended method to initialize capture.
 */
-(nonnull instancetype)initWithDelegate:(id<SKTCaptureDelegate> _Nullable) delegate;

/**
 @brief change the capture delegate.
 @param delegate set a new delegate or nil as delegate for receiving Capture event

 @remark it is safe to specify nil as delegate to ignore all capture events
 */
-(void)setDelegate:(id<SKTCaptureDelegate> _Nullable) delegate;

/**
 @brief open the first instance of capture
 @param appInfo contains the application information to open capture
 @param block receives the result of opening capture
 */
-(void) openWithAppInfo:(SKTAppInfo* _Nonnull) appInfo completionHandler:(void(^_Nullable)(SKTResult result)) block;

/**
 @brief open the device identified by the GUID
 @param guid unique identifier of the device to open
 @param block receives the result of opening the device and a new capture instance reprensenting
 the device
 */
-(void) openDeviceWithGuid:(NSString* _Nonnull) guid completionHandler:(void(^_Nullable)(SKTResult result, SKTCapture* _Nullable deviceCapture)) block;

/**
 @brief close a capture instance. It could be the main capture object or a capture
 object that represents a device. In this last case, closing a device won't disconnect
 the device from the iOS device.
 @param block contains the result of closing the capture instance.
 */
-(void) closeWithCompletionHandler:(void(^_Nullable)(SKTResult result)) block;

/**
 @brief set a property and depending of the capture instance used it could be setting
 a property for a device or for capture main object.
 @param property contains the property to set.
 @param block receives the result of setting the property.
 */
-(void) setProperty:(SKTCaptureProperty*_Nonnull) property completionHandler:(void(^_Nullable)(SKTResult result, SKTCaptureProperty* _Nullable complete)) block;

/**
 @brief get a property and depending of the capture instalce used it could be getting
        a property of a device or of the main capture object.
 */
-(void) getProperty:(SKTCaptureProperty*_Nonnull) property completionHandler:(void(^_Nullable)(SKTResult result, SKTCaptureProperty* _Nullable complete)) block;

/**
 @brief delegate for all the event received from capture low level interface.
 @param event contains the event information that is received from low level interface.
 @param handle contains the handle from the object sending the event.
 */
-(void)didReceiveEvent:(SKTCaptureEvent * _Nonnull)event withHandle:(SKTHandle _Nonnull)handle withResult:(SKTResult)result;


/**
  @brief Verifies if the the application's Bundle Info.plist contains "com.socketmobile.chs" in its "UISupportedExternalAccessoryProtocols" array.
 */
+(bool)canConnectToBarcodeScannersWithBundle:(NSBundle * _Nonnull) bundle;
@end

#pragma mark - Helper
/**
 *  Helper for the values received from Capture in the properties or events
 */
@interface SKTHelper : NSObject
/**
 * retrieves the ID from a property ID
 *
 * @param propId  property ID
 * @return only the ID of the property without the other bitwise value
 */
+(NSInteger) retrieveIdFromPropertId:(NSInteger) propId;

/**
 * retrieves the Set parameter type of a property
 *
 * @param propId property ID
 * @return type of the parameter to set the property with
 */
+(NSInteger) retrieveSetTypeFromPropertyId:(NSInteger) propId;

/**
 * retrieves the Get parameter type of a property
 *
 * @param propId property ID
 * @return type of the parameter to get the property (usually 'none')
 */
+(NSInteger) retrieveGetTypeFromPropertyId:(NSInteger) propId;

/**
 * retrieves the group ID of a property
 *
 * @param propId property ID
 * @return the group ID to which the property belongs
 */
+(NSInteger) retrieveGroupIdFromPropertyId:(NSInteger) propId;

/**
 * checks if the property is a main capture object property or
 * a capture device property
 *
 * @param propId property ID
 * @return  true is the property is a main capture object, false otherwise
 */
+(NSInteger) isCaptureFromPropertyId:(NSInteger) propId;

/**
 * creates the bitwise value for Data Confirmation
 *
 * @param reserved  should be set to 0
 * @param rumble 1 for good vibrate, 2 for bad vibrate, 0 for no vibrate
 * @param beep 1 for good beep, 2 for bad beep, 0 for no beep
 * @param led 1 for green LED, 2 for red LED, 0 for no LED
 * @return the data confirmation bitwise value
 */
+(NSInteger) getDataComfirmationWithReserve:(NSInteger) reserved withRumble:(NSInteger) rumble withBeep:(NSInteger) beep withLed:(NSInteger) led;

/**
 * retrieves the data confirmation LED setting
 *
 * @param dataConfirmation data confirmation long value
 * @return 1 for green LED, 2 for red LED, 0 for no LED
 */
+(NSInteger) retrieveLedFromDataConfirmation:(NSInteger) dataConfirmation;

/**
 * retrieves the data confirmation beep setting
 *
 * @param dataConfirmation data confirmation long value
 * @return 1 for good beep, 2 for bad beep, 0 for no beep
 */
+(NSInteger) retrieveBeepFromDataConfirmation:(NSInteger) dataConfirmation;

/**
 * retrieves the data confirmation vibrate setting
 *
 * @param dataConfirmation data confirmation long value
 * @return 1 for good vibrate, 2 for bad vibrate, 0 for no vibrate
 */
+(NSInteger) retrieveRumbleFromDataConfirmation:(NSInteger) dataConfirmation;

/**
 * checks if the Left Button is pressed. For device that has
 * only one trigger button, the Middle Button is the one reflecting
 * the state of the button.
 *
 * @param buttonsStatus value received in the button property or event
 * @return true if the left button is pressed, false otherwise
 */
+(NSInteger) isLeftPressedFromButtonsStatus:(NSInteger) buttonsStatus;

/**
 * checks if the Right Button is pressed. For device that has
 * only one trigger button, the Middle Button is the one reflecting
 * the state of the button.
 *
 * @param buttonsStatus value received in the button property or event
 * @return true if the right button is pressed, false otherwise
 */
+(NSInteger) isRightPressedFromButtonsStatus:(NSInteger) buttonsStatus;

/**
 * checks if the Middle Button is pressed. For device that has
 * only one trigger button, the Middle Button is the one reflecting
 * the state of the button.
 *
 * @param buttonsStatus value received in the button property or event
 * @return true if the middle button is pressed, false otherwise
 */
+(NSInteger) isMiddlePressedFromButtonsStatus:(NSInteger) buttonsStatus;

/**
 * checks if the Power Button is pressed.
 *
 * @param buttonsStatus value received in the button property or event
 * @return true if the power button is pressed, false otherwise
 */
+(NSInteger) isPowerPressedFromButtonsStatus:(NSInteger) buttonsStatus;

/**
 * checks if the Ring Detached is asserted. This is used only for the Ring Scanner
 * CRS Series 9.
 *
 * @param buttonsStatus value received in the button property or event
 * @return true if the Ring Detached is asserted, false otherwise
 */
+(NSInteger) IsRingDetachedFromButtonsStatus:(NSInteger) buttonsStatus;

/**
 * fills the bitwise value then the Left button is pressed or not
 *
 * @param pressed 1 for pressed, 0 for released
 * @return return the value with the left button filled accordingly
 */
+(NSInteger) pressLeftButton:(NSInteger) pressed;

/**
 * fills the bitwise value then the Right button is pressed or not
 *
 * @param pressed 1 for pressed, 0 for released
 * @return return the value with the right button filled accordingly
 */
+(NSInteger) pressRightButton:(NSInteger) pressed;

/**
 * fills the bitwise value then the Middle button is pressed or not
 *
 * @param pressed 1 for pressed, 0 for released
 * @return return the value with the middle button filled accordingly
 */
+(NSInteger) pressMiddleButton:(NSInteger) pressed;

/**
 * fills the bitwise value then the Power button is pressed or not
 *
 * @param pressed 1 for pressed, 0 for released
 * @return return the value with the power button filled accordingly
 */
+(NSInteger) pressPowerButton:(NSInteger) pressed;

/**
 * fills the bitwise value then the Ring is detached or not
 *
 * @param detached 1 for pressed, 0 for released
 * @return return the value with the rign detached filled accordingly
 */
+(NSInteger) detachRing:(NSInteger) detached;

/**
 * retrieves the power state
 * * 0x00: Power Status Unknown
 * * 0x01: Power on Battery
 * * 0x02: Power on Craddle
 * * 0x04: Power on AC
 *
 * @param powerStatus value returned by the power state property or event
 * @return the power state
 */
+(NSInteger) getPowerStateFromPower:(NSInteger) powerStatus;

/**
 * retrieves the minimum level of the battery status range
 *
 * @param batteryLevel value from property or event
 * @return the minimum in the battery status range, usually 0
 */
+(NSInteger) getMinimumLevelFromBatteryLevel:(NSInteger) batteryLevel;

/**
 * retrieves the maximum level of the battery status range
 *
 * @param batteryLevel value from battery level property or event
 * @return the maximum in the battery status range, usually 100
 */
+(NSInteger) getMaximumLevelFromBatteryLevel:(NSInteger) batteryLevel;

/**
 * retrieves the current level of the battery between
 * with its minimum and maximum value
 *
 * @param batteryLevel value from battery level property or event
 * @return current battery level in the range defined with a minimum and maximum value
 */
+(NSInteger) getCurrentLevelFromBatteryLevel:(NSInteger) batteryLevel;

/**
 * adds the power state in the final value that is received
 * by the power status property or event
 *
 * @param powerState the power state
 * @return the power status with the power state
 */
+(NSInteger) setPowerState:(NSInteger) powerState;

/**
 * sets the minimum level of the battery level range that is
 * received in the final value of the battery level property or event
 *
 * @param minLevel min level of the battery level range
 * @return battery level with the minimum level set
 */
+(NSInteger) setMinLevelForBatteryLevel:(NSInteger) minLevel;

/**
 * set the maximum level of the battery level range that is
 * received in the final value of the battery level property or event
 *
 * @param maxLevel maximum level of the battery level range
 * @return battery level with the maximum level set
 */
+(NSInteger) setMaxLevelForBatteryLevel:(NSInteger) maxLevel;

/**
 * set the current level of the battery level range that is
 * received in the final value of the battery level property or event
 *
 * @param curLevel current battery level in the battery level range
 * @return battery level with the current battery level set
 */
+(NSInteger) setCurLevelForBatteryLevel:(NSInteger) curLevel;

@end

#import "SktCaptureHelper.h"

#endif
