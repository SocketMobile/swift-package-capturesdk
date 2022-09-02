//
//  SktCaptureHelper.h
//  CaptureSDK
//
//  Created by Cyrille on 16.06.22.
//  Copyright © 2022 Socket Mobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CaptureSDK.h"

#pragma mark - SKTCaptureHelperDevice to handle a device
/**
 * CaptureHelperDevice regroups the APIs
 * that are related to the device and its configuration.
 *
 * There is no need to create a CaptureHelperDevice, as
 * it is created when CaptureHelper notifies a Device Arrival.
 * A reference of a CaptureHelperDevice is kept in a devices
 * list in CaptureHelper.
 *
 * The main entry point of the CaptureSDK is CaptureHelper.
 * To use CaptureHelper, open it with the method openWithAppInfo.
 *
 * CaptureHelper shares its instance across the application and
 * it is accessible by using the static method [SKTCaptureHelper sharedInstance]
 * It is best to setup the delegates before opening CaptureHelper
 * to make sure to not miss any asynchronous event.
 */
@interface SKTCaptureHelperDevice: NSObject {
    /**
     * _extensionProperties can be used by the Category
     * class of SKTCaptureHelperDevice to store some properties
     */
    NSDictionary* _extensionProperties;
}


#pragma mark - Basic Read Only Device Information

/** device friendly name */
@property (strong, readonly) NSString *friendlyName;

/** device type as a SKT Capture device type numeric value */
@property (readonly) SKTCaptureDeviceType deviceType;

/** device GUID (for the same device the GUID changes at each connection) */
@property (strong, readonly) NSString *guid;


#pragma mark - Convenience properties for Device Information

/** device battery level expressed as a percentage: 84% */
@property NSString *batteryLevel;


#pragma mark - Initialization

/** initialize the device with the device information coming from Device Arrival notification */
-(instancetype)initWithDeviceInfo:(SKTCaptureDeviceInfo *)deviceInfo;

/**
 * set the dispatch queue used by Capture when invoking
 * delegates and completion handlers
 *
 * If Capture Helper dispatch queue is set to the main queue
 * then UI controls can be updated directly from the Capture Helper
 * delegates and completion handlers.
 */
-(void)setDispatchQueue:(__weak dispatch_queue_t) queue;

/**
 * retrieve the dispatch queue used by Capture when invoking
 * delegates and completion handlers
 */
-(__weak dispatch_queue_t)getDispatchQueue;


#pragma mark - Device Information
/**
 *  retrieve the device friendly name
 *
 *  @param block receiving the response with the result and the friendly name of
 *  the device if the result is successful
 */
-(void)getFriendlyNameWithCompletionHandler:(void(^)(SKTResult result, NSString *name))block;

/**
 *  set the device friendly name. The device friendly name has a limit of
 *  32 UTF8 characters including the null terminated character, an error is
 *  generated if the friendly name is too long.
 *
 *  @param name friendly name to set the device with
 *  @param block receiving the result of setting the new friendly name
 */
-(void)setFriendlyName:(NSString *)name completionHandler:(void(^)(SKTResult result))block;

/**
 * get the device Bluetooth address
 *
 *  @param block receiving the result of getting the device Bluetooth Address if the result
 *  is successful
 */
-(void)getBluetoothAddressWithCompletionHandler:(void(^)(SKTResult result, NSArray *address))block;

/**
 * get the device Type
 *
 *  @param block receiving the result and the device Type if the result is successful
 */
-(void)getTypeWithCompletionHandler:(void(^)(SKTResult result, SKTCaptureDeviceType deviceType))block;

/**
 * get the device Firmware version
 *
 *  @param block receiving the result and the device Firmware version if the result is successful
 */
-(void)getFirmwareVersionWithCompletionHandler:(void(^)(SKTResult result, SKTCaptureVersion *version))block;

/**
 * get the device battery level
 *
 * NOTE: to avoid pulling the battery level, some devices support a battery level change
 * notification.
 *
 *  @param block receiving the result and the device battery level if the result is successful
 */
-(void)getBatteryLevelWithCompletionHandler:(void(^)(SKTResult result, NSInteger levelInPercentage))block;

/**
 * get the device power state
 *
 * NOTE: to avoid pulling the power state, some devices support a power state change
 * notification.
 *
 *  @param block receiving the result and the device power state if the result is successful
 */
-(void)getPowerStateWithCompletionHandler:(void(^)(SKTResult result, SKTCapturePowerState powerState))block;


/**
 * get the device buttons state
 *
 * NOTE: some devices support buttons state change notifications
 *
 *  @param block receiving the result and the device buttons state if the result is successful
 */
-(void)getButtonsStateWithCompletionHandler:(void(^)(SKTResult result, SKTCaptureButtonsState buttonsState))block;


#pragma mark - Behaviour Configuration

/**
 * get the device stand configuration
 *
 *  @param block receiving the result and the device stand configuration if the result is successful
 */
-(void)getStandConfigWithCompletionHandler:(void(^)(SKTResult result, SKTCaptureStandConfig config))block;

/**
 * set the device stand configuration
 *
 *  @param config stand configuration to set the device with
 *  @param block receiving the result of changing the device stand configuration
 */
-(void)setStandConfig:(SKTCaptureStandConfig)config completionHandler:(void(^)(SKTResult result))block;

/**
 * get the device decode action
 *
 *  @param block receiving the result and the device decode action if the result is successful
 */
-(void)getDecodeActionWithCompletionHandler:(void(^)(SKTResult result, SKTCaptureLocalDecodeAction decodeAction))block;

/**
 * set the device decode action
 *
 *  @param decodeAction decode action to set the device with
 *  @param block receiving the result of changing the device decode action
 */
-(void)setDecodeAction:(SKTCaptureLocalDecodeAction)decodeAction completionHandler:(void(^)(SKTResult result))block;

/**
 * get the device local data acknowledgment
 *
 *  @param block receiving the result and the device local acknowledgment if the result is successful
 */
-(void)getDataAcknowledgmentWithCompletionHandler:(void(^)(SKTResult result, SKTCaptureDeviceDataAcknowledgment dataAcknowledgment))block;

/**
 * set the device local data acknowledgment
 *
 *  @param dataAcknowledgment set how the device acknwoledges data locally on the device
 *  @param block receiving the result of changing the device stand configuration
 */
-(void)setDataAcknowledgment:(SKTCaptureDeviceDataAcknowledgment)dataAcknowledgment completionHandler:(void(^)(SKTResult result))block;


#pragma mark - Decoded Data

/**
 * get the device postamble
 *
 *  @param block receiving the result and the device postamble if the result is successful
 */
-(void)getPostambleWithCompletionHandler:(void(^)(SKTResult result, NSString *postamble))block;

/**
 * set the device postamble
 *
 *  @param postamble postamble to set the device with
 *  @param block receiving the result of changing the device postamble
 */
-(void)setPostamble:(NSString *)postamble completionHandler:(void(^)(SKTResult result))block;

/**
 * get the device data source information
 *
 * @param dataSourceId contains the data source ID for which the information would be retrieved
 * @param block receiving the result and the device data source information if the result is successful
 */
-(void)getDataSourceInfo:(SKTCaptureDataSourceID)dataSourceId completionHandler:(void(^)(SKTResult result, SKTCaptureDataSource *dataSource))block;

/**
 * set the device data source
 *
 * @param dataSource dataSource to enable or disable
 * @param block receiving the result of changing the device data source
 */
-(void)setDataSourceInfo:(SKTCaptureDataSource *)dataSource completionHandler:(void(^)(SKTResult result))block;

/**
 * set the device trigger
 *
 * this operation can programmatically starts a device read operation, or it can
 * disable the device trigger button until it gets re-enable again by using this
 * function too.
 *
 * @param trigger contains the command to apply
 * @param block receiving the result of setting the trigger
 */
-(void)setTrigger:(SKTCaptureTrigger)trigger completionHandler:(void(^)(SKTResult result))block;

/**
 * set the decoded data confirmation
 *
 * This function is required to acknowledge the decoded data that has been received
 * when the data confirmation mode has been set to SKTCaptureDataConfirmationModeApp
 *
 * This function could also be called at any point of time if something needs to
 * be reported to the user. By example making the scanner beep or vibrate to get
 * the user to look at a screen.
 *
 * NOTE: Good AND Bad settings can not be used together.
 *
 * @param led contains the led to light (None, Green, Red)
 * @param beep contains the beep to perform (None, Good, Bad)
 * @param rumble contains the rumble to perform (None, Good, Bad)
 * @param block receiving the result of setting the decoded data confirmation
 */
-(void)setDataConfirmationWithLed:(SKTCaptureDataConfirmationLed)led withBeep:(SKTCaptureDataConfirmationBeep)beep withRumble:(SKTCaptureDataConfirmationRumble)rumble completionHandler:(void(^)(SKTResult result))block;


#pragma mark - Notifications

/**
 * set the device notifications
 *
 * @param notifications select the notifications to receive
 * @param block receiving the result of setting the notifications
 */
-(void)setNotifications:(SKTCaptureNotifications)notifications completionHandler:(void(^)(SKTResult result))block;

/**
 * get the device notifications selection
 *
 * @param block receiving the result and the device notifications setting if the result is successful
 */
-(void)getNotificationsWithCompletionHandler:(void(^)(SKTResult result, SKTCaptureNotifications notifications))block;


#pragma mark - Advanced Commands

/**
 * send a specific command to the device
 *
 * These commands are specific to a device, therefore the device should first be identified
 * before sending such commands otherwise an unpredicable result could happen if they are
 * sent to a different device.
 *
 * @param command an array of bytes that holds the specific command to send to the device
 * @param block receiving the result and the device specific command response if the result is successful
 */
-(void)getDeviceSpecificCommand:(NSData *)command completionHandler:(void(^)(SKTResult result, NSData *commandResult))block;


#pragma mark - SocketCam (scanner using Camera)
/**
 * set the device overlay view
 *
 * @param overlay overlay settings
 * @param block receiving the result of setting the overlay view
 */
-(void)setOverlayView:(NSDictionary *)overlay completionHandler:(void(^)(SKTResult result))block;


#pragma mark - Data Format (D600 Reading data from card)
/**
 * Set a data format to the device
 *
 * Examples:
 * ID-Only, TagType-and-ID, Data-Only, TagType-and-Data
 * NOTE: Only tagType-and-ID , TagType-and-Data formats are accepted. The other two will purposely return an error
 */
-(void)setDataFormat:(SKTCaptureDataFormat)dataFormat completionHandler:(void(^)(SKTResult result))block;

/**
 * Get current data format from the device
 *
 */
-(void)getDataFormatWithCompletionHandler:(void(^)(SKTResult result, SKTCaptureDataFormat dataFormat))block;


#pragma mark - generic get and set property
/*
 * Get a Device Property
 * Use this generic method only if the property is
 * not already provided in the Capture Helper
 * device methods.
 */
-(void)getProperty:(SKTCaptureProperty *)property completionHandler:(void(^)(SKTResult result, SKTCaptureProperty *property))block;

/*
 * Set a Device Property
 * Use this generic method only if the property is
 * not already provided in the Capture Helper
 * device methods.
 */
-(void)setProperty:(SKTCaptureProperty *)property completionHandler:(void(^)(SKTResult result, SKTCaptureProperty *property))block;

@end


#pragma mark - SKTCaptureHelperDeviceManager

/**
 * DeviceManager manages the BLE devices, and provides an API
 * to start the discovery of BLE devices (only looking for Socket Mobile D600).
 * It also handles the favorites. Setting a particular D600 as favorite will
 * make the DeviceManager try to connect to it automatically.
 *
 */
@interface SKTCaptureHelperDeviceManager : SKTCaptureHelperDevice

/**
 * start a discovery of devices manages by this manager (BLE)
 *
 * The discovery starts immediately and this method returns also immediately
 * with the result in the block function.
 *
 * If there are some devices around a
 * @param timeInSeconds contains the number of seconds the discovery should last
 * @param block receiving the result of starting the discovery
 */
-(void)startDiscoveryWithTimeout:(NSInteger)timeInSeconds completionHandler:(void(^)(SKTResult result))block;

/**
 * set the favorites for the auto connection. If favorites are set, the DeviceManager
 * tries to discover BLE device (only looking for Socket D600 device) and try to connect
 * to the one matching to the favorite information
 *
 * @param favorites contains the D600 peripheral identifier (UUID) semi-colon separated
 * in case there are more than one device to connect to
 * @param block called when the favorites has been set with the result as argument
 */
-(void)setFavoriteDevices:(NSString *)favorites completionHandler:(void(^)(SKTResult result))block;

/**
 * retrieve the list of favorites devices.
 * the favorites is a string of semi-colon separated peripheral UUID identifier.
 *
 * @param block called when getting the favorites has completed with the result and the
 * actual favorites string as argument.
 */
-(void)getFavoriteDevicesWithCompletionHandler:(void(^)(SKTResult result, NSString *favorites))block;

/**
 * retrieve the device unique identifier from the device GUID. The unique identifier can
 * be use to add it into the favorites list.
 *
 * @param deviceGuid contains the device GUID to identify the device to get the unique identifier from
 * @param block called when getting the device unique identifier has completed with the result and the
 * unique identifier as argument.
 */
-(void)getDeviceUniqueIdentifierFromDeviceGuid:(NSString *)deviceGuid completionHandler:(void(^)(SKTResult result, NSString *deviceUniqueIdentifier))block;

@end


#pragma mark - SKTCaptureHelperDelegate

/**
 * Capture Helper delegates
 *
 * Asynchronous event and unsolicited events are regrouped here and these
 * delegates would be called at any point of time.
 */
@protocol SKTCaptureHelperDelegate <NSObject>

@optional
/**
 * called when a error needs to be reported to the application
 *
 * @param error contains the error code
 * @param message contains an optional message, can be null
 */
-(void)didReceiveError:(SKTResult)error withMessage:(NSString *)message;

/**
 * called when a device has connected to the host
 *
 * @param device identifies the device that has just connected
 * @param result contains an error if something went wrong during the device connection
 */
-(void)didNotifyArrivalForDevice:(SKTCaptureHelperDevice *)device withResult:(SKTResult)result;

/**
 * called when a device has disconnected from the host
 *
 * @param device identifies the device that has just disconnected
 * @param result contains an error if something went wrong during the device disconnection
 */
-(void)didNotifyRemovalForDevice:(SKTCaptureHelperDevice *)device withResult:(SKTResult)result;

/**
 * called when decoded data are received from a device
 *
 * @param decodedData contains the decoded data
 * @param device identifies the device from which the decoded data comes from
 * @param result contains an error if something wrong happen while getting the decoded data
 * or if the SocketCam trigger operation has been cancelled
 */
-(void)didReceiveDecodedData:(SKTCaptureDecodedData *)decodedData fromDevice:(SKTCaptureHelperDevice *)device withResult:(SKTResult)result;

/**
 * called when the device power state has changed and if the device notifications
 * has been configured to notify the application for such event.
 *
 * @param powerState contains the new power state
 * @param device identifies the device for which the power state has changed
 */
-(void)didChangePowerState:(SKTCapturePowerState)powerState forDevice:(SKTCaptureHelperDevice *)device;

/**
 * called when the device buttons state has changed and if the device notifications
 * has been configured to notify the application for such event.
 *
 * @param buttonsState contains the actual button state of the device
 * @param device identifies the device for which the button state has changed
 */
-(void)didChangeButtonsState:(SKTCaptureButtonsState)buttonsState forDevice:(SKTCaptureHelperDevice *)device;

/**
 * called when the device battery level has changed and if the device notifications
 * has been configured to notify the application for such event.
 *
 * @param batteryPercentage contains the new battery level in percentage
 * @param device identifies the device for which the battery level has changed
 */
-(void)didChangeBatteryLevel:(NSInteger)batteryPercentage forDevice:(SKTCaptureHelperDevice *)device withResult:(SKTResult)result;

/**
 * called when the listener thread in Capture has started.
 */
-(void)listenerDidStart;

/**
 * called when a Capture is terminating. The result could
 * give an indication regarding the reason of why such event is
 * sent especially when unsolicitated.
 *
 * This event indicates the last event an application can receive
 * from Capture. It then then safe to close and free the resources
 * used for Capture.
 *
 * @param result contains an eventual error code
 */
-(void)didTerminateWithResult:(SKTResult)result;

/**
 * called when a device manager is available to the host
 *
 * @param deviceManager identifies the device manager that is just available
 * @param result contains an error if something went wrong during the device connection
 */
-(void)didNotifyArrivalForDeviceManager:(SKTCaptureHelperDeviceManager *)deviceManager withResult:(SKTResult)result;

/**
 * called when a device manager is unavailable to the host
 *
 * @param deviceManager identifies the device manage that is just unavailable
 * @param result contains an error if something went wrong during the device disconnection
 */
-(void)didNotifyRemovalForDeviceManager:(SKTCaptureHelperDeviceManager *)deviceManager withResult:(SKTResult)result;

/**
 * called when a device has been discovered by the DeviceManager
 *
 * This feature works only for BLE devices such as Socket D600
 *
 * @param device contains the device discovered indentification
 * @param deviceManager from which the device discovery has started
 */
-(void)didDiscoverDevice:(NSString *)device fromDeviceManager:(SKTCaptureHelperDeviceManager *)deviceManager;

/**
 * called with a device discovery has ended.
 *
 * This feature works only when used with a BLE DeviceManager
 *
 * @param result contains the result of the discovery
 * @param deviceManager from which the device discovery has started
 */
-(void)didDiscoveryEndWithResult:(SKTResult)result fromDeviceManager:(SKTCaptureHelperDeviceManager *)deviceManager;

@end


#pragma mark - SKTCaptureHelper Main Entry Point
/**
 *  CaptureHelper is the main entry point for the Capture API.
 *
 *  CaptureHelper should be instantiated by calling the static
 *  member: sharedInstance, which returns a reference to the
 *  unique instance of CaptureHelper.
 */
@interface SKTCaptureHelper : NSObject {

    /**
     * _extensionProperties can be used for Category SKTCaptureHelper class
     * to store some properties.
     */
    NSDictionary *_extensionProperties;

}

/**
 * instantiate a capture helper for the entire app
 * @return a unique capture helper instance
 */
+(instancetype)sharedInstance;


#pragma mark - Queue context for delegates and completion handlers

/**
 * set the dispatch queue used by Capture when invoking
 * delegates and completion handlers
 *
 * If Capture Helper dispatch queue is set to the main queue
 * then UI controls can be updated directly from the Capture Helper
 * delegates and completion handlers.
 */
-(void)setDispatchQueue:(__weak dispatch_queue_t)queue;

/**
 * retrieve the dispatch queue used by Capture when invoking
 * delegates and completion handlers
 */
-(__weak dispatch_queue_t)getDispatchQueue;


#pragma mark - Delegates Stack to handle View hierarchy

/**
 * push a delegate in the delegates stack. The last delegate
 * being pushed is the one receiving the notification.
 *
 * If the delegate on top of the stack is the same as the delegate
 * it will added like if it was a different delegate.
 *
 * returns true if the delegate has been added, false
 * otherwise.
 */
-(BOOL)pushDelegate:(id<SKTCaptureHelperDelegate>)delegate;

/**
 * pop a delegate from the delegates stack. The last delegate
 * being pushed is the first one to be pop out the stack if it
 * matches the delegate passed in argument.
 *
 * If it does not match with delegate provided in argument
 * then nothing happen.
 *
 * returns true if the delegate has been removed, false
 * otherwise.
 */
-(BOOL)popDelegate:(id<SKTCaptureHelperDelegate>)delegate;


#pragma mark - SKTCaptureHelper Open and Close

/**
 *
 * Open Capture for this app by providing the App information.
 *
 * The app must be registered on Socket Mobile developer portal
 * in order to get a AppKey matching to the application.
 *
 * @param appInfo contains the app information with the AppKey to
 * validate the access to this API.
 * @param block called upon completion of opening capture with the
 * result code
 */
-(void)openWithAppInfo:(SKTAppInfo *)appInfo completionHandler:(void(^)(SKTResult result))block;

/**
 * Close capture when the application needs to free some resources.
 *
 * @param block called upon completion of closing capture with the
 * result code
 */
-(void)closeWithCompletionHandler:(void(^)(SKTResult result))block;


#pragma mark - Capture Devices list

/**
 * Return the actual list of connected devices. This is mostly useful
 * when displaying somewhere the devices that are actually connected to
 * the host.
 * @returns the list of devices
 */
-(NSArray *)getDevicesList;


#pragma  mark - Capture information

/**
 * retrieve the Capture version
 *
 * @param block called upon completion of getting the Capture version
 * with the result and the version as argument.
 */
-(void)getVersionWithCompletionHandler:(void(^)(SKTResult result, SKTCaptureVersion *version))block;


#pragma mark - Capture configuration

/**
 * retrieve the confirmation mode used to configure how the decoded data
 * are confirmed.
 *
 * @param block called upon completion of getting the confirmation mode
 * with the result and the confirmation mode as argument.
 */
-(void)getConfirmationModeWithCompletionHandler:(void(^)(SKTResult result, SKTCaptureDataConfirmation confirmationMode))block;

/**
 * set the confirmation mode to define how the decoded data should be confirmed.
 *
 * @param confirmationMode contains the confirmation mode to set Capture with
 * @param block called upon completion of setting the confirmation mode
 * with the result of setting the confirmation mode.
 */
-(void)setConfirmationMode:(SKTCaptureDataConfirmation)confirmationMode completionHandler:(void(^)(SKTResult result))block;


#pragma mark - SocketCam (Scanner using the Camera)

/**
 * retrieve the SocketCam (Scanning using the host camera) status. The status could
 * be "not supported", "supported", "disabled" and "enabled".
 *
 * @param block called upon completion of getting the SocketCam status with
 * result and SocketCam status as argument.
 */
-(void)getSocketCamStatusWithConfirmationHandler:(void(^)(SKTResult result, SKTCaptureSocketCam status))block;

/**
 * set the SocketCam (Scanning using the host camera) status. The status could
 * be "not supported", "supported", "disabled" and "enabled".
 *
 * @param status contains the new SocketCam status.
 * @param block called upon completion of setting the SocketCam status with the
 * result as argument.
 */
-(void)setSocketCamStatus:(SKTCaptureSocketCam)status completionHandler:(void(^)(SKTResult result))block;


#pragma mark - Generic get and set property

/*
 * Get a Capture Property
 * Use this generic method only if the property is
 * not already provided in the Capture Helper
 * device methods.
 */
-(void)getProperty:(SKTCaptureProperty *)property completionHandler:(void(^)(SKTResult result, SKTCaptureProperty *property))block;

/*
 * Set a Capture Property
 * Use this generic method only if the property is
 * not already provided in the Capture Helper
 * device methods.
 */
-(void)setProperty:(SKTCaptureProperty *)property completionHandler:(void(^)(SKTResult result, SKTCaptureProperty *property))block;


@end
